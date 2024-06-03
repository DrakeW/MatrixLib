#pragma once
#include "Matrix.h"
#include <math.h>


namespace mtxai
{

	float LearningRate = 0.2;

	float WeightInitializer()
	{
		return rand() / (float)RAND_MAX;
	}

	float ActivationFunc(float input)
	{
		return 1 / (1 + exp(-input));
	}

	float ActivationFuncDer(float input)
	{
		return ActivationFunc(input) * (1 - ActivationFunc(input));
	}

	float Backpropagate(float weight, float error, float nodeOutput)
	{
		return weight - LearningRate * error * ActivationFuncDer(nodeOutput);
	}

	float(*WeightInitFunc)() = &WeightInitializer;

	void NeurralNetSetup(std::vector<mtx::matrix<float>>* weights, std::vector<mtx::matrix<float>>* nodes, std::vector<int> net)
	{
		for (int l = 0; l < net.size(); l++)
		{
			mtx::matrix<float> NodeInsert(net[l], 1);
			nodes->push_back(NodeInsert);
			if (l < net.size() - 1)
			{
				mtx::matrix<float> WeightsInsert(net[l + 1], net[l], 0);
				weights->push_back(WeightsInsert);
				(*weights)[weights->size() - 1].Apply(WeightInitFunc);
			}
		}
	}

	void NeurralNetTest(std::vector<float> input, std::vector<mtx::matrix<float>> weights, std::vector<mtx::matrix<float>> *nodes)
	{
		for (int i = 0; i < input.size(); i++)
		{
			(*nodes)[0].Data[i][0] = input[i];
		}

		for (int t = 1; t < nodes->size(); t++)
		{
			(*nodes)[t] = mtx::Multiply((*nodes)[t - 1], weights[t - 1]);
		}
	}
	void NeurralNetTrain(std::vector<float> input, std::vector<float> targets, std::vector<mtx::matrix<float>> *weights, std::vector<mtx::matrix<float>> *nodes)
	{
		NeurralNetTest(input, *weights, nodes);
		std::vector<mtx::matrix<float>> NodeErrors = *nodes;
		
		for (int i = 0; i < (*nodes)[(*nodes).size() - 1].Data.size(); i++)
		{
			(*nodes)[(*nodes).size() - 1].Data[i][0] = pow((*nodes)[(*nodes).size() - 1].Data[i][0] - targets[i], 2);
		}

		if (!((*nodes)[(*nodes).size() - 1].Data.size() - targets.size()))
		{
			for (int l = (*nodes).size() - 2; l >= 0; l--)
			{
				for (int n = 0; n < (*nodes)[l].Data.size(); n++)
				{
					(*nodes)[l].Data[n][0] = 0;
					for (int g = 0; g < (*nodes)[l + 1].Data.size(); g++)
					{
						(*nodes)[l].Data[n][0] += (*nodes)[l + 1].Data[g][0] * (*weights)[l].Data[g][n];
					}
				}
			}
		}
	}
}
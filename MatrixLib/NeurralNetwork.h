#pragma once
#include "Matrix.h"

namespace mtxai
{

	float WeightInitializer()
	{
		return rand() / (float)RAND_MAX;
	}

	float Backpropagate(float error, float oldWeight, float nodeOutput)
	{
		return;
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
	void NeurralNetTrain(std::vector<float> input, std::vector<mtx::matrix<float>> *weights, std::vector<mtx::matrix<float>> *nodes)
	{
		NeurralNetTest(input, *weights, nodes);
		std::vector<mtx::matrix<float>> NodeErrors = *nodes;



	}
}
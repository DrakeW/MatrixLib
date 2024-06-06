#pragma once
#include "Matrix.h"
#include <math.h>


namespace mtxai
{

	float LearningRate = 0.1;

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

	void Backpropagate(float *weight, float error, float nodeOutput)
	{
		*weight -= LearningRate * error * ActivationFuncDer(nodeOutput) * nodeOutput;
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

	void NeuralNetTest(std::vector<float> input, std::vector<mtx::matrix<float>> weights, std::vector<mtx::matrix<float>> *nodes)
	{
		for (int i = 0; i < input.size(); i++)
		{
			(*nodes)[0].Data[i][0] = input[i];
		}

		for (int t = 1; t < nodes->size(); t++)
		{
			(*nodes)[t] = mtx::Multiply((*nodes)[t - 1], weights[t - 1]);
			(*nodes)[t].Apply(&ActivationFunc);
		}
	}

	void NeuralNetTrain(std::vector<float> input, mtx::matrix<float> targets, std::vector<mtx::matrix<float>> *weights, std::vector<mtx::matrix<float>> *nodes)
	{
		NeuralNetTest(input, *weights, nodes);
		mtx::matrix<float> NodeErrors((*nodes).size(), 1);

		if (!((*nodes)[(*nodes).size() - 1].Data.size() - targets.Data.size()))
		{

			/*

			Setting the initial errors for the last layer, which are then used to backpropagate

			*/

			for (int i = 0; i < (*nodes)[(*nodes).size() - 1].Data.size(); i++)
			{
				NodeErrors.Data[i][0] = mtx::DirectSubtract(targets, *nodes)
			}


			/*

			Backpropagating the errors to have an error for each node

			*/

			for (int l = NodeErrors.size() - 2; l >= 0; l--)
			{
				for (int n = 0; n < NodeErrors[l].Data.size(); n++)
				{
					NodeErrors
				}
				(*nodes)[l].Apply(&ActivationFunc);
			}

			/*
			
			Setting the NodeErrors to their derivatives to help with backprop
			
			*/

			for (int i = 0; i < (*nodes)[(*nodes).size() - 1].Data.size(); i++)
			{
				NodeErrors[NodeErrors.size() - 1].Data[i][0] = -2 * (targets[i] - (*nodes)[(*nodes).size() - 1].Data[i][0]);
			}

			/*
			
			Backpropagating through the weights to update them
			
			*/
			
			for (int l = (*nodes).size() - 2; l >= 0; l--)
			{
				for (int n = 0; n < (*nodes)[l].Data.size(); n++)
				{
					for (int g = 0; g < (*nodes)[l + 1].Data.size(); g++)
					{
						Backpropagate(&(*weights)[l].Data[g][n], NodeErrors[l + 1].Data[g][0], (*nodes)[l + 1].Data[g][0]);
					}
				}
			}
		}
	}
}
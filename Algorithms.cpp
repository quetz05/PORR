#include "Algorithms.h"
#include <algorithm>
#include <iostream>
#include <thread>

using namespace std;

const static int INF = 100000;

namespace PORR
{


	Algorithm::Algorithm(const Graph &g) : graph(g)//, labels(graph.getSize(), std::make_pair(INF, false))
	{
		


	}

	Algorithm::~Algorithm()
	{
		graph.clear();
		delete[] matrixLock;
		//labels.clear();
	}

	//bool Algorithm::allChecked() const
	//{
	//	for (auto x : labels)
	//		if (x.second == false)
	//			return false;

	//	return true;
	//}

	//int Algorithm::getMinimal() const
	//{
	//	int min = INF;
	//	int node = -1;
	//	for (unsigned int i = 0; i < labels.size(); i++)
	//		if (labels[i].second == false)
	//		{
	//			if (min > labels[i].first)
	//			{
	//				min = labels[i].first;
	//				node = i;
	//			}
	//		}

	//	return node;
	//}

	//int Algorithm::getMinimal(int first, int count) const
	//{
	//	int min = INF;
	//	int node = -1;
	//	for (int i = first; i < first + count; i++)
	//		if (labels[i].second == false)
	//		{
	//			if (min > labels[i].first)
	//			{
	//				min = labels[i].first;
	//				node = i;
	//			}
	//		}

	//	return node;
	//}

	//int Algorithm::getMinimal(const std::vector<int>& nodes) const
	//{
	//	int min = INF;
	//	int node = -1;
	//	for (unsigned int i = 0; i < nodes.size(); i++)
	//		if (nodes[i] != -1 && labels[nodes[i]].second == false)
	//		{
	//			if (min > labels[nodes[i]].first)
	//			{
	//				min = labels[nodes[i]].first;
	//				node = nodes[i];
	//			}
	//		}

	//	return node;
	//}

	//int Algorithm::markNextLabels(int node)
	//{
	//	for (auto x : graph.getNode(node).connectionsTo)
	//	{
	//		if (labels[x.first].second != true)
	//		{
	//			labels[x.first].first = std::min(labels[x.first].first, labels[node].first + x.second.weight);
	//		}
	//	}

	//	int min = getMinimal();
	//	if (min != -1)
	//		labels[min].second = true;

	//	return min;

	//}

	//void Algorithm::Dijkstra(int firstNode)
	//{
	//	clearLabels();
	//	for (unsigned int i = 0; i < labels.size(); i++)
	//	{
	//		if (i == firstNode)
	//		{
	//			labels[i].first = 0;
	//			labels[i].second = true;
	//		}

	//	}

	//	int nextNode = firstNode;

	//	do
	//	{
	//		nextNode = markNextLabels(nextNode);

	//	} while (nextNode != -1);

	//	std::cout << "DIJKSTRA TABLE: ";
	//	for (auto x : labels)
	//		std::cout << x.first << " ";
	//	std::cout << std::endl;
	//}

	//void Algorithm::DijkstraParallel(int firstNode, int threadsNo)
	//{
	//	std::vector<thread*> threads(threadsNo, nullptr);
	//	clearLabels();
	//	std::vector<int> minimals(threadsNo);
	//	int threadIter = (int)graph.size() / threadsNo;

	//	for (unsigned int i = 0; i < labels.size(); i++)
	//		if (i == firstNode)
	//		{
	//			labels[i].first = 0;
	//			labels[i].second = true;
	//		}

	//	int node = firstNode;

	//	do
	//	{

	//		for (int i = 0; i < threadsNo; i++)
	//		{
	//			//ComputeRoute(std::ref(minimals[i]), node, i * threadIter, threadIter);
	//			delete threads[i];
	//			threads[i] = new thread(&Algorithm::ComputeRoute, this, std::ref(minimals[i]), node, i * threadIter, threadIter);
	//		}

	//		for (auto x : threads)
	//			x->join();


	//		int min = getMinimal(minimals);
	//		if (min != -1)
	//			labels[min].second = true;

	//		node = min;

	//	} while (node != -1);


	//	std::cout << "DIJKSTRA TABLE (THREADS " << threadsNo << "): ";
	//	for (auto x : labels)
	//		std::cout << x.first << " ";
	//	std::cout << std::endl;
	//}

	//void Algorithm::ComputeRoute(int& minimal, int node, int first, int count)
	//{
	//	auto sourceNode = graph.getNode(node);

	//	for (int i = first; i < first + count; i++)
	//	{
	//		if (sourceNode.connectionsTo.find(i) != sourceNode.connectionsTo.end() )
	//		{
	//			matrixLock.lock();
	//			//if (labels[i].second != true)
	//			//{
	//			labels[i].first = std::min(labels[i].first, labels[node].first + sourceNode.connectionsTo[i].weight);
	//			//}
	//			matrixLock.unlock();
	//		}
	//	}

	//	minimal = getMinimal(first, count);
	//}


	//std::deque<int> Algorithm::GetRoute(int firstNode, int secondNode, std::deque<int> &weights)
	//{
	//	std::deque<int> route;

	//	// dodajemy wierzcho³ek koñcowy
	//	route.push_front(secondNode);
	//	int node = secondNode;
	//	int lastNode = node;
	//	while (node != firstNode)
	//	{
	//		for (auto x : graph.find(node)->second.connectionsIn)
	//		{
	//			if (x.second.weight + labels[x.second.connectedNodeId].first == labels[node].first)
	//			{
	//				node = x.second.connectedNodeId;
	//				weights.push_front(x.second.weight);
	//				route.push_front(node);
	//				//lastNode = node;
	//				break;
	//			}

	//		}

	//		if (node == lastNode)
	//		{
	//			std::cout << "BRAK NAJKROTSZEJ SCIEZKI W GRAFIE!" << std::endl;
	//			std::deque<int> deq (0);
	//			return deq;
	//		}
	//		else
	//			lastNode = node;

	//	}

	//	std::cout << "SCIEZKA: ";
	//	for (auto x : route)
	//		std::cout << x << " ";
	//	std::cout << std::endl;

	//	return route;
	//}

	//void Algorithm::clearLabels()
	//{
	//	labels.clear();

	//	int i = 0;
	//	while (i < graph.getSize())
	//	{
	//		labels.push_back(std::make_pair(INF, false));
	//		i++;
	//	}
	//}


	/*** BELLMAN-FORD ***/

	void Algorithm::clearMatrix()
	{
		Matrix.clear();
		Matrix.push_back(std::make_pair(0, -1));
		for (int i = 1; i < graph.getSize(); i++)
			Matrix.push_back(std::make_pair(INF, -1));
	}

	void Algorithm::BellmanFord(int threadsNo)
	{
		clearMatrix();

		//int nextNode = firstNode;

		bool wasChange = false;

		for (int k = 0; k < graph.getSize(); k++)
		{
			wasChange = false;
			for (int i = 0; i < graph.getSize(); i++)
				for (auto x : graph[i].connectionsTo)
				{
					if (Matrix[x.first].first > Matrix[i].first + x.second.weight)
					{
						Matrix[x.first].first = Matrix[i].first + x.second.weight;
						Matrix[x.first].second = i;
						wasChange = true;
					}
				}

			if (!wasChange)
				break;
		}

		std::cout << "BELLMAN-FORD TABLE: " << std::endl;

		for (auto x : Matrix)
			std::cout << x.first << " ";
		std::cout << std::endl;
		for (auto x : Matrix)
			std::cout << x.second << " ";

		std::cout << std::endl;
	}

	void Algorithm::SPFA(int threadsNo)
	{
		clearMatrix();

		//int nextNode = firstNode;
		toRelax.clear();
		toRelax.push_back(0);

		while (!toRelax.empty())
		{
			int i = toRelax.front();
			toRelax.pop_front();

			for (int i = 0; i < graph.getSize(); i++)
				for (auto x : graph[i].connectionsTo)
				{
					if (Matrix[x.first].first > Matrix[i].first + x.second.weight)
					{
						Matrix[x.first].first = Matrix[i].first + x.second.weight;
						Matrix[x.first].second = i;

						if (std::find(toRelax.begin(), toRelax.end(), x.first) == toRelax.end())
							toRelax.push_back(x.first);
					}
				}
		}

		std::cout << "SPFA TABLE: " << std::endl;

		for (auto x : Matrix)
			std::cout << x.first << " ";
		std::cout << std::endl;
		for (auto x : Matrix)
			std::cout << x.second << " ";

		std::cout << std::endl;
	}

	void Algorithm::SLF(int threadsNo)
	{
		clearMatrix();

		//int nextNode = firstNode;
		toRelax.clear();
		toRelax.push_back(0);

		while (!toRelax.empty())
		{
			int i = toRelax.front();
			toRelax.pop_front();

			for (int i = 0; i < graph.getSize(); i++)
				for (auto x : graph[i].connectionsTo)
				{
					if (Matrix[x.first].first > Matrix[i].first + x.second.weight)
					{
						Matrix[x.first].first = Matrix[i].first + x.second.weight;
						Matrix[x.first].second = i;

						
						if (std::find(toRelax.begin(), toRelax.end(), x.first) == toRelax.end())
							toRelax.push_back(x.first);

						if (Matrix[toRelax.back()] < Matrix[toRelax.front()])
						{
							int temp = toRelax.back();
							toRelax.pop_back();
							toRelax.push_front(temp);
						}
							
					}
				}
		}

		std::cout << "SLF TABLE: " << std::endl;

		for (auto x : Matrix)
			std::cout << x.first << " ";
		std::cout << std::endl;
		for (auto x : Matrix)
			std::cout << x.second << " ";

		std::cout << std::endl;
	}

	void Algorithm::LLL(int threadsNo)
	{
		clearMatrix();

		//int nextNode = firstNode;
		toRelax.clear();
		toRelax.push_back(0);

		while (!toRelax.empty())
		{
			int i = toRelax.front();
			toRelax.pop_front();

			for (int i = 0; i < graph.getSize(); i++)
				for (auto x : graph[i].connectionsTo)
				{
					if (Matrix[x.first].first > Matrix[i].first + x.second.weight)
					{
						Matrix[x.first].first = Matrix[i].first + x.second.weight;
						Matrix[x.first].second = i;


						if (std::find(toRelax.begin(), toRelax.end(), x.first) == toRelax.end())
							toRelax.push_back(x.first);

						int average = 0;
						for (int v : toRelax)
							average += v;
						average = average / (int)toRelax.size();

						while (toRelax.front() > average)
						{
							int temp = toRelax.front();
							toRelax.pop_front();
							toRelax.push_back(temp);
						}
					}
				}
		}

		std::cout << "LLL TABLE: " << std::endl;

		for (auto x : Matrix)
			std::cout << x.first << " ";
		std::cout << std::endl;
		for (auto x : Matrix)
			std::cout << x.second << " ";

		std::cout << std::endl;
	}

	int Algorithm::getMinFromMatrix(const std::deque<int>& list) const
	{
		int node = -1;
		int min = INF;
		for (int x : list)
				if (min > Matrix[x].first)
				{
					min = Matrix[x].first;
					node = x;
				}

		return node;
	}

	void Algorithm::SLFLLL(int threadsNo)
	{
		clearMatrix();

		//int nextNode = firstNode;
		toRelax.clear();
		toRelax.push_back(0);

		while (!toRelax.empty())
		{
			int i = toRelax.front();
			toRelax.pop_front();

			for (int i = 0; i < graph.getSize(); i++)
				for (auto x : graph[i].connectionsTo)
				{
					if (Matrix[x.first].first > Matrix[i].first + x.second.weight)
					{
						Matrix[x.first].first = Matrix[i].first + x.second.weight;
						Matrix[x.first].second = i;


						if (std::find(toRelax.begin(), toRelax.end(), x.first) == toRelax.end())
							toRelax.push_back(x.first);

						int average = 0;
						for (int v : toRelax)
							average += v;
						average = average / (int)toRelax.size();

						if (Matrix[toRelax.back()] < Matrix[toRelax.front()])
						{
							int temp = toRelax.back();
							toRelax.pop_back();
							toRelax.push_front(temp);
						}

						while (toRelax.front() > average)
						{
							int temp = toRelax.front();
							toRelax.pop_front();
							toRelax.push_back(temp);
						}
					}
				}
		}

		std::cout << "SLF-LLL TABLE: " << std::endl;

		for (auto x : Matrix)
			std::cout << x.first << " ";
		std::cout << std::endl;
		for (auto x : Matrix)
			std::cout << x.second << " ";

		std::cout << std::endl;
	}

	void Algorithm::Dijkstra(int threadsNo)
	{
		clearMatrix();

		std::deque<int> Q;

		for (int j = 0; j < graph.getSize(); j++)
			Q.push_back(j);


		while (!Q.empty())
		{
			int i = getMinFromMatrix(Q);
			Q.erase(std::find(Q.begin(), Q.end(), i));

			for (auto x : graph[i].connectionsTo)
			{
				if (Matrix[x.first].first > Matrix[i].first + x.second.weight)
				{
					Matrix[x.first].first = Matrix[i].first + x.second.weight;
					Matrix[x.first].second = i;
				}
			}
		}

		std::cout << "DIJKSTRA TABLE: " << std::endl;

		for (auto x : Matrix)
			std::cout << x.first << " ";
		std::cout << std::endl;
		for (auto x : Matrix)
			std::cout << x.second << " ";

		std::cout << std::endl;
	}


	
	//	clearLabels();
	//	std::vector<int> minimals(threadsNo);
	//	int threadIter = (int)graph.size() / threadsNo;

	//	for (unsigned int i = 0; i < labels.size(); i++)
	//		if (i == firstNode)
	//		{
	//			labels[i].first = 0;
	//			labels[i].second = true;
	//		}

	//	int node = firstNode;

	//	do
	//	{

	//		for (int i = 0; i < threadsNo; i++)
	//		{
	//			//ComputeRoute(std::ref(minimals[i]), node, i * threadIter, threadIter);
	//			delete threads[i];
	//			threads[i] = new thread(&Algorithm::ComputeRoute, this, std::ref(minimals[i]), node, i * threadIter, threadIter);
	//		}

	//		for (auto x : threads)
	//			x->join();

	void Algorithm::DijkstraParallel(int threadsNo)
	{
		clearMatrix();
		delete[] matrixLock;
		matrixLock = new mutex[graph.getSize()];
		Q.clear();
		std::vector<thread*> threads(threadsNo, nullptr);

		for (int j = 0; j < graph.getSize(); j++)
			Q.push_back(j);

		for (int i = 0; i < threadsNo; i++)
		{
			threads[i] = new thread(&Algorithm::DijkstraThreadWork, this);
		}

		for (auto x : threads)
				x->join();

		for (auto x : threads)
			delete x;

		std::cout << "DIJKSTRA [" + std::to_string(threadsNo)  + " threads] TABLE: " << std::endl;

		for (auto x : Matrix)
			std::cout << x.first << " ";
		std::cout << std::endl;
		for (auto x : Matrix)
			std::cout << x.second << " ";

		std::cout << std::endl;
	}

	void Algorithm::DijkstraThreadWork()
	{
		
		while (!Q.empty())
		{
			qLock.lock();
			if (Q.empty())
			{
				qLock.unlock();
				return;
			}

			int i = getMinFromMatrix(Q);
			Q.erase(std::find(Q.begin(), Q.end(), i));
			qLock.unlock();

			int currentWeight = Matrix[i].first;

			for (auto x : graph[i].connectionsTo)
			{
				matrixLock[x.first].lock();
				if (Matrix[x.first].first > currentWeight + x.second.weight)
				{
					Matrix[x.first].first = currentWeight + x.second.weight;
					Matrix[x.first].second = i;
				}
				matrixLock[x.first].unlock();
			}
		}	
	}

	void Algorithm::SLFLLLParallel(int threadsNo)
	{

		clearMatrix();
		std::vector<thread*> threads(threadsNo, nullptr);
		std::vector<int> minimals(threadsNo);
		int threadIter = (int)graph.size() / threadsNo;
		delete[] matrixLock;
		matrixLock = new mutex[graph.getSize()];
		toRelax.clear();

		for (int j = 0; j < graph.getSize(); j++)
			Q.push_back(j);

		for (int i = 0; i < threadsNo; i++)
		{
			delete threads[i];
			threads[i] = new thread(&Algorithm::SLFLLLThreadWork, this, i * threadIter, threadIter);
		}

		for (auto x : threads)
			x->join();

		for (auto x : threads)
			delete x;

		//clearMatrix();
		//std::vector<thread*> threads(threadsNo, nullptr);
		//std::vector<int> minimals(threadsNo);
		//int threadIter = (int)graph.size() / threadsNo;
		//delete[] matrixLock;
		//matrixLock = new mutex[graph.getSize()];
		//toRelax.clear();
		//toRelax.push_back(0);

		//while (!toRelax.empty())
		//{
		//	int i = toRelax.front();
		//	toRelax.pop_front();

		//	for (int i = 0; i < threadsNo; i++)
		//	{
		//		delete threads[i];
		//		threads[i] = new thread(&Algorithm::SLFLLLThreadWork, this, i * threadIter, threadIter);
		//	}

		//	for (auto x : threads)
		//		x->join();
		//}

		std::cout << "SLF-LLL TABLE: " << std::endl;

		for (auto x : Matrix)
			std::cout << x.first << " ";
		std::cout << std::endl;
		for (auto x : Matrix)
			std::cout << x.second << " ";

		std::cout << std::endl;
	}

	void Algorithm::SLFLLLThreadWork(int first, int count)
	{
		while (!toRelax.empty())
		{
			qLock.lock();
			if (Q.empty())
			{
				qLock.unlock();
				return;
			}

			int i = toRelax.front();
			toRelax.pop_front();
			qLock.unlock();

			for (int i = first; i < first + count; i++)
				for (auto x : graph[i].connectionsTo)
				{
					int currentWeight = Matrix[i].first;

					matrixLock[x.first].lock();
					if (Matrix[x.first].first > currentWeight + x.second.weight)
					{
						Matrix[x.first].first = currentWeight + x.second.weight;
						Matrix[x.first].second = i;

						qLock.lock();
						if (std::find(toRelax.begin(), toRelax.end(), x.first) == toRelax.end())
						{
							toRelax.push_back(x.first);
							qLock.unlock();
						}
						else
							qLock.unlock();


						int average = 0;
						for (int v : toRelax)
							average += v;
						average = average / (int)toRelax.size();

						qLock.lock();
						if (Matrix[toRelax.back()] < Matrix[toRelax.front()])
						{
							int temp = toRelax.back();
							toRelax.pop_back();
							toRelax.push_front(temp);
							qLock.unlock();
						}

						while (toRelax.front() > average)
						{
							int temp = toRelax.front();
							toRelax.pop_front();
							toRelax.push_back(temp);
						}
						qLock.unlock();
						matrixLock[x.first].unlock();
					}
				}
		}

		
		//for (int i = first; i < first + count; i++)
		//	for (auto x : graph[i].connectionsTo)
		//	{
		//		int currentWeight = Matrix[i].first;

		//		if (Matrix[x.first].first > currentWeight + x.second.weight)
		//		{
		//			matrixLock[x.first].lock();

		//			Matrix[x.first].first = currentWeight + x.second.weight;
		//			Matrix[x.first].second = i;

		//			matrixLock[x.first].unlock();

		//			qLock.lock();
		//			if (std::find(toRelax.begin(), toRelax.end(), x.first) == toRelax.end())
		//				toRelax.push_back(x.first);

		//			int average = 0;
		//			for (int v : toRelax)
		//				average += v;
		//			average = average / (int)toRelax.size();
		//								

		//			if (Matrix[toRelax.back()] < Matrix[toRelax.front()])
		//			{
		//				int temp = toRelax.back();
		//				toRelax.pop_back();
		//				toRelax.push_front(temp);
		//			}

		//			while (toRelax.front() > average)
		//			{
		//				int temp = toRelax.front();
		//				toRelax.pop_front();
		//				toRelax.push_back(temp);
		//			}
		//			qLock.unlock();
		//		}
		//	}
	}
};


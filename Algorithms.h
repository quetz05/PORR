#pragma once
#include "Graph.h"
#include <vector>
#include <deque>
#include <mutex>
#include <list>
#include <atomic>
#include <limits>

namespace PORR
{
	class Algorithm{
	public:
		Algorithm(const Graph &g);
		~Algorithm();



		void clearAll();

		//void DijkstraParallel(int firstNode, int threadsNo = 1);
		//void ComputeRoute(int& minimal, int node, int first, int count);

		void BellmanFord(int threadsNo = 1);
		void SPFA(int threadsNo = 1);
		void SLF(int threadsNo = 1);
		void LLL(int threadsNo = 1);

		void SLFLLL(int threadsNo = 1);
		void Dijkstra(int threadsNo = 1);
		

		void DijkstraParallel(int threadsNo = 1);
		void DijkstraThreadWork();

		void SLFLLLParallel(int threadsNo = 1);
		void SLFLLLThreadWork(std::list<int>& queue);

	private:
		Graph graph;	
		std::list<int> toRelax;
		std::list<int>* toRelaxTab;
		void clearMatrix();
		std::vector<std::pair<int, int>> Matrix;
		std::deque<int> Q;
		std::mutex* matrixLock;
		std::mutex qLock;
		int getMinFromMatrix(const std::deque<int>& list) const;
		//bool CheckEdgesWeight(int node);
	};



};
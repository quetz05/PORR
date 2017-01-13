#include "Graph.h"
#include "Algorithms.h"
#include <iostream>
#include <chrono>

using namespace PORR;
using namespace std;

int main()
{
	//Graph graph("result800_40pp.txt");
	//Graph graph("result16.txt");
	//Graph graph("result128.txt");
	//Graph graph("result800.txt");
	Graph graph("result2400.txt");
	//Graph graph("result3200.txt");
	//Graph graph("result4000.txt");
	Algorithm algo(graph);


	//algo.BellmanFord();
	//algo.SPFA();
	//algo.SLF();
	//algo.LLL();
	//algo.Dijkstra();
	//algo.DijkstraParallel(1);
	//algo.DijkstraParallel(2);
	//algo.SLFLLLParallel(1);
	//algo.SLFLLLParallel(2);
	//algo.SLFLLLParallel(4);
	//algo.SLFLLLParallel(8);
	//algo.SLFLLLParallel(16);

		// dijkstra 1
		algo.DijkstraParallel(1);

		// dijkstra 2
		algo.DijkstraParallel(2);

		// dijkstra 4
		algo.DijkstraParallel(4);

		// dijkstra 8
		algo.DijkstraParallel(8);

		// dijkstra 16
		algo.DijkstraParallel(16);

		// SFLLLL 1
		algo.SLFLLLParallel(1);

		// SFLLLL 2
		algo.SLFLLLParallel(2);

		// SFLLLL 4
		algo.SLFLLLParallel(4);

		// SFLLLL 8
		algo.SLFLLLParallel(8);

		// SFLLLL 16
		algo.SLFLLLParallel(16);

	return 0;
}
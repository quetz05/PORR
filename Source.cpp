#include "Graph.h"
#include "Algorithms.h"
#include <iostream>
#include <chrono>

using namespace PORR;
using namespace std;

int main()
{
	//Graph graph("result800_40pp.txt");
	Graph graph("result16.txt");
	//Graph graph("result128.txt");
	//Graph graph("result800.txt");
	//Graph graph("result2400.txt");
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

	std::chrono::high_resolution_clock::time_point start;
	std::chrono::high_resolution_clock::time_point end;

		// dijkstra 1
		start = std::chrono::high_resolution_clock::now();
		algo.DijkstraParallel(1);
		end = std::chrono::high_resolution_clock::now();
		std::cout << "dijkstra 1: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
		cout << endl;

		// dijkstra 2
		start = std::chrono::high_resolution_clock::now();
		algo.DijkstraParallel(2);
		end = std::chrono::high_resolution_clock::now();
		std::cout << "dijkstra 2: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
		cout << endl;

		// dijkstra 4
		start = std::chrono::high_resolution_clock::now();
		algo.DijkstraParallel(4);
		end = std::chrono::high_resolution_clock::now();
		std::cout << "dijkstra 4: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
		cout << endl;

		// dijkstra 8
		start = std::chrono::high_resolution_clock::now();
		algo.DijkstraParallel(8);
		end = std::chrono::high_resolution_clock::now();
		std::cout << "dijkstra 8: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
		cout << endl;

		// dijkstra 16
		start = std::chrono::high_resolution_clock::now();
		algo.DijkstraParallel(16);
		end = std::chrono::high_resolution_clock::now();
		std::cout << "dijkstra 16: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
		cout << endl;


		// SFLLLL 1
		start = std::chrono::high_resolution_clock::now();
		algo.SLFLLLParallel(1);
		end = std::chrono::high_resolution_clock::now();
		std::cout << "SFLLLL 1: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
		cout << endl;

		// SFLLLL 2
		start = std::chrono::high_resolution_clock::now();
		algo.SLFLLLParallel(2);
		end = std::chrono::high_resolution_clock::now();
		std::cout << "SFLLLL 2: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
		cout << endl;

		// SFLLLL 4
		start = std::chrono::high_resolution_clock::now();
		algo.SLFLLLParallel(4);
		end = std::chrono::high_resolution_clock::now();
		std::cout << "SFLLLL 4: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
		cout << endl;

		// SFLLLL 8
		start = std::chrono::high_resolution_clock::now();
		algo.SLFLLLParallel(8);
		end = std::chrono::high_resolution_clock::now();
		std::cout << "SFLLLL 8: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
		cout << endl;

		// SFLLLL 16
		start = std::chrono::high_resolution_clock::now();
		algo.SLFLLLParallel(16);
		end = std::chrono::high_resolution_clock::now();
		std::cout << "SFLLLL 16: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
		cout << endl;

	return 0;
}
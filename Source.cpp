#include "Graph.h"
#include "Algorithms.h"
#include <iostream>
#include <chrono>

using namespace PORR;
using namespace std;

int main()
{
	//Graph graph("result16.txt");
	//Graph graph("result128.txt");
	//Graph graph("result800.txt");
	//Graph graph("result2400.txt");
	Graph graph("result3200.txt");
	Algorithm algo(graph);


	//algo.BellmanFord();
	//algo.SPFA();
	//algo.SLF();
	//algo.LLL();
	//algo.Dijkstra();
	//algo.DijkstraParallel(1);
	//algo.DijkstraParallel(2);
	//algo.SLFLLL();

	std::chrono::high_resolution_clock::time_point start;
	std::chrono::high_resolution_clock::time_point end;

	// dijkstra 1
	start = std::chrono::high_resolution_clock::now();
	algo.DijkstraParallel(1);
	end = std::chrono::high_resolution_clock::now();
	std::cout << std::endl << std::endl << "Czas wykonywania: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	cout << "--------------------------------------" << endl;

	// dijkstra 2
	start = std::chrono::high_resolution_clock::now();
	algo.DijkstraParallel(2);
	end = std::chrono::high_resolution_clock::now();
	std::cout << std::endl << std::endl << "Czas wykonywania: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	cout << "--------------------------------------" << endl;

	// dijkstra 4
	start = std::chrono::high_resolution_clock::now();
	algo.DijkstraParallel(4);
	end = std::chrono::high_resolution_clock::now();
	std::cout << std::endl << std::endl << "Czas wykonywania: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	cout << "--------------------------------------" << endl;

	// dijkstra 8
	start = std::chrono::high_resolution_clock::now();
	algo.DijkstraParallel(8);
	end = std::chrono::high_resolution_clock::now();
	std::cout << std::endl << std::endl << "Czas wykonywania: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	cout << "--------------------------------------" << endl;

	// dijkstra 16
	start = std::chrono::high_resolution_clock::now();
	algo.DijkstraParallel(16);
	end = std::chrono::high_resolution_clock::now();
	std::cout << std::endl << std::endl << "Czas wykonywania: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	cout << "--------------------------------------" << endl;

	std::cin.get();
	return 0;
}
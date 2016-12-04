#include "Graph.h"
#include <cassert>
#include <fstream>
#include <iostream>

namespace PORR
{
	Path::Path(int connNodeId, int pathWeight) : connectedNodeId(connNodeId), weight(pathWeight)
	{
	}

	Node::Node()
	{
	}

	Node::Node(int id) : id(id)
	{
	}

	bool Node::hasConnection(int nodeId) const
	{

		return false;
	}

	int Node::deleteConnection(int node, bool out, int weight)
	{
		if (out)
		{
			auto itPair = connectionsTo.equal_range(node);

			for (auto it = itPair.first; it != itPair.second; ++it)
			{
				if (it->second.weight == weight)
				{
					connectionsTo.erase(it);
					return weight;
				}

			}


		}
		else
		{
			auto itPair = connectionsIn.equal_range(node);
			for (auto it = itPair.first; it != itPair.second; ++it)
			{
				if (it->second.weight == weight)
				{
					connectionsIn.erase(it);
					return weight;
				}

			}
		}
		return 0;

	}

	Graph::Graph()
	{


	}

	Graph::Graph(int nodeAmount)
	{


	}


	Graph::Graph(std::string fileName)
	{
		using namespace std;


		ifstream file;
		file.open(fileName);

		if (!file.good())
		{
			cout << "Error with file " << fileName << endl;
			return;
		}

		string line = "";
		while (getline(file, line))
		{
			if (line[0] != '#' && line[0] != ' ' && line[0] != '\t' && line != "")
			{

				if (line[0] == 'W')
				{
					size_t spacePos1 = line.find(" ");
					size_t spacePos2 = line.find(" ", spacePos1 + 1);

					firstNode = atoi(line.substr(spacePos1, spacePos2).c_str());
					lastNode = atoi(line.substr(spacePos2).c_str());

				}
				else
				{
					size_t spacePos1 = line.find(" ");
					size_t spacePos2 = line.find(" ", spacePos1 + 1);

					int nodeFirst = atoi(line.substr(0, spacePos1).c_str());
					int nodeSecond = atoi(line.substr(spacePos1, spacePos2).c_str());
					int pathWeight = atoi(line.substr(spacePos2).c_str());

					addConnection(nodeFirst, Path(nodeSecond, pathWeight), true);
					addConnection(nodeSecond, Path(nodeFirst, pathWeight), false);
				}
			}
		}
	}

	Graph::~Graph()
	{


	}

	Graph::Graph(const Graph& graph)
	{
		for (auto x : graph)
			insert(x);
	}

	Graph& Graph::operator =(const Graph &graph)
	{
		clear();
		for (auto x : graph)
			insert(x);

		return *this;
	}

	const Node& Graph::getNode(int nodeId) const
	{
		return find(nodeId)->second;
	}


	int Graph::getSize() const
	{
		return (int)size();
	}


	void Graph::addConnection(int nodeId, int connectedNodeId, int weight, bool nodeOut)
	{
		auto it = find(nodeId);
		if (it == end())
			it = addNode(nodeId);

		if (nodeOut)
			it->second.connectionsTo.insert(std::make_pair(connectedNodeId, Path(connectedNodeId, weight)));
		else
			it->second.connectionsIn.insert(std::make_pair(connectedNodeId, Path(connectedNodeId, weight)));
	}


	void Graph::addConnection(int nodeId, const Path& path, bool nodeOut)
	{
		auto it = find(nodeId);
		if (it == end())
			it = addNode(nodeId);

		if (nodeOut)
			it->second.connectionsTo.insert(std::make_pair(path.connectedNodeId, path));
		else
			it->second.connectionsIn.insert(std::make_pair(path.connectedNodeId, path));

	}

	Graph::iterator Graph::addNode(const Node& newNode)
	{
		return insert(std::make_pair(newNode.id, newNode)).first;
	}


	Graph::iterator Graph::addNode(int id)
	{
		return insert(std::make_pair(id, Node(id))).first;
	}

	int Graph::deleteConnection(int nodeId1, int nodeId2, int weight)
	{
		auto it = find(nodeId1);
		auto it2 = find(nodeId2);
		if (it == end() || it2 == end())
			return 0;


		int w1 = it->second.deleteConnection(nodeId2, true, weight);
		int w2 = it2->second.deleteConnection(nodeId1, false, weight);

		assert(w1 == w2);
		assert(w1 == weight);

		return weight;
	}

	void Graph::print()
	{
		for (auto x : *this)
		{
			std::cout << x.first << ":\n\tin:" << std::endl;

			for (auto y : x.second.connectionsIn)
				std::cout << "\t\t" << y.first << " " << x.first << " (" << y.second.weight << ")" << std::endl;
			std::cout << "\tout:" << std::endl;
			for (auto y : x.second.connectionsTo)
				std::cout << "\t\t" << x.first << " " << y.first << " (" << y.second.weight << ")" << std::endl;
			std::cout << std::endl;
		}
	}

}

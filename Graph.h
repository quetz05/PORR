#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <map>

namespace PORR
{
	///
	/// \brief Klasa �cie�ki grafu
	///
	struct Path
	{
		Path() = default;
		Path(int connNodeId, int pathWeight);
		int connectedNodeId;
		int weight;

	};

	///
	/// \brief Klasa w�z�a grafu posiadaj�ca id w�z�a oraz map� po��cze� tego w�z�a z innymi
	///
	struct Node
	{
		Node();

		///
		/// \brief Konstruktor w�z�a o podanym id
		/// \param id id w�z�a
		///
		Node(int id);

		int id;
		std::map<int, Path> connectionsTo;
		std::map<int, Path> connectionsIn;

		///
		/// \brief Konstruktor w�z�a o podanym id
		/// \param nodeId id w�z�a
		/// \return zwraca true lub false w zale�no�ci czy dany w�ze� jest po��czony z drugim
		///
		bool hasConnection(int nodeId) const;

		///
		/// \brief Funkcja usuwaj�ca dane po��czenie w�z�a
		/// \param node id w�z�a
		/// \param out okre�la czy ma to by� po��czenie wchodz�ce czy wychodz�ce z w�z�a
		/// \return zwraca wag� usuni�tego po��czenia
		///
		int deleteConnection(int node, bool out, int weight);
	};

	///
	/// \brief Klasa grafu skierowanego, gdzie mi�dzy tymi samymi w�z�ami mo�e by� maksymalnie jedno po��czenie (w jednym kierunku)
	///
	class Graph : public std::map<int, Node>
	{
	public:
		///
		/// \brief Konstruktor bezargumentowy
		///
		Graph();

		///
		/// \brief Konstruktor kopiuj�cy
		///
		Graph(const Graph& graph);

		///
		/// \brief Konstruktor tworz�cy graf o danej ilo�ci w�z��w (bez po��cze�)
		/// \param nodeAmount ilo�� w�z��w
		///
		Graph(int nodeAmount);

		///
		/// \brief Konstruktor grafu wczytuj�cy dane o w�z�ach i po��czeniach z pliku
		/// \param fileName �cie�ka do pliku
		///
		Graph(std::string fileName);

		///
		/// \brief Destruktor
		///
		~Graph();

		///
		/// \brief Operator przypisania
		///
		Graph & operator =(const Graph &graph);

		///
		/// \brief Funkcja zwracaj�ca w�ze�
		/// \param nodeId id w�z�a
		/// \return w�ze� o danym id
		///
		const Node& getNode(int nodeId) const;

		///
		/// \brief Funkcja zwracaj�ca ilo�� w�z��w
		/// \return ilo�� w�z��w
		///
		int getSize() const;

		///
		/// \brief Funkcja dodaj�ca po��czenie
		/// \param noteId id w�z�a pocz�tkowego
		/// \param connectedNodeId id w�z�a ko�cowego
		/// \param weight waga �cie�ki
		///	\param nodeOut okre�la czy jest to kraw�d� skierowana do czy od w�z�a
		///
		void addConnection(int nodeId, int connectedNodeId, int weight, bool nodeOut);

		///
		/// \brief Funkcja dodaj�ca po��czenie
		/// \param noteId id w�z�a pocz�tkowego
		/// \param path nowa �cie�ka
		///	\param nodeOut okre�la czy jest to kraw�d� skierowana do czy od w�z�a
		///
		void addConnection(int nodeId, const Path& path, bool nodeOut);

		///
		/// \brief Funkcja dodaj�ca w�ze�
		/// \param newNode nowy w�ze�
		///
		void hasNode(const Node& newNode);


		///
		/// \brief Funkcja dodaj�ca w�ze�
		/// \param newNode nowy w�ze�
		/// \return iterator dodanego w�z�a
		///
		Graph::iterator addNode(const Node& newNode);

		///
		/// \brief Funkcja dodaj�ca w�ze�
		/// \param id id nowego w�z�a
		/// \return iterator dodanego w�z�a
		///
		Graph::iterator addNode(int id);


		///
		/// \brief Funkcja usuwaj�ca dane po��czenie w grafie
		/// \param nodeId1 id pierwszego w�z�a
		/// \param nodeId2 id drugiego w�z�a
		/// \return waga usuni�tego po��czenia
		///
		int deleteConnection(int nodeId1, int nodeId2, int weight);

		///
		/// \brief Funkcja drukuj�ca na ekranie struktur� grafu
		///
		void print();

		int firstNode;
		int lastNode;
	};


}


#endif
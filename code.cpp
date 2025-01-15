//#include<iostream>
//
//using namespace std;
//
//class graph // creating an array based graph
//{
//	int* vertices; // will contain vertices
//	int** edges; // will contain edges as its a 2D array
//	int numVertex;
//	int edgesCount;
//	int size;
//
//public:
//	graph(int size) // constructor for graph where size of vertices is specified
//	{
//		this->size = size;
//		vertices = new int[size];     // creating vertices of graph
//
//		edges = new int* [size];        // creating edges of graph
//		for (int i = 0; i < size; i++)
//		{
//			edges[i] = new int[size];
//		}
//
//		numVertex = 0;
//		edgesCount = 0;
//	}
//
//	void addVertex(int vertex)    // for adding vertex in graph
//	{
//		if (numVertex == size)           // if size is full then can't add
//		{
//			cout << "Can't add vertices! \n";
//			return;
//		}
//
//		vertices[numVertex] = vertex;
//		for (int i = 0; i <= numVertex; i++)
//		{
//			edges[numVertex][i] = 0; // as its a undirectional graph so both edges will be zero
//			edges[i][numVertex] = 0;
//		}
//
//		numVertex++;
//	}
//
//	void addEdge(int fromVertex, int toVertex)    // for adding edges in graph
//	{
//		if (edgesCount == size * size)        // for maximum edges in graph
//		{
//			cout << "Can't add edge! \n";
//			return;
//		}
//
//		int fromIndex = indexIs(fromVertex);
//		int toIndex = indexIs(toVertex);
//
//		if (fromIndex == -1 || toIndex == -1)     // this is if one of two vertices or both vertices are not present
//		{
//			cout << "Invalid vertices! \n";
//			return;
//		}
//
//		edges[fromIndex][toIndex] += 1; // because of undirectional graph
//		edges[toIndex][fromIndex] += 1;
//
//		edgesCount++;
//	}
//
//	int indexIs(int vertex)         // will help to fetch the index of vertex
//	{
//		for (int i = 0; i < numVertex; i++)
//		{
//			if (vertex == vertices[i])
//			{
//				return i;
//			}
//		}
//
//		return -1;     // if not found
//	}
//
//	void displayGraph() // Will display the graph in the form of matrix
//	{
//		if (numVertex == 0)       // if graph is empty
//		{
//			cout << "Graph is empty! \n";
//			return;
//		}
//
//		cout << "   ";
//		for (int i = 0; i < numVertex; i++)         // diplaying vertices
//		{
//			cout << vertices[i] << " ";
//		}
//		cout << endl;
//
//		for (int i = 0; i < numVertex; i++)
//		{
//			cout << vertices[i] << ": ";
//
//			for (int j = 0; j < numVertex; j++)
//			{
//				cout << edges[i][j] << " ";        // displaying edges
//			}
//			cout << endl;
//		}
//	}
//
//	bool isHamiltonianCircuitHelper(int path[], bool visited[], int& pos) // helper function for hamilton circuit
//	{
//		if (pos == numVertex)  // if length of path reaches all vertices
//		{
//			if (edges[path[pos - 1]][path[0]] == 1) // if the last one makes circuit with first
//			{
//				path[pos] = path[0];
//				pos++;
//				return true; // it is hamilton circuit
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//		// will go and check the transitional relation of every vertex
//		for (int i = 0; i < numVertex; i++)
//		{
//			if (edges[path[pos - 1]][i] == 1 && !visited[i])
//			{
//				visited[i] = true;
//				path[pos] = i;
//				pos++;
//
//				if (isHamiltonianCircuitHelper(path, visited, pos))  // recursive call 
//				{
//					return true;
//				}
//
//				visited[i] = false;
//			}
//		}
//		return false;      // if hamilton circuit not found then return false
//	}
//
//	bool isHamiltonianCircuit(int path[], int& length)  // parent hamilton circuit function
//	{
//		if (numVertex == 0) // check for empty graph
//		{
//			cout << "Graph is empty! \n";
//			return false;
//		}
//
//		bool* visited = new bool[numVertex], result; // initialize the visited array with false
//		for (int i = 0; i < numVertex; i++)
//		{
//			visited[i] = false;
//		}
//
//		path[0] = 0; // checking circuit from first vertex
//		length++; // length for path
//		visited[0] = true; // the first vertex is visited
//
//		result = isHamiltonianCircuitHelper(path, visited, length);  // calling helper function
//		delete[]visited;
//		return result;
//	}
//
//	bool isHamiltonianPathHelper(int path[], bool visited[], int& pos)  // helper function for hamilton path
//	{
//		if (pos == numVertex)  // if it completes all vertices then it is hamilton path
//		{
//			return true;
//		}
//
//		// will go and check the transitional relation of every vertex
//		for (int i = 0; i < numVertex; i++)
//		{
//			if (edges[path[pos - 1]][i] == 1 && !visited[i])
//			{
//				visited[i] = true;
//				path[pos] = i;
//				pos++;
//
//				if (isHamiltonianPathHelper(path, visited, pos))  // recursive call 
//				{
//					return true;
//				}
//
//				visited[i] = false;
//			}
//		}
//
//		return false;  // if hamilton path not found then return false
//	}
//
//	bool isHamiltonianPath(int path[], int& length)  // parent hamilton path function
//	{
//		if (numVertex == 0) // check for empty graph
//		{
//			cout << "Graph is empty! \n";
//			return false;
//		}
//
//		bool* visited = new bool[numVertex], result;// initialize the visited array with false
//		for (int i = 0; i < numVertex; i++)
//		{
//			visited[i] = false;
//		}
//
//		for (int i = 0; i < numVertex; i++)
//		{
//			path[0] = i; // cheking path from every vertex
//			length++; // the length of path
//			visited[i] = true; // starting vertex is visited
//
//			if (isHamiltonianPathHelper(path, visited, length))  // calling helper function
//			{
//				delete[]visited;
//				return true;
//			}
//		}
//
//		delete[]visited;
//		return false;
//	}
//
//	bool isConnected(int path[], int& length, int startVertex = 0)  // Function to check if the graph is connected starting from a vertex
//	{
//		int** tempEdges = new int* [numVertex];   // create a temporary copy of edges
//		for (int i = 0; i < numVertex; i++)
//		{
//			tempEdges[i] = new int[numVertex];
//			for (int j = 0; j < numVertex; j++)
//			{
//				tempEdges[i][j] = edges[i][j];   // copy edges to temp array
//			}
//		}
//
//		bool* visited = new bool[numVertex];
//		for (int i = 0; i < numVertex; i++)
//		{
//			visited[i] = false; // mark all vertices as unvisited
//		}
//		length = 0;
//
//		dfs(startVertex, visited, path, length, tempEdges); // perform DFS to check connectivity
//
//		// Check for disconnected vertices
//		for (int i = 0; i < numVertex; i++)
//		{
//			int degree = 0;
//			for (int j = 0; j < numVertex; j++)
//			{
//				degree += tempEdges[i][j]; // calculate degree of the vertex
//			}
//
//			if (degree > 0 && !visited[i]) // if degree > 0 and vertex is not visited
//			{
//				for (int k = 0; k < numVertex; k++)
//				{
//					delete[] tempEdges[k]; // free memory
//				}
//				delete[] tempEdges;
//				delete[] visited;
//				return false;  // graph is not connected
//			}
//		}
//
//		// Clean up and return true if connected
//		for (int i = 0; i < numVertex; i++)
//		{
//			delete[] tempEdges[i];
//		}
//		delete[] tempEdges;
//		delete[] visited;
//		return true;
//	}
//
//	void dfs(int vertex, bool visited[], int path[], int& length, int** tempEdges)  // Depth First Search to check connectivity
//	{
//		visited[vertex] = true;   // mark current vertex as visited
//		path[length++] = vertex;  // add to the path
//
//		for (int i = 0; i < numVertex; i++)
//		{
//			if (tempEdges[vertex][i] > 0)  // check for edge existence
//			{
//				tempEdges[vertex][i]--;  // decrement edge count
//				tempEdges[i][vertex]--;  // decrement reverse edge count
//				dfs(i, visited, path, length, tempEdges);  // recursive DFS call
//			}
//		}
//	}
//
//	bool isEulerianCircuit(int path[], int& length)  // Check if the graph has an Eulerian Circuit
//	{
//		if (numVertex == 0) // check for empty graph
//		{
//			cout << "Graph is empty! \n";
//			return false;
//		}
//
//		// Check if all vertices have even degree
//		for (int i = 0; i < numVertex; i++)
//		{
//			int degree = 0;
//			for (int j = 0; j < numVertex; j++)
//			{
//				degree += edges[i][j];
//			}
//
//			if (degree % 2 != 0)  // if degree is odd, not Eulerian Circuit
//				return false;
//		}
//
//		// Check connectivity
//		if (isConnected(path, length))
//		{
//			path[length] = path[0];  // close the circuit
//			return true;   // Eulerian Circuit exists
//		}
//
//		return false;  // otherwise, no Eulerian Circuit
//	}
//
//	bool isEulerianPath(int path[], int& length)   // Check if the graph has an Eulerian Path
//	{
//		if (numVertex == 0) // check for empty graph
//		{
//			cout << "Graph is empty! \n";
//			return false;
//		}
//
//		int oddDegreeCount = 0;
//
//		for (int i = 0; i < numVertex; i++)   // for calculating degree of all vertices
//		{
//			int degree = 0;
//			for (int j = 0; j < numVertex; j++)
//			{
//				degree += edges[i][j];
//			}
//			if (degree % 2 != 0)    // if degree is odd
//			{
//				oddDegreeCount++;  // increment odd degree count
//			}
//		}
//
//		if (oddDegreeCount != 0 && oddDegreeCount != 2) // if not 0 or 2 odd degree vertices
//			return false;
//
//		if (isConnected(path, length)) // check connectivity
//		{
//			return true; // Eulerian Path exists
//		}
//
//		return false; // otherwise, no Eulerian Path
//	}
//
//	void displayPath(int path[], int length)   // Function to display the path
//	{
//		if (length < 1) // if path is empty
//		{
//			return; // do nothing
//		}
//
//		for (int i = 0; i < length; i++)  // loop through path
//		{
//			cout << vertices[path[i]]; // display vertex
//			if (i < length - 1)    // for formatting
//			{
//				cout << ", ";   // separate vertices with a comma
//			}
//		}
//		cout << endl;
//	}
//
//	~graph()    // Destructor to free dynamically allocated memory
//	{
//		delete[] vertices; // delete vertex array
//
//		for (int i = 0; i < size; i++)
//		{
//			delete[] edges[i]; // delete rows of edges
//		}
//		delete[] edges; // delete the edge array
//	}
//};
//
//int main()
//{
//	int vertices, edges, length;
//
//	cout << "Enter the total number of vertices: ";
//	cin >> vertices;
//	while (vertices < 1)    // correcting vertex input
//	{
//		cout << "Enter valid number of vertices: ";
//		cin >> vertices;
//	}
//	graph Graph(vertices);
//
//	cout << "\nEnter vertices: \n";
//	for (int i = 0; i < vertices; i++)
//	{
//		int temp;
//		cin >> temp;
//		Graph.addVertex(temp); // add vertices to the graph
//	}
//
//	cout << "\nEnter the total number of edges: ";
//	cin >> edges;
//	while (edges < 1 || edges > vertices * vertices) // correcting edge input
//	{
//		cout << "Enter valid number of edges: ";
//		cin >> edges;
//	}
//
//	for (int i = 0; i < edges; ++i)
//	{
//		cout << "\nEnter edge " << i + 1 << ": \n";
//		int u, v;
//		cout << "Enter from vertex: ";
//		cin >> u;
//		cout << "Enter to vertex: ";
//		cin >> v;
//		Graph.addEdge(u, v);   // add edges to the graph
//	}
//
//	cout << "\nDisplaying graph: \n";
//	Graph.displayGraph();    // show graph structure
//
//	while (true)
//	{
//		// Menu driven
//		cout << "\nMenu: \n";
//		cout << "0. Exit \n";
//		cout << "1. Check for Hamiltonian Circuit \n";
//		cout << "2. Check for Hamiltonian Path \n";
//		cout << "3. Check for Euler Circuit \n";
//		cout << "4. Check for Euler Path \n";
//		cout << "Enter your choice: ";
//		int choice;
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 0:
//			cout << "\nExiting...\n";
//			return 0;
//
//		case 1:
//		{
//			int* path = new int[vertices * vertices]; // create path array
//			length = 0;
//			if (Graph.isHamiltonianCircuit(path, length)) // check for Hamiltonian Circuit
//			{
//				cout << "\nHamiltonian Circuit exists: ";
//				Graph.displayPath(path, length); // display the circuit
//			}
//			else
//			{
//				cout << "\nNo Hamiltonian Circuit exists.\n";
//			}
//
//			delete[] path; // free memory
//			break;
//		}
//		case 2:
//		{
//			int* path = new int[vertices * vertices]; // create path array
//			length = 0;
//			if (Graph.isHamiltonianPath(path, length)) // check for Hamiltonian Path
//			{
//				cout << "\nHamiltonian Path exists: ";
//				Graph.displayPath(path, length); // display the path
//			}
//			else
//			{
//				cout << "\nNo Hamiltonian Path exists.\n";
//			}
//
//			delete[] path; // free memory
//			break;
//		}
//		case 3:
//		{
//			int* path = new int[vertices * vertices]; // create path array
//			length = 0;
//			if (Graph.isEulerianCircuit(path, length)) // check for Eulerian Circuit
//			{
//				cout << "\nEuler Circuit exists: ";
//				Graph.displayPath(path, length); // display the circuit
//			}
//			else
//			{
//				cout << "\nNo Euler Circuit exists.\n";
//			}
//
//			delete[] path; // free memory
//			break;
//		}
//		case 4:
//		{
//			int* path = new int[vertices * vertices]; // create path array
//			length = 0;
//			if (Graph.isEulerianPath(path, length)) // check for Eulerian Path
//			{
//				cout << "\nEuler Path exists: ";
//				Graph.displayPath(path, length); // display the path
//			}
//			else
//			{
//				cout << "\nNo Euler Path exists.\n";
//			}
//
//			delete[] path; // free memory
//			break;
//		}
//		default:
//			cout << "\nInvalid choice.\n";
//		}
//	}
//
//	system("pause");
//	return 0;
//}
// #include<bits/stdc++.h>
// using namespace std;
// #define M 101
// int n;
// int minKey(int key[],bool mstSet[]){
// 	int min = INT_MAX,min_index;
// 	for(int v = 0;v<M;v++){
// 		if(mstSet[v] == false and key[v] < min){
// 			min = key[v],min_index = v;
// 		}
// 	}
// 	return min_index;
// }

// void printMST(int parent[],int graph[][M]){
// 	int sum = 0;
// 	cout << "Edge \tWeight\n";
// 	for(int i = 1;i<n;i++){
// 		cout << parent[i] << " - " << i << " \t " <<
// 				graph[i][parent[i]] << " \n";
// 				sum += graph[i][parent[i]];
// 	}
// 	cout << endl << sum;
// }

// void primMST(int graph[][M]){
// 	int parent[M];
// 	int key[M];
// 	bool mstSET[M];
// 	for(int i = 0;i < M;i++){
// 		key[i] = INT_MAX,mstSET[i] = false;
// 	}
// 	key[0] = 0;
// 	parent[0] = -1;
// 	for(int cnt = 0;cnt < n-1;cnt++){
// 		int u = minKey(key,mstSET);
// 		mstSET[u] = true;
// 		for(int v = 0;v < M;v++){
// 			if(graph[u][v] != 0 and mstSET[v] == false 
// 			   and graph[u][v] < key[v]){
// 				parent[v] = u,key[v] = graph[u][v];
// 			}
// 		}
// 	}
// 	printMST(parent,graph);
// }

// // #include <bits/stdc++.h>
// // using namespace std;
 
// // // Number of vertices in the graph
// // #define M 9
 
// // // A utility function to find the vertex with
// // // minimum key value, from the set of vertices
// // // not yet included in MST
// // int minKey(int key[], bool mstSet[])
// // {
// //     // Initialize min value
// //     int min = INT_MAX, min_index;
 
// //     for (int v = 0; v < M; v++)
// //         if (mstSet[v] == false && key[v] < min)
// //             min = key[v], min_index = v;
 
// //     return min_index;
// // }
 
// // // A utility function to print the
// // // constructed MST stored in parent[]
// // void printMST(int parent[], int graph[][M])
// // {
// //     cout << "Edge \tWeight\n";
// //     for (int i = 1; i < M; i++)
// //         cout << parent[i] << " - " << i << " \t"
// //              << graph[i][parent[i]] << " \n";
// // }
 
// // // Function to construct and print MST for
// // // a graph represented using adjacency
// // // matrix representation
// // void primMST(int graph[][M])
// // {
// //     // Array to store constructed MST
// //     int parent[M];
 
// //     // Key values used to pick minimum weight edge in cut
// //     int key[M];
 
// //     // To represent set of vertices included in MST
// //     bool mstSet[M];
 
// //     // Initialize all keys as INFINITE
// //     for (int i = 0; i < M; i++)
// //         key[i] = INT_MAX, mstSet[i] = false;
 
// //     // Always include first 1st vertex in MST.
// //     // Make key 0 so that this vertex is picked as first
// //     // vertex.
// //     key[0] = 0;
   
// //     // First node is always root of MST
// //     parent[0] = -1;
 
// //     // The MST will have V vertices
// //     for (int count = 0; count < M - 1; count++) {
         
// //         // Pick the minimum key vertex from the
// //         // set of vertices not yet included in MST
// //         int u = minKey(key, mstSet);
 
// //         // Add the picked vertex to the MST Set
// //         mstSet[u] = true;
 
// //         // Update key value and parent index of
// //         // the adjacent vertices of the picked vertex.
// //         // Consider only those vertices which are not
// //         // yet included in MST
// //         for (int v = 0; v < M; v++)
 
// //             // graph[u][v] is non zero only for adjacent
// //             // vertices of m mstSet[v] is false for vertices
// //             // not yet included in MST Update the key only
// //             // if graph[u][v] is smaller than key[v]
// //             if (graph[u][v] && mstSet[v] == false
// //                 && graph[u][v] < key[v])
// //                 parent[v] = u, key[v] = graph[u][v];
// //     }
 
// //     // Print the constructed MST
// //     printMST(parent, graph);
// // }

// int main(){
// 	cin >> n;
// 	int graph[M][M] = {
// 		{0, 4, 0, 0, 0, 0, 0, 8, 0},
// 		{4, 0, 8, 0, 0, 0, 0, 11, 0},
// 		{0, 8, 0, 7, 0, 4, 3, 0, 4},
// 		{0, 0, 7, 0, 9, 14, 0, 0, 0},
// 		{0, 0, 0, 9, 0, 10, 0, 0, 0},
// 		{0, 0, 4, 14, 10, 0, 2, 0, 0},
// 		{0, 0, 3, 0, 0, 2, 0, 1, 4},
// 		{8, 11, 0, 0, 0, 0, 1, 0, 7},
// 		{0, 0, 4, 0, 0, 0, 4, 7, 0}
// 	};
// 	primMST(graph);
// 	return 0;
// }


// Prim's Algorithm in C++

#include <cstring>
#include <iostream>
using namespace std;

#define INF 9999999

// number of vertices in grapj
#define V 9

// create a 2d array of size 5x5
//for adjacency matrix to represent graph

int G[V][V] = {
	{0, 4, 0, 0, 0, 0, 0, 8, 0},
	{4, 0, 8, 0, 0, 0, 0, 11, 0},
	{0, 8, 0, 7, 0, 4, 3, 0, 4},
	{0, 0, 7, 0, 9, 14, 0, 0, 0},
	{0, 0, 0, 9, 0, 10, 0, 0, 0},
	{0, 0, 4, 14, 10, 0, 2, 0, 0},
	{0, 0, 3, 0, 0, 2, 0, 1, 3},
	{8, 11, 0, 0, 0, 0, 1, 0, 7},
	{0, 0, 4, 0, 0, 0, 3, 7, 0}
};

int main() {
  int no_edge;  // number of edge
  int sum = 0;
  // create a array to track selected vertex
  // selected will become true otherwise false
  int selected[V];

  // set selected false initially
  memset(selected, false, sizeof(selected));

  // set number of edge to 0
  no_edge = 0;

  // the number of egde in minimum spanning tree will be
  // always less than (V -1), where V is number of vertices in
  //graph

  // choose 0th vertex and make it true
  selected[0] = true;

  int x;  //  row number
  int y;  //  col number

  // print for edge and weight
  cout << "Edge"
     << " : "
     << "Weight";
  cout << endl;
  while (no_edge < V - 1) {
    //For every vertex in the set S, find the all adjacent vertices
    // , calculate the distance from the vertex selected at step 1.
    // if the vertex is already in the set S, discard it otherwise
    //choose another vertex nearest to selected vertex  at step 1.

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout << x << " - " << y << " :  " << G[x][y];
	sum+=G[x][y];
    cout << endl;
    selected[y] = true;
    no_edge++;
  }
  cout << sum << endl;
  return 0;
}
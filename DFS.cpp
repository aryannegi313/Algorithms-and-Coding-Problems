#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int src;
    int dest;
};

class Graph{
    
    vector<vector<int>> adjList;
    public:
        void addEdge(vector<Edge>& edges, int N)
        {
            adjList.resize(N);
            for(auto& edge:edges){
                adjList[edge.src] = adjList[edge.dest];
                adjList[edge.dest] = adjList[edge.src];
            }
        }
        
        void printGraph(Graph g,int N)
        {
        	for(int i=0;i<N;i++)
        	{
        		for(auto& edge:g.adjList[i]){
        			cout << edge << "->";
				}
			}
		}
};

int main(){
    Graph g;
    vector<Edge> edges = {{1,2},{3,4},{4,5}};
    g.addEdge(edges,3);
    g.printGraph(g,3);
}

#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    std::vector<vector<int>> adjList;
    
    public:
    
        Graph(int V){
            this->V = V;
            adjList.resize(V);
        }
        
        void addEdge(int src,int dest){
            adjList[src].push_back(dest);
        }
        
        void printGraph(){
            
            for(int i=0;i<V;i++)
            {
                cout<<i<<"-> ";
                for(auto& j:adjList[i])
                {
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
        
        void DFS(int x, vector<bool> visited){
            visited[x] = true;
            cout<< x <<" ";
            for(auto& i:adjList[x]){
                if(!visited[i]){
                    DFS(i,visited);
                }
            }
        }
        
        void BFS(int x, vector<bool> visited){
            std::queue<int> q;
            q.push(x);
            
            while(!q.empty()){
                int el = q.front();
                
                if(!visited[el]){
                    cout<< el <<" ";
                    visited[el] = true;
                    q.pop();
                    
                    for(auto& i:adjList[el]){
                        if(!visited[i])
                            q.push(i);
                    }
                }
            }
        }
};

int main(){
    
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    
    cout<<"the graph:"<<endl;
    g.printGraph();
    cout<<endl;
    
    
    cout<<endl<<"DFS"<<endl;
    vector<bool> visited(4,false);
    g.DFS(2,visited);
    
    cout<<endl<<"BFS"<<endl;
    g.BFS(2,visited);
}
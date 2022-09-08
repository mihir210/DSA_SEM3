#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

class DFS
{
    public:
    
    int v;
    vector<list<int>> adj;
    
    DFS(int l)
    {
        v=l;
        adj.resize(v);
    }
    
    void addEdges(int e,int g)
    {
        adj[e].push_back(g);
    }
    
    void dfsTraversal(int s)
    {
        stack <int> st;
        vector <bool> visited(v,false);
        st.push(s);
        visited[s]=true;
        
        while(!st.empty())
        {
            int e = st.top();
            cout << e << " ";
            st.pop();
            for(auto a:adj[e])
            {
                if(!visited[a])
                {
                    visited[a]=true;
                    st.push(a);
                }
            }
            
        }
    }
    
};

int main()
{
    DFS d(7);
    d.addEdges(0,1);
    d.addEdges(1,0);
    d.addEdges(1,2);
    d.addEdges(1,3);
    d.addEdges(2,1);
    d.addEdges(3,1);
    d.addEdges(2,4);
    d.addEdges(4,2);
    d.addEdges(3,4);
    d.addEdges(4,3);
    d.addEdges(4,5);
    d.addEdges(5,4);
    d.addEdges(4,6);
    d.addEdges(6,4);
    d.dfsTraversal(1);
    return 0;
}
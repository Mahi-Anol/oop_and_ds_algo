#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int nodes;//How many nodes?
    list<int>* nbrs;//ADJ list
public:
    Graph(int nodes):nodes(nodes){
        nbrs=new list<int>[nodes];
    }

    void add_edge(int x,int y,bool undir=true)
    {
        nbrs[x].push_back(y);
        if(undir)
        {
            nbrs[y].push_back(x);
        }
    }
    void print(){

        for(int i=0;i<nodes;i++)
        {
            for(auto y:nbrs[i])
            {

                cout<<i<<"-->"<<y<<endl;
            }
        }
    }

    void bfs(int source)
    {

        cout<<"Performing BFS: "<<endl;

        bool *visited=new bool[nodes]{false};

        queue<int>q;
        q.push(source);
        visited[source]=true;

        while(!q.empty())
        {
            int node=q.front();
            cout<<node<<" ";
            q.pop();
            for(auto nbr:nbrs[node])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }

        cout<<endl;

        delete[] visited;

    }


    void sssp(int source,int dest=-1)//single source shortest path.(modified bfs)
    {

        cout<<"Performing single source shortest path: "<<endl;

        bool *visited=new bool[nodes]{false};

        int *distance=new int[nodes]{0};//From source to each individual node.

        int *parent=new int[nodes];

        for(int i=0;i<nodes;i++)
        {

            parent[i]=-1;
        }

        queue<int>q;
        q.push(source);
        visited[source]=true;

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto nbr:nbrs[node])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    parent[nbr]=node;
                    distance[nbr]=distance[node]+1;
                    visited[nbr]=true;
                }
            }
        }

        for(int i=0;i<nodes;i++)
        {

            cout<<"Distance from "<<source<<" to "<<i<<" is "<<distance[i]<<endl;
        }

        if(dest!=-1)
        {

            int temp=dest;
            while(temp!=source)
            {
                cout<<temp<<"-->";
                temp=parent[temp];
            }
            cout<<source<<endl;
        }



        delete[] distance;
        delete[] parent;
        delete[] visited;
    }

    void dfs_helper(int node,bool* visited)
    {

         cout<<node<<" ";
         visited[node]=true;
         for(auto it:nbrs[node]){
            if(!visited[it])
            {
                visited[it]=true;
                dfs_helper(it,visited);
            }
         }
    }
    void dfs_recursive(int source)
    {

        cout<<"Performing DFS"<<endl;
        bool *visited=new bool[nodes]{false};
        dfs_helper(source,visited);
        cout<<endl;
        delete[] visited;
    }

    void dfs_stack(int source)
    {
        bool *vis=new bool[nodes]{false};
        stack<int>s;
        s.push(source);
        vis[source]=true;
        while(!s.empty())
        {
            int node=s.top();
            cout<<node<<" ";
            s.pop();
            for(auto it: nbrs[node]){

                    if(!vis[it])
                    {
                        s.push(it);
                        vis[it]=true;
                    }
            }
        }

        delete[] vis;
    }

    void dfs_ssp(int node,int dest=-1)
    {
        int *parent=new int[nodes];
        for(int i=0;i<nodes;i++)
        {
            parent[i]=-1;
        }
        int *distance=new int[nodes]{0};
        bool *visited=new bool[nodes]{0};

        stack<int>s;
        s.push(node);
        visited[node]=true;
        while(!s.empty())
        {
            int cur=s.top();
            s.pop();
            for(auto it:nbrs[cur])
            {
                if(!visited[it]){
                    s.push(it);
                    parent[it]=cur;
                    distance[it]=1+distance[cur];
                    visited[it]=true;
                }
            }

        }

        if(dest!=-1)
        {
            cout<<endl;
            for(int i=0;i<nodes;i++)
            {
                cout<<"distance from "<<node<<" to "<<i<<" : "<<distance[i]<<endl;
            }
        }

        delete[] parent;
        delete[] distance;
        delete[] visited;
    }
    ~Graph(){
        delete[] nbrs;
    }
};

int main()
{
    Graph g(7);
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(3,5);
    g.add_edge(5,6);
    g.add_edge(4,5);
    g.add_edge(0,4);
    g.add_edge(3,4);
    g.print();
    g.bfs(1);
    g.sssp(1,6);//uses bfs
    g.dfs_recursive(1);
    g.dfs_stack(1);
    g.dfs_ssp(1,6);


//
//    Graph x(8);
//    x.add_edge(1,2);
//    x.add_edge(1,3);
//    x.add_edge(2,4);
//    x.add_edge(2,5);
//    x.add_edge(3,6);
//    x.add_edge(3,7);
//    x.print();
//    x.dfs_ssp(1,6);



    return 0;
}

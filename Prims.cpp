// for finding minimum spanning tree
// -weighted undirected graph
// -greedy algo

/* 
select a node and mark its distance as 0, then update the distance of 
unvisited neighbouring nodes and then find the next unvisited node with
minimum distance(top element in the minimum priority queue).

Time Complexity: O((E+V) logV) -> O(E logV)

->finding min element
    O(E log(E))=O(E log(V^2))= O(2E logV)
*/

#include<bits/stdc++.h>

#define ll long long

#define pii pair<int,int>
#define vi vector<int> 
#define vvi vector<vi> 
#define vpii vector<pii> 

#define pb push_back
#define endl "\n"
#define ub upper_bound
#define lb lower_bound
#define test() int t;cin>>t;while(t--)

const int mod = 1e9+7,MAX = 1e6+5;
const ll inf = 1e18+5;
const double pi = 3.14159265358979323846;

using namespace std;

vpii *l;

void prims(int n){
    int i;
    bool visited[n];
    int parent[n];
    int weight[n];
    
    for(i=0;i<n;i++){
        visited[i]=false;
        parent[i]=-1;
        weight[i]=INT_MAX;
    }
    
    priority_queue< pii, vpii , greater<pii> > pq;
    pq.push({0,0});
    while(!pq.empty()){
        int minvertex = pq.top().second;
        pq.pop();
        if(visited[minvertex]==true){
            continue;
        }
        visited[minvertex]=true;
       
        for(auto itr:l[minvertex]){
            if(visited[itr.first]==0){
                if(itr.second < weight[itr.first])
                {
                    weight[itr.first]=itr.second;
                    parent[itr.first]=minvertex;
                    pq.push({itr.second,itr.first});
                }
            }
        }
    }
    
    for(i=1;i<n;i++)
    {
        cout<<i<<"  "<<parent[i]<<"  "<<weight[i];
        
        cout<<endl;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    int i,u,v,w;
    l=new vpii [n];
    
    for(i=0;i<e;i++){
        cin>>u>>v>>w;
        l[u].pb({v,w});
        l[v].pb({u,w});
    }
    
    prims(n);
    
    return 0;   
}
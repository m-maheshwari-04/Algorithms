// FOR FINDING SHORTEST DISTANCE FROM SINGLE SOURCE NODE
// -weighted graph
// -greedy algo

/* 
mark the distance of source node as 0, then update the distance of 
unvisited neighbouring nodes(distace of current node+ weight of edge)
and then find the next unvisited node with minimum distance
(top element in the minimum priority queue).

Time Complexity: O(ELogV)) as there will be at most O(E) 
vertices in priority queue and O(Log E) is same as O(Log V)
*/


#include<bits/stdc++.h>

#define ll long long

#define pii pair<int,int>
#define vi vector<int> 
#define vvi vector<vi> 
#define vpii vector<pii> 

#define pb push_back
#define endl "\n"
#define test() int t;cin>>t;while(t--)
#define lopr(i,n) for(ll i=n-1;i>=0;i--)

const int mod = 1e9+7,MAX = 1e6+5;
const ll inf = 1e18+5;
const double pi = 3.14159265358979323846;

using namespace std;

vpii *l;

void dijkstra(int start,int n){
    int i;
    bool visited[n];
    int weight[n];
    
    for(i=0;i<n;i++){
        visited[i]=false;
        weight[i]=INT_MAX;
    }
    weight[start]=0;
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
                if(itr.second+weight[minvertex] < weight[itr.first])
                {
                    weight[itr.first]=itr.second+weight[minvertex];
                    pq.push({weight[itr.first],itr.first});
                }
            }
        }
    }
    
    for(i=1;i<n;i++)
    {
        cout<<i<<"  "<<weight[i]<<endl;
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
    
    dijkstra(0,n);
    
    return 0;   
}
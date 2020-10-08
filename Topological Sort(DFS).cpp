/*
pushfront each node at the time of returning from dfs call
leaf node comes after parent node in topological sort
*/

#include<bits/stdc++.h>
#define ll   long long int
#define endl "\n"
#define MOD  1000000007
using namespace std;

bool compare(ll &a,ll &b){
    return a<b;
}

vector<ll> v;
class Graph{
    ll n;
    vector<ll> *l;
   
  public:
    Graph(ll x){
        n=x;
        l=new vector<ll> [x+1];
    }
    
    void addEdge(ll u,ll v){
        l[u].push_back(v);
    }
    
    void help(ll node,bool *visited)
    {
        visited[node]=true;
        //FOR LEXICOGRAPHY ORDER
        sort(l[node].begin(),l[node].end(),compare);
        for(auto itr:l[node])
        {
            if(!visited[itr])
            {
                help(itr,visited);
            }
        }
        v.push_back(node);
    }
    void topological(){
        bool *visited=new bool[n+1];
        for(ll i=0;i<n+1;i++)
        {
            visited[i]=0;
        }
        for(ll i=n;i>0;i--)
        {
            if(visited[i]==0)
                help(i,visited);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,e,x,y,i,j;
    cin>>n>>e;
        
    Graph g(n);
    for(i=0;i<e;i++){
        cin>>x>>y;
        g.addEdge(x,y);
    }
    g.topological();
    
    
    for(ll i=v.size()-1;i>=0;i--){
        cout<<v[i]<<" ";
    }
    
    return 0;
}
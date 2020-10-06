#include<bits/stdc++.h>
#define ll   long long int
#define endl "\n"
#define MOD  1000000007
using namespace std;

class Graph{
    ll n;
    map<ll,ll> indegree;
    vector<ll> *l;
   
  public:
    Graph(ll x){
        n=x;
        l=new vector<ll> [x+1];
    }
    
    void addEdge(ll u,ll v)
    {
        l[u].push_back(v);
        indegree[v]++;
    }
    
    void topological(){
        bool *visited=new bool[n+1];
        for(ll i=0;i<n+1;i++)
        {
            visited[i]=false;
        }
        
        vector<ll> v;
        queue<ll> q;
        
        for(ll i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                v.push_back(i);
            }
        }
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            visited[temp]=true;
            
            for(auto itr:l[temp])
            {
                if(!visited[itr])
                {
                    indegree[itr]--;
                    if(indegree[itr]==0){
                        q.push(itr);
                        v.push_back(itr);
                    }
                }
            }
        }
        for(ll i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        return;
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
    return 0;
}

// input:
// 7 10
// 0 2
// 0 1
// 1 2
// 2 3
// 1 4
// 4 5
// 4 6
// 1 6
// 6 5
// 5 3

// output:
// 0 1 2 4 6 5 3 
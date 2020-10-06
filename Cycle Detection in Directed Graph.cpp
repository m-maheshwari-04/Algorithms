#include<bits/stdc++.h>
#define ll   long long int
#define endl "\n"
#define MOD  1000000007
using namespace std;

bool compare(ll &a,ll &b){
    return a>b;
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
    
    bool help_cycle(ll node,bool *visited,bool *stack){
        visited[node]=true;
        stack[node]=true;
        
        for(auto itr:l[node]){
            if(stack[itr]==true){
                return true;
            }
            else if(!visited[itr]){
                bool t=help_cycle(itr,visited,stack);
                if(t)
                    return true;
            }
        }
        stack[node]=false;
        return false;
    }
    bool cycle(){
        bool *visited=new bool[n+1];
        bool *stack=new bool[n+1];
        for(ll i=0;i<n+1;i++){
            visited[i]=0;
            stack[i]=0;
        }
        for(ll i=n;i>0;i--){
            if(visited[i]==0){
                bool t=help_cycle(i,visited,stack);
                if(t)
                    return true;
            }
        }
        return false;
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
    
    if(g.cycle()){
        cout<<"cycle is present";
    }
    else
    {
        cout<<"No cycle";
    }
    
    return 0;
}
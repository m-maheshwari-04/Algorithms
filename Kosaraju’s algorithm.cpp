// TO FIND STRONGLY CONNECTED COMPONENTS
/*
    step 1: store the nodes according to dfs finish time
    step 2:reverse the graph and then traverse the reversed graph according to the order in stack

    Time Complexity: O(V+E)
        (DFS takes O(V+E) for a graph represented using adjacency list.)
*/


#include<bits/stdc++.h>
#define ll      long long int
#define vl vector<ll> 
#define pb push_back
#define endl "\n"
#define MOD     1000000007
using namespace std;


void dfs(vl graph[],ll node,bool *visited,stack<ll> &st){
    visited[node]=true;
    
    for(auto itr:graph[node]){
        if(!visited[itr]){
            dfs(graph,itr,visited,st);
        }
    }
    st.push(node);
}

void dfs1(vl rev_graph[],ll node,bool *visited){
    visited[node]=true;
    
    for(auto itr:rev_graph[node]){
        if(!visited[itr]){
            dfs1(rev_graph,itr,visited);
        }
    }
    cout<<node<<" ";
}

void solve(vl graph[],vl rev_graph[],int n){
    bool *visited=new bool[n];
    for(ll i=0;i<n;i++)
        visited[i]=0;
    
    stack<ll> st;
    
    for(ll i=0;i<n;i++){
        if(visited[i]==0){
            dfs(graph,i,visited,st);
        }
    }
    
    for(ll i=0;i<n;i++)
        visited[i]=0;
    
    while(!st.empty()){
        ll temp=st.top();
        st.pop();
        
        if(visited[temp]==0){
            cout<<"-->  ";
            dfs1(rev_graph,temp,visited);
            cout<<endl;
        }
    }
}
        
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,e,x,y,i,j;
    cin>>n>>e;
        
    vl graph[n];
    vl rev_graph[n];
        
    for(i=0;i<e;i++){
        cin>>x>>y;
        graph[x].pb(y);
        rev_graph[y].pb(x);
    }
    
    solve(graph,rev_graph,n);
    return 0;
}

/*
//input
7 8
2 1
1 0
0 2
0 3
3 5
5 6
6 3
3 4

//output
-->  2 1 0 
-->  5 6 3 
-->  4 
*/
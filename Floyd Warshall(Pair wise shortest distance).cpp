// TO FIND ALL PAIRS SHORTEST PATH

/*
	- works with negative edges
	- can detect negative cycle with one extra step

    step 1: Mark all the distances in the matrix as MAX.
    step 2: choose one vertex in each iteration and check if we go through 
            that vertex then the distance is reduces or not.
        x->y  ::  x->k then k->y
	step 3: Repeat above step for all vertices.
	step 4: Mark the distance of diagonal elements as 0.

    Time Complexity: O(V^3)
        iterate through the matrix V times.
*/



#include<bits/stdc++.h>

#define ll long long
#define vi vector<int> 
#define vvi vector<vi> 
#define vl vector<ll> 
#define vvl vector<vl> 

const int MAX = 1e6+5;

using namespace std;

vvl floyd_warshall(vvl graph, int n){
    
    vvl dist(graph);
    int i,j,k;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(dist[i][k]!=MAX && dist[k][j]!=MAX){
                   if(dist[i][j] > dist[i][k]+dist[k][j]) {
                       dist[i][j] = dist[i][k]+dist[k][j];
                   }
                }
            }
        }   
    }
    for(i=0;i<n;i++){
        dist[i][i]=0;
    }
    return dist;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,e,i,j;
    cin>>n>>e;
    vvl graph(n,vl(n,MAX));
    
    while(e--)
    {
        ll x,y,c;
        cin>>x>>y>>c;
        graph[x][y]=min(graph[x][y],c);
    }
    auto final=floyd_warshall(graph,n);
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<final[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;   
}

/*
    #input
    4 5
    0 2 -2
    1 0 4
    1 2 3
    2 3 2
    3 1 -1
    
    #output
    0 -1 -2 0 
    4 0 2 4 
    5 1 0 2 
    3 -1 1 0 
*/

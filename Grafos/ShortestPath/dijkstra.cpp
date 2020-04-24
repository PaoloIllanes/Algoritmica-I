#include <bits/stdc++.h> 
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

#define SIZE 100000 + 1
#define INF 100000010

using namespace std; 

vector<pair< int , int > > v[SIZE];   // each vertex has all the connected vertices with the edges weights
int dist [SIZE];
bool vis [SIZE];

void dijkstra(){
    memset(dist, INF , sizeof vis);            // set the vertices distances as infinity
    memset(vis, false , sizeof vis);            // set all vertex as unvisited
    dist[1] = 0;
    multiset < pair < int , int > > s;          // multiset do the job as a min-priority queue

    s.insert(make_pair(0 , 1));                          // insert the source node with distance = 0

    while(!s.empty()){

        pair <int , int> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());

        int x = p.second; int wei = p.first;
        if( vis[x] ) {
            continue;                  // check if the popped vertex is visited before
        }
         vis[x] = true;

        for(int i = 0; i < v[x].size(); i++){
            int e = v[x][i].first; 
            int w = v[x][i].second;
            if(dist[x] + w < dist[e]  ){            // check if the next vertex distance could be minimized
                dist[e] = dist[x] + w;
                s.insert(make_pair(dist[e],  e) );           // insert the next vertex with the updated distance
            }
        }
    }
}

int main() {
    cout<<"it's ok?"<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;


#define int long long 
const int N = 1e5 + 5;
const int INF = 1e18+10;

// solution of CF 20C dijkstra?
vector< pair<int,int> > graph[N];
vector<int> dist(N,INF);
bool vis[N];

void dijkstra()
{
	  priority_queue<pair<int,int>, vector< pair<int,int> >, greater< pair<int,int>> > q;

		q.push({0,1}); 
		dist[1] = 0;

		while(!q.empty()){
				int curr_dist=q.top().first , curr_edge = q.top().second; 
				q.pop();
				
				if(vis[curr_edge]) continue;
				vis[curr_edge] = 1;

				for(auto child:graph[curr_edge]){
							int child_edge = child.second , child_dist = child.first;
							
							if( curr_dist + child_dist < dist[child_edge]){
								dist[child_edge] = curr_dist + child_dist;
								q.push({dist[child_edge],child_edge});	
							}
				}		
	  }
}

int32_t main()
{
	     #ifndef ONLINE_JUDGE
          freopen("in.txt","r", stdin);
      //   freopen("out.txt", "w", stdout);
          freopen("Error.txt", "w", stderr);
     #endif // ONLINE_JUDGE

	int node,edges; cin >> node  >> edges;
	
	for(int i=0;i<edges;i++)
	{
		int x,y,z; cin >> x >> y >> z;
		if( x == y) continue;
		graph[x].push_back({z,y});
	}

	dijkstra();

	for (int i = 1; i <= node; ++i)
	{
		cout << dist[i] << ' ';
	}
	// if(path[node] == 0) { cout << -1 << '\n'; return 0;}
	// print(node); // can print it by storing values in vector and then reversing it
		
	return 0;
		
}
#include<bits/stdc++.h>
using namespace std;
void DFS(int node,vector<int>adj[],vector<int>&vis)
{
	vis[node]=1;
	cout<<node<<" ";
	for(auto it:adj[node])
	{
		if(!vis[it])
		{
			DFS(it,adj,vis);
		}
	}
}
void BFS(int node,vector<int>adj[],vector<int>&vis)
{
	queue<int>Q;
	Q.push(node);
	vis[node]=1;
	while(!Q.empty())
	{
		node=Q.front();
		cout<<node<<" ";
		Q.pop();
		for(auto it:adj[node])
		{
			if(!vis[it]){
				Q.push(it);
				vis[it]=1;
			}
		}
	}
}
int main()
{
	int N,E;
	cin>>N>>E;
	//Adjacency matrix
	/*int matrix[N+1][N+1];
	int u,v;
	for(int i=0;i<N+1;i++)
	{
		for(int j=0;j<N+1;j++)
		{
			matrix[i][j]=0;
		}
	}
	for(int i=0;i<E;i++)
	{
		cin>>u>>v;
		matrix[u][v]=1;
		matrix[v][u]=1;
	}
	for(int i=0;i<N+1;i++)
	{
		for(int j=0;j<N+1;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}*/
	//using adjacency list
	vector<int>adj[N+1];
	int u,v;
	for(int i=0;i<E;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int>vis(N+1,0);
	for(int i=1;i<N+1;i++)
	{
		if(!vis[i])
		{
			DFS(i,adj,vis);
		}
	}
	cout<<endl;
	vector<int>vis2(N+1,0);
	for(int i=1;i<=N;i++)
	{
		if(!vis2[i])
		{
			BFS(i,adj,vis2);
		}
	}
	
}
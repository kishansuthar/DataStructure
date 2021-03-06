#include<bits/stdc++.h>
using namespace std;

#define SIZE 10000
vector<int> adjList[SIZE+1];

int dis[SIZE+1];
bool isVisited[SIZE+1];
int n,e,t,a,b;

void singleSourceShortestPath(int source)
{
	queue<int>q;
	isVisited[source] = 1;
	dis[source] = 0;
	q.push(source);
	while(!q.empty())
	{
		int currNode = q.front();
		q.pop();

		for(int child: adjList[currNode])
			if(!isVisited[child])
			{
				q.push(child);
				isVisited[child] = 1;
				dis[child] = dis[currNode] + 1;
			}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		for(int i=0;i<SIZE+1; i++)
			adjList[i].clear(), isVisited[i]=0, dis[i]=0;
		cin>>n>>e;
		while(e--)
		{
			cin>>a>>b;
			adjList[a].push_back(b);
			adjList[b].push_back(a);
		}
		singleSourceShortestPath(1);
		cout<<dis[n]<<endl;
	}
}
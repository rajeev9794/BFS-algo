#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#include<vector>
vector<int>v[100001];
bool vis[100001];
int dfs(int k)
{	
	//cout<<"bfs traversal of a graph";
	queue<int>s;//creating a queue for backtracking
	s.push(k);//inserting source node
	vis[k]=true;//mark as souce is visited
	while(!s.empty())
	{
		int h=s.front();
		cout<<h<<" ";//output the bfs traversal of graph
		s.pop();
		for(int i=0;i<v[h].size();i++)
		{
			if(vis[v[h][i]]==false)
			{
				s.push(v[h][i]);
				vis[v[h][i]]=true;
			//	cout<<v[h][i]<<" ";
			}
		}
	}
}

int main()
{
    ll n,m,k;
    for(int i=0;i<100001;i++)
    vis[i]=false;
    cin>>n>>m>>k;
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int c=0;
    for(int i=1;i<=n;i++)
    {	
    	if(vis[i]==false)
    	{	c++;
    		dfs(i);
		}
	}
    cout<<"no of connected components:"<<c<<endl;
}

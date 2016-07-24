const int maxn=2e5+9;
const int inf=2e9+9;

typedef pair<int,int> P;

struct edge
{
	int to,cap,cost,rev;
};

int V;
vector<edge> G[maxn];
int h[maxn];
int dist[maxn];
int prevv[maxn],preve[maxn];

void add_edge(int from,int to,int cap,int cost);
int min_cost_flow(int s,int t,int f);

int main()
{ 
// 注意 G初始化，V 总共点个数初始
	return 0;
}

int min_cost_flow(int s,int t,int f)
{
	int res=0;
	memset(h,0,sizeof(h));
	while(f>0)
	{
		priority_queue<P,vector<P>,greater<P> >que;
		for(int i=0;i<=V;i++)
			dist[i]=inf;
		dist[s]=0;
		que.push(P(0,s));
		while(!que.empty())
		{
			P p=que.top();que.pop();
			int v=p.second;
			if(dist[v]<p.first) continue;
			for(int i=0;i<G[v].size();i++)
			{
				edge &e=G[v][i];
				if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to])
				{
					dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
					prevv[e.to]=v;
					preve[e.to]=i;
					que.push(P(dist[e.to],e.to));
				}
			}
		}
		if(dist[t]==inf) return -1;
		for(int v=0;v<V;v++) h[v]+=dist[v];

		int d=f;
		for(int v=t;v!=s;v=prevv[v])
			d=min(d,G[prevv[v]][preve[v]].cap);
		f-=d;
		res+=d*h[t];
		for(int v=t;v!=s;v=prevv[v])
		{
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}


void add_edge(int from,int to,int cap,int cost)
{
	G[from].push_back((edge){to,cap,cost,G[to].size()});
	G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}

#include<iostream>
using namespace std;
class dijkstra
{
			int n, a[10][10],d[10],p[10],visit[10];
		public: void read();
				void dis(int );
				void path(int);
};

void dijkstra :: read()
{
	int i,j,k;
	cout<<"enter number of vertices:";
	cin>>n;
	cout<<"enter cost adjacency matrix:"<<endl;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			cin>>k;
			if(k==0)
				a[i][j]=999;
			else
				a[i][j]=k;
		}

}

void dijkstra ::dis(int src)
{
	int i,k,pt;
	for(i=0;i<n;i++)
	{
		if(i==src)
			continue;
		cout<<endl<<"shortest path from:"<<src<<" to:"<<i<<" is: ";
		k=i;
		cout<<k<<"<---";
		while(p[k]!=src)
		{
			cout<<p[k]<<"<---";
			k=p[k];
		}
		cout<<src;
		cout<<" and the cost="<<d[i]<<endl;
	}
}

void dijkstra :: path(int src)
{
	int i,j,min,u,v;
	for(i=0;i<n;i++)
	{
		d[i]=a[src][i];
		visit[i]=0;
		p[i]=src;
	}
	visit[src]=1;
	for(i=0;i<n;i++)
	{
		min=999;
		u=0;
		for(j=0;j<n;j++)
			if(!visit[j])
				if(d[j]<min)
				{
					min=d[j];
					u=j;
				}
		visit[u]=1;
		for(v=0;v<n;v++)
			if(!visit[v]&&(d[u]+a[u][v]<d[v]))
			{
				d[v]=d[u]+a[u][v];
				p[v]=u;
			}
	}
}

int main()
{
	int s;
	dijkstra d;
	d.read();
	cout<<"enter source:";
	cin>>s;
	d.path(s);
	d.dis(s);
	return 0;
}

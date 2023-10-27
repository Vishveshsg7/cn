#include &lt;bits/stdc++.h&gt;
using namespace std;
int Bellman_Ford(int G[100][100] , int V, int E, int
edge[100][2]) {
int i,u,v,k,distance[100],S,flag=1;
for(i=0;i&lt;V;i++)
distance[i] = 1000 ;
cout&lt;&lt;&quot;\nEnter source : &quot;;
cin&gt;&gt;S;
distance[S-1]=0;
for(i=0;i&lt;V-1;i++)
{
for(k=0;k&lt;E;k++)
{
u = edge[k][0];
v = edge[k][1];
if(distance[u]+G[u][v] &lt; distance[v])
distance[v] = distance[u] + G[u][v];
}
}
for(k=0;k&lt;E;k++){
u = edge[k][0];
v = edge[k][1] ;
if(distance[u]+G[u][v] &lt; distance[v])
flag = 0 ;
}
if(flag)
for(i=0;i&lt;V;i++)
cout&lt;&lt;&quot;\nDistance from source &quot;&lt;&lt;S&lt;&lt;&quot; to vertex&quot;&lt;&lt;i+1&lt;&lt;&quot; is &quot;&lt;&lt;distance[i];
return flag;
}

int main()
{
int V,edge[100][2],G[100][100],i,j,k=0;
cout&lt;&lt;&quot;Enter no. of vertices: &quot;;
cin&gt;&gt;V;
cout&lt;&lt;&quot;Enter graph in matrix form:\n&quot;;
for(i=0;i&lt;V;i++)
for(j=0;j&lt;V;j++)
{
cin&gt;&gt;G[i][j];
if(G[i][j]!=0)
edge[k][0]=i,edge[k++][1]=j;
}
if(Bellman_Ford(G,V,k,edge))
cout&lt;&lt;&quot;\nNo negative weight cycle exists\n&quot;;
return 0;
}
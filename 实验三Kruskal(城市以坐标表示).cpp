
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
#include<math.h>
using namespace std;
 
struct Land{   //  记录岛位置坐标 
    int  num;// 标一个号 
    double x,  y;
}land[220];
 
struct Node{  // 用于记录符合条件的边以及相应的权值 
    int u,v;
    double weight; 
}node[20000];
 
int mark[220]; 
 
double distance( double x1,double y1,double x2,double y2) //  计算两点距离 
{
    double dis;
    double temp1,temp2;
    temp1 = (double)(x1-x2)*(x1-x2) ;
    temp2= (double)(y1-y2)*(y1-y2); 
    dis = sqrt(temp1+temp2);
    return dis;
}
 
bool cmp( Node x, Node y)
{
    return x.weight < y.weight;
}
 
int find(int x)
{
    return mark[x] == x ? x : mark[x] = find(mark[x]); 
}
 
void join(int x,int y)
{
    int r1 = find( x );
    int r2 = find( y );
    if( r1 < r2 )
         mark[r2] = r1;
    else if( r2 < r1)
        mark[r1] = r2;
}
 
int main()
{
    int n;
    printf("设定城市数量规模: "); 
    scanf("%d",&n);
    printf("请输入每个城市从坐标(可表示为小数)\n");
    for ( int i = 1; i <= n; i++)
    {
    	printf("第%d个城市：  ", i);
        scanf("%lf %lf", &land[i].x, &land[i].y);
        land[i].num = i;
    }
    int k=0;
    for ( int i = 1; i <= n; i++)
    {
        for ( int j = i+1; j <= n; j++)
        {
            double temp =  distance(land[i].x,land[i].y,land[j].x,land[j].y); // 计算两个城市之间的距离 
            if( 1/*temp >= 10.0 && temp <= 1000.0*/ ) //  判断是否符合条件 
            {
                node[k].u = land[i].num;
                node[k].v = land[j].num;
                node[k].weight = temp;//两个之间的距离 
                k++;
            }
        }
    }
 
    for( int i = 1; i <= n; i++)  //  初始化数组 
        mark[i] = i; 
    sort( node, node + k, cmp);
    double ans = 0;
    for ( int i = 0; i < k; i++)
    {
        if( find(node[i].u) != find( node[i].v))
            {
                join( node[i].u, node[i].v);
                ans += node[i].weight;
            } 
    }
    int count = 0;
    for ( int i = 1; i <= n; i++)
        if( mark[i] == i)  //  若是能建立符合条件的桥，那么就只存在一个根节点 
        	count ++;
    if( count == 1)
        printf("可以建立\t最小距离为%.1lf\n", ans);
    else 
        printf("oh!我想我们无法建设成功\n");
    return 0;
}

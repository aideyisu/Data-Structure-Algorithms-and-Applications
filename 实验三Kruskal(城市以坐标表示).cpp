
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
#include<math.h>
using namespace std;
 
struct Land{   //  ��¼��λ������ 
    int  num;// ��һ���� 
    double x,  y;
}land[220];
 
struct Node{  // ���ڼ�¼���������ı��Լ���Ӧ��Ȩֵ 
    int u,v;
    double weight; 
}node[20000];
 
int mark[220]; 
 
double distance( double x1,double y1,double x2,double y2) //  ����������� 
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
    printf("�趨����������ģ: "); 
    scanf("%d",&n);
    printf("������ÿ�����д�����(�ɱ�ʾΪС��)\n");
    for ( int i = 1; i <= n; i++)
    {
    	printf("��%d�����У�  ", i);
        scanf("%lf %lf", &land[i].x, &land[i].y);
        land[i].num = i;
    }
    int k=0;
    for ( int i = 1; i <= n; i++)
    {
        for ( int j = i+1; j <= n; j++)
        {
            double temp =  distance(land[i].x,land[i].y,land[j].x,land[j].y); // ������������֮��ľ��� 
            if( 1/*temp >= 10.0 && temp <= 1000.0*/ ) //  �ж��Ƿ�������� 
            {
                node[k].u = land[i].num;
                node[k].v = land[j].num;
                node[k].weight = temp;//����֮��ľ��� 
                k++;
            }
        }
    }
 
    for( int i = 1; i <= n; i++)  //  ��ʼ������ 
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
        if( mark[i] == i)  //  �����ܽ��������������ţ���ô��ֻ����һ�����ڵ� 
        	count ++;
    if( count == 1)
        printf("���Խ���\t��С����Ϊ%.1lf\n", ans);
    else 
        printf("oh!���������޷�����ɹ�\n");
    return 0;
}

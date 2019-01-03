#include <stdio.h>
#define N 20
#define TRUE 1
#define FALSE 0
int visited[N];        /*点数最多不超过20*/
typedef struct{        /*队列的定义*/
	int data[N];
	int front, rear;
}queue;    

typedef struct{        /*图的邻接矩阵*/
	int vexnum, arcnum;/*图的定点数量和弧数量*/ 
	char vexs[N];	   /*点集的数据*/ 
	int arcs[N][N];    /*边的权值*/ 
}graph;

/*----------------------------------------------------------*/
/**/void createGraph(graph *g);   /*建立一个无向图的邻接矩阵*/
/**/void dfs(int i,graph *g);  /*从第i个顶点出发深度优先搜索*/
/**/void tdfs(graph *g); 	 		    /*深度优先搜索整个图*/
/**/void bfs(int k,graph *g);  	   /*从第k个顶点广度优先搜索*/
/**/void tbfs(graph *g); 			    /*广度优先搜索整个图*/
/**/void init_visit(); 				    /*初始化访问标识数组*/
/*----------------------------------------------------------*/

void createGraph(graph * g){      /*建立一个无向图的邻接矩阵*/
	int i, j;
	char v;
	g->vexnum = 0;
	g->arcnum = 0;
	i = 0;
	printf("请输入顶点序列    (以 # 结尾)   否则别怪我出bug！\n");
	while((v = getchar()) != '#'){/*几个点就录入几个点的信息*/
		g->vexs[i] = v;                       /*读入顶点信息*/
		i++;
	}
	g->vexnum = i;
	for(i = 0; i < g->vexnum ; i++)
		for(j = 0; j < g->vexnum; j++)
			g->arcs[i][j] = 0;       /*初始状态为0(断开状态)*/
	printf("完成点的录入，请输入每条边的权值(-1为断开)\n");
	printf("格式为： 点A 点B\n");
	scanf("%d %d", &i, &j);           		     /*读入边i,j*/   
	while(i != -1){                     /*读入i,j为－1时结束*/
		g->arcs[i][j] = 1;
		g->arcs[i][j] = 1; 
		scanf("%d %d", &i, &j);
	}
}

void dfs(int i, graph * g){      /*第i个顶点出发深度优先搜索*/
	int j;
	printf("%c", g->vexs[i]);          /*输出顶点信息*/
	visited[i] = TRUE;
	for(j = 0; j < g->vexnum; j++)
		if((g->arcs[i][j] == 1) && (!visited[j])) 
			dfs(j, g);
}

void tdfs(graph * g){            /*深度优先搜索整个图*/
	int i;
	printf("\n从顶点%C开始深度优先搜索序列：",g->vexs[0]);
	for(i = 0; i < g->vexnum; i++)
		if(visited[i] != TRUE)
			dfs(i, g); 
}

void bfs(int k, graph * g){      /*从第k个顶点广度优先搜索*/
	int i, j;
	queue qlist, * q;
	q = &qlist;
	q->rear = 0;
	q->front = 0;
	printf("%c", g->vexs[k]);
	visited[k] = TRUE;
	q->data[q->rear] = k;
	q->rear = (q->rear+1)%N;
	while(q->rear != q->front){
		i = q->data[q->front];
		q->front = (q->front+1)%N;
		for(j = 0; j < g->vexnum; j++)
			if((g->arcs[i][j] == 1) && (!visited[j])){
				printf("%c", g->vexs[j]);
				visited[j] = TRUE;
				q->data[q->rear] = j;
				q->rear = (q->rear+1)%N;
			}	
	}
}

void tbfs(graph * g){                  /*广度优先搜索整个图*/
	int i;
	printf("\n从顶点%C开始广度优先搜索序列：",g->vexs[0]);
	for(i = 0; i<g->vexnum; i++)
		if(visited[i] != TRUE)
			bfs(i, g);
	printf("\n"); 
}

void init_visit(){                     /*初始化访问标识数组*/
	int i;
	for(i = 0; i < N; i++)
		visited[i] = FALSE;
}

int main(){
	graph ga;
	int i, j;
	createGraph(&ga);
	printf("无向图的邻接矩阵:\n");
	for(i = 0; i < ga.vexnum; i++){ 
		for(j = 0; j < ga.vexnum; j++)
			printf("%3d",ga.arcs[i][j]);
		printf("\n");
	} 
	init_visit();
	tdfs(&ga);
	init_visit();
	tbfs(&ga);
	return 0;
}

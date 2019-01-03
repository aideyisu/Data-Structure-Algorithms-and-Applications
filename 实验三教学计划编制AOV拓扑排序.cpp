#include<stdio.h>
#include<malloc.h>
#define max 100

typedef struct arcnode{
    int adjvex;
    struct arcnode * next;
}arcnode;         // 边的关系 

typedef struct {
    int vertex;    //入度 
    arcnode*firstarc;
}vexnode;        //点的关系 
vexnode adjlist[max];                     //点集上限为100 

int creatadjlist(){
    arcnode * ptr;
    int arcnum,vexnum,k,v1,v2; 
	printf("input vexnum and arcnum:");   /*vexnum代表科目数量*/ 
    scanf("%d,%d",&vexnum,&arcnum);		  /*arcnum代表科目之间的关系*/
    for(k=1;k<=vexnum;k++)
    {
        adjlist[k].firstarc=NULL;        /*每个点的出度起始为空*/ 
        adjlist[k].vertex=0;
    }
    for(k = 1;k <= arcnum; k++)             /*输入每个点*/
    {
    	printf("Gropg %d Subject Relations\t", k);
        printf("Subject1,Subject2=");
        scanf("%d,%d", &v1, &v2);
        ptr=(arcnode*)malloc(sizeof(arcnode));
        ptr->adjvex=v2;                      /*下个边的代号*/ 
        ptr->next=adjlist[v1].firstarc;			/*这里采用头插入法增加节点出度*/	 
        adjlist[v1].firstarc=ptr;
        adjlist[v2].vertex++;
    }
    return vexnum;
}

void toposort(int n){                			/*拓扑排序*/ 
    int queue[max];                               /*数组当队列*/
    int front=0, rear=0;								/*队首和队尾*/ 
    int v, w, m;
    arcnode * p;
    m=0;
    for(v = 1;v <= n; v++)                        /*每个点遍历一遍*/
    	//printf("\n%d's vertex is  %d\n", v, adjlist[v].vertex); 
        if(adjlist[v].vertex == 0){               /*若该点的出度为0*/ 
            rear=(rear+1)%max;               /*max is 100 环*/ 
            queue[rear]=v;                   /*送入队列*/ 
        }
    printf("the toposort:\n");  // 遍历输出拓扑排序 
    while(front!=rear){
        front=(front+1)%max;
        v=queue[front];
        printf("%d ",v);
        m++;
        p=adjlist[v].firstarc;
        while(p!=NULL){
            w=p->adjvex;
            adjlist[w].vertex--;           /*出度逐渐减小*/ 
            if(adjlist[w].vertex==0){
                rear=(rear+1)%max;
                queue[rear]=w;
            }
            p=p->next;
        }
    }
    if(m<n)
        printf("the toposort is fail.");
}
int main(){
    int n;
    n=creatadjlist();
    toposort(n);
    return 0;
}

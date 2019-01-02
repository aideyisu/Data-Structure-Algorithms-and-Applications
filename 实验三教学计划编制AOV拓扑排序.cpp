#include<stdio.h>
#include<malloc.h>
#define max 100

typedef struct arcnode{
    int adjvex;
    struct arcnode * next;
}arcnode;         // �ߵĹ�ϵ 

typedef struct {
    int vertex;    //��� 
    arcnode*firstarc;
}vexnode;        //��Ĺ�ϵ 
vexnode adjlist[max];                     //�㼯����Ϊ100 

int creatadjlist(){
    arcnode * ptr;
    int arcnum,vexnum,k,v1,v2; 
	printf("input vexnum and arcnum:");   /*vexnum�����Ŀ����*/ 
    scanf("%d,%d",&vexnum,&arcnum);		  /*arcnum�����Ŀ֮��Ĺ�ϵ*/
    for(k=1;k<=vexnum;k++)
    {
        adjlist[k].firstarc=NULL;        /*ÿ����ĳ�����ʼΪ��*/ 
        adjlist[k].vertex=0;
    }
    for(k = 1;k <= arcnum; k++)             /*����ÿ����*/
    {
    	printf("Gropg %d Subject Relations\t", k);
        printf("Subject1,Subject2=");
        scanf("%d,%d", &v1, &v2);
        ptr=(arcnode*)malloc(sizeof(arcnode));
        ptr->adjvex=v2;                      /*�¸��ߵĴ���*/ 
        ptr->next=adjlist[v1].firstarc;			/*�������ͷ���뷨���ӽڵ����*/	 
        adjlist[v1].firstarc=ptr;
        adjlist[v2].vertex++;
    }
    return vexnum;
}

void toposort(int n){                			/*��������*/ 
    int queue[max];                               /*���鵱����*/
    int front=0, rear=0;								/*���׺Ͷ�β*/ 
    int v, w, m;
    arcnode * p;
    m=0;
    for(v = 1;v <= n; v++)                        /*ÿ�������һ��*/
    	printf("\n%d's vertex is  %d\n", v, adjlist[v].vertex); 
        if(adjlist[v].vertex == 0){               /*���õ�ĳ���Ϊ0*/ 
            rear=(rear+1)%max;               /*max is 100 ��*/ 
            queue[rear]=v;                   /*�������*/ 
        }
    printf("the toposort:\n");  // ��������������� 
    while(front!=rear){
        front=(front+1)%max;
        v=queue[front];
        printf("%d ",v);
        m++;
        p=adjlist[v].firstarc;
        while(p!=NULL){
            w=p->adjvex;
            adjlist[w].vertex--;           /*�����𽥼�С*/ 
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

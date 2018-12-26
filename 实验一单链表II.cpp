#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int ElemType;
// 声明链表类型 
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode;
typedef LNode* LinkList;


	// 十分社会的声明函数 
	// ----------------------------------------------------------- 
	LinkList CreateList(); 									//   \ 
	int ListLength(LinkList L);								//   \ 
	void ShowList(LinkList L);								//   \ 
	LinkList Get_LinkList(LinkList L,int i);		     	//   \ 
	LinkList Locate_LinkList(LinkList L,ElemType x);		//   \ 
	LinkList ListInsert(LinkList L,int i,ElemType x);		//   \ 
	LinkList ListDelete(LinkList L,int i); 					//   \ 
	// ----------------------------------------------------------- 
	



//创建单链表 
LinkList CreateList(){
	LinkList L,r;
	LinkList p;
	ElemType x, len;
	len = 0;
	r = (LinkList)malloc(sizeof(LNode));
	L = r;
	L->next=NULL;
	printf("当前链表中已有%3d个节点\t", len); 
	printf("输入 0 停止载入新节点-->") ;
	scanf("%d",&x);   // 我到底要输入个什么 
	while(x){
		p=(LinkList)malloc(sizeof(LNode));
		p->data=x;
		p->next=NULL;
		r->next=p;
		r=p;
		len++;
		printf("当前已有%3d个节点\t", len); 
		printf("输入 0 停止载入新节点-->") ;
		scanf("%d",&x);
	}
	return L;
}

//查看单链表长度 
int ListLength(LinkList L)
{
	int num=0;
	LinkList p;
	p=L;
	while(p->next){
		num++;
		p=p->next;
	}
	return num;
}

//打印单链表节点 
void ShowList(LinkList L){
	LinkList p;
	p=L->next;
	while(p->next!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d ",p->data);
	printf("\n链节全部展示完毕\n");
}

//查找单链表第i个节点 
LinkList Get_LinkList(LinkList L,int i){
	int ListLength(LinkList L); // x声明 
	LinkList p=L;
	int j=0;
	while(p->next!=NULL&&j<i){
		p=p->next;
		j++;
	}
	if(j==i) return p;
	else return 0; 
}

//在单链表中查找值为x的节点 ???如果没有x这个值时会出错 
// 下面的是小傻瓜写的 
LinkList Locate_LinkList(LinkList L,ElemType x){
	LinkList p, HAHAHA;
	HAHAHA = (LinkList)malloc(sizeof(LNode));
	HAHAHA->data = 0;
	printf("开始查找！");
	p=L->next;
	while(p->data!=x && p->next != NULL)
		p=p->next;
	if(p->data == x) 
		return p;
	else 
		printf("怎么没有一样的呢？");
	printf("................");
	return HAHAHA;
} 

//单链表第i个节点前插入值为x的元素 
LinkList ListInsert(LinkList L,int i,ElemType x){
	LinkList p,r;
	int j=0;
	p=L;
	if(i<1)
	printf("插入位置不对");
	while(p!=NULL&&j<i-1){
		p=p->next;
		j++;
	}
	r=(LinkList)malloc(sizeof(LNode));
	r->data=x;
	r->next=p->next;
	p->next=r;
	return L;
}

//删除单链表第i个数据节点 
LinkList ListDelete(LinkList L,int i){
	LinkList p,r;
	int j=0;
	p=L;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j++;
	}
	r=p->next;
	p->next=r->next;
	free(r);
	return L;
} 





int main(){
	LinkList L,node1,node2;  // 声明变量 
	
	
	

	L=CreateList();//创建链表 
	
	ShowList(L); //我要展示啦！
	 
	//printf("%d\n",ListLength(L));
	
	/*node1=Get_LinkList(L,2);
	if(!node1)
	printf("找不到\n"); 
	else printf("%d\n",node1->data);
	*/
	
	
	int You_Want;
	printf("请输入你想查找的数值 : ");
	scanf("%d", &You_Want);
	node2 = Locate_LinkList(L,34); // 让我去翻一翻有没有数值为34的节点 
	if(node2->data == 0) 
		printf("找不到\n"); 
	else	
		printf("找到啦！   %d\n", node2->data);
	
	
 //	ListInsert(L,2,45); // 在对应链表中插入 
	
//	ShowList(L); // 展示修改之后的链表 
	
	
	
	//printf("%d\n",ListLength(L));
	
	
//	ListDelete(L,3);// 删除 对应链表位置的链节 
	
//	ShowList(L);  // 展示修改之后的链表 
	
	//printf("%d\n",ListLength(L));
	
	
	return 0;  //走你！拜拜了您馁！ 
}


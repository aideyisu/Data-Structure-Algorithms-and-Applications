#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int ElemType;
// ������������ 
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode;
typedef LNode* LinkList;


	// ʮ�������������� 
	// ----------------------------------------------------------- 
	LinkList CreateList(); 									//   \ 
	int ListLength(LinkList L);								//   \ 
	void ShowList(LinkList L);								//   \ 
	LinkList Get_LinkList(LinkList L,int i);		     	//   \ 
	LinkList Locate_LinkList(LinkList L,ElemType x);		//   \ 
	LinkList ListInsert(LinkList L,int i,ElemType x);		//   \ 
	LinkList ListDelete(LinkList L,int i); 					//   \ 
	// ----------------------------------------------------------- 
	



//���������� 
LinkList CreateList(){
	LinkList L,r;
	LinkList p;
	ElemType x, len;
	len = 0;
	r = (LinkList)malloc(sizeof(LNode));
	L = r;
	L->next=NULL;
	printf("��ǰ����������%3d���ڵ�\t", len); 
	printf("���� 0 ֹͣ�����½ڵ�-->") ;
	scanf("%d",&x);   // �ҵ���Ҫ�����ʲô 
	while(x){
		p=(LinkList)malloc(sizeof(LNode));
		p->data=x;
		p->next=NULL;
		r->next=p;
		r=p;
		len++;
		printf("��ǰ����%3d���ڵ�\t", len); 
		printf("���� 0 ֹͣ�����½ڵ�-->") ;
		scanf("%d",&x);
	}
	return L;
}

//�鿴�������� 
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

//��ӡ������ڵ� 
void ShowList(LinkList L){
	LinkList p;
	p=L->next;
	while(p->next!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d ",p->data);
	printf("\n����ȫ��չʾ���\n");
}

//���ҵ������i���ڵ� 
LinkList Get_LinkList(LinkList L,int i){
	int ListLength(LinkList L); // x���� 
	LinkList p=L;
	int j=0;
	while(p->next!=NULL&&j<i){
		p=p->next;
		j++;
	}
	if(j==i) return p;
	else return 0; 
}

//�ڵ������в���ֵΪx�Ľڵ� ???���û��x���ֵʱ����� 
// �������Сɵ��д�� 
LinkList Locate_LinkList(LinkList L,ElemType x){
	LinkList p, HAHAHA;
	HAHAHA = (LinkList)malloc(sizeof(LNode));
	HAHAHA->data = 0;
	printf("��ʼ���ң�");
	p=L->next;
	while(p->data!=x && p->next != NULL)
		p=p->next;
	if(p->data == x) 
		return p;
	else 
		printf("��ôû��һ�����أ�");
	printf("................");
	return HAHAHA;
} 

//�������i���ڵ�ǰ����ֵΪx��Ԫ�� 
LinkList ListInsert(LinkList L,int i,ElemType x){
	LinkList p,r;
	int j=0;
	p=L;
	if(i<1)
	printf("����λ�ò���");
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

//ɾ���������i�����ݽڵ� 
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
	LinkList L,node1,node2;  // �������� 
	
	
	

	L=CreateList();//�������� 
	
	ShowList(L); //��Ҫչʾ����
	 
	//printf("%d\n",ListLength(L));
	
	/*node1=Get_LinkList(L,2);
	if(!node1)
	printf("�Ҳ���\n"); 
	else printf("%d\n",node1->data);
	*/
	
	
	int You_Want;
	printf("������������ҵ���ֵ : ");
	scanf("%d", &You_Want);
	node2 = Locate_LinkList(L,34); // ����ȥ��һ����û����ֵΪ34�Ľڵ� 
	if(node2->data == 0) 
		printf("�Ҳ���\n"); 
	else	
		printf("�ҵ�����   %d\n", node2->data);
	
	
 //	ListInsert(L,2,45); // �ڶ�Ӧ�����в��� 
	
//	ShowList(L); // չʾ�޸�֮������� 
	
	
	
	//printf("%d\n",ListLength(L));
	
	
//	ListDelete(L,3);// ɾ�� ��Ӧ����λ�õ����� 
	
//	ShowList(L);  // չʾ�޸�֮������� 
	
	//printf("%d\n",ListLength(L));
	
	
	return 0;  //���㣡�ݰ������٣� 
}


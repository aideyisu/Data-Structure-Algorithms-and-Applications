#include <stdio.h>
#include <stdlib.h>
#define Maxn 2000
typedef int Element;
typedef struct CSNode{
	Element data;
	struct CSNode * firstchild;
	struct CSNode * nextsibling;
}CSNode;
typedef CSNode * CSTree;

CSTree creat_tree()
{
    int n;
    scanf("%d",&n);
    if (n==-1) return NULL;
    CSTree root;
    root=(CSTree)malloc(sizeof(CSNode));
    root->data=n;
    root->firstchild=creat_tree();
    root->nextsibling=creat_tree();
    return root;
}

CSTree creat_forest(){                                    // ÿ�δ���һ��������������ɭ����  
	CSTree p, rppt, Tree_root;
	Tree_root = root = (CSTree)malloc(sizeof(CSNode));
	root->firstchild = NULL;
	root->nextsibling = NULL;
	p = root;
	printf("���������ĸ���\n");
	int num;
	scanf("%d", &num);
	for(int id = 1; id <= num; id++){
		printf("�������%d����������\n", id);
		Tree_root = creat_tree();                          // �����ｨ�� 
		p = root;                                          //  
		if(p->firstchild==NULL && p->nextsibling == NULL){ // ���p�ǵ�һ���ڵ� 
			p->data = Tree_root->data;                     // p�ͼ̳�Tree_root������ 
			p->firstchild = Tree_root->firstchild;		   // �ڵ�һ�ε�ʱ��ָ��ͷ�ڵ� 
		}
		else{
			while(p->nextsibling != NULL)                  //������������±��� ֱ����ײ� 
				p = p->nextsibling;
			p->nextsibling = Tree_root;                    //��ײ����һ���ڵ����´ε������ڵ� 
		}
	}
	return root;
}

void PreOrder(CSTree root)
{
    printf("%d ",root->data);
    if (root->firstchild!=NULL) PreOrder(root->firstchild);
    if (root->nextsibling!=NULL) PreOrder(root->nextsibling);
}
void Midorder(CSTree root)
{
    if (root->firstchild!=NULL) Midorder(root->firstchild);
    printf("%d ",root->data);
    if (root->nextsibling!=NULL) Midorder(root->nextsibling);
}
int main()
{
    printf("1.����ɭ��\n");
    printf("2.�������ɭ��\n");
    printf("3.�������ɭ��\n");
    printf("0.���� \n");
    int n;
    CSTree root;
    root=(CSTree)malloc(sizeof(CSNode));
    while (1)
    {
        printf("���������\n");
        scanf("%d",&n);
        if (n==1)
        {
            root=creat_forest();
        }
        if (n==2)
        {
            PreOrder(root);
        }
        if (n==3)
        {
            Midorder(root);
        }
        if (n==0)
            break;
    }
}

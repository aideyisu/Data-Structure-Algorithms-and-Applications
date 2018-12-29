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

CSTree creat_forest(){                                    // 每次创建一个树，把树挂在森林上  
	CSTree p, rppt, Tree_root;
	Tree_root = root = (CSTree)malloc(sizeof(CSNode));
	root->firstchild = NULL;
	root->nextsibling = NULL;
	p = root;
	printf("请输入树的个数\n");
	int num;
	scanf("%d", &num);
	for(int id = 1; id <= num; id++){
		printf("请输入第%d棵树的数据\n", id);
		Tree_root = creat_tree();                          // 在这里建树 
		p = root;                                          //  
		if(p->firstchild==NULL && p->nextsibling == NULL){ // 如果p是第一个节点 
			p->data = Tree_root->data;                     // p就继承Tree_root的数据 
			p->firstchild = Tree_root->firstchild;		   // 在第一次的时候指向头节点 
		}
		else{
			while(p->nextsibling != NULL)                  //如果正常则向下遍历 直到最底层 
				p = p->nextsibling;
			p->nextsibling = Tree_root;                    //最底层的下一个节点是下次的树根节点 
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
    printf("1.读入森林\n");
    printf("2.先序遍历森林\n");
    printf("3.中序遍历森林\n");
    printf("0.结束 \n");
    int n;
    CSTree root;
    root=(CSTree)malloc(sizeof(CSNode));
    while (1)
    {
        printf("请输入操作\n");
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

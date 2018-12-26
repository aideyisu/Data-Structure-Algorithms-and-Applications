#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define MaxNode 10

typedef char Elementtype;
typedef struct TreeNode * Node;
typedef struct TreeNode{
	Elementtype Element;
	Node left;
	Node right;
}TREE, *PTREE;

//创建二叉树当遇到 * 的时候结束树的创建 
void CreatTree(PTREE * Root){
	char val = 0;
	val = getchar();
	if (val == '*'){
		(*Root) = (PTREE)malloc(sizeof(TREE));
		(*Root)->Element = '*';
	}
	else{
		(*Root) = (PTREE)malloc(sizeof(TREE));
		if ((*Root) == NULL){
			printf("创建失败！");
			exit(-1); 
		}
		else{
			(*Root)->Element = val;
			CreatTree(&(*Root)->left);
			CreatTree(&(*Root)->right);
		}
	}
}

void CreatTree_Mega(PTREE * Mega){
	(*Mega) = (PTREE)malloc(sizeof(TREE));
	(*Mega)->Element = '*';
}

void First(PTREE * Root){
	if((*Root)->Element != '*'){
		printf("%c-", (*Root)->Element);      // printf("--%c--", ( * &(*Root)->left)->Element);   测试实验是否存在 
		//printf("--%c--", ( * &(*Root)->left)->Element);
		First(&(*Root)->left);
		First(&(*Root)->right);
	}
}


void Mid(PTREE * Root){
	if((*Root)->Element != '*'){
		First(&(*Root)->left);
		printf("%c-", (*Root)->Element);
		First(&(*Root)->right);
	}
}

void NRInOder2(PTREE * root, PTREE * Mega){
	PTREE * stack[MaxNode], * p;
	int top = 0;
	p = root;
	if ((*root)->Element == '*'){
		printf("The first point is NULL！");
		return; 
	}
	else{
		stack[top] = Mega;
		top++;                                           // 将top位置设置为空 
	}
	while((*p)->Element != '*' || top != 0){             // 当且仅当这个点的数据是'*'并且栈中无元素的时候退出循环 
		while((*p)->Element != '*'){
			if(top < (MaxNode - 1)){
				//printf("-%c-", (*p)->Element); 
				stack[top] = p;		//put in to the stack
				top++;				//the number of stack ++
			}
			else{
				printf("Stack overflow!\n");
				return; 
			}
			//printf("下个点的数值  %c  ", (*p)->left->Element);
			if( (*p)->left->Element != '*') 
				p=&( * &(*p)->left);				// 只有当下个点有数值，那么才会转移到下个左孩子 
			else
				break;
		} 
		
		if (top <= 1){
			printf("The stack is empty.\n");
			return;   
		}
		else{
			top--;
			p = stack[top];
			printf("-%c-", (*p)->Element); 
			p=&( * &(*p)->right);
		}
	}
} 

/*第一次失败原因，在递归形式上就出现了一些与原书本教程代码实际实现有出入的地方，因此再非递归的操作过程中造成了实际运用的BUG
  我个人的解决方案 ： 既然 * 是空的意思，那么我们在栈中提前加入一个节点来直接表示空 
  这样在首节点向上出栈的时候是的程序可以正确运行，不会出现死循环 异常退出等意外情况*/ 
void NRInOrder(PTREE * Root){                        
	PTREE * stack[MaxNode];
	printf("The maximum stack capacity is %d\n", MaxNode);
	int top = 0;
	PTREE * p;
	p = Root;
	printf("the data is -%c-\n", (*Root)->Element);
	printf("The copy is -%c-\n", (*p)->Element) ;
	if ((*Root)->Element == '*'){
		printf("there is no thing in stack.\n");
		return;
	}
	printf("I'm OK\n");
	while ((*p)->Element != '*' || top != 0){
		printf("\nOuter circulation\n\n");
		while((*p)->Element != '*'){
			printf("inner loop\n\n");
			if(top < (MaxNode - 1)){
				printf("一轮新的入栈-%c-", (*p)->Element); 
				stack[top] = p;		//put in to the stack
				top++;				//the number of stack ++
			}
			else{
				printf("Stack overflow!\n");
				return; 
			}
			printf("下个点的数值  %c  ", (*p)->left->Element);
			if( (*p)->left->Element != '*') 
				p=&( * &(*p)->left);				// 只有当下个点有数值，那么才会转移到下个左孩子 
			else{
				printf("next point is NULL(*)\n"); 
				break; 
				
			}
		}
		
		if (top <= 0){
			printf("The stack is empty.\n");
			return;   
		}           				 //The stack is empty.
		
		else{
			top--;
			p = stack[top];
			printf("-%c-", (*Root)->Element);
			if ( (*p)->right->Element != '*') 
				p =&( * &(*p)->right);
			else{
				printf("next point is NULL(*)\n"); 
				break;
			}
		} 
	}
	
	printf("\n正常退出非递归循环\n");
	
}

void Last(PTREE * Root){
	if((*Root)->Element != '*'){
		First(&(*Root)->left); 
		First(&(*Root)->right);
		printf("%c-", (*Root)->Element);
	}
}

void Free(PTREE * Root){
		if((*Root)->Element != '*'){
			First(&(*Root)->left); 
			First(&(*Root)->right);
			printf("释放节点 : %c\n", (*Root)->Element);
			free(Root);
	}
}

int main(){
	PTREE Root;
	PTREE NRInOrderRoot; 
	CreatTree(&Root); // 初始化遍历 
	CreatTree_Mega(&NRInOrderRoot);
	printf("前序遍历 ： "); 
	First(&Root);
	printf("end\n");
	printf("中序遍历 ： "); 
	Mid(&Root);
	printf("end\n");
	printf("后序遍历 :  ");
	Last(&Root);
	printf("end\n");
	printf("非递归中序遍历 :  ");
	NRInOder2(&Root, &NRInOrderRoot);
	printf("end\n"); 
			
} 

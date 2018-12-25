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

//���������������� * ��ʱ��������Ĵ��� 
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
			printf("����ʧ�ܣ�");
			exit(-1); 
		}
		else{
			(*Root)->Element = val;
			CreatTree(&(*Root)->left);
			CreatTree(&(*Root)->right);
		}
	}
}

void First(PTREE * Root){
	if((*Root)->Element != '*'){
		printf("%c-", (*Root)->Element);      // printf("--%c--", ( * &(*Root)->left)->Element);   ����ʵ���Ƿ���� 
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
				printf("һ���µ���ջ-%c-", (*p)->Element); 
				stack[top] = p;		//put in to the stack
				top++;				//the number of stack ++
			}
			else{
				printf("Stack overflow!\n");
				return; 
			}
			printf("�¸������ֵ  %c  ", (*p)->left->Element);
			if( (*p)->left->Element != '*') 
				p=&( * &(*p)->left);				// ֻ�е��¸�������ֵ����ô�Ż�ת�Ƶ��¸����� 
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
	
	printf("\n�����˳��ǵݹ�ѭ��\n");
	
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
			printf("�ͷŽڵ� : %c\n", (*Root)->Element);
			free(Root);
	}
}

int main(){
	PTREE Root;
			CreatTree(&Root); // ��ʼ������ 
			printf("ǰ����� �� "); 
			First(&Root);
			printf("end\n");
			printf("������� �� "); 
			Mid(&Root);
			printf("end\n");
			printf("������� :  ");
			Last(&Root);
			printf("end\n");
			printf("�ǵݹ�������� :  ");
			NRInOrder(&Root);
			printf("end\n"); 
			
} 

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

void CreatTree_Mega(PTREE * Mega){
	(*Mega) = (PTREE)malloc(sizeof(TREE));
	(*Mega)->Element = '*';
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

void NRInOder2(PTREE * root, PTREE * Mega){
	PTREE * stack[MaxNode], * p;
	int top = 0;
	p = root;
	if ((*root)->Element == '*'){
		printf("The first point is NULL��");
		return; 
	}
	else{
		stack[top] = Mega;
		top++;                                           // ��topλ������Ϊ�� 
	}
	while((*p)->Element != '*' || top != 0){             // ���ҽ���������������'*'����ջ����Ԫ�ص�ʱ���˳�ѭ�� 
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
			//printf("�¸������ֵ  %c  ", (*p)->left->Element);
			if( (*p)->left->Element != '*') 
				p=&( * &(*p)->left);				// ֻ�е��¸�������ֵ����ô�Ż�ת�Ƶ��¸����� 
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

/*��һ��ʧ��ԭ���ڵݹ���ʽ�Ͼͳ�����һЩ��ԭ�鱾�̴̳���ʵ��ʵ���г���ĵط�������ٷǵݹ�Ĳ��������������ʵ�����õ�BUG
  �Ҹ��˵Ľ������ �� ��Ȼ * �ǿյ���˼����ô������ջ����ǰ����һ���ڵ���ֱ�ӱ�ʾ�� 
  �������׽ڵ����ϳ�ջ��ʱ���ǵĳ��������ȷ���У����������ѭ�� �쳣�˳����������*/ 
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
	PTREE NRInOrderRoot; 
	CreatTree(&Root); // ��ʼ������ 
	CreatTree_Mega(&NRInOrderRoot);
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
	NRInOder2(&Root, &NRInOrderRoot);
	printf("end\n"); 
			
} 

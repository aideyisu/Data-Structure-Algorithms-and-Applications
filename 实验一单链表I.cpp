#include <stdio.h>
#include <stdlib.h>
/* �������� */ 
typedef int Element;
typedef struct LNode{
	Element data;
	Element length = 0; 
	struct LNode * next;
}LNode , * LinkList;

typedef LNode * LinkList;

LinkList CreatLinklist(){
	LNode * first;
	LNode * Remember; 
	int number;
	int sum = 0;
	first = (LNode *) malloc(sizeof(LNode));
	if (first == NULL){
		printf("û���ڴ�����������\n\t\t ORZ ����������һ�µ�����\n\n");
	}
	printf("������ͷ�ڵ���ֵ��  ");
	scanf("%d", &first->data);
	first->next = NULL;
	/*   ����ͷ�ڵ㲿��  */
	printf("ͷ��㴴�����~\n\n");
	/* ��ʼ��λ���� */
	Remember = first; 
	printf("�������� 0 ��ʱ�򣬽�����ֹ�����������ڵĴ���\n\n");
	sum++;
	while(1){
		printf("���ǵ�%d���ڵ�   ", sum);
		printf("data����ֵ�� : "); 
		scanf("%d", &number);
		if (number == 0){
			printf("��ֹ������\t��ǰ����������Ϊ : %d\n", sum);
			break;
		}
		LNode * second;
		second = (LNode *) malloc(sizeof(LNode));
		Remember->next = second;
		second->data = number;
		second->next = NULL;
		Remember = second;
		/*����ʹRemember�������ڵĴ�������ƫ��, ͬʱʹ��sum����������*/ 
		sum++;
	}	
	first->length = sum;
	printf("���崴���ɹ�\n");
	
	/*  ������Ϊ���Բ��� �� ԭ�� �� �����������  */
	 Remember = first;
	 while(Remember->next != NULL){
	 	LNode * second= Remember->next;
	 	printf("%d\t", Remember->data);
	 	Remember = second;
	 } 
	printf("%d", Remember->data);
	
	/*     ���Խ���    */
	/*    ������������   ���Ǹо�������ֺ����Ի�������֮*/
	return first;
}

void ContLinklist(LinkList pre, LinkList now){
	LinkList t;
	while(pre->next != NULL){
		t = pre->next;
		pre = t;
	}
	pre->next = now;
	pre->length = pre->length + now->length;
}

void OutputLinklist(LinkList first){
	LinkList TI;
	LinkList t;
	int i = 0;
	int a = 1;
	printf("�б���%d���ڵ�\n", first->length);
	TI = first;
	while(TI->next != NULL){
		printf("Current  %d �ڵ���ֵ��  %d\t", a ,  TI->data);
		t = TI->next;
		TI = t;
		i++;
		a++;
		if (i == 3){
			printf("\n");
			i = 0;
		} 
	} 
	printf("Current  %d �ڵ���ֵ��  %d\t", a , TI->data);
}

void delected(LinkList My_list){
	LinkList t;
	while(1){
		if (My_list->next == NULL){
			printf("�������ͷ���ȫ\n");
			break;  
		}
		t = My_list->next;
		printf("ɾ���ڵ� %d", My_list->data); 
		free(My_list);
		My_list = t;
	}
}


int main(){
	int order = 0;
	int choose; 
	int how_many = 0; 
	LinkList first;
	LinkList second;
	while(1){
		printf("----------������1->����һ������   2->�ںϽ���!    3->ѡ����ʾ����     4->Quit\n");
		printf("��ǰ�������� %d\n\n���ѡ����", how_many);
		scanf("%d", &choose);
		if (choose == 1){
			if (how_many == 0){
				printf("��ӭ�������һ������\n");
				first =  CreatLinklist();
				how_many++;
				continue;
			} 
			else if (how_many == 1){
				printf("��ӭ�㴴������һ������\n");
				second = CreatLinklist();
				how_many++;
				continue;
			}
			else if (how_many == 2){
				system("cls");
				printf("��,�����Ѿ������������ˡ� ����Կ��Ǻϲ������ٴ���һ���µ�����\n");
				printf("��װ�ص������ѵ������ޡ�\n\n");		
				continue;
			} 
			else{
				system("cls");
				printf("�����δ֪��ԭ��������ĳЩԭ�����������������������������");
				break;
			}
		}
		if(choose == 2){
			if ( how_many < 2){
				system("cls");
				printf("��������������δ�ﵽ����\n");
				printf("����ӵ������������ٽ��кϲ�����\n\n");
				continue;
			}
			/*  ��û���������ʱ��������  �������� */
			system("cls");
			printf("������ͷβ�ν�˳�� 1:��һ������β�ӵڶ�������\t2:�ڶ�������β�ӵ�һ������\n");
			scanf("%d", &order);
			if(order == 1){
				ContLinklist(first, second);
			}
			else if(order == 2){
				ContLinklist(second, first);
			}
			else{
				system("cls");
				printf("�����δ֪��ԭ��������ĳЩԭ�����������������������������");
				break;
			}
		}	
		if (choose == 3){
			printf("������չʾ������ 1:first���� 2��second����\n");
			scanf("%d", &order);
			if(order == 1){
				system("cls");
				OutputLinklist(first);
			}
			else if(order == 2){
				system("cls");
				OutputLinklist(second);
			}
			else{
				system("cls");
				printf("�����δ֪��ԭ��������ĳЩԭ�����������������������������");
				break;
			}
		}
		if (choose == 4){
			printf("\n\n�����ͷ������˳�����");
		}
		
		/*������ѭ���Ľ���~*/ 
			
	}
	
	/* �������ͷ��������� */
	if (how_many >= 1){
		delected(first);
		printf("first���� ok");
	}
	if (how_many == 2){
		delected(second);
		printf("second���� ok"); 
	}
	return 0;
}


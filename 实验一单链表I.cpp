#include <stdio.h>
#include <stdlib.h>
/* 声明链节 */ 
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
		printf("没有内存啦！！！！\n\t\t ORZ 该重启清理一下电脑啦\n\n");
	}
	printf("请输入头节点数值：  ");
	scanf("%d", &first->data);
	first->next = NULL;
	/*   创建头节点部分  */
	printf("头结点创建完毕~\n\n");
	/* 开始错位操作 */
	Remember = first; 
	printf("当你输入 0 的时候，将会终止链表中新链节的创建\n\n");
	sum++;
	while(1){
		printf("这是第%d个节点   ", sum);
		printf("data的数值是 : "); 
		scanf("%d", &number);
		if (number == 0){
			printf("终止链表创建\t当前链表链节数为 : %d\n", sum);
			break;
		}
		LNode * second;
		second = (LNode *) malloc(sizeof(LNode));
		Remember->next = second;
		second->data = number;
		second->next = NULL;
		Remember = second;
		/*迭代使Remember随着链节的创建而逐渐偏移, 同时使用sum记下链表长度*/ 
		sum++;
	}	
	first->length = sum;
	printf("整体创建成功\n");
	
	/*  接下来为测试部分 ： 原因 ： 输出链表不正常  */
	 Remember = first;
	 while(Remember->next != NULL){
	 	LNode * second= Remember->next;
	 	printf("%d\t", Remember->data);
	 	Remember = second;
	 } 
	printf("%d", Remember->data);
	
	/*     测试结束    */
	/*    链表正常创建   但是感觉这个部分很人性化，遂留之*/
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
	printf("列表共有%d个节点\n", first->length);
	TI = first;
	while(TI->next != NULL){
		printf("Current  %d 节点数值：  %d\t", a ,  TI->data);
		t = TI->next;
		TI = t;
		i++;
		a++;
		if (i == 3){
			printf("\n");
			i = 0;
		} 
	} 
	printf("Current  %d 节点数值：  %d\t", a , TI->data);
}

void delected(LinkList My_list){
	LinkList t;
	while(1){
		if (My_list->next == NULL){
			printf("链表已释放完全\n");
			break;  
		}
		t = My_list->next;
		printf("删除节点 %d", My_list->data); 
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
		printf("----------请输入1->建立一个链表   2->融合进化!    3->选择并显示链表     4->Quit\n");
		printf("当前链表数量 %d\n\n你的选择是", how_many);
		scanf("%d", &choose);
		if (choose == 1){
			if (how_many == 0){
				printf("欢迎你输入第一个链表\n");
				first =  CreatLinklist();
				how_many++;
				continue;
			} 
			else if (how_many == 1){
				printf("欢迎你创建另外一个链表\n");
				second = CreatLinklist();
				how_many++;
				continue;
			}
			else if (how_many == 2){
				system("cls");
				printf("呃,现在已经有两个链表了。 你可以考虑合并他们再创造一个新的链表\n");
				printf("可装载的链表已到达上限。\n\n");		
				continue;
			} 
			else{
				system("cls");
				printf("进入的未知荒原。可能因某些原因导致了这种情况。可重启程序重试");
				break;
			}
		}
		if(choose == 2){
			if ( how_many < 2){
				system("cls");
				printf("现在链表数量尚未达到两个\n");
				printf("请在拥有两个链表后再进行合并操作\n\n");
				continue;
			}
			/*  在没有意外情况时继续运行  首先清屏 */
			system("cls");
			printf("请输入头尾衔接顺序 1:第一个链表尾接第二个链表\t2:第二个链表尾接第一个链表\n");
			scanf("%d", &order);
			if(order == 1){
				ContLinklist(first, second);
			}
			else if(order == 2){
				ContLinklist(second, first);
			}
			else{
				system("cls");
				printf("进入的未知荒原。可能因某些原因导致了这种情况。可重启程序重试");
				break;
			}
		}	
		if (choose == 3){
			printf("请输入展示的链表 1:first链表 2：second链表\n");
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
				printf("进入的未知荒原。可能因某些原因导致了这种情况。可重启程序重试");
				break;
			}
		}
		if (choose == 4){
			printf("\n\n即将释放链表并退出程序");
		}
		
		/*这里是循环的结束~*/ 
			
	}
	
	/* 在这里释放所有链节 */
	if (how_many >= 1){
		delected(first);
		printf("first链表 ok");
	}
	if (how_many == 2){
		delected(second);
		printf("second链表 ok"); 
	}
	return 0;
}


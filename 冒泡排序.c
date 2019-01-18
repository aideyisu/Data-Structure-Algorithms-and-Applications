#include <stdio.h>
#define MAX 100
void BubbleSort(int R[], int length){
	int i, j, t;
	for(i = 0; i < length; i++){
		for(j = 0; j < i; j++){
			if(R[i] < R[j]){
				t = R[i];
				R[i] = R[j];
				R[j] = t;
			}
		}
	}
}

void show(int R[], int length){
	int i;
	printf("\n");
	for(i = 1; i-1 < length; i++){
		printf("%5d ", R[i-1]);
		if(i % 5 == 0)
			printf("\n");
	}
	printf("\n");
}

int main(){
	int R[MAX];
	printf("请输入你想要的数据；(65535结束输入)");
	int num, sum;
	sum = 0;
	scanf("%d ", &num);	
	while(num != -65535){
		R[sum] = num;
		sum++;
		scanf("%d, &num");
	}
	printf("你共计输入了 %d 个数据", sum);
	printf("他们分别是 : \n");
	show(R, sum);
	printf("接下来冒泡排序后的输出为\n");
	BubbleSort(R,sum);
	show(R, sum); 
	return 0;
}

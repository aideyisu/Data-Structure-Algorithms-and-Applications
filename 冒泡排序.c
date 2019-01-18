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
	printf("����������Ҫ�����ݣ�(65535��������)");
	int num, sum;
	sum = 0;
	scanf("%d ", &num);	
	while(num != -65535){
		R[sum] = num;
		sum++;
		scanf("%d, &num");
	}
	printf("�㹲�������� %d ������", sum);
	printf("���Ƿֱ��� : \n");
	show(R, sum);
	printf("������ð�����������Ϊ\n");
	BubbleSort(R,sum);
	show(R, sum); 
	return 0;
}

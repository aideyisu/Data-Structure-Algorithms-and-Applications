#include <stdio.h>
#define MAXSIZE 10

typedef struct SqList{
	int r[MAXSIZE] ;
	int length;
	int time;
}SqList; 

void swap(SqList * L, int i, int j){
	L->time++;
	printf("第%-2d次交换    %d : %d \t %d : %d\n",L->time, i,L->r[i], j,L->r[j]);
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
	
}

int Partition(SqList * L, int low, int high){
	int pivotkey;
	pivotkey = L->r[low];
	
	while(low < high){
		while (low < high && L->r[high] >= pivotkey){
			//printf("%d 比 %d 大,high数值降低  ", L->r[high], pivotkey);
			high--;
			//printf("%d\n", high);
		}
		swap( L, low, high);
		
		while (low < high && L->r[low] <= pivotkey)
			//printf("%d 比 %d 小,low数值升高  ", L->r[high], pivotkey);
			low++;
			//printf("%d\n", low);
		swap(L, low, high);
	}
	
	return low;
}


void QSort(SqList * L, int low, int high){
	int pivot;
	if(low < high){
		pivot = Partition(L, low, high);
		
		QSort(L, low, pivot-1);
		QSort(L, pivot+1, high);
	}
}

void QuickSort(SqList * L){
	QSort(L, 1, L->length);
}


// = {50,10,90,30,70,40,80,60,20,01}
int main(){
	SqList K;
	K.r[1]=50;
	K.r[2]=10;
	K.r[3]=90;
	K.r[4]=30;
	K.r[5]=70;
	K.r[6]=40;
	K.r[7]=80;
	K.r[8]=60;
	K.r[9]=20;
	K.time=0;
	K.length=9;
	printf("快排之前的数组\n");
	int i;
	for (i = 1; i < 10; i++){
		printf("%d\n", K.r[i]);
	}
	QuickSort(&K); 
	printf("\n\n排列后\n\n");
		for (i = 1; i < 10; i++){
		printf("%d\n", K.r[i]);
	}
	
	return 0;
}

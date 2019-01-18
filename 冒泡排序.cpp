#include <bits/stdc++.h>
using namespace std;

void exchange(int R[], int i, int j){
	int t;
	t = R[i];
	R[i] = R[j];
	R[j] = t;
}

void BubbleSort(int R[], int length){
	for(int i = 0; i < length; i++){
		for(int j = 0; j < length; j++){
			if(R[i] < R[j]){
				exchange(R, i, j);
			}
		}
	}
}

void Show(int R[], int length){
	cout << endl;
	for(int i = 1; i-1 < length; i++){
		cout <<   setw(5) << R[i-1] ;
		if(i % 5 == 0)
			cout << endl;
	}
}

int main(){
	int const MAX = 100;
	int R[MAX];
	int sum = 0;
	cout << "输入你的数据 (-65535为退出)" << endl; 
	cin >> R[sum];
	while(R[sum] != -65535){
		sum++;
		cin >> R[sum];
	}
	cout << "你总计输入了 " << sum << "个数据" << endl << "他们分别是" << endl;
	Show(R, sum);
	cout << "冒泡排序后的序列为" << endl;
	BubbleSort(R, sum);
	Show(R, sum);
	return 0;
} 

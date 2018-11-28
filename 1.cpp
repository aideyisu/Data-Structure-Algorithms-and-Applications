#include<bits/stdc++.h>
using namespace std; 


void swap(int & a, int & b){
	int temp = a;
	a = b;
	b = temp;
}


int main(){
	int a, b;
	cout << "input the data of a and b  " ;
	cin >> a >> b;  
	swap(a, b);
	cout << endl << "after swap the data is  "; 
	cout << a << "    " << b <<  endl;
	
}

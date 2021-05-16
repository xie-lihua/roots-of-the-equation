#include<iostream>
using namespace std;
int main() {

	int a[5] = { 0 };
	for (int i = 0; i < 5; i++) {
		a[i] = 2 * i + 1;
	}
	int* p = a;
	//定义指针数组
	int* pp[5] = { p,p + 1,p + 2,p + 3,p + 4 };
	for (int i = 0; i < 5; i++) {
		//以下两种表述等价
		cout << *pp[i] << "  ";
		cout << **(pp + i) << "  ";
	}
	//定义二维数组
	int b[2][3] = { 0 };
	int* z = b[0];//z为数组首地址
	for (int i = 0; i < 6; i++) {
		*(z + i) = 2 * i;
	}cout << endl;

	int* zz[2] = { b[0],b[1] };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			//以下两种表述等价
			cout << *(zz[i] + j) << "  ";
			cout << *(*(zz + i) + j) << "  ";
		}
	}cout << endl;
	return 0;
}
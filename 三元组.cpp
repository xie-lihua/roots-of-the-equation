#include<iostream>
using namespace std;

//  已知 2< a< b< c<30;a，b,c,及三者和均为素数
//  求满足条件的a，b,c . 打印出来 。
//	 a不可能等于2，因为后面两个必为奇数，其和必定是偶数，合数

//三元组编号bn
int an[50][4];
int bn = 0;
//判断质数
int isprime(int a) {
	int  sq = sqrt(a)+1;
	
	int flag = 1;
	for (int i = 2; i < sq+1 ; i++) {
		if (a % i == 0) {
			flag = 0; break;
		}
	}
	return flag;
}

class Prime {

	//定义成员
public:
	int a=3;
	int b=0;
	int c=0;
	

	void primea() {

		//判断 获取质数a，
		int sign = isprime(a);
		while (sign == 0) {
			a++;
			sign = isprime(a);
		} 
		//给b赋值，下一步获取离a最近的质数
			b = a + 2;
		//质数一定是奇数，+2可以节约判断成本
	}
	void primeb() {
		//判断 获取质数b
		int sign = isprime(b);
		while (sign == 0) {
			b++;
			sign = isprime(b);
		}//给c赋值
		c = b + 2;
	}

	void primecs() {

		//定义重复判断标记
	flag:
		while (c < 30) {
			// a与b 值先不动，遍历c与和是否是素数
		int sign = isprime(c);

			while (sign == 0 && c < 28) {
				c++;
				sign = isprime(c);
			}
			//判断和是否是素数，是则输出。循环c值加1，重新判断。
			int s = a + b + c;
			int si = isprime(s);

			if (si == 1)
			{
				an[bn][0] = a;
				an[bn][1] = b;
				an[bn][2] = c;
				an[bn][3] = s;
				bn++;
				c++;
			}
			else {
				c++;
				si = isprime(s);
				goto flag;
			}
		} // a与单个b回合完成，b值+2，重新选择符合条件的c;
		 while (b<30) {
			b += 2;
			primeb();
			goto flag;
		}
		
		a+=2;
		//单个a与所有的b及c完成，a值加2，挑选出全部符合的a
		 //至此方法完成，结束。
	}

};


int main() {
	//重复执行三个步骤
	Prime zhishu;
	while (zhishu.a < 30) {
		zhishu.primea();
		zhishu.primeb();
		zhishu.primecs();
	}
	for (int i = 0; i < bn; i++) {
		cout <<"第"<<i + 1 << "组\t" << an[i][0] << "\t" << an[i][1]
			<< "\t" << an[i][2] << "\t" << an[i][3] << endl;
	}
	return 0;
}
//  2021/4/14. xie-lihua
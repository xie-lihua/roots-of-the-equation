#include<iostream>
using namespace std;

//  ��֪ 2< a< b< c<30;a��b,c,�����ߺ;�Ϊ����
//  ������������a��b,c . ��ӡ���� ��
//	 a�����ܵ���2����Ϊ����������Ϊ��������ͱض���ż��������

//��Ԫ����bn
int an[50][4];
int bn = 0;
//�ж�����
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

	//�����Ա
public:
	int a=3;
	int b=0;
	int c=0;
	

	void primea() {

		//�ж� ��ȡ����a��
		int sign = isprime(a);
		while (sign == 0) {
			a++;
			sign = isprime(a);
		} 
		//��b��ֵ����һ����ȡ��a���������
			b = a + 2;
		//����һ����������+2���Խ�Լ�жϳɱ�
	}
	void primeb() {
		//�ж� ��ȡ����b
		int sign = isprime(b);
		while (sign == 0) {
			b++;
			sign = isprime(b);
		}//��c��ֵ
		c = b + 2;
	}

	void primecs() {

		//�����ظ��жϱ��
	flag:
		while (c < 30) {
			// a��b ֵ�Ȳ���������c����Ƿ�������
		int sign = isprime(c);

			while (sign == 0 && c < 28) {
				c++;
				sign = isprime(c);
			}
			//�жϺ��Ƿ������������������ѭ��cֵ��1�������жϡ�
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
		} // a�뵥��b�غ���ɣ�bֵ+2������ѡ�����������c;
		 while (b<30) {
			b += 2;
			primeb();
			goto flag;
		}
		
		a+=2;
		//����a�����е�b��c��ɣ�aֵ��2����ѡ��ȫ�����ϵ�a
		 //���˷�����ɣ�������
	}

};


int main() {
	//�ظ�ִ����������
	Prime zhishu;
	while (zhishu.a < 30) {
		zhishu.primea();
		zhishu.primeb();
		zhishu.primecs();
	}
	for (int i = 0; i < bn; i++) {
		cout <<"��"<<i + 1 << "��\t" << an[i][0] << "\t" << an[i][1]
			<< "\t" << an[i][2] << "\t" << an[i][3] << endl;
	}
	return 0;
}
//  2021/4/14. xie-lihua
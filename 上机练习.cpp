#include<iostream>
#include <math.h>
using namespace std;

//��Ƶ���
class Point {
private:
	int x = 0;
	int y = 0;
public:
	void setX() {
		cout << "�������ĺ����� :";
		int x;
		cin >> x;
		this->x = x;

	}int getX() {
		return x;
	}
	void setY() {
		cout << "�������������� :";
		int y = 0;
		cin >> y;
		this->y = y;
	}int getY() {
		return y;
	}
	void issame(Point& a) {
		if (a.getX() == x && a.getY() == y)
			cout << "����Ϊͬһ����" << endl;
		else
			cout << "���߲���ͬһ����" << endl;
	}
	void Distance(Point& a) {

		double s = 0;
		s= sqrt((a.getX() - x) * (a.getX() - x) + (a.getY() - y) * (a.getY() - y));
		cout << "\n��������Ϊ "<< s << endl;
	}
};

//��ƾ�����
class Rectg {

private:
	Point a;
	Point b;
public:
	//���������㹹�����
		void setJu(Point p1,Point p2) {
		a = p1; b = p2;
	}

	//	��ȡ������Ϣ
	Point getJu() {
		return a,b;
	}

	//abs ��fabs �õ�����ֵ��߳�
	void calC() {
		int c = (abs(a.getX() -b.getX()) + abs(a.getY() -b.getY())) * 2;
		cout << "�ܳ�Ϊ ��" << c << endl;;
	}
	void calS() {
		double s = fabs(a.getX() - b.getX()) * fabs(a.getY() -b.getY());
		cout << "���Ϊ��" << s << endl;

	}
};

int main() {
	//ʵ����������
	Point p1, p2;

	cout << "�������һ���������" << endl;
	p1.setX();
	p1.setY();
	cout << "������ڶ����������" << endl;
	p2.setX();
	p2.setY();

	//�ж������Ƿ��ػ�
	p1.issame(p2);

	//�������
	p2.Distance(p1);
	
	// �������㶨�����fang
	Rectg fang;
	//��fang ��ֵ������
	fang.setJu(p1, p2);

	//�����ܳ����������ӡ
	fang.calC();
	fang.calS();

	return 0;
}

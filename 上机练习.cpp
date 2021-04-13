#include<iostream>
#include <math.h>
using namespace std;

//设计点类
class Point {
private:
	int x = 0;
	int y = 0;
public:
	void setX() {
		cout << "请输入点的横坐标 :";
		int x;
		cin >> x;
		this->x = x;

	}int getX() {
		return x;
	}
	void setY() {
		cout << "请输入点的纵坐标 :";
		int y = 0;
		cin >> y;
		this->y = y;
	}int getY() {
		return y;
	}
	void issame(Point& a) {
		if (a.getX() == x && a.getY() == y)
			cout << "二者为同一个点" << endl;
		else
			cout << "二者不是同一个点" << endl;
	}
	void Distance(Point& a) {

		double s = 0;
		s= sqrt((a.getX() - x) * (a.getX() - x) + (a.getY() - y) * (a.getY() - y));
		cout << "\n两点间距离为 "<< s << endl;
	}
};

//设计矩形类
class Rectg {

private:
	Point a;
	Point b;
public:
	//输入两个点构造矩形
		void setJu(Point p1,Point p2) {
		a = p1; b = p2;
	}

	//	获取对象信息
	Point getJu() {
		return a,b;
	}

	//abs 和fabs 得到绝对值求边长
	void calC() {
		int c = (abs(a.getX() -b.getX()) + abs(a.getY() -b.getY())) * 2;
		cout << "周长为 ：" << c << endl;;
	}
	void calS() {
		double s = fabs(a.getX() - b.getX()) * fabs(a.getY() -b.getY());
		cout << "面积为：" << s << endl;

	}
};

int main() {
	//实例化两个点
	Point p1, p2;

	cout << "请输入第一个点的坐标" << endl;
	p1.setX();
	p1.setY();
	cout << "请输入第二个点的坐标" << endl;
	p2.setX();
	p2.setY();

	//判断两点是否重回
	p1.issame(p2);

	//计算距离
	p2.Distance(p1);
	
	// 由两个点定义矩形fang
	Rectg fang;
	//给fang 赋值两个点
	fang.setJu(p1, p2);

	//计算周长和面积并打印
	fang.calC();
	fang.calS();

	return 0;
}

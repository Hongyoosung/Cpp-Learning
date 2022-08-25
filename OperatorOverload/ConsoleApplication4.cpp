#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;



class Man {
	int age;
	int money;
public:
	Man(int age = 0, int money = 0) {
		this->age = age;
		this->money = money;
	}
	void show() {
		cout << "age : " << age << endl << "money : " << money << endl;
	}
	Man operator+ (int op); // 오른쪽 피연산자는 정수이므로 int형 매개 변수
	
};
Man Man::operator+ (int op) {
	Man a;
	a.money = this->money - 100;    // + 연산자 함수이지만 멤버마다 다른 연산을 수행할 수 있다
	a.age = this->age + op;         // a는 자기 자신의 age에 전달받은 op값을 더함
	return a;                       // 객체 반환
}


int main(int argc, const char* argv[]) {

	Man Jinho(26, 100), Dohyeon(23, 50);
	

	cout << "Jinho의 나이와 돈" << endl;
	Jinho.show();
	cout << endl << "Dohyeon의 나이와 돈" << endl;
	Dohyeon.show();
	
	cout << endl << "2년의 시간이 흘렀습니다" << endl << endl;

	Man OldJinho = Jinho + 2;
	Man OldDohyeon = Dohyeon + 2;
	
	cout << "Jinho의 나이와 돈" << endl;
	OldJinho.show();
	cout << endl << "Dohyeon의 나이와 돈" << endl;
	OldDohyeon.show();

	return 0;
}


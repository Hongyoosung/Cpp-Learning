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
	Man& operator++ (int x); // 참조를 반환하기 위해 기호 '&' 사용
	Man& operator++ ();
};
Man& Man::operator++ (int x) {  
	Man c = *this;  // 변경 전 값을 미리 저장
	age++;
	money++;
	return c;       // 변경 전 객체 자기 자신을 반환
}
Man& Man::operator++ () {     // 모든 멤버의 값 1씩 증가
	age++;
	money++;
	return *this;       // 변경된 객체 자기 자신을 반환
}

int main(int argc, const char* argv[]) {

	Man Jinho(26, 100), Dohyeon(23, 150);

	Jinho.show();
	Dohyeon.show();

	Jinho = Dohyeon++;        // Jinho에 변경 이전 Dohyeon의 값을 저장   
	++Dohyeon;                // Dohyeon의 값 1 증가
	cout << endl << "1년 후.." << endl << endl;

	Jinho.show();             
	Dohyeon.show();           

	return 0;
}


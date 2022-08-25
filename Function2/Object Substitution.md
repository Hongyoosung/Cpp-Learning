# 객체 치환 및 객체 반환

프로그래밍에서 치환이란 복사 대입이라고 생각하면 된다. 다음은 객체를 치환한 예이다.


+ ## 객체의 치환

```c++
class Man {
	int age;
public:
	Man() { age = 26; }
	Man(int age) { this->age = age; }

	int getAge() { return age; }
};


int main(int argc, const char* argv[]) {

	Man Jinho;
	Man Dohyeon(23);

	Jinho = Dohyeon;        // 객체 Jinho에 Dohyeon의 모든 값을 복사 대입

	cout << "Jinho : " << Jinho.getAge() << endl;
	cout << "Dohyeon : " << Dohyeon.getAge() << endl;

	return 0;
}
```

실행 결과
```c++
Jinho : 23   //Jinho의 age 값이 Dohyeon의 age 값으로 변경
Dohyeon : 23
```

객체의 치환은 한 객체가 가진 모든 값을 복사 대입하며, 이는 동일한 클래스를 가진 객체끼리만 가능하다.


+ ## 객체의 반환

객체의 치환과 마찬가지로, 객체를 함수에 사용하여 반환 값으로 이용해 해당 객체의 모든 값을 복사 대입한다. 다음은 그 예이다.

```c++
class Man {
	int age;
public:
	Man() { age = 26; }
	Man(int age) { this->age = age; }

	int getAge() { return age; }
};

Man get() {           // 클래스로 함수를 만들 수 있다
	Man Dohyeon(23);  // 같은 클래스의 객체에만 사용 가능
	return Dohyeon;   // 객체의 모든 값을 반환
}
int main(int argc, const char* argv[]) {

	Man Jinho;
	cout << "Jinho : " << Jinho.getAge() << endl;

	Jinho = get();   // 반환값을 Jinho에 복사 대입
	cout << "Jinho : " << Jinho.getAge() << endl;

	return 0;
}
```
실헹 결과

```c++
Jinho : 26
Jinho : 23
```

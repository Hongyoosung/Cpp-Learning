# 상속과 생성자, 소멸자



+ ## protected 접근 지정자

C++에서 사용할 수 있는 접근 지정자로는 지금까지 써왔던 private와 public 외에도 protected라는 접근 지정자가 존재한다. 해당 접근 지정자로 등록된 멤버는
선언된 클래스와 그 클래스의 파생 클래스에서만 접근할 수 있다. 즉, private보단 허용 범위가 넓으면서도 public보다는 좁다. 다음은 protected 접근 지정자를 사용하는 예시이다.

```c++
class Person {      
protected:               // 멤버 변수를 protected로 지정
    int age = 23;
    int money = 100;
public:
    void setAge(int age) { this->age = age; }
    void setMoney(int money) { this->money = money; }
    
};

class Man : public Person {           // Person 멤버를 상속받는 클래스 Man
    string name;
public:
    Man(string name) { this->name = name; }
    void showAll() {
        cout << name << "  age : " << age << " money : " << money << endl; // 기본 클래스의 멤버 변수에 접근 가능
                              
    }
};




int main()
{
    Man J("Jinho");
    J.showAll();
    
    return 0;
}
```
실행 결과
```c++
Jinho  age : 23 money : 100
```
protected 접근 지정자인 멤버라도 객체에서 직접 접근할 순 없다(예 : J.age). 이는 기본 클래스의 객체라도 마찬가지이다. 따라서 기본, 파생 클래스의 멤버 구현에서만 protected 멤버를
사용할 수 있다.

+ ## 상속과 생성자, 소멸자

클래스에는 생성자와 소멸자가 최소 한 개씩은 있다. 만약 파생 클래스의 객체가 생성되면 기본 클래스와 파생 클래스 중 어떤 생성자가 호출될까? 우선 파생 클래스의 객체가
생성되면 컴파일러는 파생 클래스의 생성자를 호출한다. 이 때, 클래스 간의 상속 관계를 파악 후 만약 상속받는 기본 클래스가 있다면, 이 호출문은 다시 기본 클래스의 생성자를
호출한다. 해당 과정을 반복하여 더 이상 상위 클래스가 존재하지 않을 경우, 최상위 클래스의 생성자가 먼저 실행되고, 그 다음 계층의 클래스 생성자가 순차적으로 실행된다.
따라서 클래스 간 상속 관계가 A >> B >> C 일 경우, C의 객체가 생성되면 A -> B -> C 의 순서로 각 클래스의 생성자가 실행된다. 이는 파생 클래스의 객체가
기본 클래스의 멤버를 활용하기 위해 멤버 초기화가 필요하기 때문이다.

파생 클래스의 객체가 소멸할 때 역시 파생 클래스와 기본 클래스의 소멸자가 모두 실행되며 생성자의 실행 순서와 반대로 실행된다. 
이는 파생 클래스의 소멸자를 실행 후 기본 클래스에 반환할 값이 있을 수 있기 때문이다. 다음은 해당 과정을 볼 수 있도록 코드로 구현한 것이다.

```c++
class A {                   
    int age = 23;
    int money = 100;
public:                // 생성자, 소멸자의 접근 지정자는 public 또는 protected여야 파생 클래스에서 호출 가능
    A() { cout << "A 클래스 생성자 실행" << endl; }
    ~A() { cout << "A 클래스 소멸자 실행" << endl; }
};

class B : public A {
public:
    B() { cout << "B 클래스 생성자 실행" << endl; }
    ~B() { cout << "B 클래스 소멸자 실행" << endl; }
};

class C : public B {
public:
    C() { cout << "C 클래스 생성자 실행" << endl; }
    ~C() { cout << "C 클래스 소멸자 실행" << endl; }
};



int main()
{
    C c; // 클래스 C의 객체 c 생성
    
    return 0;
}
```
실행 결과
```c++
A 클래스 생성자 실행
B 클래스 생성자 실행
C 클래스 생성자 실행
C 클래스 소멸자 실행
B 클래스 소멸자 실행
A 클래스 소멸자 실행
```
컴파일러는 파생 클래스의 생성자가 실행될 때, 묵시적으로 기본 클래스의 기본 생성자를 호출하기 때문에, 만약 기본 생성자가 구현되어 있지 않다면, 컴파일 에러를 일으킨다.
하지만 컴파일러가 호출할 기본 클래스의 생성자를 명시적으로 선택할 수도 있다. 다음은 그 방법이다.

```c++
class A {                   
    int age = 23;
    int money = 100;
public:    
    A() { cout << "A 클래스 생성자 1 실행" << endl; }
    A(int x) { cout << "A 클래스 생성자 2 실행 x = " << x << endl; }
    ~A() { cout << "A 클래스 소멸자 실행" << endl; }
};

class B : public A {
public:
    B() { cout << "B 클래스 생성자 1 실행" << endl; }
    B(int x) : A(x + 10) { cout << "B 클래스 생성자 2 실행 x = " << x << endl; } // A의 매개 변수를 가진 생성자에 x + 10을 전달
    ~B() { cout << "B 클래스 소멸자 실행" << endl; }
};





int main()
{
    B b(10);    // B 클래스의 생성자 2 호출
    
    return 0;
}
```
실행 결과
```c++
A 클래스 생성자 2 실행 x = 20
B 클래스 생성자 2 실행 x = 10
B 클래스 소멸자 실행
A 클래스 소멸자 실행
```

객체 b가 생성될 때, 인자가 입력되었으니 자동으로 매개 변수를 가진 생성자가 호출된다. 그리고 ' : A(x + 10) ' 문장으로 인해 컴파일러는 A의 기본 생성자를 호출하지 않고
A에 x + 10의 값을 전달할 수 있는 생성자 2를 호출한다.

다음은 이를 응용한 코드이다.

```c++
class Person {                   
    int age;
public:    
    Person(int age = 20) { this->age = age; }
    int getAge() { return age; }
};

class Man : public Person {
    int money;
public:
    Man(int age, int money) : Person(age) // 클래스 Person의 생성자에 전달받은 age의 값을 전달
    { this->money = money; }
    int getMoney() { return money; }
};

class Student : public Man {
    string name;
public:
    Student(int age, string name) : Man(age, 100) // 클래스 Man의 생성자에 age 값과 100을 전달
    { this->name = name; }
    string getName() { return name; }
};


int main()
{
    Student A(26, "Jinho");      // Student 클래스 객체 생성, age : 26

    cout << "name : " << A.getName() << endl;
    cout << "money : " << A.getMoney() << endl;
    cout << "age : " << A.getAge() << endl;
    
    return 0;
}
```
실행 결과
```c++
name : Jinho
money : 100
age : 26
```

+ ## 자식 생성자에서 부모 생성자 호출하기

자식 생성자 내에서 부모 생성자를 호출하여 부모의 멤버를 초기화할 수 있을까?
```c++
#include <iostream>
using namespace std;

class A {
	int a;
public:
	A() { cout << "A 생성자1 실행" << endl; }
	A(int a) { 
		this->a = a;
		cout << "A 생성자2 실행" << endl; 	
	}
	int getA() { return a; }
};
class B : public A {
	int b;
public:
	B() { cout << "B 생성자1 실행" << endl; }
	B(int b) {
		cout << "B 생성자2 실행" << endl;
		A::A(b); // A의 생성자2 호출
	}
};

int main(int argc, const char* argv[]) {

	B b(100); 
	cout << "a : " << b.getA() << endl;

	return 0;
}
```
실행 결과
```c++
A 생성자1 실행
B 생성자2 실행
A 생성자2 실행
a : -858993460
```
B의 입력 파라미터가 있는 생성자에 부모 클래스 A의 생성자를 호출하여 해당 생성자에 입력 값을 전달해 부모 멤버를 초기화하는 코드. 하지만 값이 제대로 전달되지 않아 이상한 값이 저장되어 있음을 알 수 있다. 생성자의 실행 순서는 A의 생성자 1이 실행된 후 B의 생성자 2가 실행되는데, 이 때 다시 A의 생성자 2가 실행된다. 실행 순으로만 따지면 별 문제없이 값이 전달되야 한다고 생각할 수 있다.

  해당 문제는 객체 생성 시 필요한 생성자 실행을 모두 마친 후 뒤늦게 A의 생성자2가 실행되어 전달된 값이 버려졌다고 생각해볼 수 있다. 즉, 생성자 실행 사이클이 끝나 객체를 이미 생성한 상태에서 A의 생성자 2를 실행하여 객체에 값이 저장되지 않음을 알 수 있다. 따라서 전달된 값은 그대로 버려져 버렸다. 따라서 생성자 실행 사이클 내에 A의 생성자2를 실행하기 위해서는 B의  생성자 2가 A의 생성자 2를 호출하도록 위에서 사용한 명시적 선택이 필요하다.











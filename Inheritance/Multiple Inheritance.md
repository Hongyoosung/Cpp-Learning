+ ## 다중 상속

다중 상속이란 상속을 통해 하나의 파생 클래스가 여러 기본 클래스를 동시에 갖는 것을 말한다. 다중 상속을 통해 여러 클래스의 기능을 가진 통합된 하나의 클래스를 만들 수 있다.


+ ## 다중 상속 선언

```c++
class A {                   
    int a;
public:
    void setA(int a) { this->a = a; }
    int getA() { return a; }
};

class B {
    int b;
public:
    void setB(int b) { this->b = b; }
    int getB() { return b; }
};

class C : public A, public B {  // 클래스 A와 B를 동시에 상속받음
public:
    void show() { cout << getA() << endl << getB() << endl; }
};

int main()
{
    C c;

    c.setA(10);
    c.setB(20);
    c.show();

    return 0;
}
```
실행 결과
```c++
10
20
```

위처럼 다중 상속을 통해 한 클래스가 여러 클래스의 기능을 사용할 수 있다.

+ ## 다중 상속 활용

```c++
class Work {                   
    int money, health;
public:
    Work() { money = 0; health = 100; }
    void doWork();
    int getMoney() { return money; }
    int getHealth() { return health; }
    void healthPlus() { health += 20; }
};
void Work::doWork() {
    money += 100; 
    health -= 10;
    cout << "일을 하기 시작합니다" << endl;
}
class Rest {
public:
    void doRest() { cout << "휴식을 취합니다" << endl; }
};

class Person : public Work, public Rest {    // Work와 Rest의 public 멤버 사용 가능
public:
    void show();
    void life();

};
void Person::show() {
    cout << "Money : " << getMoney() << endl << "Health : " << getHealth() << endl;
}
void Person::life() {
    for (int i = 0; i < 10; i++) {
        doWork();
        show();
        if (getHealth() < 50) {
            doRest();
            healthPlus();
        }
    }
}

int main()
{
    Person J;

    J.life();

    return 0;
}
```
실행 결과
```c++
일을 하기 시작합니다
Money : 400
Health : 60
일을 하기 시작합니다
Money : 500
Health : 50
일을 하기 시작합니다
Money : 600
Health : 40
휴식을 취합니다
일을 하기 시작합니다
Money : 700
Health : 50
일을 하기 시작합니다
Money : 800
Health : 40
휴식을 취합니다
일을 하기 시작합니다
Money : 900
Health : 50
일을 하기 시작합니다
Money : 1000
Health : 40
휴식을 취합니다
```

+ ## 가상 상속

다중 상속에는 다음의 문제점이 있다.
```c++
class A {                   
public:
    int a;
};

class B : public A {
public:
    int b;
};

class C : public A {
public:
    int c;
};

class D : public B, public C {
public:
    int d;
    void show(){ cout << b << endl << c << endl << d << endl; }
};
int main()
{
    D dong;

    dong.b = 20;
    dong.c = 30;
    dong.d = 10;
    dong.a = 10;   // 컴파일 에러 발생, a가 모호함


    return 0;
}
```
위와 같은 상황에서, D가 다중 상속 받는 B와 C는 모두 A를 상속받고 있다. 이 때, D 또한 A를 상속받게 되는데, 해당 과정에서 D 객체에는 B를 통해 상속받은 A 멤버의 저장 공간과
C를 통해 상속받은 A 멤버의 저장 공간이 별도로 생성된다. 따라서 D 객체에는 같은 이름의 A 멤버 저장 공간이 두 개가 생성 되며, D 클래스 내부나 D 객체를 통해 A의 멤버에
접근하려는 경우, 컴파일러가 어느 저장 공간을 처리할지 몰라
A의 멤버 a가 모호하다는 설명과 함께 컴파일 에러를 발생시킨다. 이러한 멤버 중복 문제를 해결하기 위하여 **가상 상속**을 사용한다.


+ ## 가상 상속 선언

파생 클래스를 선언할 때, 상속받을 기본 클래스의 접근 지정자 앞에 **virtual** 키워드를 붙여주어 **가상 상속**을 선언한다. 멤버 중복 문제가 발생한 위 코드에서
B, C가 A를 가상 상속하도록 수정한다.

```c++
class A {                   
public:
    int a;
};

class B : virtual public A {  // A를 가상 상속
public:
    int b;
};

class C : virtual public A {  // A를 가상 상속
public:
    int c;
};

class D : public B, public C {
public:
    int d;
    void show(){ cout << b << endl << c << endl << d << endl << a << endl; }
};
int main()
{
    D dong;

    dong.b = 20;
    dong.c = 30;
    dong.d = 10;
    dong.a = 100;   
    dong.show();


    return 0;
}
```
실행 결과

```c++
20
30
10
100
```
이 때, B와 C는 가상 기본 클래스 A를 상속받는다. 가상 상속을 받은 파생 클래스의 객체가 생성될 때, 컴파일러는 기본 클래스의 멤버 저장 공간을 할당하고, 이미 할당되어 있다면
같은 저장 공간을 공유하도록 한다. 따라서 위의 코드는 멤버 a의 저장 공간이 하나이기 때문에 모호성이 발생하지 않는다.








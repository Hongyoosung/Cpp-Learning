# 상속의 종류


상속을 하기위해서 클래스 선언부에 상속받을 클래스 앞에 접근 지정자 public을 사용하였다. 이번에는 public 이외의 접근지정자를 통하여 상속을 할 때를 알아본다.

+ ## public 상속

일반적으로 사용되는 상속, 기본 클래스를 public으로 상속받으면, 기본 클래스의 멤버들은 접근 지정 변경 없이 그대로 파생 클래스에 확장된다.

+ ## protected 상속

기본 클래스를 protected로 상속받으면, 기본 클래스의 protected, public 멤버들이 모두 protected로 변경되어 파생 클래스에 확장된다.
다음은 protected 상속의 예시이다.

```c++
class Person {                   
    int age;
protected:
    void setAge(int age) { this->age = age; }
public:
    int getAge() { return age; }
};

class Man : protected Person {
    int money = 100;
protected:
    void setMoney(int money) { this->money = money; }
public:
    int getMoney() { return money; }
    void show() { cout << getAge() << endl << getMoney(); }
};

int main()
{
    Man a;

    a.age = 10; // 컴파일 에러, age는 기본 클래스의 private 멤버임
    a.setAge(30); // 컴파일 에러, setAge는 본인 클래스나 protected로 상속받은 클래스 외부에서 사용 불가
    a.getAge(); // 컴파일 에러, protected로 상속받는 과정에서 getAge 멤버가 protected로 설정되어 외부에서 사용 불가
    a.setMoney(100); // 컴파일 에러, protected이기 때문에 외부에서 사용 불가
    a.getMoney(); // public 멤버이므로 사용 가능
    a.show();     // public 멤버이므로 사용 가능, 상속 받은 클래스 내에서는 protected 멤버 사용 가능
    
    return 0;
}
```

+ ## private 상속

기본 클래스를 private로 상속받으면, 기본 클래스의 protected, public 멤버들이 모두 private로 변경되어 파생 클래스에 확장된다.
다음은 private 상속의 예시이다.


```c++

class A {                   
    int a;
protected:
    void setA(int a) { this->a = a; }
public:
    int getA() { return a; }
};

class B : private A {
    int b;
protected:
    void setB(int b) { this->b = b; }
public:
    int getB() { return b; }
    void show() { cout << getA() << endl << getB(); }
};

class C : private B {
    int c;
protected:
    void setC(int c) { this->c - c; }
public:
    int getC() { return c; }
    void show() { cout << getA() << endl << getB() << endl << getC(); }  // 컴파일 에러, getA는 클래스 B의 private로 상속되었기 때문에 C에서 접근 불가
    void set(int x) { setA(x); setB(x); } // 컴파일 에러, 마찬가지로 접근 불가
};
```

위처럼 private 상속은 상속받은 그 클래스만 해당 멤버들을 사용할 수 있게 해주며 중첩 상속을 허용하지 않는다.



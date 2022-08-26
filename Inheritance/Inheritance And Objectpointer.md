# 상속과 객체 포인터

+ ## 업 캐스팅

자식 클래스는 부모 클래스의 모든 멤버를 가지고 있기 때문에, 이 또한 포인터로 접근이 가능하다.
이를 응용하여 부모 클래스의 객체에 자식 클래스 객체의 주소를 저장할 수 있으며 이를 **업 캐스팅(up-casting)** 이라고 한다. 업 캐스팅을 통해
자식 클래스의 객체를 부모 클래스의 객체처럼 사용할 수 있다. 단, 업 캐스팅한 부모 클래스의 포인터로는 부모 클래스의 멤버만 접근할 수 있다.

```c++
int main()
{
    Man Jinho("Jinho");
    Man* Dohyeon = &Jinho;

    Person* p = Dohyeon;     // 업 캐스팅, *p = &Jinho 와 같음

    Dohyeon->setAge(10);
    Dohyeon->setMoney(100);
    p->show();
    

    return 0;
}
```


+ ## 다운 캐스팅

업 캐스팅과 반대되는 개념으로 부모 클래스의 포인터 객체가 가리키는 객체를 자식 클래스의 포인터로 가리키는 것을 말한다. 업 캐스팅과의 차이점으로는
**명시적 타입 변환**이라는 과정이 필요하다. 

```c++
class Person {
    int age;
    int money;
public:
    void setAge(int age) { this->age = age; }
    void setMoney(int money) { this->money = money; }
    void show() {
        cout << " Age : " << age << " Money : " << money << endl;
    }
};

class Man : public Person {           // Person 멤버를 상속받는 클래스 Man
    string name;
public:
    Man(string name) { this->name = name; }
    void showAll() {
        cout << name << " ";
        show();                       // 멤버 함수에 Person의 멤버 함수 호출
    }
};




int main()
{
    Man Jinho("Jinho");
    Man* Dohyeon;

    Person* p = &Jinho;   // 업 캐스팅, 부모 클래스의 포인터 객체 p는 자식 클래스 객체 Jinho를 가리킴

    p->setAge(20);        // 부모 클래스의 멤버로 자식 클래스 객체에 영향을 줄 수 있음
    p->setMoney(100);
    p->show();

    Dohyeon = (Man*)p;    // 다운 캐스팅, 명시적 타입 변환 필요
                          // 자식 클래스의 포인터 객체 Dohyeon은 부모 클래스의 포인터 객체 p를 가리킴
                          // 따라서 Dohyeon은 다시 자식 클래스의 Jinho를 가리킴
    Dohyeon->show();

    
    return 0;
}
```
실행 결과
```c++
 Age : 20 Money : 100
 Age : 20 Money : 100
```
두 show 함수 모두 객체 Jinho의 값을 출력한다.

정리하자면 업 캐스팅은 부모의 포인터 객체로 자식의 객체를 가리키는 것이고, 다운 캐스팅은 자식의 포인터 객체로 부모의 포인터 객체를 가리키는 것이다.








## 상속이란

클래스에서 통용되는 개념으로, 간단하게 말하자면, 한 클래스가 다른 클래스의 모든 멤버를 그대로 물려받아 사용할 수 있게 하는 것이다. 이 때, 물려주는 클래스를 **부모 클래스**(또는
기본 클래스),물려받는 클래스를 **자식 클래스**(또는 파생 클래스)라고 부른다. 

어떤 클래스 a가 있다. 그리고 새로운 클래스 b를 만드는데 a의 기능을 상속받도록 설정했다. a는 부모 클래스가 되고 b는 a의 자식 클래스가 된다. b는 a에 구현된 모든
멤버를 활용할 수 있지만, a는 b에 새로 구현된 멤버를 사용할 수 없다. 즉, 쌍방통행이 불가능하다. 한 클래스가 여러 클래스의 기능을 상속받을 수도 있다. 
일반적인 상속의 의미와 달리, 어떤 클래스가 다른 클래스에 기능을 상속한다 할 때, 자신의 기능을 모두 복사해서 전달하기 때문에 본인 클래스에는 아무 영향을 끼치지 않는다.

이러한 클래스의 계층적 구조 표현을 통해 중복된 코드를 줄이고, 재사용성을 높여주며 프로그램의 유지보수를 수월하게 만들어주는 상속은 객체 지향의 중요한 특성 중 하나다.


+ ## 상속 선언

클래스가 어떤 클래스의 기능을 상속받을지 선언하는 법이다.

```c++

class Person {
public:
    int age = 10;
};
class Man : public Person {
public:
    // Person 클래스를 상속 받은 Man 클래스 선언
    int money = 100;
    int getAge() { return age; }
    

};


class Work : public Man {
    // Man 클래스를 상속 받는 Work 클래스 선언
    int getMoney() { return money; }
    int getAge() { return age; }
};
```
위의 경우를 보면 이중 상속이 되어도 상위 클래스의 멤버를 모두 활용할 수 있음을 알 수 있다. 또한, 상속받은 클래스의 private 멤버에는 직접 접근하지 못한다.

+ ## 상속 멤버 호출

다음은 상속받은 클래스의 멤버를 실제로 활용하는 예이다.
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
    Man J("Jinho");              // 파생 클래스 객체 생성

    J.setAge(26);
    J.setMoney(100);

    J.showAll();

    return 0;
}
```
실행 결과
```c++
Jinho  Age : 26 Money : 100
```

Man 클래스의 객체가 상속받은 Man 클래스의 멤버를 이용하는 모습이다. 또한, 클래스 내의 멤버 구현에서도 상속받은 클래스의 멤버를 사용할 수 있다는 것을 알 수 있다.
단, 상속받은 클래스의 private 멤버는 오직 멤버 함수로만 접근이 가능하다.







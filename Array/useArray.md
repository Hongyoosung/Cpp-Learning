## 배열이란

배열은 동일한 맥락에 속한 데이터를 저장할 공간을 여러 개 할당하는 것이다. 동일한 맥락이란 성적, 나이 등 분류할 때 같은 것끼리 뭉쳐질 수 있는 것을 의미한다. 배열의 사용 예를 들면 학생 100명의 성적을 저장할 공간을 할당할 때, 변수 100개를 일일이 선언할 필요 없이 배열 변수를 이용하여 한 번에 100개의 저장공간을 선언할 수 있다.
```c++
#include<iostream>
using namespace std;

int main()
{
    int score[100]; //배열 변수의 선언

    score[0] = 80; //배열의 첫 번째 공간에 정수 80 저장
    score[1] = 90; //배열의 두 번째 공간에 정수 90 저장

    cout << score[0] << endl;
    cout << score[1] << endl;

    return 0;
}
```
실행 결과
```c++
80
90
```

위의 예는 정수형 저장공간 100개를 할당하는 배열 score를 선언하고 각 저장공간에 데이터를 입력한 모습이다. 배열은 선언 시 인덱스라고 불리는 [ ]에 의해 크기가 결정되며 만약 배열로 20개의 실수형 저장공간을 할당 시 배열의 자료형은 double, [ ]안 숫자는 20이 된다. 선언을 통해 저장공간 20개가 할당되면, 이후 각 저장공간의 구분도 인덱스에 의해 이루어진다. 배열의 인덱스는 0부터 시작해 1씩 증가하며, 따라서 마지막 저장공간의 인덱스는 항상 선언 시 적은 인덱스 값의 -1 이다. 위의 예로 살펴보면, 100개의 정수형 저장공간을 할당 후 첫 번째 저장공간의 인덱스는 0, 두 번째 저장공간의 인덱스는 1이므로 마지막 저장공간의 인덱스는 99인 것을 유추할 수 있다. 배열의 각 저장공간은 그 배열의 요소라고 불리우며 위의 배열 score는 100개의 요소를 가진다고 할 수 있다.

정리하자면, 배열을 처음 선언 시에 사용한 인덱스는 '기호'로서 저장공간의 개수를 뜻하지만, 선언 이후의 인덱스는 ‘연산자’로 그 배열의 몇 번째 변수인지 표현하는 데에 사용된다. 
```c++
#include<iostream>
using namespace std;

int main()
{
    int score[5] = {1, 2, 3, 4, 5};

    cout << score[0] << endl;
    cout << score[1] << endl;

    return 0;
}
```
실행 결과
```c++
1
2
```
위처럼 배열 또한 선언과 동시에 초기화가 가능하다. 이 때, 만약 몇 개만 초기화했을 시, 초기화되지 않은 저장공간에는 0이 저장된다. 단, 초기화를 아예 하지 않고 배열을 출력하려하면, 이상한 값이 저장되어있는 것을 알 수 있다.
```c++
#include<iostream>
using namespace std;

int main()
{
    int score[] = {1, 2, 3, 4, 5};

    cout << score[0] << endl;
    cout << score[1] << endl;

    return 0;
}
```
배열 선언 시 인덱스를 작성하지 않고 초기화를 하면, 프로그램 실행 후 자동으로 초기화된 만큼의 저장공간이 할당된다. 따라서 이는 위의 int score[5]와 동일하다.



## 배열과 반복문
배열은 그 특성상 주로 반복문과 함께 쓰인다. 반복문에 사용되는 변수를 배열의 인덱스로 활용해 배열 안의 모든 요소를 손쉽게 활용할 수 있다.
```c++
#include <iostream>
using namespace std;

int main()
{
    int score[10];
    int num = 1;

    for (int i = 0; i < 10; i++) { //반복문을 이용해 배열의 모든 요소에 데이터를 입력
        score[i] = num;
        num++;
    }

    for (int i = 0; i < 10; i++) { //반복문을 이용해 배열의 모든 요소를 출력
        cout << score[i] << " ";
    }

    return 0;
}
```
실행 결과
```c++
1 2 3 4 5 6 7 8 9 10
```

## 문자열 배열
배열을 통해 문자열을 저장할 수 있다. 우선 문자형 배열을 선언 후 내부에 " "를 이용해 문자열을 작성한다. 문자 하나가 저장공간 하나를 차지하므로, 만약 Hello를 저장하고 싶으면 5개의 문자형 저장공간을 갖는 배열을 선언하면 된다고 생각할 수 있지만, 프로그램에서는 문자열의 끝을 알려주는 특수한 문자 '\0'가 마지막에 저장되어 총 6개의 저장공간이 필요하다.
```c++
#include <iostream>
using namespace std;

int main()
{
    char a[6] = "Hello"; //문자열은 초기화 시 {}를 사용하지 않아도 된다.
    char b[6] = { 'W', 'o', 'r', 'l', 'd' }; //' '를 이용해 문자 하나하나를 초기화할 수도 있다.

    for (int i = 0; i < 6; i++) {
        cout << a[i];
    }

    cout << endl;

    a[3] = '\0'; //배열의 4번 째 칸에 끝마침 문자 저장
    for (int i = 0; i < 6; i++) {
        cout << a[i];
    }

    cout << endl;

    b[2] = '\n'; //배열의 3번 째 칸에 줄띄움 문자 저장
    for (int i = 0; i < 6; i++) {
        cout << b[i];
    }

    return 0;
}
```
실행 결과
```c++
Hello
Helo
Wo
ld
```
위의 예를 보면 알 수 있듯, 끝마침 문자는 해당 저장공간에 빈 칸을 저장한다. 배열은 일반 변수들의 집합이므로 일반 변수의 특성을 그대로 갖고 있다. 따라서 입력 순서에 따른 데이터 덮어씌우기가 이루어져 기존에 저장되어있는 데이터는 소멸하고 새로 저장되는 데이터가 입력되는 것을 알 수 있다. 


## sizeof()
sizeof() 연산자는 ()안 변수가 갖는 저장공간의 크기를 바이트 단위로 알려준다. 예를 들어 정수형 변수 a와 문자형 변수 b가 있을 때, sizeof(a)와 sizeof(b)를 출력해보면 각 4와 1을 출력하게 된다. 이는 배열에도 활용이 가능하며, 정수형 저장공간 10개를 갖는 배열 array가 있다고 하자. sizeof(array)는 출력 시 40을 출력한다. 이는 정수형 저장공간 하나가 4byte이고, 이러한 공간이 10개이므로 4 x 10 총 40을 표현하게 된다. 
```c++
#include <iostream>
using namespace std;

int main()
{
    int a = 10;

    cout << "a의 크기 : " << sizeof(a) << endl;

    int array1[10];
    double array2[5];

    cout << "배열 array1의 크기 : " << sizeof(array1) << endl;
    cout << "배열 array2의 크기 : " << sizeof(array2) << endl;

    return 0;
}
```
실행 결과
```c++
a의 크기 : 4
배열 array1의 크기 : 40
배열 array2의 크기 : 40
```

이러한 특성으로 인해 배열의 sizeof 값에 그 배열의 자료형의 sizeof값을 나누면 해당 배열의 요소의 수를 알 수 있다는 점이 있다.
```c++
#include <iostream>
using namespace std;

int main()
{
    int a[100];
    int size1 = sizeof(a);
    int size2 = sizeof(int);
    int size3 = sizeof(a) / sizeof(int);

    cout << "배열 a의 크기 : " << size1 << endl;
    cout << "배열 a의 자료형 크기 : " << size2 << endl;
    cout << "배열 a의 요소 개수 : " << size3 << endl;
 

    return 0;
}
```
실행 결과
```c++
배열 a의 크기 : 400
배열 a의 자료형 크기 : 4
배열 a의 요소 개수 : 100
```
위의 예에서는 새로운 변수를 선언해 sizeof()값을 저장하고 해당 변수를 출력하는 방식을 사용했지만, sizeof()의 값이 변수에도 저장될 수 있음을 보여주기 위한 것일 뿐, 출력문에 직접 작성해도 문제가 없다.

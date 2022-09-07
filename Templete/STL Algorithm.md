## STL 알고리즘

> STL 알고리즘은 전역 함수로서, STL 컨테이너 클래스의 멤버 함수가 아니며 템플릿으로 작성되어 있다. STL 알고리즘 함수는 iterator와 함께 작동한다.
> STL 알고리즘 중 하나인 sort() 함수는 정렬의 역할을 하며 두 개의 매개 변수를 가지고 있다. 첫 번째 매개 변수에는 정렬을 시작할 원소에 대한 iterator 주소를,
> 두 번째 매개 변수에는 마지막 원소 다음의 iterator 주소를 입력해 정렬을 시작한다.

```c++
vector<int> v;
``
sort(v.begin(), v.begin()+3);  // 벡터의 시작 원소부터 3개의 원소를 정렬
sort(v.begin()+2, v.begin()+5);// 벡터의 3번 째 원소에서 5번 째 원소까지 3개의 원소를 정렬
sort(v.begin(), v.end());      // 벡터의 전체 원소를 정렬
```
v.begin()뒤의 +에 오는 정수를 햇갈리지 않도록 주의한다. 정수는 벡터의 인덱스를 의미하며 두 번째 매개 변수는 정렬할 마지막 원소의 다음 원소이다. 
두 번째 줄의 경우, 첫 매개 변수가 begin()+2 이므로 벡터의 인덱스 [2]인 3번 째 원소이며 두 번째 매개 변수 begin()+5의 인덱스 [5]는 정렬의 마지막 다음이므로 
마지막은 인덱스 [4]이다. 따라서 벡터의 5번 째 원소를 정렬의 마지막으로 설정한다.

#

+ ### sort() 함수를 이용한 vector 소팅

다음은 정수형 벡터에 값을 저장하고 sort()를 사용하여 정렬하는 코드이다.

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, const char* argv[]) {

	vector<int> v;  // 정수 벡터 v 생성
  
  cout << "정수를 입력하세요" << endl;
	for (int i = 0; i < 5; i++) { // 키보드로 부터 입력받은 5개의 정수를 벡터에 저장
		int n;
		cin >> n;
		v.push_back(n);
	}

	sort(v.begin(), v.end()); // 벡터 내 모든 원소를 오름차순으로 정렬, 벡터의 원소 순서를 변경

	vector<int>::iterator it; // 벡터 내 원소를 탐색하는 iterator 변수 it 생성

  cout << "정렬 결과" << endl;
	for (it = v.begin(); it != v.end(); it++)  // 벡터 내 모든 원소를 출력
		cout << *it << ' ';
	
	cout << endl;

	return 0;
}
```
실행 결과
```c++
정수를 입력하세요
5
2
4
3
1
정렬 결과
1 2 3 4 5
```




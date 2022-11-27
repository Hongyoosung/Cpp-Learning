## list 컨테이너

 리스트는 데이터의 순서와 관련된 시퀀스 컨테이너로, 위치를 통해 데이터의 검색과 저장이 가능한 자료구조이다.
 연속된 메모리를 사용하며, 데이터의 삽입, 삭제에 특화된 컨테이너이다. 따라서 연속되지 않은 벡터보다 데이터의 삽입과 삭제가 빠르다.
 
 #
 
 ### 주요 멤버 함수
 
 
반복자

+ **begin()**: beginning iterator 반환
+ **end()**: end iterator 반환


삽입

+ **push_front(element)**: 리스트 맨 앞에 원소 추가
+ **push_back(element)**: 리스트 맨 뒤에 원소 추가
+ **insert(iterator, element)**: iterator가 가리키는 부분의 앞에 원소 추가
+ **splice(iterator, list)** : 해당 반복자의 위치에 리스트의 모든 요소를 옮김.


삭제

+ **pop_front()**: 리스트 맨 앞의 원소 삭제
+ **pop_back()**: 리스트 맨 뒤의 원소 삭제
+ **erase(iterator)**: iterator가 가리키는 부분의 원소 삭제


조회

+ *iterator: iterator가 가리키는 원소에 접근
+ **front()**: 첫번째 원소 반환
+ **back()**: 마지막 원소 반환

기타

+ **empty()**: 리스트가 비어있는지 여부
+ **size()**: 리스트 사이즈 반환


다음은 list의 splice 등의 멤버 함수를 이용하는 예이다.

```c++
#include <iostream>
#include <list>

using namespace std;

int main(int argc, const char* argv[]) {
	list<int> l1, l2;
	list<int>::iterator it;

	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	cout << "l1 : ";
	for (it = l1.begin(); it != l1.end(); it++)
		cout << *it << " ";
	cout << endl;

	l2.push_back(99);
	l2.push_back(99);
	l2.push_back(99);

	cout << "l2 : ";
	for (it = l2.begin(); it != l2.end(); it++)
		cout << *it << " ";
	cout << endl;

	it = l1.begin();
	it++;
	it++;

	cout << endl << "splice" << endl << endl;
	l1.splice(it, l2);

	cout << "l1 : ";
	for (it = l1.begin(); it != l1.end(); it++)
		cout << *it << " ";
	cout << endl;

	cout << "l2 : ";
	for (it = l2.begin(); it != l2.end(); it++)
		cout << *it << " ";
	cout << endl;

	return 0;
}
```







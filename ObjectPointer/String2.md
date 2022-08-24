# string을 통한 문자열 사용 2


+ ### 문자열 치환
```c++
string a = "Hello", b = "world";
a = b;
cout << a << endl; // world 출력
```

+ ### 문자열 비교

**compare() 함수**를 통해 두 문자열을 비교한다. 문자열이 서로 같을 시 0, 비교되는 문자열보다 사전 순으로
앞에 오면 양수, 뒤에 오면 음수를 반환한다.
```c++
int main(int argc, const char* argv[]) {

	string a = "Jinho", b = "Dohyeon";

	int c = a.compare(b);

	if (c == 0) cout << "두 문자열은 같다" << endl;
	else if (c > 0) cout << b << "이(가) 더 앞에 온다" << endl;
	else cout << a << "이(가) 더 앞에 온다" << endl;

	return 0;
}
```
실행 결과
```c++
Dohyeon이(가) 더 앞에 온다
```

+ ### 문자열 연결
```c++
int main(int argc, const char* argv[]) {

	string a = "Hi";
	a.append(" Wow");

	cout << a << endl; // Hi Wow 출력

	return 0;
}
```
또는 +, += 를 이용하여 더 쉽게 작성이 가능하다.
```c++
int main(int argc, const char* argv[]) {

	string a = "Hi";
	string b = " Wow";
	string c = a + b;

	cout << c << endl; // Hi Wow 출력

	return 0;
}
```

+ ### 문자열 삽입

기존에 있는 문자열에서 원하는 위치에 새로운 문자열을 추가할 수 있다.

```c++
int main(int argc, const char* argv[]) {

	string a = "i can it ";
	a.insert(6, " do ");   // 문자열 삽입, 기존의 문자는 뒤로 밀리며 공백은 덮어 씌어진다.

	cout << a << endl;

	a.replace(7, 11, "study"); // 7 ~ 11 자리의 문자열을 "study"로 교체

	cout << a << endl;

	return 0;
}
```
실행 결과
```c++
i can  do it
i can  study
```
replace 함수에서 만약 교체되는 자리의 범위보다 문자열이 더 클 경우, 처음 시작되는 자리로부터
해당 문자열이 차례로 덮어 씌어진다. 위의 경우에서 범위가 7 ~ 11이 아닌, 7 ~ 8일 때도, 뒤의 문자가
덮어 씌어져 같은 결과를 출력한다.

+ ### 문자열의 길이와 용량
```c++
int main(int argc, const char* argv[]) {

	string a = "Hello";

	int length = a.length(); // a에 저장된 문자열의 길이, Hello의 문자 개수는 5이다.
	int size = a.size();     // length()와 동일
	int capacity = a.capacity();  // a의 현재 용량

	cout << length << endl << size << endl << capacity << endl;
	

	return 0;
}
```
실행 결과
```c++
5
5
15
```
문자열의 길이와 문자열의 인덱스는 엄연히 다른 값이다. 길이는 1부터 세며, 문자열의 인덱스는 0부터 시작한다.

+ ## 문자열 삭제

```c++
int main(int argc, const char* argv[]) {

	string a = "Hello";

	a.erase(0, 3); // 특정 범위의 문자만 삭제
	cout << a << endl;

	a.clear(); //문자열을 모두 
	cout << a << endl;
	

	return 0;
}
```
실행 결과
```c++
lo

```

+ ### 문자열 추출

문자열의 일부분을 추출하여 저장하는 명령어

```c++
int main(int argc, const char* argv[]) {

	string a = "Hello World";
	string b = a.substr(6, 10); // 6 ~ 10번째 까지의 문자열을 복사
	string c = a.substr(3); // 3번째부터 끝까지의 문자열 복사

	cout << a << endl << b << endl << c << endl;

	return 0;
}
```
실행 결과
```c++
Hello World
World
lo World
```

+ ### 문자열 검색

문자열 내에 특정 문자 또는 문자열이 존재하는지 검색할 수 있는 기능. find() 함수는 검색할 문장을
발견했을 시 해당 문장이 문자열에서 몇 번째 부터 시작하는지를 반환하고, 발견하지 못하면 -1을 반환한다.
```c++

string a = "hello HELLO world WORLD";

int num = a.find("world"); // world가 시작되는 지점을 저장 : 12
num = a.find("WORLD", num ); // 12번 째부터 검색 : 18
num = a.find("asd"); // -1 반환

```

+ ### 문자열에서 각 문자별로 다루기

```c++

string a = "hello";

char a1 = a.at(2); // 인덱스 2(3번 째)의 문자를 반환
char a2 = a[3]; // 위와 동일한 표현이지만 해당 위치의 문자를 변경 가능

a[3] = 'h'; // 인덱스 3의 l을 h로 변경


```
+ ### 문자열을 숫자로 변환

문자열을 연산에 활용할 수 있는 숫자로 변환하는 기능이다. 물론 문자열은 수여야 한다.

```c++
string age = "25";

int n = stoi(age); // 문자열 25를 정수 형태의 25로 저장
```

+ ### 문자 변환

문자열에서 각 문자를 다룰 수 있도록 도와주는 <locale> 헤더파일을 사용하여 그 안의 함수를 활용하는 예이다.

```c++
string a = "hello";

a[0] = toupper(a[0]); //소문자를 대문자로 변환
cout << a << endl; // Hello 출력

cout << isdigit(a[0]) << endl; // 숫자일 경우 1, 아닐 경우 0 반환
cout << isalpha(a[0]) << endl; // 문자일 경우 1, 아닐 경우 0 반환
```
	
	
















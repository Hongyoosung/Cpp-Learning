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







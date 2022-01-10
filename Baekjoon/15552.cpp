#include <iostream>

// 입출력 방식이 느리면 여러 줄을 입력받거나 출력할 때 시간초과가 날 수 있음을 알려주는 문제

int main() {
	int t, a, b;

	std::cin.tie(NULL);
	/*
	결론부터 말하자면 cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	기본적으로 cin과 cout은 묶여있고 묶여있는 스트림들은 한 스트림이 다른 스트림에서 각 IO 작업을 진행하기 전에 자동으로 버퍼를 비워줌을 보장합니다.
	아래의 코드로 예시를 들어보겠습니다.

	cout << "이름을 입력하세요: ";
	cin >> name;

	위 경우 cin과 cout이 묶여있기 때문에, 이름을 입력하기 전에 "이름을 입력하세요: " 구문이 먼저 출력될 것입니다.
	하지만, cin.tie(null); 코드를 추가한다면 cin과 cout의 묶음이 풀리면서 "이름을 입력하세요: "; 구문이 먼저 출력되지도 않았는데 먼저 이름을 입력을 받는 경우가 발생할 수 있습니다.
	이는 cout이 기본적으로 버퍼에 추가되고 바로 비워지지 않기 때문입니다. (출력 명령을 내리거나 버퍼가 가득 찼을 경우에만 버퍼를 비우고 출력합니다.)
	따라서, cin.tie(null); 코드를 추가했고 name을 입력받기 전에 "이름을 입력하세요: " 구문을 먼저 보고 싶다면 cout으로 "이름을 입력하세요: "를 출력할 때 버퍼를 비워줘야 합니다.
	*/

	std::ios::sync_with_stdio(false);
	/*
	ios_base::sync_with_stdio(false);의 장점
	ios_base::sync_with_stdio 구문은 c의 stdio와 cpp의 iostream을 동기화시켜주는 역할을 하는데, 이 때 iostream과 stdio의 버퍼를 모두 사용하기 때문에 딜레이가 발생합니다.
	따라서, ios_base::sync_with_stdio(false); 코드를 작성해줌으로써 동기화를 비활성화시켜줍니다.
	이로 인해, c++만의 독립적인 버퍼가 생성되어 c의 버퍼와 병행하여 사용할 수 없게 되지만, 사용하는 버퍼의 수가 줄어들었기 때문에 실행 속도는 빨라지게 됩니다.
	알고리즘 문제를 풀 때는 대부분 싱글 쓰레드 환경이기 때문에 해당 코드를 추가해줘도 문제가 발생하지 않을 확률이 높습니다.

	ios_base::sync_with_stdio(false);의 단점
	동기화된 C++ 버퍼의 경우 thread-safe하기 때문에 모든 IO의 순서가 예상한 것과 정확히 일치함을 보장할 수 있습니다.
	-> (output from different threads may interleave, but you get no data races).
	하지만, ios_base::sync_with_stdio(false); 코드를 추가함으로 인해 동기화가 비활성화됐기 때문에 멀티 쓰레드 환경에서는 출력 순서를 보장할 수 없습니다.
	그리고 버퍼가 분리되었기 때문에 cin과 C의 scanf, gets, getchar 등을 같이 사용하면 안되고 
	cout과 C의 printf, puts, putchar 등을 같이 사용하면 엉뚱한 결과가 나올 확률이 높기 때문에 사용하면 안 됩니다.
	*/

	std::cin >> t;

	for (int i = 0; i < t; i++) {
		std::cin >> a >> b;
		std::cout << a + b << "\n"; // endl 쓰면 시간 초과됨

		// endl 쓰려면
	}
}
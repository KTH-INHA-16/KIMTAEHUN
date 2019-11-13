#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
using namespace std;
char l[300001];
char r[300001];
//좌우를 받기위한 배열
int ln = 0;
int rn = 0;
//좌우의 길이를 표시
char a[31];
char ar[31];
//ar은 a의 역방향을 보관하기 위해 사용
char b[300001];
// 총길이
int n, m;
//n은 a의 길이m은 b의 길이
bool check(int where) {
	char *stack = l;
	int len = ln;
	char *str = ar;
	//좌측일때 사용
	if (where == 1) {
		stack = r;
		len = rn;
		str = a;
		//우측일때 사용
	}
	if (len - n < 0) {
		return false;
		//길이가 a보다 작을시
	}
	for (int i = 0; i < n; i++) {
		if (stack[len - i - 1] != str[i]) {
			return false;
		}
		//ar이랑 같은지 검사
		//스택에서 빠져나올때는 순서가 역으로 바뀐다.
	}
	if (where == 0) {
		ln -= n;
		//좌측의 인덱스를 감소
	}
	else {
		rn -= n;
		//우측의 인덱스를 감소
	}
	return true;
}
int main() {
	scanf("%s", a);
	n = strlen(a);
	//a의길이를 저장
	for (int i = 0; i < n; i++) {
		ar[i] = a[n - i - 1];
	}
	//비교함수에서의 배열을 뒤집어서 저장
	scanf("%s", b);
	m = strlen(b);
	// b의 길이
	int left = 0;
	int right = m - 1;
	int where = 0;
	//좌측이 맞으면 우측으로 바꿔주기위한 변수
	while (left <= right) {
		if (where == 0) {
			l[ln++] = b[left++];
			//좌측 비교할 것들 스택에 추가
		}
		else {
			r[rn++] = b[right--];
			//우측 비교할것들 스택에 추가
		}
		if (check(where)) {
			where = 1 - where;
			//검사 하기 및 비교해야될 방향 바꾸기
			//true이면 방향 전환
			//false이면 그대로 가기
		}
	}
	for (int i = ln - 1; i >= 0; i--) {
		r[rn++] = l[i];
		check(1);
		//우좌측에 있는것을 우측으로 옮기는 과정
		//계속 검사
	}
	for (int i = rn - 1; i >= 0; i--) {
		putchar(r[i]);
		//출력
	}
	printf("\n");
	return 0;
}
#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
using namespace std;
char l[300001];
char r[300001];
//�¿츦 �ޱ����� �迭
int ln = 0;
int rn = 0;
//�¿��� ���̸� ǥ��
char a[31];
char ar[31];
//ar�� a�� �������� �����ϱ� ���� ���
char b[300001];
// �ѱ���
int n, m;
//n�� a�� ����m�� b�� ����
bool check(int where) {
	char *stack = l;
	int len = ln;
	char *str = ar;
	//�����϶� ���
	if (where == 1) {
		stack = r;
		len = rn;
		str = a;
		//�����϶� ���
	}
	if (len - n < 0) {
		return false;
		//���̰� a���� ������
	}
	for (int i = 0; i < n; i++) {
		if (stack[len - i - 1] != str[i]) {
			return false;
		}
		//ar�̶� ������ �˻�
		//���ÿ��� �������ö��� ������ ������ �ٲ��.
	}
	if (where == 0) {
		ln -= n;
		//������ �ε����� ����
	}
	else {
		rn -= n;
		//������ �ε����� ����
	}
	return true;
}
int main() {
	scanf("%s", a);
	n = strlen(a);
	//a�Ǳ��̸� ����
	for (int i = 0; i < n; i++) {
		ar[i] = a[n - i - 1];
	}
	//���Լ������� �迭�� ����� ����
	scanf("%s", b);
	m = strlen(b);
	// b�� ����
	int left = 0;
	int right = m - 1;
	int where = 0;
	//������ ������ �������� �ٲ��ֱ����� ����
	while (left <= right) {
		if (where == 0) {
			l[ln++] = b[left++];
			//���� ���� �͵� ���ÿ� �߰�
		}
		else {
			r[rn++] = b[right--];
			//���� ���Ұ͵� ���ÿ� �߰�
		}
		if (check(where)) {
			where = 1 - where;
			//�˻� �ϱ� �� ���ؾߵ� ���� �ٲٱ�
			//true�̸� ���� ��ȯ
			//false�̸� �״�� ����
		}
	}
	for (int i = ln - 1; i >= 0; i--) {
		r[rn++] = l[i];
		check(1);
		//�������� �ִ°��� �������� �ű�� ����
		//��� �˻�
	}
	for (int i = rn - 1; i >= 0; i--) {
		putchar(r[i]);
		//���
	}
	printf("\n");
	return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Person
{
	int age;
	string name;
	int join;
};

bool cmp(const Person &u, const Person &v)
{
	if (u.age == v.age)
		return u.join < v.join;
	else
		return u.age < v.age;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	Person *a=new Person[n];
	int count = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].age;
		cin >> a[i].name;
		a[i].join = count++;
	}

	sort(a, a + n, cmp);
	//stable_sort(a, a + n, cmp);
	//���� ���� �ִ� ��쿡 �����ϱ� ���� ������
	//�����Ǵ� ���� �˰��� ->stable sorting

	for (int i = 0; i < n; i++)
	{
		printf("%d %s\n",a[i].age,a[i].name.c_str());
	}

}
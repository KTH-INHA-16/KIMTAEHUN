#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Person
{
	int g;
	int e;
	int m;
	string name;
};

bool cmp(const Person &u, const Person &v)
{
	if (u.g == v.g)
	{
		if (u.e == v.e)
		{
			if (u.m == v.m)
				return u.name < v.name;
			else
				return u.m > v.m;
		}
		else
			return u.e < v.e;
	}
	else
		return u.g > v.g;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;

	Person *a = new Person[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].name>>a[i].g>>a[i].e>>a[i].m;
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", a[i].name.c_str());
	}
}
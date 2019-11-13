#include <iostream>
using namespace std;

int main(void)
{
	int m, d;
	int dcount=0;
	cin >> m >> d;
	/*
		if (a > 1)
	{
		for (int i = 0; i < a-1; i++)
		{
			sum += year[i];
		}
	}//year을 배열로 해 각 달에 해당하는 날짜 추가
	*/
	int mcount = 1;
	if (m >= 2)
	{
		while (mcount != m)
		{
			if (mcount == 1)
			{
				dcount += 31;
				mcount++;
			}
			else if (mcount == 2)
			{
				dcount += 28;
				mcount++;
			}
			else if (mcount == 3)
			{
				dcount += 31;
				mcount++;
			}
			else if (mcount == 4)
			{
				dcount += 30;
				mcount++;
			}
			else if (mcount == 5)
			{
				dcount += 31;
				mcount++;
			}
			else if (mcount == 6)
			{
				dcount += 30;
				mcount++;
			}
			else if (mcount == 7)
			{
				dcount += 31;
				mcount++;
			}
			else if (mcount == 8)
			{
				dcount += 31;
				mcount++;
			}
			else if (mcount == 9)
			{
				dcount += 30;
				mcount++;
			}
			else if (mcount == 10)
			{
				dcount += 31;
				mcount++;
			}
			else if (mcount == 11)
			{
				dcount += 30;
				mcount++;
			}
		}
		dcount += d;
	}
	else
		dcount += d;
	dcount %= 7;
	if (dcount == 1)
		cout << "MON";
	else if (dcount == 2)
		cout << "TUE";
	else if (dcount == 3)
		cout << "WED";
	else if (dcount == 4)
		cout << "THU";
	else if (dcount == 5)
		cout << "FRI";
	else if (dcount == 6)
		cout << "SAT";
	else if(dcount ==0)
		cout << "SUN";
}
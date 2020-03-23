#include <iostream>
#include <string>
using namespace std;

string S, subS;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); //cin 실행속도 향상
	getline(cin, S);
	getline(cin, subS);
	if (subS.size() > S.size())
		cout << 0 << "\n";
	else
	{
		int result = 0;
		for (int i = 0; i < S.size() - subS.size() + 1; i++)
		{
			bool same = true;
			for (int j = 0; j < subS.size(); j++)
				if (S[i + j] != subS[j])
				{
					same = false;
					break;
				}
			if (same)
			{
				result++;
				i += subS.size() - 1;
			}
		}
		cout << result << "\n";
	}
	return 0;
}


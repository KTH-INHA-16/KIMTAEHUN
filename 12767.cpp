#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Node
{
	int val;
	Node *left;
	Node *right;
	//노드의 좌측 우측 그리고 값들 설정
	Node()
	{
		val = 0;
		left = NULL;
		right = NULL;
	}
};

string preorder(Node *root)
//프리오더 방식으로 계산
{
	string ans = "";
	ans += "V";
	//루트 추가(V)
	if (root->left)
		//인오더 방식 좌측부터 계산
	{
		ans += "L";
		//맨처음의 좌측
		ans += preorder(root->left);
		//왼쪽의 왼쪽 계산 후에 재귀로 인한 오른쪽 순환
		ans += 'l';
		//조그만한 l로 좌측이 끝났다는 것을 알림(조그만한 좌측이든 상관없이)
	}
	if (root->right)
		//루트의 우측 좌측을 돌던 방식이랑 같음
		//결국은 인오더 방식으로 계산
	{
		ans += 'R';
		ans += preorder(root->right);
		ans += 'r';
	}
	ans += "v";
	//종료 소문자(v)추가
	return ans;
	//답 반환
}

void remove(Node *root)
{
	if (root->left)
	{
		remove(root->left);
	}
	if (root->right)
	{
		remove(root->right);
	}
	delete root;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	set<string>s;
	//set을 이용해 같은 크기 같은 내용값이 들어가는것을 방지
	for (int k = 0; k < n; k++)
	{
		vector <int> a(m);
		for (int i = 0; i < m; i++)
		{
			cin >> a[i];
		}
		Node* root = new Node;
		root->val = a[0];
		for (int i = 1; i < m; i++)
		{
			Node* cur = root;
			while (true)
			{
				if (cur->val > a[i])
				{
					if (cur->left == NULL)
					{
						cur->left = new Node;
						cur->left->val = a[i];
						break;
					}
					else
					{
						cur = cur->left;
					}
				}
				else if (cur->val < a[i])
				{
					if (cur->right == NULL)
					{
						cur->right = new Node;
						cur->right->val = a[i];
						break;
					}
					else
						cur = cur->right;
				}
				else
					break;
			}
		}
		s.insert(preorder(root));
		remove(root);
	}
	cout << s.size() << '\n';
}
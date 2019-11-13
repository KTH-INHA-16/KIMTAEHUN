#include <set>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	node()
	{
		left = NULL;
		right = NULL;
		data = 0;
	}
};

string preorder(node* root)
{
	string ans = "";
	ans += "V";
	if (root->left)
	{
		ans += "L";
		ans += preorder(root->left);
		ans += 'l';
	}
	if (root->right)
	{
		ans += "R";
		ans += preorder(root->right);
		ans += "r";
	}
	ans += 'v';
	return ans;
}

void remove(node* root)
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

int main()
{
	int n, m;
	cin >> n >> m;
	set <string>s;
	for (int i = 0; i < n; i++)
	{
		vector <int> a(m);
		for (int j = 0; j < m; j++)
		{
			cin >> a[j];
		}
		node* root = new node;
		root->data = a[0];
		for (int j = 1; j < m; j++)
		{
			node* cur = root;
			while (true)
			{
				if (cur->data > a[j])
				{
					if (cur->left == NULL)
					{
						cur->left = new node;
						cur->left->data = a[j];
						break;
					}
					else
					{
						cur = cur->left;
					}
				}
				else if (cur->data < a[j])
				{
					if (cur->right == NULL)
					{
						cur->right = new node;
						cur->right->data = a[j];
						break;
					}
					else
					{
						cur = cur->right;
					}
				}
				else
				{
					break;
				}
			}
		}
		s.insert(preorder(root));
		remove(root);
	}
	cout << s.size() << '\n';
}
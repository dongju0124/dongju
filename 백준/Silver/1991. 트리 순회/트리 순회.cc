#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	Node* left;
	Node* right;
	char value;
};

void pre(Node* root)
{
	if (root->value == '.') return;
	cout << root->value;
	pre(root->left);
	pre(root->right);
}

void in(Node* root)
{
	if (root->value == '.') return;
	in(root->left);
	cout << root->value;
	in(root->right);
}

void post(Node* root)
{
	if (root->value == '.') return;
	post(root->left);
	post(root->right);
	cout << root->value;
}

int main()
{
	int N;

	cin >> N;
	
	Node arr[255];
	arr['.'].value = '.';

	for (int i = 0; i < N; i++)
	{
		char a, b, c;

		cin >> a >> b >> c;

		arr[a].left = &arr[b];
		arr[a].right = &arr[c];
		arr[a].value = a;

	}
	
	pre(&arr['A']);
	cout << "\n";
	in(&arr['A']);
	cout << "\n";
	post(&arr['A']);
}
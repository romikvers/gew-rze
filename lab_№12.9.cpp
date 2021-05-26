// lab_№12.9.cpp 
//
// Визначити кількість елементів бінарного дерева / бінарного дерева пошуку,
// батьківські до яких мають значення k.
/*

Реалізувати наступні дії:
1) створення бінарного дерева із наперед вказаною кількістю елементів;
2) вивід бінарного дерева / бінарного дерева пошуку на екран (з виділенням біжучого
елемента);
3) створення бінарного дерева пошуку із наперед вказаною кількістю елементів;
4) добавлення нового елемента із збереженням порядку (для побудови бінарного
дерева пошуку);
5) збалансування бінарного дерева пошуку;
6) видалення елемента бінарного дерева / бінарного дерева пошуку, який не має
дочірніх вузлів;
7) видалення елемента бінарного дерева / бінарного дерева пошуку, який має один
дочірній вузол;
8) видалення елемента бінарного дерева / бінарного дерева пошуку, який має два
дочірніх вузли;
9) видалення елемента бінарного дерева / бінарного дерева пошуку з усіма його
дочірніми вузлами (тобто, видалення цілої гілки);
10) опрацювання бінарного дерева / бінарного дерева пошуку – виконати завдання свого
варіанту : Визначити кількість елементів бінарного дерева / бінарного дерева пошуку,
батьківські до яких мають значення k.
*/

#include <iostream>

using namespace std;

typedef int Info;

struct Node
{
	Node* left,
		* right;
	Info info;
};

void Menu();
Node* CreateTree(int nodeCount);
void PrintTree(Node* root, int level);
int Count(Node* root);
Node* BinarySearchInsert(Node*& root, Info Info, bool& found);
int Height(Node* root);
int BFactor(Node* root);
Node* leftRotation(Node* q);
Node* rightRotation(Node* p);
void balanceHeight(Node* root);
Node* FindMin(Node* root);
Node* deleteMin(Node* p);
Node* Delete(Node* p);
void Deletevalue(Node* root);

int main()
{
	Menu();
	return 0;
}

void Menu()
{
	Node* root = NULL;
	Info info;
	int kilkistElem;
	int choice;
	bool found = false;

	do {
		cout << " [1] створення бінарного дерева із наперед вказаною кількістю елементів";
		cout << " [2] вивід бінарного дерева || бінарного дерева пошуку на екран (з виділенням біжучого елемента)";
		cout << " [3] створення бінарного дерева пошуку із наперед вказаною кількістю елементів";
		cout << " [4] добавлення нового елемента із збереженням порядку (для побудови бінарного дерева пошуку)";
		cout << " [5] збалансування бінарного дерева пошуку";
		cout << " [6] видалення елемента бінарного дерева / бінарного дерева пошуку, який не має дочірніх вузлів";
		cout << " [7] видалення елемента бінарного дерева / бінарного дерева пошуку, який має один дочірній вузоли";
		cout << " [8] видалення елемента бінарного дерева / бінарного дерева пошуку, який має два дочірніх вузл";
		cout << " [9] видалення елемента бінарного дерева / бінарного дерева пошуку з усіма його дочірніми вузлами(тобто, видалення цілої гілки); ";
		cout << " [10] Визначити кількість елементів бінарного дерева / бінарного дерева пошуку, батьківські до яких мають значення k.";
		cout << " [0] завершити виконання команд";
     	cout << "Виберіть команду : "; cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Введіть кількість елементів дерева : "; cin >> kilkistElem;
			for (int i = 0; i < kilkistElem; i++)
			{
				cout << "value: "; cin >> info;
				Node* root = CreateTree(info);
			}
			break;
		case 2:
				PrintTree(root, 0);
				cout << "Кількіть елементів" << Count(root) << endl;
			break;
		case 3:
			cout << "Введіть кількість елементів дерева : "; cin >> kilkistElem;
			for (int i = 0; i < kilkistElem; i++)
			{
				cout << "value: "; cin >> info;
				root = BinarySearchInsert(root, info, found);
			}
			break;
		case 4:
			int value;
			cout << "Введіть значення яке хочете помістити до дерева : "; cin >> value;
			BinarySearchInsert(root, value, found);
			break;
		case 5:
			balanceHeight(root);
			break;
		case 6:
			cout << "DELETE : " << endl; cin >> value;////////////////////////////
			Deletevalue(root);
		case 7: 
		case 8:
		case 9:
		case 10:
		case 0:
			break;
		default:
			cout << "Помилка при введені! Будьте уважніші!."
				"спробуймо ще раз" << endl;
		}
	 } while (choice != 0);
}
Node* CreateTree(int nodeCount) ////////  2
{
	if (nodeCount == 0)
		return NULL;
	else
	{
		Node* newNode = new Node;

		cout << " Enter node value: ";
		cin >> newNode->info;

		int leftCount = nodeCount / 2;
		int rightCount = nodeCount - leftCount - 1;
		newNode->left = CreateTree(leftCount);
		newNode->right = CreateTree(rightCount);
		return newNode;
	}
}
void PrintTree(Node* root, int level)///////////    3
{
	if (root != NULL)
	{
		PrintTree(root->right, level + 1);
		for (int i = 1; i <= level; i++)
			cout << " ";
		cout << root->info << endl;
		PrintTree(root->left, level + 1);
	}
}

void InfixOrder(Node* root)
{
	if (root != NULL)
	{
		InfixOrder(root->left);
		cout << root->info << " ";
		InfixOrder(root->right);
	}
}
int Count(Node* root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + Count(root->left) + Count(root->right);
}
Node* BinarySearchInsert(Node*& root, Info value, bool& found) ////////////  4
{
	if (root == NULL)
	{
		root = new Node;
		root->info = value;
		root->left = NULL;
		root->right = NULL;
		found = false;
		return root;
	}
	else
		if (value == root->info)
		{
			found = true;
			return root;
		}
		else
			if (value < root->info)
				return BinarySearchInsert(root->left, value, found);
			else
				return BinarySearchInsert(root->right, value, found);
}
Node* rightRotation(Node* p)
{
	Node* q = p->left;
	p->left = q->right;
	q->right = p;
	return q;
}
Node* leftRotation(Node* q)
{
	Node* p = q->right;
	q->right = p->left;
	p->left = q;
	return p;
}
int Height(Node* root)
{
	if (root == NULL)
		return 0;
	int hL = Height(root->left);
	int hR = Height(root->right);
	return (hL > hR ? hL : hR) + 1;
}
int BFactor(Node* root)
{
	return Height(root->right) - Height(root->left);
}
void balanceHeight(Node* root) /////////    5
{
	if (BFactor(root) == 2)
	{
		if (BFactor(root->right) < 0)
			root->right = rightRotation(root->right);
		leftRotation(root);
	}
	if (BFactor(root) == -2)
	{
		if (BFactor(root->left) > 0)
			root->left = leftRotation(root->left);
		 rightRotation(root);
	}
}
void Deletevalue(Node* root)
{
	if (BFactor(root) == 2)
	{
		Deletevalue(root->left);
	}
	if (BFactor(root) == -2)
	{
		Deletevalue(root->right);
	}
	else
		Delete(root);
}
Node* FindMin(Node* root)
{
	if (root->left != NULL)
		return FindMin(root->left);
	else
		return root;
}
Node* deleteMin(Node* p)
{
	if (p->left == 0)
		return p->right;
	p->left = deleteMin(p->left);
	return balanceHeight(p);
}
Node* Delete(Node* p)
{
	if (!p)
		return 0;
	if (Delete(p->left) != NULL)
		p->left = Delete(p->left, value);
	else if (value > p->info)
		p->right = Delete(p->right, value);
	else // value == p->info
	{
		Node* q = p->left;
		Node* r = p->right;
		delete p;
		if (!r)
			return q;
		Node* min = FindMin(r);
		min->right = deleteMin(r);
		min->left = q;
		return balanceHeight(min);
	}
	return balanceHeight(p);
}

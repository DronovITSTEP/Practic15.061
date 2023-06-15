#include "Tree.h"
Tree::Tree() {
	root = nullptr;
}
Tree::~Tree() {
	Del();
}
// печать от указанного узла
void Tree::Print(Elem* node) {
	if (node != nullptr) {
		Print(node->left);
		cout << node->Name
			<< node->Match
			<< node->Opponent << endl << endl;
		Print(node->right);
	}
}
// поиск по указанному ключу и позиции в дереве
Elem* Tree::Search(Elem* node, const char* key) {
	while (node != nullptr && strcmp(key, node->Name) != 0) {
		if (strcmp(key, node->Name) < 0)
			node = node->left;
		else
			node = node->right;
	}
	return node;
}
// поиск минимального или максимального значения в дереве
Elem* Tree::Min(Elem* node){
	if (node != nullptr) 
		while (node->left != nullptr)
			node = node->left;

	return node;
}
Elem* Tree::Max(Elem* node){
	if (node != nullptr)
		while (node->right != nullptr)
			node = node->right;

	return node;
}
// следующий или предыдущий элемент от указанного узла
Elem* Tree::Next(Elem* node) {
	Elem* y = nullptr;
	if (node != nullptr) {
		if (node->right != nullptr)
			return Min(node->right);
		y = node->parent;
		while (y != nullptr && node == y->right)
		{
			node = y; 
			y = y->parent;
		}
	}
	return y;
}
Elem* Tree::Previous(Elem* node) {
	Elem* y = nullptr;
	if (node != nullptr) {
		if (node->left != nullptr)
			return Max(node->left);
		y = node->parent;
		while (y != nullptr && node == y->left)
		{
			node = y;
			y = y->parent;
		}
	}
	return y;
}
// втсавка узла
void Tree::Insert(Elem* node) {
	node->left = nullptr;
	node->right = nullptr;

	Elem* y = nullptr;
	Elem* node_root = root;

	while (node_root != nullptr) {
		y = node_root;
		if (strcmp(node->Name, node_root->Name) < 0)
			node_root = node_root->left;
		else
			node_root = node_root->right;
	}
	node->parent = y;
	if (y == nullptr)
		root = node;
	else if (strcmp(node->Name, y->Name) < 0)
		y->left = node;
	else
		y->right = node;
}
// удаление указанной ветки
void Tree::Del(Elem* node) {
	if (node != nullptr) {
		Elem* x, * y;
		if (node->left == nullptr || node->right == nullptr)
			y = node;
		else
			y = Next(node);

		if (y->left != nullptr)
			x = y->left;
		else
			x = y->right;

		if (y->parent == nullptr)
			root = x;
		else if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;

		if (y != node) {
			strcpy_s(node->Name, y->Name);
			strcpy_s(node->Opponent, y->Opponent);
			strcpy_s(node->Match, y->Match);
			node->oppPoints =  y->oppPoints;
			node->ownerPoints = y->ownerPoints;
		}
		delete y;
	}
	else
	{
		while (root != nullptr)
			Del(root);
	}
}
// получение корня
Elem* Tree::GetRoot() {
	return root;
}

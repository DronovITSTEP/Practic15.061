#pragma once
#include <iostream>
using namespace std;

struct Elem {
	int ownerPoints;	// очки хозяина
	int oppPoints;		// очки соперника
	char Name[20];		// имя хозяина
	char Opponent[20];	// имя соперника
	char Match[10];		// счет матча

	Elem* left, * right, * parent;
};

class Tree
{
	Elem* root;
public:
	Tree();
	~Tree();
	// печать от указанного узла
	void Print(Elem* node); 
	// поиск по указанному ключу и позиции в дереве
	Elem* Search(Elem* node, const char* key);
	// поиск минимального или максимального значения в дереве
	Elem* Min(Elem* node);
	Elem* Max(Elem* node);
	// следующий или предыдущий элемент от указанного узла
	Elem* Next(Elem* node);
	Elem* Previous(Elem* node);
	// втсавка узла
	void Insert(Elem* node);
	// удаление указанной ветки
	void Del(Elem* node = nullptr);
	// получение корня
	Elem* GetRoot();

};


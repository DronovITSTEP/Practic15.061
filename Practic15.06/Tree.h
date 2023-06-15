#pragma once
#include <iostream>
using namespace std;

struct Elem {
	int ownerPoints;	// ���� �������
	int oppPoints;		// ���� ���������
	char Name[20];		// ��� �������
	char Opponent[20];	// ��� ���������
	char Match[10];		// ���� �����

	Elem* left, * right, * parent;
};

class Tree
{
	Elem* root;
public:
	Tree();
	~Tree();
	// ������ �� ���������� ����
	void Print(Elem* node); 
	// ����� �� ���������� ����� � ������� � ������
	Elem* Search(Elem* node, const char* key);
	// ����� ������������ ��� ������������� �������� � ������
	Elem* Min(Elem* node);
	Elem* Max(Elem* node);
	// ��������� ��� ���������� ������� �� ���������� ����
	Elem* Next(Elem* node);
	Elem* Previous(Elem* node);
	// ������� ����
	void Insert(Elem* node);
	// �������� ��������� �����
	void Del(Elem* node = nullptr);
	// ��������� �����
	Elem* GetRoot();

};


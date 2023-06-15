#include <iostream>
#include <string>

#include "Tree.h"

using namespace std;

Tree tournament;

void Game(char Commands[][20], int N) {
	int i, j;
	int p1, p2;

	int k;
	Elem* temp;

	for (k = 0; k < 2; k++) {
		for (i = 0; i < N - 1; i++) {
			for (j = i + 1; j < N; j++) {
				temp = new Elem;
				if (k == 0) {
					strcpy_s(temp->Name, Commands[i]);
					strcpy_s(temp->Opponent, Commands[j]);
				}
				else
				{
					strcpy_s(temp->Name, Commands[j]);
					strcpy_s(temp->Opponent, Commands[i]);
				}
				p1 = rand() % 6;
				p2 = rand() % 6;

				if (p1 > p2) {
					temp->ownerPoints = 3;
					temp->oppPoints = 0;
				}
				else if (p1 == p2) {
					temp->ownerPoints = 1;
					temp->oppPoints = 1;
				}
				else {
					temp->ownerPoints = 0;
					temp->oppPoints = 3;
				}

				sprintf_s(temp->Match, " %d : %d ", p1, p2);
				tournament.Insert(temp);
			}
		}
	}
}


int main()
{
	srand(time(NULL));

	const int N = 4;
	char Commands[4][20] = {
		"Arsenal",
		"Liverpool",
		"Manchester",
		"Zenit"
	};

	Game(Commands, N);
	tournament.Print(tournament.GetRoot());
}

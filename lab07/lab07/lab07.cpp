// lab07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct node
{
	int info; //reytynh
	string surname;
	node *l, *r; //liva i prava chastyna dereva
};

node * tree = NULL; //zminna tyou structura Derevo

					/*ZAPYS ELEMENTU V BINARNE DEREVO*/
int push(int a, string surn, node **t)
{
	if ((*t) == NULL) //Yaksho dereva ne isnuje
	{
		(*t) = new node;
		(*t)->info = a;
		(*t)->surname = surn;
		(*t)->l = (*t)->r = NULL;
		return 0;
	}
	//Yaksho derevo isnuje
	if (a>(*t)->info) push(a, surn, &(*t)->r); //Yaksho reytunh bilshyj, to klademo vpravo
	else push(a, surn, &(*t)->l); //inakshe klademo vlivo
	return 0;
}

/*VIDOBRAZHENNYA DEREVA NA EKRANI*/
int print(node *t, int u, bool prn)
{
	if (t == NULL) return 0;
	else
	{
		
		print(t->l, ++u, prn);
		if (prn)
		{
			if (t->info > 70) //perevirka znachennya reytynhu
			{
				cout << "      " << t->info << "      " << "|    " << t->surname << endl;
			}
		}
		else
		{
			cout << "      " << t->info << "      " << "|    " << t->surname << endl;
		}
		u--;
	}
	print(t->r, ++u, prn);
	return 0;
}

int create(void) {
	int n; //Kilkist elementiv
	int s; //Reytynh
	string sur = "";
	cout << "Number of students: ";
	cin >> n;

	for (int i = 0; i<n; ++i)
	{
		cout << "\n\n--------------------------------\n";
		cout << i + 1 << " student\n--------------------------------\n";
		cout << "Mark: ";
		cin >> s;
		cout << "Surname: ";
		cin.ignore();
		getline(cin, sur);
		push(s, sur, &tree);
	}
	return 0;
}

int printtree(void)
{
	bool prn = 0;
	cout << "\nDo you need the info about all students (by default or enter '0') or only above average students (enter '1'): ";
	cin >> prn;
	cout << "\n\n--------------------------------\n";
	if (prn)
		cout << "-----Above-average Students-----\n";
	else
		cout << "----------All Students----------\n";
	cout << "-----Mark-----" << "|-----Surname-----" << endl;
	print(tree, 0, prn);
	return 0;
}

void main() {
	
	create();
	printtree();
	_getch();
}


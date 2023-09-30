#include <iostream>
#include <fstream>

using namespace std;

#define MIN_N 2
#define MAX_N 100

int main()
{
	ifstream fin("relatii.in");

	if (! fin.is_open())
	{
		cout << "Eroare deschidere fisier relatii.in\n";
		return 1;
	}	

	int n;

	fin >> n;

	if (n < MIN_N || n > MAX_N)
	{
		cout << "Eroare valoare n\n";
		return 2;
	}

	int i, j, a[n][n];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			fin >> a[i][j];
		}
	}

	// Determinati si afisati pe ecran toate perechile distincte de elevi care se agreeaza reciproc
	
	cout << "Perechile distincte de elevi care se agreeaza reciproc:\n";

	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (a[i][j] == 1 && a[j][i] == 1)
			{
				cout << i+1 << ' ' << j+1 << '\n'; 
			}
		}
	}

	// Afisati elevii care nu sunt agreati de nimeni
	
	cout << "Elevii care nu sunt agreati de nimeni: ";

	bool ok;

	for (j = 0; j < n; j++)
	{
		ok = 1;

		for (i = 0; i < n && ok; i++)
		{
			if (i != j && a[i][j])
			{
				ok = 0;
			}
		}

		if (ok)
		{
			cout << j+1 << ' ';
		}
	}

	

	// Afisati elevii care nu agreeaza pe nimeni

	cout << "\nElevii care nu agreeaza pe nimeni: ";

	for (i = 0; i < n; i++)
	{
		ok = 1;

		for (j = 0; j < n && ok; j++)
		{
			if (i != j && a[i][j])
			{
				ok = 0;
			}
		}

		if (ok)
		{
			cout << i+1 << ' ';
		}
	}
	
	// Afisati elevii in ordinea descrescatoare a popularitatii lor
	// Popularitatea unui elev este egala cu numarul de elevi care il agreeaza

	int p[n];

	for (i = 0; i < n; i++)
	{
		p[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i != j && a[i][j])
			{
				p[j]++;
			}
		}
	}
	
	int ep[n], st, dr, mij, lg;

	ep[0] = 0, lg = 1;

	for (i = 0; i < n; i++)
	{
		st = -1, dr = lg;

		while (dr-st > 1)
		{
			mij = st + (dr-st)/2;

			if (p[ep[mij]] > p[i])
			{
				st = mij;
			}
			else
			{
				dr = mij;
			}
		}

		lg++;

		for (j = lg; j > dr; j--)
		{
			ep[j] = ep[j-1];
		}

		ep[dr] = i;
	}
	
	cout << "\nCei mai populari elevi: ";

	for (i = 0; i < n; i++)
	{
		cout << ep[i]+1 << ' ';
	}

	return 0;
}

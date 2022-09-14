#include <iostream>
#include <cmath>

using namespace std;

int kombinacje(int k, int s)
{
	int n = 1;
	int a = 1;
	int n_a = 1;
	int wynik = 1;

	for (int i = k; i > 1; i--)
		n *= i;
	for (int i = s; i > 1; i--)
		a *= i;
	for (int i = k-s; i > 1; i--)
		n_a *= i;

	wynik = n / (a * n_a);

	return wynik;
}

int main()
{
	const int m = 8; // liczba punktów
	double X[m] = { 1, 2, 3, 4, 5, 6, 7, 8}; // węzeł
	double Y[m] = { 2, 4, 3, 5, 6, 9, 11, 11 }; // wartości
	double h = 1;
	double q[m] = { NULL };
	int n;
	double C[m] = { NULL };
	double S[m] = { NULL };
	double b[m] = { NULL };

	double** M = new double* [m];
	for (int i = 0; i < m; i++)
	{
		M[i] = new double[m];
	}
	double g = 0.0;

	cout << "Liczba wezlow: " << m << endl << endl;

	cout << "Punkty: " << endl;

	for (int i = 0; i < m; i++)
	{
		cout << "(" << X[i] << ", " << Y[i] << ")";
	}
	cout << endl << endl;

	for (int i = 0; i < m; i++)
	{
		q[i] = (X[i] - X[0]) / h;
		cout << "q" << i << " = " << q[i] << endl;
	}
	
	cout << endl << endl;

		for (int i = 0; i < m; i++)
		{
			for (int k = 0; k < m; k++)
			{
				if (k == 0)
				{
					M[i][k] = 1;
				}
				else
				{
					n = 7;

					for (int s = 1; s <= k; s++)
					{
						if (s == 1)
						{
							M[i][k] = 1 - kombinacje(k, s) * kombinacje(k + s, s) * (q[i] / n);
						}
						else if (s == 2) 
						{
							M[i][k] += kombinacje(k, s) * kombinacje(k + s, s) * ((q[i] * (q[i] - 1)) / (n * (n - 1)));
						}
						else if (s == 3)
						{
							M[i][k] -= kombinacje(k, s) * kombinacje(k + s, s) * ((q[i] * (q[i] - 1) * (q[i] - 2)) / (n * (n - 1) * (n - 2)));
						}
						else if (s == 4)
						{
							M[i][k] += kombinacje(k, s) * kombinacje(k + s, s) * ((q[i] * (q[i] - 1) * (q[i] - 2) * (q[i] - 3)) / (n * (n - 1) * (n - 2) * (n - 3) * (n - 4)));
						}
						else if (s == 5)
						{
							M[i][k] -= kombinacje(k, s) * kombinacje(k + s, s) * ((q[i] * (q[i] - 1) * (q[i] - 2) * (q[i] - 3) * (q[i] - 4)) / (n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5)));
						}
						else if (s == 6)
						{
							M[i][k] += kombinacje(k, s) * kombinacje(k + s, s) * ((q[i] * (q[i] - 1) * (q[i] - 2) * (q[i] - 3) * (q[i] - 4) * (q[i] - 5)) / (n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5)));
						}
						else if (s == 7)
						{
							M[i][k] -= kombinacje(k, s) * kombinacje(k + s, s) * ((q[i] * (q[i] - 1) * (q[i] - 2) * (q[i] - 3) * (q[i] - 4) * (q[i] - 5) * (q[i] - 6)) / (n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) * (n - 6)));
						}
					}
				}
				cout << M[i][k] << "			";
			}
			cout << endl;
		}

		cout << endl << endl;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				C[i] += Y[i] * M[i][j];
			}
			cout << "Ci dla " << i << " = " << C[i] << endl;
		}
		
		cout << endl << endl;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				S[i] += M[i][j] * M[i][j];
			}
			cout << "Si dla " << i << " = " << S[i] << endl;
		}

		cout << endl << endl;

		for (int j = 0; j < m; j++)
		{
			b[j] = C[j] / S[j];
			cout << "bi dla " << j << " = " << b[j] << endl;
		}
		

	return 0;
}
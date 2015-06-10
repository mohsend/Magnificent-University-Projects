/*
 * 
 */

#include <iostream>
#include <iomanip>
using namespace std;

class matrixes
{
	private:
		int A[20][20], B[20][20], C[20][20]; // arrays for matrix
		int Am, An, Bm, Bn, Cm, Cn; // size of the matrix
	public:
		void fill();
		void add();
		void print(int matrix[20][20], int, int);
		void print_all();
		void multiply();
};

int main(int argc, char **argv)
{
	matrixes mat;
	mat.fill();
	mat.add();
	mat.print_all();
	mat.multiply();
	mat.print_all();
	return 0;
}

void matrixes::fill()
{
	cout << "first matrix:" << endl;
	cout << "How many rows? ";
	cin >> Am;
	cout << "How many culomns?";
	cin >> An;
	for (int i = 0; i < An; i++)
	{
		for (int j = 0; j < Am; j++)
		{
			cout << "A[" << j << "][" << i << "] = ";
			cin >> A[j][i];
		}	
	}
	
	cout << "second matrix:" << endl;
	cout << "How many rows? ";
	cin >> Bm;
	cout << "How many culomns?";
	cin >> Bn;
	for (int i = 0; i < Bn; i++)
	{
		for (int j = 0; j < Bm; j++)
		{
			cout << "\nA[" << j << "][" << i << "] = ";
			cin >> B[j][i];
		}	
	}
	
}

void matrixes::print(int matrix[20][20], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(6) << matrix[j][i];
		}	
		cout << endl;
	}
	
}

void matrixes::print_all()
{
	cout << "A:" << endl;
	print(A, Am, An);
	cout << "A:" << endl;
	print(B, Bm, Bn);
	cout << "C:" << endl;
	print(C, Cm, Cn);
}

void matrixes::add()
{
	if (Am == Bm && An == Bn)
	{
		Cm = Am; Cn = An;
		for (int i = 0; i < Am; i++)
		{
			for (int j = 0; j < An; j++)
			{
				C[i][j] = A[i][j] + B[i][j];
			}
		}
	}
	else
	{
		return;
	}
}

void matrixes::multiply()
{
	Cm = Am; Cn = Bn;
	for (int i = 0; i < Am; i++)
	{
		for (int j = 0; j < Bn; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < Bm; k++)
			{
				C[i][j] = A[i][k] * B[k][j] + C[i][j];
			}
		}
	}
}

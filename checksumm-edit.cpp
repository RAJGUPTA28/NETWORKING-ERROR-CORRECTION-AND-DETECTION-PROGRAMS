#include <iostream>
using namespace std;

#define MAX 100

int *addone(int arr[], int segments);

int *binaryadd(int b[], int c[], int segments)
{
	int carry = 0, i;
	int *d = new int[MAX];

	for (i = segments - 1; i >= 0; i--)
	{
		if (b[i] == 1 && c[i] == 1 && carry == 0)
		{
			d[i] = 0;
			carry = 1;
		}
		else if (b[i] == 1 && c[i] == 1 && carry == 1)
		{
			d[i] = 1;
			carry = 1;
		}
		else if (b[i] == 0 && c[i] == 0 && carry == 0)
		{
			d[i] = 0;
			carry = 0;
		}
		else if (b[i] == 0 && c[i] == 0 && carry == 1)
		{
			d[i] = 1;
			carry = 0;
		}
		else if (b[i] == 1 && c[i] == 0 && carry == 0)
		{
			d[i] = 1;
			carry = 0;
		}
		else if (b[i] == 1 && c[i] == 0 && carry == 1)
		{
			d[i] = 0;
			carry = 1;
		}
		else if (b[i] == 0 && c[i] == 1 && carry == 0)
		{
			d[i] = 1;
			carry = 0;
		}
		else if (b[i] == 0 && c[i] == 1 && carry == 1)
		{
			d[i] = 0;
			carry = 1;
		}
		else
			break;
	}

	if (carry == 1)
	{
		d = addone(d, segments);
	}
	return d;
}

int *addone(int arr[], int segments)
{
	int onematrix[segments];
	for (int i = 0; i < segments - 1; i++)
	{
		onematrix[i] = 0;
	}
	onematrix[segments - 1] = 1;

	int *crr = new int[MAX/2];
	crr = binaryadd(arr, onematrix, segments);
	return crr;
}

int *complement(int *a, int segments)
{

	for (int i = 0; i < segments; i++)
	{
		if (a[i] == 0)
			a[i] = 1;
		else
			a[i] = 0;

		cout << a[i];
	}
	return a;
}

int main()
{
	int bits, a[MAX], b[MAX], c[MAX], i, j, segments;
	cout << "\n-----------CHECKSUM------------\n";
	cout << "\nEnter no of bits: ";
	cin >> bits;

	if (bits % 2 != 0)
	{
		cout << "\nenter even bit no.\n";
		exit(1);
	}

	cout << "\nEnter no. : ";
	for (i = 0; i < bits; i++)
	{

		cin >> a[i];
	}
	cout << "_____________________________________________________" << endl;
	cout << "\nSender ";
	cout << "\n\nMain Message = ";
	for (i = 0; i < bits; i++)
	{
		cout << a[i];
	}

	segments = bits / 2;

	for (i = 0; i < segments; i++)
		b[i] = a[i];

	j = 0;
	for (i = segments; i < bits; i++)
	{
		c[j] = a[i];
		j++;
	}

	cout << "\n\nAfter dividing data into 2 segments : ";
	for (i = 0; i < segments; i++)
	{
		cout << b[i];
	}
	cout << "  |   ";
	for (i = 0; i < segments; i++)
	{
		cout << c[i];
	}

	int *f;

	f = binaryadd(b, c, segments);
	cout << "\n\nafter adding previous 2 terms: ";
	for (i = 0; i < segments; i++)
	{
		cout << f[i];
	}
	cout << "\n\nafter compliment of sum : ";
	cout << "\n CHECK SUM  ";
	int *tmp = complement(f, segments);

	cout << "\n________________________________________________________" << endl;
	cout << "\nReceiver side : \n";
	int *g = binaryadd(b, c, segments);
	cout << "\nafter adding received segments terms: ";
	for (i = 0; i < segments; i++)
	{
		cout << g[i];
	}

	cout << "" << endl;
	int *s = binaryadd(tmp, g, segments);

	cout << " \n Taking complement of SUM :  ";
	s = complement(s, segments);

	cout << "\n\nALL ELEMENTS AFTER COMPLEMENTS OF SUM IS 0 !!!\n         NO ERROR!!! " << endl;
	return 0;
}

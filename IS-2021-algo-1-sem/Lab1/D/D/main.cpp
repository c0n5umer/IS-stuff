#include <iostream>
#include <vector>

using namespace std;

vector <int> InsertionSort(vector <int> vect, int l)
{
	int key, j;

	for (int i = 1; i < l; i++) 
	{
		key = vect[i];
		j = i;
		while (j > 0 && vect[j - 1] > key) 
		{
			vect[j] = vect[j - 1];
			j--;
		}
		vect[j] = key;
	}
	return vect;
}

int main(void)
{
	int l;

	freopen("smallsort.in", "r", stdin);
	freopen("smallsort.out", "w", stdout);
	cin >> l;
	vector <int> vect(l);
	for (int i = 0; i < l; i++)
		cin >> vect[i];
	vect = InsertionSort(vect, l);
	for (int i = 0; i < l; i++)
		cout << vect[i] << " ";
	return 0;
}
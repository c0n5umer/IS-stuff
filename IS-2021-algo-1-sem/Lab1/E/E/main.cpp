#include <iostream>
#include <vector>

using namespace std;

vector <float> InsertionSort(vector <float> vect, int l)
{
    int j;
    float key;

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

int FindGuy(vector <float> m, float sum)
{
    int i = 0;

    while (sum != m[i])
        i++;
    return i + 1;
}

int main(void)
{
    int n;

    freopen("sortland.in", "r", stdin);
    freopen("sortland.out", "w", stdout);
    cin >> n;
    vector <float> m(n);
    for (int i = 0; i < n; i++)
        cin >> m[i];
    vector <float> sorted(n);
    sorted = InsertionSort(m, n);
    cout << FindGuy(m, sorted[0]) << " " << FindGuy(m, sorted[int(n / 2)]) << " " << FindGuy(m, sorted[n - 1]);
    return 0;
}
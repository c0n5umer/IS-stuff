#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>

using namespace std;

vector <double> vec;
double l = 0, r = 1000000;

double garland(int n)
{
    while (r - l > 0.00000000001)
    {
        bool triger = 1;

        vec[1] = (r + l) / 2;
        for (int i = 2; i < n; i++)
        {
            vec[i] = 2 * vec[i - 1] - vec[i - 2] + 2;
            if (vec[i] < 0)
            {
                triger = 0;
                break;
            }
        }
        if (triger)
            r = vec[1];
        else
            l = vec[1];

    }
    return vec[n - 1];
}

int main(void)
{
    int n;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("garland.in", "r", stdin);
    freopen("garland.out", "w", stdout);
    cout.precision(2);

    cin >> n;
    vec.resize(n);

    cin >> vec[0];
    cout << fixed << garland(n);
    return 0;
}
#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef struct {
    string surname;
    string country;
} Competitor;

void merge_sort(vector <Competitor>& vec, int left, int right);
bool compare_words(string s1, string s2);

int main(void)
{
    int n;
    string last_country = "";
    
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    cin >> n;

    vector <Competitor> competitors(n);

    for (int i = 0; i < n; i++)
    {
        string input;

        cin >> competitors[i].country;
        cin >> competitors[i].surname;
    }

    merge_sort(competitors, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        if (competitors[i].country != last_country)
        {
            last_country = competitors[i].country;
            cout << "=== " << last_country << " ===\n";
        }
        cout << competitors[i].surname << "\n";
    }

    return 0;
}

void merge(vector <Competitor> &vec, int left, int mid, int right)
{
    int it1 = 0, it2 = 0, len1 = mid - left + 1, len2 = right - mid, res_counter = 0;
    vector <Competitor> result(len1 + len2);

    while (it1 < len1 && it2 < len2)
    {
        if (compare_words(vec[left + it1].country, vec[mid + 1 + it2].country))
            result[res_counter++] = vec[left + it1++];
        else
            result[res_counter++] = vec[mid + 1 + it2++];
    }

    while (it1 < len1)
        result[res_counter++] = vec[left + it1++];

    while (it2 < len2)
        result[res_counter++] = vec[mid + 1 + it2++];

    for (int i = 0; i < len1 + len2; i++)
        vec[left + i] = result[i];
}

void merge_sort(vector <Competitor>& vec, int left, int right)
{
    int mid = floor((left + right) * 0.5);

    if (left >= right)
        return;

    merge_sort(vec, left, mid);
    merge_sort(vec, mid + 1, right);
    merge(vec, left, mid, right);
}

bool compare_words(string s1, string s2)
{
    int len1 = s1.length(), len2 = s2.length(), iterations = min(len1, len2);

    if (s1 == s2)
        return 1;

    for (int i = 0; i < iterations; i++)
    {
        if (s1[i] < s2[i])
            return 1;
        else if (s1[i] > s2[i])
            return 0;
    }
    if (len1 < len2)
        return 1;
    else
        return 0;
}
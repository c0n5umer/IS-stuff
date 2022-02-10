#include <iostream>
#include <vector>
#include <algorithm>

int search_height(std::vector <std::vector <int>>& vec, int root) {
    int l = 0, r = 0;

    if (vec[root][0] == -1 && vec[root][1] == -1)
        return 1;
    if (vec[root][0] != -1)
        l = search_height(vec, vec[root][0]);
    if (vec[root][1] != -1)
        r = search_height(vec, vec[root][1]);

    return std::max(l + 1, r + 1);
}

int main(void) {
    int n, k, l, r;

    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);

    std::cin >> n;
    std::vector <std::vector <int>> vec(n, std::vector <int>(2));;

    for (int i = 0; i < n; ++i) {
        std::cin >> k >> l >> r;
        vec[i][0] = l - 1;
        vec[i][1] = r - 1;
    }

    if (n != 0)
        std::cout << search_height(vec, 0);
    else
        std::cout << 0;
    return 0;
}
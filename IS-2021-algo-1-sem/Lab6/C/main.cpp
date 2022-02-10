#include<iostream>
#include<vector>
#include<string>
using namespace std;

typedef struct st* Map;
struct st {
    string key;
    string val;
    Map next;
    Map prev;
    Map n;
    Map p;
};

Map head = 0;
const int m = 200000;
Map table[m];

int divhash(string key) {
    int k = 0;

    for (char c: key)
        k = (k * CHAR_MAX + c) % m;
    return k;
}

Map build(string key, string value) {
    Map map = new st;
    map->key = key;
    map->val = value;
    map->next = 0;
    map->prev = 0;

    map->p = 0;
    map->n = 0;
    return map;
}

Map search(string key) {
    int h = divhash(key);
    Map map = table[h];

    while (map && map->key != key)
        map = map->next;
    return map;
}

Map insert(string key, string val) {
    Map map = search(key);

    if (map == 0) {
        int h = divhash(key);

        map = build(key, val);

        map->next = table[h];
        map->prev = 0;
        if (table[h])
            table[h]->prev = map;
        table[h] = map;
        if (head) {
            head->n = map;
            map->p = head;
        }
        head = map;

    } else
        map->val = val;
    return map;
}

void del(string key) {
    Map map = search(key);

    if (map) {
        int h = divhash(key);
        if (table[h] == map) {
            table[h] = map->next;
        } else {
            if (map->next)
                map->next->prev = map->prev;
            map->prev->next = map->next;
        }

        if (map->p)
            map->p->n = map->n;

        if (map->n)
            map->n->p = map->p;

        if (head == map)
            head = map->p;
    }
}

Map next(string x) {
    Map map = search(x);

    if (map)
        return map->n;
    return map;
}

Map prev(string x) {
    Map map = search(x);

    if (map)
        return map->p;
    return map;
}

int main() {
    freopen("linkedmap.in", "r", stdin);
    freopen("linkedmap.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, x, y;

    while (cin >> s >> x) {
        if (s == "put") {
            cin >> y;
            insert(x, y);
        } else if (s == "get") {
            Map map = search(x);

            if (map)
                cout << map->val << "\n";
            else
                cout << "none\n";
        } else if (s == "delete") {
            del(x);
        } else if (s == "prev") {
            Map map = prev(x);

            if (map)
                cout << map->val << "\n";
            else
                cout << "none\n";
        } else if (s == "next") {
            Map map = next(x);

            if (map)
                cout << map->val << "\n";
            else
                cout << "none\n";
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int find_hash(int value) {
    return abs(value % 1000001);
}

struct hashh {
    hashh* next;
    int value;
};

bool exists(vector <hashh*>& table, int value) {
    int value_hash = find_hash(value);
    hashh* temp = table[value_hash];
    bool res = false;

    while (temp != NULL) {
        if (temp->value == value) {
            res = true;
            break;
        }
        temp = temp->next;
    }

    return res;
}

void insert(vector <hashh*>& table, int value) {
    hashh* temp, * new_hash;
    int value_hash = find_hash(value);

    if (exists(table, value))
        return;

    temp = table[value_hash];

    if (temp == NULL) {
        new_hash = new hashh;
        new_hash->value = value;
        new_hash->next = NULL;
        table[value_hash] = new_hash;
    }
    else {
        /* if (temp->value == value)
             return; */

        while (temp->next != NULL)
            temp = temp->next;

        new_hash = new hashh;
        new_hash->value = value;
        new_hash->next = NULL;
        temp->next = new_hash;
    }
}

void delete_value(vector <hashh*>& table, int value) {
    int value_hash = find_hash(value);
    hashh* temp = table[value_hash], *last_hash = NULL;

    if (temp == NULL)
        return;

    while (temp != NULL) {
        if (temp->value == value) {
            if (last_hash == NULL) {
                table[value_hash] = temp->next;
                delete temp;
            }
            else {
                last_hash->next = temp->next;
                delete temp;
            }
            return;
        }
        last_hash = temp;
        temp = temp->next;
    }
}

int main(void) {
    vector <hashh*> table(1000001);
    string comand;
    int value;

    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> comand) {
        if (comand == "insert") {
            cin >> value;
            insert(table, value);
        }
        else if (comand == "exists") {
            cin >> value;
            if (exists(table, value))
                cout << "true\n";
            else
                cout << "false\n";
        }
        else if (comand == "delete") {
            cin >> value;
            delete_value(table, value);
        }
    }

    return 0;
}
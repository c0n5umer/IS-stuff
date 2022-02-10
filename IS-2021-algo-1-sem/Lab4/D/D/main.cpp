#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

typedef struct Stack {
    char value;
    Stack* previous;
} Stack;

void push(Stack** last_element, char value)
{
    Stack* el = (Stack*)malloc(sizeof(Stack));

    el->value = value;
    el->previous = *last_element;
    *last_element = el;
}

char pop(Stack** last_element)
{
    if (*last_element == NULL)
        return 'e';

    char value = (*last_element)->value;
    Stack* temp_pointer = *last_element;

    *last_element = (*last_element)->previous;
    free(temp_pointer);
    return value;
}

int count(Stack **last_element)
{
    int result, element_1, element_2; 
    char operation;

    operation = pop(last_element);

    char element = pop(last_element);

    if (element == '*' || element == '+' || element == '-')
    {
        push(last_element, element);
        element_1 = count(last_element);
        element = pop(last_element);
    }
    else
    {
        element_1 = element - '0';
        element = pop(last_element);
    }

    if (element == '*' || element == '+' || element == '-')
    {
        push(last_element, element);
        element_2 = count(last_element);
    }
    else
        element_2 = element - '0';

    if (operation == '+')
        result = element_1 + element_2;
    else if (operation == '*')
        result = element_1 * element_2;
    else if (operation == '-')
        result = element_2 - element_1;

    return result;
}

int main(void)
{
    Stack *last_element = NULL;
    string str;
    char c;

    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> c)
        push(&last_element, c);

    cout << count(&last_element) << '\n';

    return 0;
}
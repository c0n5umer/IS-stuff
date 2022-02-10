#include <iostream>

using namespace std;

typedef struct Stack {
    int value;
    Stack *previous;
} Stack;

void push(Stack** last_element, int value)
{
    Stack* el = (Stack*)malloc(sizeof(Stack));

    el->value = value;
    el->previous = *last_element;
    *last_element = el;
}

int pop(Stack** last_element)
{
    int value = (*last_element)->value;
    Stack* temp_pointer = *last_element;

    *last_element = (*last_element)->previous;
    free(temp_pointer);
    return value;
}

int main(void)
{
    Stack *last_element;
    int n;

    last_element = NULL;

    freopen("Stack.in", "r", stdin);
    freopen("Stack.out", "w", stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char operation;
        int value;

        cin >> operation;

        if (operation == '+')
        {
            cin >> value;
            push(&last_element, value);
        }
        else if (operation == '-')
            cout << pop(&last_element) << "\n";         
    }

    return 0;
}
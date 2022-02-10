#include <iostream>

using namespace std;

typedef struct Queue {
    int value;
    Queue* next;
} Queue;

void push(Queue** tail, Queue** head, int x)
{
    Queue* element = *tail;

    *tail = (Queue*)malloc(sizeof(Queue));
    (*tail)->value = x;
    (*tail)->next = NULL;
    if (*head == NULL)
        *head = *tail;
    else
        element->next = *tail;
}

int pop(Queue** head)
{
    Queue* element = *head;

    *head = (*head)->next;
    return element->value;
}

int main(void)
{
    Queue* head = NULL, *tail = NULL;
    int n;

    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
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
           push(&tail, &head, value);
        }
        else if (operation == '-')
            cout << pop(&head) << "\n";
    }

    return 0;
}
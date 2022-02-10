/* Orlov Aleksandr, 12-5, M3107,  11.10.2021 */

#include <stdio.h>
#include <math.h>
#include "uint1024.h"

void find_rank(uint1024_t* result)
{
    int rank = 1;

    for (int i = ARR_SIZE - 1; i >= 0; i--)
        if (result->a[i] != 0)
        {
            rank = i + 1;
            break;
        }

    result->ranks = rank;
}

void init(uint1024_t* x)
{
    for (int i = 0; i < ARR_SIZE; i++)
        x->a[i] = 0;
}

void scanf_value(uint1024_t *x)
{
    char temp_str[STRING_SIZE];
    int i, digits = 0;

    init(x);

    for (i = 0; i < STRING_SIZE; i++)
        temp_str[i] = '\0';

    --i;
    scanf("%309s", temp_str);

    while (temp_str[i] == '\0')
        --i;

    while (i >= 0)
    {
        x->a[digits / INT_LEN] += (temp_str[i] - '0') * pow(10, digits % INT_LEN);
        --i;
        ++digits;
    }

    x->ranks = (digits - 1) / 9 + 1;
}

uint1024_t from_uint(unsigned int x)
{
    uint1024_t value;
    int digits = 0;

    init(&value);

    while (x > 0)
    {
        value.a[digits / INT_LEN] += (x % 10) * pow(10, digits % INT_LEN);
        x = x / 10;
        ++digits;
    }

    value.ranks = (digits - 1) / 9 + 1;

    return value;
}

void printf_value(uint1024_t x)
{
    int i;

    for (i = x.ranks - 1; i >= 0; i--)
    {
        int j = 8;

        while (i != x.ranks - 1 && pow(10, j--) - x.a[i] > 0 && j >= 0)
            printf("0");

        printf("%i", x.a[i]);
    }
}

uint1024_t add_op(uint1024_t x, uint1024_t y)
{
    uint1024_t result;
    unsigned long long buff = 0;
    
    init(&result);

    for (int i = 0; i < ARR_SIZE; i++)
    {
        buff = (long long)x.a[i] + (long long)y.a[i] + buff;
        result.a[i] = buff % BASE;
        buff /= BASE;
    }

    find_rank(&result);
    return result;
}

uint1024_t subtr_op(uint1024_t x, uint1024_t y)
{
    uint1024_t result;
    long long buff = 0;

    init(&result);

    for (int i = 0; i < ARR_SIZE; i++)
    {
        buff = (long long)x.a[i] - (long long)y.a[i] - buff;
        result.a[i] = buff >= 0 ? buff : BASE + buff;
        buff = buff >= 0 ? 0 : 1;
    }

    find_rank(&result);
    return result;
}

uint1024_t mult_op(uint1024_t x, uint1024_t y)
{
    uint1024_t result;
    unsigned long long buff = 0, carry = 0;

    init(&result);

    for (int i = 0; i < ARR_SIZE; i++)
        for (int j = 0; i + j < ARR_SIZE; j++)
        {
            buff = result.a[i + j] + (long long)x.a[i] * (long long)y.a[j] + carry;
            result.a[i + j] = buff % BASE;
            carry = buff / BASE;
        }

    find_rank(&result);
    return result;
}
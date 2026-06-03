#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void recerse_string(uint8_t *str, uint8_t len)
{
    uint8_t temp = '0';
    uint8_t loopVer = 0;
    for (loopVer = 0; loopVer < len / 2; loopVer++)
    {
        temp = str[loopVer];
        str[loopVer] = str[len - loopVer - 1];
        str[len - loopVer - 1] = temp;
    }
}

bool palndromeStr(uint8_t *str, uint8_t len)
{
    printf("%s\n", str);
    for (uint8_t i = 0; i < len / 2; i++)
        if (str[i] != str[len - i - 1])
        {
            printf("%c - %c \n", str[i], str[len - i - 1]);
            return false;
        }
    return true;
}
uint16_t factorial(uint8_t val)
{
    if (val < 1)
        return 1;
    return val * factorial(val - 1);
}
void palndromeNum(uint16_t Num, uint8_t *arr)
{
    printf("%d\n", Num);
    uint8_t temp = 1;
    uint16_t val = Num;
    uint8_t i = 0;
    while (val >= 1)
    {
        arr[i] = val % 10;
        val = val / 10;
        printf("val[%d]) = %d\n", i, arr[i]);
        i++;
    }
    arr[i] = '\0';
    printf("\n%s\n", arr);
}
void swapVar(uint16_t *a, uint16_t *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
bool isNumPrime(uint16_t num)
{
    if (num < 2)
        return 0;
    for (uint8_t i = 2; i <= num / 2; i++)
        if (num % i == 0)
            return 0;
    return 1;
}
bool isNumPrime1(uint16_t n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
void findMinMax(uint8_t *arr, uint8_t *min, uint8_t *max)
{
    uint8_t len = 0, i = 0, j = 0, cnt = 1;
    while (arr[i++] != '\0')
        ;
    len = i;
    printf("Len: %d\n", len);
    for (i = 0; i < len; i++)
        for (j = i; j < len; j++)
        {
            if (arr[i] < arr[j])
            {
                *max = arr[j];
                *min = arr[i];
                printf("%d %d - %d\n", cnt++, *max, *min);
            }
        }
}
typedef struct linkedList
{
    uint8_t data;
    struct linkedList *next;
} linkedList_t;
linkedList_t *head = NULL, *tail = NULL;

linkedList_t *createNode(uint16_t data)
{
    linkedList_t *node;
    if (head == NULL)
    {
        node = head = tail = (linkedList_t *)malloc(sizeof(linkedList_t));
        if (node != NULL)
        {
            node->data = data;
            node->next = NULL;
        }
    }
    else
    {
        node = (linkedList_t *)malloc(sizeof(linkedList_t));
        if (node != NULL)
        {
            node->data = data;
        }
    }
    return node;
}

int main()
{
    uint8_t arr[] = "Hello1";
    uint8_t arr1[] = "RADAR";
    uint8_t val = 5;
    printf("%s\n\n", arr);
    recerse_string(arr, strlen(arr));
    printf("%s\n", arr);

    if (palndromeStr(arr1, strlen(arr1)))
        printf("gevien str is Palondrom\n");
    else
        printf("NOT Palondrom\n");
    arr[0] = '\0'; // Reset the array for number palindrome check
    palndromeNum(12321, arr);
    if (palndromeStr(arr, strlen(arr)))
        printf("gevien Number is Palondrom\n");
    else
        printf("gevien Number is Not a Palondrom\n");

    printf("factorial of %d :%d\n", val, factorial(val));

    uint16_t a = 1024, b = 2048;
    printf("a = %d b = %d\n", a, b);
    swapVar(&a, &b);
    printf("a = %d b = %d\n", a, b);
    uint8_t numArr[11] = {2, 1, 3, 5, 7, 11, 10, 6, 102};
    for (uint8_t i = 0; i < 10; i++)
        if (isNumPrime1(numArr[i]))
            printf("%d is Prime number\n", numArr[i]);
        else
            printf("%d is not Prime number\n", numArr[i]);
    uint8_t min, max;
    findMinMax(numArr, &min, &max);
    return 0;
}

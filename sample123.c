#include <stdio.h>
void add(int a, int b)
{
    printf("Sum of %d and %d is %d\r\n", a, b, a + b);
}
int main()
{
    add(5, 10);
    return 0;
}
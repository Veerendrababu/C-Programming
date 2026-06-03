#include <stdio.h>
#include <stdint.h>
#include <string.h>
int arr[] = {1, 2, 3, 4, 5, 6, 17, 68, 9, 10};
int main()
{
    char strg[20] = "Veerendra Babu Bommakanti";
    uint8_t i = 0, Max, j;
    uint16_t strLen = 0, arrLen = 0;
    for (; strg[i] != '\0'; i++)
        printf("%c", strg[i]);
    ;
    printf("\r\n");

    strLen = i;
    i = 0;
    printf("%s length is 2: %d \r\n", strg, strLen);

    for (; arr[i] != '\0'; i++)
        printf("%d\r\n", arr[i]);
    arrLen = i;
    printf("arrLen : %d\r\n", arrLen);
    for (i = 0; i < arrLen; i++)
        for (j = i; j < arrLen; j++)
        {
            if ((arr[i] < arr[j]) && (i != j) && (arr[j] > Max))
                Max = arr[j];
            else if (i == 0 && j == 0)
                Max = arr[i];
        }
    printf("Max : %d \r\n", Max);

    Max = arr[0];
    for (i = 1; i < arrLen; i++)

        // second largest number in the array
        if (arr[i] > Max)
            Max = arr[i];
    printf("Max : %d \r\n", Max);

    return 0;
}
#include <stdio.h>

#define LENGTH 10

int main(void)
{
    int numbers[LENGTH] = {10, 1, 9, 2, 8, 3, 7, 4, 5, 6};

    int position, swap;
    for (int i = 0; i < LENGTH; i++)
    {
        position = i;
        for (int j = i + 1; j < LENGTH; j++)
        {
            if (numbers[position] > numbers[j])
            {
                position = j;
            }
            if (position != i)
            {
                swap = numbers[i];
                numbers[i] = numbers[position];
                numbers[position] = swap;
            }
        }
    }

    for (int k = 0; k < LENGTH; k++)
    {
        printf("%d ", numbers[k]);
    }
    printf("\n");
    return 0;
}
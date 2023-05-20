#include <stdio.h>

#define LENGTH 10

int main(void)
{
    int array[LENGTH] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};

    //loop to acess each array element
    for (int step = 0; step < LENGTH - 1; step++)
    {
        //loop to compare array elements
        for (int i = 0; i < LENGTH - step - 1; i++)
        {
            //compare two adjacent elements
            //just choose between > or <
            if (array[i] < array[i + 1])
            {
                //swapping occurs if elements are not in the order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }

    for (int j = 0; j < LENGTH; j++)
    {
        printf("%d ", array[j]);
    }
    printf("\n");
}
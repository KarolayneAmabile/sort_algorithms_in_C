#include <stdio.h>

void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int left, int right);
void merge_sorted_arrays(int a[], int left, int mid, int right);


int main(void)
{
    // test array and length
    int a[] = { 9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
    int length = 10;

    // sort the array using merge sort
    merge_sort(a, length);

    // print out the array elements to verify they have been sorted
    for (int i = 0; i < length; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}


void merge_sort(int a[], int length)
{
    // call the merge sort recursion function, the left index of 0 and
    // the rigth index of lenth - 1 are provided as we are initially looking
    // at sorting "the entire array"
    merge_sort_recursion(a, 0, length - 1);
}

// applies the merge sort algorithm to the array a between the left index 1
// and the right index r. This function implements the recursive
// divide-and-conquer step of the merge sort algorithm, splitting the array
// portion between 1... right at the middle, and calling itself on each portion,
// before applying the function to merge the sorted portions of the array
// that will result
void merge_sort_recursion(int a[], int left, int right)
{
    // we stop recursion when left >= right
    if (left < right)
    {
        // find the midpoint of left and right
        int mid = left + (right - left) / 2;

        // apply the function recursively to the left and right portions aplit
        // at the midpoint
        merge_sort_recursion(a, left, mid);
        merge_sort_recursion(a, mid + 1, right);

        // at this point both portions of the array have been sorted, and we now
        // merge the sorted portions of the array
        merge_sorted_arrays(a, left, mid, right);
    }
}

// erge the two sorted portions of the array a between the indexes 1 ... mid
// and mid + 1 ... right
void merge_sorted_arrays(int a[], int left, int mid, int right)
{
    // calculate the length of the left and right portions of the array
    int left_length = mid - left + 1;
    int right_length = right - mid;

    // create temporary arrays to store these portions
    int temp_left[left_length];
    int temp_right[right_length];

    // useed as index/counter variables for the 3 arrays: a, temp_left and temp_right
    int i, j, k;

    // copy the left portion into de temp_left array
    for (int p = 0; p < left_length; p++)
        temp_left[p] = a[left + p];

    // copy the right portion into the temp_right array
    for (int p = 0; p < right_length; p++)
        temp_right[p] = a[mid + 1 + p];


    for (i = 0, j = 0, k = left; k <= right; k++)
    {
        if ((i < left_length) &&
        (j >= right_length || temp_left[i] <= temp_right[j]))
        {
            a[k] = temp_left[i];
            i++;
        }
        else
        {
            a[k] = temp_right[j];
            j++;
        }
    }

}
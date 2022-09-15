#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 5000000
int ssc = 0;
int bsc = 0;
int isc = 0;
int msc = 0;
int qsc = 0;
void main()
{
    int arraySize, i;
    int array[1000000];
    printf("Enter size of array");
    scanf("%d", &arraySize);
    for (i = 0; i < arraySize; i++)
    {
        array[i] = i;
    }
    selection_sort(array, arraySize);
    bubblesort(array, arraySize);
    insertionsort(array, arraySize);
    merge_sort(array, 0, arraySize - 1);
    printf("Merge sort count is %d \n", msc);
    quicksort(array, 0, arraySize - 1);
    printf("Quick sort count is %d\n", qsc);
}
void selection_sort(int *a, long int size)
{
    long int temp, i, j;
    ssc++; // outter for loop last time condition check
    for (i = 0; i < size; i++)
    {
        ssc += 2; // outter for loop count
        ssc++;    // inner for loop last time condition check
        for (j = i + 1; j < size; j++)
        {
            ssc += 2; // inner for loop count
            if (a[i] > a[j])
            {
                ssc += 4; // if condition check and swapping
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("selection sort count is %d\n", ssc);
}
void bubblesort(int *a, long int n)
{
    long int pass, i, swap_flag, t;
    bsc++;
    for (pass = 0; pass < n - 1; pass++)
    {
        swap_flag = 0;
        bsc += 4;
        for (i = 0; i < n - 1 - pass; i++)
        {
            bsc += 2;
            if (a[i] > a[i + 1])
            {
                bsc += 5; // if and swapping
                t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
                swap_flag = 1;
            }
        }
        bsc += 1; // for if checking
        if (swap_flag == 0)
            bsc += 1; // for return
        printf("Bubble Sort count is %d\n", bsc);
        return;
    }
    bsc += 1; // for return
    printf("Bubble Sort count is %d\n", bsc);
    return;
}
void insertionsort(int *a, long int n)
{
    long int i, j, key;
    isc++;
    for (i = 1; i < n; i++)
    {
        isc += 2;
        key = a[i];
        isc++;
        j = i - 1;
        isc++;
        while (key < a[j] && j >= 0)
        {
            isc += 4;
            a[j + 1] = a[j];
            j = j - 1;
        }
        isc++;
        a[j + 1] = key;
    }
    isc++; // reutrn statement
    printf("Insertion Sort count is %d\n", isc);
    return;
}
void merge(int *a, long int low, long int mid, long int high)
{
    int temp[5000];
    long int i, j, k;
    msc += 4;
    k = low;
    j = mid + 1;
    i = low;
    while ((k <= mid) && (j <= high))
    {
        msc += 2; // while
        msc++;    // if
        if (a[k] <= a[j])
        {
            msc += 2; // inside content
            temp[i] = a[k];
            k++;
        }
        else
        {
            msc += 2; // inside content
            temp[i] = a[j];
            j++;
        }
        msc++;
        i++;
    }
    msc++;
    if (k <= mid)
    {
        msc += 1;
        for (; k <= mid; k++)
        {
            msc += 3;
            temp[i++] = a[k];
        }
    }
    else
    {
        msc++;
        for (; j <= high; j++)
        {
            msc += 3;
            temp[i++] = a[j];
        }
    }

    msc++;
    for (i = low; i <= high; i++)
    {
        msc += 3;
        a[i] = temp[i];
    }
}
void merge_sort(int *a, long int low, long int high)
{ // call this function from main
    msc++;
    if (low != high)
    {
        long int mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, mid, high);
        msc += 4;
    }
}
int quicksort(int *q, long int lb, long int ub)
{
    int flag = 1;
    qsc++;
    long int i = 0, j, key, t1, t2;
    qsc++;
    qsc++;
    if (lb < ub)
    {
        qsc += 3;
        i = lb;
        j = ub + 1;
        key = q[lb];
        qsc++;
        while (flag == 1)
        {
            qsc++;
            i++;

            qsc++;
            qsc++;

            while (q[i] < key)
            {
                qsc++;
                i++;
                qsc++;
            }
            qsc++;
            j--;
            qsc++;
            while (q[j] > key)
            {
                qsc++;
                j--;
                qsc++;
            }
            qsc++;
            if (i < j)
            {
                qsc += 3;
                t1 = q[i];
                q[i] = q[j];
                q[j] = t1;
            }
            else
            {
                flag = 0;
                qsc++;
            }
        }
        qsc += 3;
        t2 = q[lb];
        q[lb] = q[j];
        q[j] = t2;
        qsc += 2;
        quicksort(q, lb, j - 1);
        quicksort(q, j + 1, ub);
    }
    qsc += 1;
    return;
}

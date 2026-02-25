#include <stdio.h>

#define N 10

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

int main(void)
{
    int a[N] = { 12, 3, 10, 1, 8, 15, 5, 7, 9, 2 }; // テスト用の固定値
    int i;

    printf("Original array: ");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n\n");

    quicksort(a, 0, N - 1);

    printf("\nIn sorted order: ");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void quicksort(int a[], int low, int high)
{

    int middle;

    // 現在の担当範囲を表示
    printf("quicksort called: low = %d, high = %d\n", low, high);

    if (low >= high) {
        if (low == high)
            printf("  -> Base case: only one element at index %d\n", low);

        return;
    }

    middle = split(a, low, high);
    printf("  -> Split at index %d\n", middle);

    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

int split(int a[], int low, int high)
{
    int part_element = a[low];

    for (;;) {
        while (low < high && part_element <= a[high])
            high--;
        if (low >= high)
            break;

        a[low++] = a[high];

        while (low < high && a[low] <= part_element)
            low++;
        if (low >= high)
            break;
        a[high--] = a[low];
    }

    a[high] = part_element;
    return high;
}

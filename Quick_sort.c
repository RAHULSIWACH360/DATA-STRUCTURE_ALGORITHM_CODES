#include <stdio.h>

int partition(int a[], int lb, int ub) {
    int start = lb;
    int end = ub;
    int pivot = a[lb];
    int temp;

    while (start < end) {
        while (a[start] <= pivot && start <= ub) {
            start++;
        }
        while (a[end] > pivot && end >= lb) {
            end--;
        }
        if (start < end) {
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }

    a[lb] = a[end];
    a[end] = pivot;
    return end;
}

void quick_sort(int a[], int lb, int ub) {
    if (lb < ub) {
        int pos = partition(a, lb, ub);
        quick_sort(a, lb, pos - 1);
        quick_sort(a, pos + 1, ub);
    }
}

int main() {
    int n, i;
    printf("Enter the no. of elements you want to enter: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    quick_sort(a, 0, n - 1);

    printf("Order of sorted elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
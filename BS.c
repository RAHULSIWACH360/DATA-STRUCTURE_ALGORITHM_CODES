#include <stdio.h>

void InS(int b[], int len)
{
  int i, j, temp;

  for (i = 1; i < len; i++)
  {

    temp = b[i];
    j = i - 1;

    while (j >= 0 && b[j] > temp)
    {
      b[j + 1] = b[j];
      j--;
    }
    b[j + 1] = temp;
  }
}

void printArray(int b[], int len)
{
  int i;
  printf("The sorted array :");
  for (i = 0; i < len; i++)
  {
    printf("%d", b[i]);
  }
}

int bs(int a[], int n, int data)
{
  int l = 0, r = n - 1;

  while (l < r)
  {
    int mid = (l + r) / 2;

    if (data == a[mid])
      return mid;

    else if (data < a[mid])
    {
      r = mid - 1;
    }
    else
      l = mid + 1;
  }
  return -1;
}

int main()
{
  int i, n;
  printf("Enter the no. elements :");
  scanf("%d", &n);
  int a[n];
  printf("Enter the elements :\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

  InS(a, n);
  printArray(a, n);

  int data;

  printf("\nEnter the number you wnat to search :");
  scanf("%d", &data);

  int fn = bs(a, n, data);
  if (fn == -1)
  {
    printf("Data not found!!");
    return 0;
  }
  printf("Found it at %d", fn);
  return 0;
}

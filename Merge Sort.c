#include <stdio.h>

// Merge function
void merge(int a[], int l, int m, int r) { 
    int i = l, j = m + 1, k = 0;
    int temp[50];

    while (i <= m && j <= r) { 
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = temp[k];
}

// Merge Sort function
void mergeSort(int a[], int l, int r) {
    int m;
    if (l < r) {
        m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

// Main function
int main() {
  int a[50],n,i;
  printf("Enter no. of elements:");
  scanf("%d",&n);
  printf("Enter array element:");
  for(i=0;i<n;i++)
  {
      scanf("%d",&a[i]);
  }
    mergeSort(a, 0, n-1);

    printf("Sorted Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

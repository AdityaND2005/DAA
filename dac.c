#include <stdio.h>
#include <limits.h>

void divide_and_conquer(int arr[], int low, int high, int* min, int* max) {
    if (low == high) {
        *min = *max = arr[low];
        return;
    }
    
    int mid = low + (high - low) / 2;
    
    int left_min = INT_MAX, left_max = INT_MIN;
    int right_min = INT_MAX, right_max = INT_MIN;
    
    divide_and_conquer(arr, low, mid, &left_min, &left_max);
    divide_and_conquer(arr, mid + 1, high, &right_min, &right_max);
    
    *min = (left_min < right_min) ? left_min : right_min;
    *max = (left_max > right_max) ? left_max : right_max;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int min = INT_MAX, max = INT_MIN;
    divide_and_conquer(arr, 0, n-1, &min, &max);
    
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
    
    return 0;
}
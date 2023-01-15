#include <stdio.h>
#define swap(A, B) \
    int temp = A;   \
    A = B;        \
    B = temp;

int partition(int *arr, int left, int right){
    int i = left - 1, j = right, pivot = arr[right];
    for(;;) {
        while (arr[++i] < pivot);
        while (pivot < arr[--j])
            if (j == left) break;
        if (i >= j) break;
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[right]);
    return i;
}

void insertionSort(int *array, int left, int right){
    int currentElement, j, temp, i;

    for (i = right - 1; i > left; i--){
        if (array[i] < array[i - 1]){
            swap(array[i - 1], array[i]);
        }
    }

    for (j = 2; j <= right; j++){
        currentElement = j;
        temp = array[currentElement];

        while (temp < array[currentElement - 1]){
            array[currentElement] = array[currentElement - 1];
            currentElement--;
        }
        array[currentElement] = temp;
    }
}

void quickSort(int *arr, int left, int right){
    if (right - left <= 32)
        return;

    swap(arr[(left + right) / 2], arr[right - 1]);

    if (arr[left] < arr[right - 1]){
        swap(arr[left], arr[right - 1]);
    }
    if (arr[left] < arr[right]){
        swap(arr[left], arr[right]);
    }
    if (arr[right - 1] < arr[right]){
        swap(arr[right - 1], arr[right]);
    }

    int j = partition(arr, left + 1, right - 1);
    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
}

void quickSortWithInsertion(int *arr, int left, int right){
    quickSort(arr, left, right);
    insertionSort(arr, left, right);
}

int main(){
    int n;
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSortWithInsertion(&arr[0], 0, n - 1);

    for (int j = 0; j < n; j++)
        printf("%d ", arr[j]);
    printf("\n");
    return 0;
}

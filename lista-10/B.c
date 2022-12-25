#include <stdio.h>

void merge(int v[], int start, int mid, int end){
    int p = start, q = mid + 1, k = 0, Arr[end-start+1];
    for(int i = start; i <= end; i++){
        if(p>mid)
            Arr[k++] = v[q++];
        else if(q>end)
            Arr[k++] = v[p++];
        else if(v[p] < v[q])
            Arr[k++] = v[p++];
        else
            Arr[k++] = v[q++];
    }
    for(int p = 0; p < k; p++) v[start++] = Arr[p];
}

void merge_sort(int v[], int start, int end){
    if(start < end){
        int mid = (start + end)/2;
        merge_sort(v, start, mid);
        merge_sort(v, mid + 1, end);
        merge(v, start, mid, end);
    }
}

int main(){
    int n = 0;
    scanf("%d",&n);
    int v[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    merge_sort(v, 0, n-1);
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
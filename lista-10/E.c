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

int binary_search(int *v, int low, int high, int key){
    while(low <= high){
        int mid = (low + high)/2;
        if(v[mid] < key){
            low = mid + 1;
        } else if(v[mid] > key){
            high = mid - 1;
        } else{
            return 1;
        }
    }
    return -1;
}

int main(){
    int n = 0, p = 0;
    scanf("%d",&n);
    int v[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    merge_sort(v, 0, n-1);
    while(scanf("%d", &p) != EOF){
        if(binary_search(v, 0, n-1, p) == 1) printf("sim\n");
        else printf("nao\n");
    }
    return 0;
}
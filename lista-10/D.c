#include <stdio.h>

int binary_search(int *v, int low, int high, int key){
    if(v[high] < key){
        return high + 1;
    }
    if(v[low] > key){
        return 0;
    }
    while(low <= high){
        int mid = (low + high)/2;
        if(v[mid] < key){
            low = mid + 1;
        } else if(v[mid] >= key && v[mid - 1] >= key){
            high = mid - 1;
        } else{
            return mid;
        }
    }
}

int main(){
    int m = 0, n = 0;
    scanf("%d %d", &n, &m);
    int v_n[n], v_m = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &v_n[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &v_m);
        printf("%d\n", binary_search(v_n, 0, n-1, v_m));
    }
    return 0;
}
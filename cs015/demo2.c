#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("\nenter element to search\n");
    int el; scanf("%d", &el); printf("\n");
    int start = 0, end = 9, mid;

    while(start <= end){
        mid = (start+end)/2;
        if(arr[mid] == el){
            printf("\nelement found at %d\n", mid);
            return 0;
        }
        else if(el < arr[mid])
            end = mid - 1;
        else
            start = mid+1;
    }

    printf("\nelement not found\n");
    return 1;
}

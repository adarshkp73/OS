#include <stdio.h>
#include <stdlib.h>

int main(){
    //smallest in array
    int arr[10] = {24, 2345, 2435, 4, 4346, 2356, 896, 1, -5, 0};
    int min = arr[0], pos = 0;

    for(int i = 0; i < 10; i++){
        if(arr[i] < min){
            min = arr[i]; pos = i;
        }
    }

    printf("\nmin is %d at position %d\n", min, pos);
}

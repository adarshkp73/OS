#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //linear search
    printf("\nenter element to search\n");
    int el; scanf("%d", &el); printf("\n");
    for(int i = 0; i < 10; i++){
        if(arr[i] == el){
            printf("\nfound!\n");
            return 0;
        }
    }
    printf("\nnot found\n");
    return 1;
}


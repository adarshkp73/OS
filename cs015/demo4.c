#include <stdio.h>
#include <stdlib.h>

int main(){
    //using hash table to check duplicates
    int arr[10] = {45, 67, 45, 67, 89, 58, 10, 34, 38, 19};
    int table[10];

    for(int i = 0; i < 10; i++){
        //hash function mod
        int id = arr[i] % 10;

        if(table[id] == arr[i]){
            printf("\n%d is a duplicate\n", table[id]);
        }
        else{
            table[id] = arr[i];
        }
    }
    return 0;
}

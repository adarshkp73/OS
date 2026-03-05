#include <stdio.h>
#include <stdlib.h>

#define LEN 4

struct Process{
	int id, at, bt, ct, tat, wt;
};

typedef struct Process *process;

int main(){
	process arr[LEN]; int idx, a, b;
	
	for(int i = 0; i < LEN; i++){
		printf("\nenter id, at and bt respectively\n");
		scanf("%d%d%d", &idx, &a, &b);
		arr[i] = (process)malloc(sizeof(struct Process));
		arr[i]->id = idx; arr[i]->at = a; arr[i]->bt = b;
	}
	
	//sorting
	
	for(int i = 0; i < LEN; i++){
		int flag = 0;
		for(int j = 0; j < LEN-i-1; j++){
			if(arr[j]->at > arr[j+1]->at){
				process temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 1;
			}
		}
		if(flag == 0)
			break;
	}

	int time_step = arr[0]->at;

	for(int i = 0; i < LEN; i++){
		time_step += arr[i]->bt;

		arr[i]->ct = time_step;
		arr[i]->tat = arr[i]->ct - arr[i]->at;
		arr[i]->wt = arr[i]->tat - arr[i]->bt;
		
		if(i != LEN-1 && (arr[i+1]->at > arr[i]->ct))
			time_step += (arr[i+1]->at - arr[i]->ct);
	}

	printf("\nP_id \t AT \t BT \t CT \t TAT \t WT\n");

	for(int i = 0; i < LEN; i++)
		printf("\n%d \t %d \t %d \t %d \t %d \t %d\n", arr[i]->id, arr[i]->at, arr[i]->bt, arr[i]->ct, arr[i]->tat, arr[i]->wt);

	return 0;
}
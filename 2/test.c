#include<stdio.h>
#include<stdlib.h>
extern void selection_sort_asm(int array[], int num_elements);
int main()
{
	int i;
	int *array;
	array = (int *)malloc (8 * sizeof(int));
	array[0]=2;
	array[1]=3;
	array[2]=1;
	array[3]=4;
	for(i=0;i<4;i++)
		printf("%d ",array[i]);
	selection_sort_asm(array,4);
	for(i=0;i<4;i++)
                printf("%d ",array[i]);
	return 0;
}

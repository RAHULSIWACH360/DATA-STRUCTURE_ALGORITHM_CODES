#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct Job {

	char id; 
	int dead; 
	int profit; 
} Job;

int compare(const void* a, const void* b)
{
	Job* temp1 = (Job*)a;
	Job* temp2 = (Job*)b;
	return (temp2->profit - temp1->profit);
}

int min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

void PJS(Job arr[], int n)
{
	qsort(arr, n, sizeof(Job), compare);

	int result[n]; 
	bool slot[n]; 

	for (int i = 0; i < n; i++)
		slot[i] = false;

	for (int i = 0; i < n; i++) {
	
		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
		
			if (slot[j] == false) {
				result[j] = i; 
				slot[j] = true; 
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (slot[i])
			printf("%c ", arr[result[i]].id);
}


int main()
{
    int n,i;

printf("Enter the number of jobs to scheduled : ");
scanf("%d",&n);
    Job a[n];
for(i=0;i<n;i++)
{
printf("Enter the Name for %d the jobs to be executed : ",i+1);
    scanf(" %c",&a[i].id);

printf("Enter the Dealine for %d the jobs to be executed : ",i+1);
    scanf(" %d",&a[i].dead);

printf("Enter the Profit for %d the jobs to be executed : ",i+1);
    scanf(" %d",&a[i].profit);
}
	printf("Following is maximum profit sequence of jobs \n");
	PJS(a, n);
	return 0;
}

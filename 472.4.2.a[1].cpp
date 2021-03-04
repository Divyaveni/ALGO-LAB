#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);


        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{ int i;
	double total_time;
	clock_t start, end;
	start = clock();
	srand(time(NULL));
    int arr[100000],n=1;
    while(n>0)
    {
   printf("\n\nPress -1 to Exit");
   printf("\nEnter the size of array\t");
    scanf("%d",&n);
    if(n==-1)
    {
    break;
    }
    if(n==-1)
    {
      exit(0);
    }
    for(int i=0;i<n;i++)
	{
	    arr[i]=rand()%1000;
	}
    quickSort(arr, 0, n-1);
    printf("Sorted array: ");
    printArray(arr, n);
    end = clock();
   	total_time = ((double) (end - start))/  CLOCKS_PER_SEC ;
	printf("\nTime taken to print %d random number is: %f",n, total_time);
	}
    return 0;
}

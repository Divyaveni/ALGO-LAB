#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define Max 20
int arr[Max];

void build_minheap(int [],int,int);
void heapify(int [],int,int);
void heapSort(int [],int);
void printArray(int [], int);
void insert_minheap(int[],int,int);


int main()
{
  int n;
  char c;

  cout<<"Enter the no. of elements: ";
  cin>>n;
  cout<<"Enter the elements: ";

  for(int i = 0;i<n;i++)
  cin>>arr[i];

	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);

  cout<<"Do you want  to insert a new element(y/n): ";
  cin>>c;

  if(c == 'y')
  {
    n++;
    int next;
    cout<<"Enter new number: ";
    cin>>next;
    insert_minheap(arr,n,next);
    printArray(arr,n);
    return 0;
  }
  else
  return 0;
}
void build_minheap(int arr[], int n, int i)
{
	int smallest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;


	if (l < n && arr[l] < arr[smallest])
		smallest = l;

	if (r < n && arr[r] < arr[smallest])
		smallest = r;

  heapify(arr, n, i);


}
void heapify(int arr[], int n, int i)
{
    int smallest = i;
    if (smallest != i) {
  		swap(arr[i], arr[smallest]);

  		build_minheap(arr, n, smallest);
    }
}

void heapSort(int arr[], int n)
{

	for (int i = n / 2 - 1; i >= 0; i--)
		build_minheap(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {

		swap(arr[0], arr[i]);

		build_minheap(arr, i, 0);
    sort(arr, arr+n, greater<int>());
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

void insert_minheap(int arr[],int n,int next)
{
    arr[n-1] = next;

    heapSort(arr,n);
}

#include <iostream>
using namespace std;
class Heap
{
public:
	Heap(int *array,int size)
	{
		arr = new int[15];
		for(int i(0); i < size; i++) {
           arr[i] = array[i];
        }
        n = size;
	}
	void Maxheapify(int k,int i)
	{
		int temp;
		int largest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if (l < k && arr[l] > arr[largest])
		{
		    largest = l;
		}
		if (r < k && arr[r] > arr[largest])
		{
		    largest = r;
		}
		if (largest != i)
		{
		    temp = arr[i];
		    arr[i] = arr[largest];
		    arr[largest] = temp;
		    Maxheapify(k, largest);
		}
	}

	void display()
	{
		cout<<"The elements in the heap :\n";
		for (int i = n-1; i >=0; i--)
		{
			cout<<arr[i]<<"\n";
		}
	}

	void insertNewElement(int num)
	{
		n = n+1;
		arr[n-1] = num;
		Maxheapify(n,n-1);
	}

	void deleteElement(int num)
	{
		int temp;
		int del;
		for (int i = 0; i < n; ++i)
		{
			if (num == arr[i])
			{
				del = i;
				break;
			}

		}
		temp = arr[n-1];
		arr[n-1] = arr[del];
		arr[del] = temp;
		n = n-1;
		Maxheapify(n,n-1);

	}
private:
	int* arr;
  	int n;
};
int main(int argc, char const *argv[])
{
	int arr[100];
	int size = 0;
	int i = 0;
	cout<<"Enter an element into the heap : \n";
	cin>>arr[i];
	Heap s(arr,1);


	while(true)
	{
		int ch;
		cout<<"Enter\n1. Insert a new element in the heap\n2. Delete an Element from the heap\n3. Display\n4. EXIT\n";
		cin>>ch;
		if (ch == 1)
		{
			int num;
			cout<<"Enter a number :";
			cin>>num;
			s.insertNewElement(num);
			cout<<num<<" is inserted\n";
		}
		else if (ch == 2)
		{
			int num;
			cout<<"Enter the number delete from the heap : \n";
			cin>>num;
			s.deleteElement(num);
			cout<<num<<" is deleted";

		}
		else if (ch == 3)
		{
			s.display();
		}
		else if(ch == 4)
		{
			break;
		}

	}

	return 0;
}

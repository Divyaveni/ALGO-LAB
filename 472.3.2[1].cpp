#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;

void Minheapify(string arr[], int n, int i)
{
int smallest = i;
int l = 2*i + 1;
int r = 2*i + 2;
if (l < n && arr[l] < arr[smallest])
smallest = l;
if (r < n && arr[r] < arr[smallest])
smallest = r;
if (smallest != i)
{
swap(arr[i], arr[smallest]);
Minheapify(arr, n, smallest);
}
}

void BuildMinHeap(string arr[], int n)
{
for (int i = n / 2 - 1; i >= 0; i--)
Minheapify(arr, n, i);
for (int i=n-1; i>=0; i--)
{
swap(arr[0], arr[i]);
Minheapify(arr, i, 0);
}
}

void printfile(string arr[], int n)
{
ofstream out;
out.open("outputfile.txt");
for(int i=n; i>=0; i--)
{
    out<<arr[i]<<"\n";
}
}

int main()
{
string arr[20];
int i=0;
ifstream in;
in.open("inputfile.txt");
while(!in.eof())
{
in>>arr[i];
i++;
}
BuildMinHeap(arr, i+1);
printfile(arr, i+1);
return 0;
}

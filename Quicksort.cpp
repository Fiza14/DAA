#include <algorithm>
#include <chrono>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
using namespace std::chrono;

int partitionM(int arr[], int l, int r, int k);
int kthSmallest(int arr[], int l, int r, int k);

//to take input in array
void input(int arr[],int size){
    int a=size;
	for(int i=0;i<size;i++){
		 arr[i]=a;
         a--;
	}
}

void print_array(int arr[],int size){

	cout<<"\nArray elements : ";
	for(int i=0;i<size;i++){
		cout<<" ";
		cout<<arr[i];
	}
}

int partition(int arr[],int low,int high){
	int pivot=arr[low];
	int i=low;
	int j=high;

	while(i<j){
		while(arr[i]<=pivot){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
		if(i<j){
			int t=arr[i];
			arr[i]=arr[j];
			arr[j]=t;
		}
	}
	swap(arr[j],arr[low]);


	return j;
}

void quick_sort(int arr[],int low,int high){
	if(low<high){
		int pivot=partition(arr,low,high);

		quick_sort(arr,low,pivot-1);
		quick_sort(arr,pivot+1,high);


	}
}
void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int n = h-l+1;

        int med = kthSmallest(arr, l, h, n/2);

        int p = partitionM(arr, l, h, med);

        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}

int findMedian(int arr[], int n)
{
    sort(arr, arr+n);
    return arr[n/2];
}


int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1;


        int i, median[(n+4)/5];
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n)
        {
            median[i] = findMedian(arr+l+i*5, n%5);
            i++;
        }


        int medOfMed = (i == 1)? median[i-1]:
                                 kthSmallest(median, 0, i-1, i/2);

        int pos = partitionM(arr, l, r, medOfMed);


        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)
            return kthSmallest(arr, l, pos-1, k);

        return kthSmallest(arr, pos+1, r, k-pos+l-1);

    }
    return INT_MAX;

}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partitionM(int arr[], int l, int r, int x)
{
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);

    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int main(){
	int size;
	cout<<"Enter the size : ";
	cin>>size;

	int arr[size];
    int arr1[size];
    int arr2[size];

	input(arr,size);
    input(arr1,size);
    input(arr2,size);

    cout<<"\n---------  ARRAY BEFORE SORTING -------------------"<<endl;
	print_array(arr,size);



    cout<<"\n---------  ARRAY AFTER QUICK SORT SORTING -------------------"<<endl;
    auto start_quick = high_resolution_clock::now();
	quick_sort(arr,0,size-1);
    auto stop_quick = high_resolution_clock::now();
	print_array(arr,size);



    cout<<"\n---------  ARRAY AFTER Quick SORT SORTING BY median-------------------"<<endl;
    auto start_quick_median = high_resolution_clock::now();
    quickSort(arr2,0,size-1);
    auto stop_quick_median = high_resolution_clock::now();
    print_array(arr2,size);


    auto duration_quick = duration_cast<microseconds>(stop_quick - start_quick);

    auto duration_quick_median = duration_cast<microseconds>(stop_quick_median - start_quick_median);
    cout << "\nTime taken by Quick Sort: "<< duration_quick.count() << " microseconds" << endl;

    cout << "\nTime taken by Quick Sort by median: "<< duration_quick_median.count() << " microseconds" << endl;




	return 0;
}

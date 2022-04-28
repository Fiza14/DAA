#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int BinarySearch(int arr[], int x, int n) {
  int low ,high =0;
   high = n-1;
	// Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == x)
      return mid;

    if (arr[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main(){
     int n=1000; 
    // cout<<"\nEnter The Number of Element  : ";
    // cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    int target =0;
    cout<<"Enter Element to searched :";
    cin>>target;
 clock_t start,end;
    start =clock();
   cout<<"\nThe Position of the Element by Binary search :"<< BinarySearch(arr,target,n)<<endl;
   end =clock();

   double time_taken = double(end -start)/double(CLOCKS_PER_SEC);

   cout<<"\nTime Taken T2 = "<<time_taken;

}
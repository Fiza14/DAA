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


int LinearSearch(int arr[],int target,int n){
    for (int  i = 0; i < n; i++)
    {
        if(arr[i]==target){
            return i;
        }
    }
    return -999;
    
}

 int main(){
     int n=10000; 
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
    //Time Taken By Binary search
    clock_t start,end;
    start =clock();
   cout<<"\nThe Position of the Element by Binary search :"<< BinarySearch(arr,target,n)<<endl;
   end =clock();

   double time_taken = double(end -start)/double(CLOCKS_PER_SEC);

   
    //Time taken By Linear Search start Here 
    clock_t start1,end1;
    start1 =clock();
   cout<<"\nThe Position of the Element Linear :"<< LinearSearch(arr,target,n)<<endl;
   end1 =clock();

   double time_taken1 = double(end1 -start1)/double(CLOCKS_PER_SEC);

    cout<<"\n1]. Time  By Linear Search \t 2].Time By Binary search\n";
    cout<<"Time T1 ="<<time_taken1<<"\t\t Time T2 ="<<time_taken<<endl;


 }
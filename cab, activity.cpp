#include<iostream>

using namespace std;
// Prints a maximum set of activities that can be done by a single
// person, one at a time.
//  n   -->  Total number of activities
//  s[] -->  An array that contains start time of all activities
//  f[] -->  An array that contains finish time of all activities
int printMaxActivities(int s[], int f[], int n)
{
    int i, j, count =1;
    printf ("No of person selected \n");

    // The first activity always gets selected
    i = 0;
    printf("%d ", i);

    // Consider rest of the activities
    for (j = 1; j < n; j++)
    {
      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
      if (s[j] >= f[i])
      {
          printf ("%d ", j);
          i = j;
          count++;
      }

    }
    return count;
}


int main()
{
    int s[30],f[30], n;

    cout<<"\n Enter the number of person :";
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cout<<"\n Start time for "<<i<<" person :";
        cin>>s[i];
        cout<<"\n Finish time for "<<i<<" person :";
        cin>>f[i];
    }
    int result= printMaxActivities(s, f, n);
    cout<<"\n Number of Cabs required :"<<result;
    return 0;
}

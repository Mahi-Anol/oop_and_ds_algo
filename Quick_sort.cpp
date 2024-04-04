#include<bits/stdc++.h>
using namespace std;

int correct_place_of_pivot(int *arr,int s,int e)
{
    srand(time(nullptr));
    int pivot=s+(rand()%(e-s));

    swap(arr[e],arr[pivot]);

    int pos=s;

    for(int i=s;i<=e-1;i++)
    {
        if(arr[i]<arr[e])
        {
            swap(arr[i],arr[pos]);
            pos++;
        }
    }

    swap(arr[pos],arr[e]);
    return pos;
}
void quick_sort(int *arr,int s,int e)
{
    if(s>=e)
    {
        return;
    }
     int p=correct_place_of_pivot(arr,s,e);
     quick_sort(arr,s,p-1);
     quick_sort(arr,p+1,e);
}
int main(){
//  int a[] = {-1,3,4,-1000,2000,2,7,3,10,5,6,2,-5};//error datasset
  int a[] = {2,-1,2,4,-1000,3,1,2,10,5,6,2,-5,50,-1000,-2200,-200};
//    int a[]={-1};

  int n=sizeof(a)/sizeof(a[0]);

  quick_sort(a,0,n-1);

  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}

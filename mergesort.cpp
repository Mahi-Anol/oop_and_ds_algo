#include<bits/stdc++.h>
using namespace std;


void merge(int *arr,int s,int e)
{

    int i=s;//First array staring point.
    int mid=s+(e-s)/2;//First array end point.
    int j=mid+1;//Second array starting point.
    int iter=0;//Temp array iterator.
    int temp[e-s+1];

    while(i<=mid||j<=e)
    {
        if(i>mid)
        {
            while(j<=e)
            {
                temp[iter++]=arr[j++];
            }
            break;
        }
        else if(j>e)
        {
            while(i<=mid)
            {

                temp[iter++]=arr[i++];
            }
            break;
        }
        else if(arr[i]<=arr[j])temp[iter++]=arr[i++];
        else temp[iter++]=arr[j++];
    }
    for(int i=s;i<=e;i++)
    {
        arr[i]=temp[i-s];//We were using zero indexing in the temp...Thats why.
    }
}
void mergesort(int *arr,int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int mid=s+(e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
}



int main(){
//  int a[] = {-1,3,4,-1000,2000,2,7,3,10,5,6,2,-5};//error datasset
  int a[] = {2,-1,2,4,-1000,3,1,2,10,5,6,2,-5,50,-1000,-2200,-200};

  int n=sizeof(a)/sizeof(a[0]);

  mergesort(a,0,n-1);

  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}

#include<bits/stdc++.h>
using namespace std;


void reverse_a(int *arr,int st,int end)
{
    if(st>end)return;
    swap(arr[st],arr[end]);
    return reverse_a(arr,st+1,end-1);

}

int main(){
//  int a[] = {-1,3,4,-1000,2000,2,7,3,10,5,6,2,-5};//error datasset
  int a[] = {2,-1,2,4,-1000,3,1,2,10,5,6,2,-5,50,-1000,-2200,-200};
//    int a[]={-1};

  int n=sizeof(a)/sizeof(a[0]);

  reverse_a(a,0,n-1);

  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}

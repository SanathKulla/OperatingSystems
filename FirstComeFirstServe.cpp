#include<bits/stdc++.h>
using namespace std;

int n;
struct job{
    int id,at,bt;
};
void merge(int lo,int mid,int hi,job a[]){
      int i = lo,j = mid+1,size = hi - lo + 1;
      job v[size];
      int ind = 0;
      while(i<=mid && j<=hi){
         if(a[i].at < a[j].at)v[ind++] = a[i++];
         else if(a[i].at == a[j].at && a[i].id < a[j].id)v[ind++] = a[i++];
         else v[ind++] = a[j++];
      }
      while(i<=mid)v[ind++] = a[i++];
      while(j<=hi)v[ind++] = a[j++];
      for(int k = 0;k<size;k++)a[lo++] = v[k];
}

void sort(job a[] ,int lo = 0,int hi = n-1){
       if(lo>=hi)return;       
       int mid = lo + (hi - lo)/2;  
       sort(a,lo,mid),sort(a,mid+1,hi); 
       merge(lo,mid,hi,a);    
}



signed main(){

  cin>>n;
   job a[n];
  for(int i = 0;i<n;i++){
     cin>>a[i].at;
     a[i].id = i;
  }
  for(int i = 0;i<n;i++){
     cin>>a[i].bt;
  }  
  sort(a);
  int ct[n];
  int tat[n],wt[n];
  double avg_tat=0,avg_awt=0;
  int cur_time = 0;
  
  for(int i = 0;i<n;i++){
      if(cur_time < a[i].at){
         cur_time = a[i].at + a[i].bt;
      }else{
          cur_time += a[i].bt;
      } 
      ct[a[i].id] = cur_time; 
      tat[a[i].id] = ct[a[i].id] - a[i].at;
      wt[a[i].id] = tat[a[i].id] - a[i].bt;
      avg_tat += tat[a[i].id] , avg_awt += wt[a[i].id];      
  }
  avg_tat/=n,avg_awt/=n;
  cout<<"ct tat wt"<<endl;
   for(int i = 0;i<n;i++){
     cout<<ct[i]<<" "<<tat[i]<<" "<<wt[i]<<" "<<endl; 
  }   
  cout<<"ATAT "<<avg_tat<<endl;
  cout<<"AWT "<<avg_awt<<endl;


  
  
  
  

}

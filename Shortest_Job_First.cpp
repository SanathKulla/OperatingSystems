#include<iostream>
#include <vector>
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

class priority_queue{
  public:
  
    vector<job> v;
    
    
    void heapify(int start ,int limit){
        int left = 2*start + 1;
        int right = 2*start + 2;
        int min_ind = start;
        if(left < limit){
           if(v[left].bt < v[min_ind].bt or (v[left].bt == v[min_ind].bt && v[left].at < v[min_ind].at) or (v[left].bt == v[min_ind].bt && v[left].at == v[min_ind].at && v[left].id < v[min_ind].id )){
              min_ind = left;
           }
        }
        if(right < limit){
           if(v[right].bt < v[min_ind].bt or (v[right].bt == v[min_ind].bt && v[right].at < v[min_ind].at) or (v[right].bt == v[min_ind].bt && v[right].at == v[min_ind].at && v[right].id < v[min_ind].id )){
              min_ind = right;
           }
        }  
        
        if(min_ind != start){
           swap(v[min_ind],v[start]);
           heapify(min_ind,limit);
        }      
    }
    
    void push(job cur){
         v.push_back(cur);
         int child = v.size() - 1;
         int par = (child - 1)/2;
         while(v[par].bt > v[child].bt or  (v[par].bt == v[child].bt and v[par].at > v[child].at) or(v[par].bt == v[child].bt and v[par].at ==  v[child].at && v[par].id > v[child].id) ){
              swap(v[par],v[child]);
              child = par;
              par = (child - 1)/2;
         }
    }
    
    void pop(){
           swap(v[0] , v[v.size()-1]);
           v.pop_back();
           heapify(0,v.size());
    }
    
    job top(){
         return v[0];
    }
    
    int size(){
         return v.size();
    }
  
};



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
  priority_queue pq;
 
  int j = 0;
  int cur_time = a[0].at;
  while(j < n && a[j].at == a[0].at){
     pq.push(a[j++]);
  }
  
  while(pq.size() or j < n){
       job top = pq.top();
       pq.pop();
       cur_time += top.bt;
       ct[top.id] = cur_time;
       
       while(j < n && a[j].at <= cur_time){
          pq.push(a[j++]);
       }
       
       if(pq.size() == 0 && j < n){
       cur_time = a[j].at;
       while(j < n && a[j].at <= cur_time){
          pq.push(a[j++]);
       }      
       } 
  
  }
  
  for(int i = 0;i<n;i++){
      int j = a[i].id;
      tat[j] = ct[j] - a[i].at;
      wt[j] = tat[j] - a[i].bt;
      avg_tat+=tat[j];
      avg_awt+=wt[j];
  }
  

  avg_tat/=n,avg_awt/=n;
  cout<<"ct tat wt"<<endl;
   for(int i = 0;i<n;i++){
     cout<<ct[i]<<" "<<tat[i]<<" "<<wt[i]<<" "<<endl; 
  }   
  cout<<"ATAT "<<avg_tat<<endl;
  cout<<"AWT "<<avg_awt<<endl;
  
  }

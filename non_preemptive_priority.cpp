#include<bits/stdc++.h>
using namespace std;

template<class T> using pqg = priority_queue<T , vector<T> , greater<T>>;


signed main(){
    int n,tq;
    cin>>n;

    vector<array<int,4>> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i][1];
        v[i][2] = i;
    }
    for(int i = 0;i<n;i++){
        cin>>v[i][3];
    }
    for(int i = 0;i<n;i++){
        cin>>v[i][0];
    }
    vector<int> ct(n);
    vector<int> tat(n);

    sort(v.begin(),v.end(),[&](array<int,4> &a,array<int,4> &b){
           return a[1] < b[1] or (a[1] == b[1] and a[2] < b[2]);
    });
    
    pqg<array<int,4>> pq;
    int cur = v[0][1];
    int i = 0;
    while(i < n and v[i][1] <= cur)pq.push(v[i]),i++;
    while(pq.size()){
          array<int,4> top = pq.top();
          pq.pop();
          cur += top[3];
          ct[top[2]] = cur;
          while(i < n and v[i][1] <= cur){
              pq.push(v[i]);
              i++;
          }
       
          if(pq.empty() and i<n){
            cur = v[i][1];
          while(i < n and v[i][1] <= cur){
              pq.push(v[i]);
              i++;
          }
          }
    }

    for(int i = 0;i<n;i++){
        cout<<ct[i]<<endl;
    }
    
}

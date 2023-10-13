#include<bits/stdc++.h>
using namespace std;

template<class T> using pqg = priority_queue<T , vector<T> , greater<T>>;

struct process{
    int at,bt,id,rt;
};

signed main(){
    int n,tq;
    cin>>n>>tq;
    vector<process> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i].at;
        v[i].id = i;
    }
    for(int i = 0;i<n;i++){
        cin>>v[i].bt;
        v[i].rt = v[i].bt;
    }

    vector<int> ct(n);
    vector<int> tat(n);

    sort(v.begin(),v.end(),[&](process &a,process &b){
           return a.at < b.at or (a.at == b.at and a.id < b.id);
    });

    queue<process> q;
    int cur = v[0].at;
    int i = 1;
    q.push(v[0]);
    while(q.size()){
          process top = q.front();
          q.pop();
          bool push = true;
          if(top.rt > tq){
               top.rt-= tq;
               cur += tq;
          }else{
              cur += top.rt;
              top.rt = 0;
              ct[top.id] = cur;
              push = false;
          }

          while(i < n and v[i].at <= cur){
              q.push(v[i]);
              i++;
          }
          if(push){
             q.push(top);
          }

          if(q.empty() and i<n){
            cur = v[i].at;
          while(i < n and v[i].at <= cur){
              q.push(v[i]);
              i++;
          }
          }
    }

    for(int i = 0;i<n;i++){
        cout<<ct[i]<<endl;
    }
    
}

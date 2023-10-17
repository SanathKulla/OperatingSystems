#include<bits/stdc++.h> 
using namespace std;

signed main(){
   string s;
   int f;
   cin>>s>>f;
   vector<bool> there(10);
   queue<int> q;
   int page_fault = 0;
   for(auto &it:s){
       if(there[it-'0'])continue;
       if(q.size() == f){
         there[q.front()] = 0;
         q.pop();
         there[it-'0'] = 1;
         q.push(it-'0');
       }else{
         there[it-'0'] = 1;
         q.push(it-'0');
       }
       ++page_fault;
   }
   cout<<page_fault<<endl;
}
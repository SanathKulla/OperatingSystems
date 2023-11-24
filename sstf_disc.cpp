#include<bits/stdc++.h>

using namespace std;

int main(){
    int head , n;
    cin>>head>>n;

    vector<int> v(n);
    vector<bool> vis(n,0);
    vector<int> sequence;
    sequence.push_back(head);
    for(int i=0; i<n; i++){
            cin>>v[i];
    }
    int head_moments = 0;
        //brute force
    /*
    while(true){
    int mini = 201;
    int ind = -1;        
    for(int i = 0;i<n;i++){
        if(vis[i])continue;
        if(abs(head - v[i]) < mini){
            mini = abs(head - v[i]);
            ind = i;
        }
    }
    if(ind == -1)break;
    head_moments += abs(head - v[ind]);
    head = v[ind];
    vis[ind] = 1;
    sequence.push_back(head);
   }
   cout<<head_moments<<endl;
   for(auto it:sequence){
       cout<<it<<" ";
   }
   cout<<endl;
   */

    // by sets
    /*
    set<int> left , right;
    for(int i=0; i<n; i++){
            if(v[i]<=head){
                left.insert(v[i]);
            }else{
                right.insert(v[i]);
            }
    }
    while(left.size() or right.size()){
        int l = 1e9 , r = 1e9;
        if(left.size()) l = abs(head - *left.rbegin());
        if(right.size()) r = abs(head - *right.begin());
        if(l <= r){
              head_moments += abs(head - *left.rbegin());
              head = *left.rbegin();
              left.erase(--(left.end()));
        }else{
              head_moments += abs(head - *right.begin());
              head = *right.begin();
              right.erase(right.begin());
        }
        sequence.push_back(head);
    }
   cout<<head_moments<<endl;
   for(auto it:sequence){
       cout<<it<<" ";
   }
   */

    // by sorting and two pointers

    sort(v.begin() , v.end());
    int l = -1 , r = n;
    for(int i=0; i<n; i++){
            if(v[i] <= head)l = i;
    }
    for(int i = n-1;i>=0;i--){
        if(v[i] > head)r = i;
    }
    while(l >= 0 or r<n){
        int left = 1e9 , right = 1e9;
        if(l>=0)left = abs(head - v[l]);
        if(r < n)right = abs(head - v[r]);
        if(left<=right){
            head_moments += abs(head - v[l]);
            head = v[l];
            --l;
        }else{
            head_moments += abs(head - v[r]);
            head = v[r];
            ++r;
        }
        sequence.push_back(head);
    }
   cout<<head_moments<<endl;
   for(auto it:sequence){
       cout<<it<<" ";
   }


}

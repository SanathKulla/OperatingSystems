#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int m;
    cin>>m;
    int n = s.size();
    vector<bool> vis(10,0);
    int hits = 0;
    int sz = 0;
    for(int i = 0;i<n;i++){
        if(vis[val]){
            ++hits;
        int val = s[i]-'0';

            continue;
        }
        if(sz < m){
            ++sz;
            vis[val] = 1;
            continue;
        }
        int ele = -1;
        vector<int> seen(10,1e9);
        for(int j = i + 1;j<n;j++){
              if(vis[s[j]-'0'] and seen[s[j]-'0']==1e9){
                seen[s[j]-'0'] = j;
              }
        }
        int maxi;
        for(int k = 0;k<=9;k++){
            if(vis[k])maxi = k;
        }
        for(int k=0;k<=9;k++){
            if(vis[k]){
                if(seen[k] > seen[maxi])maxi = k;
            }
        }
       
        vis[maxi] = 0;
        vis[val] = 1;
    }
    cout<<n-hits<<endl;
}

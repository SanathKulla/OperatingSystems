#include<bits/stdc++.h> 
using namespace std;

int main(){
    int m;
    cin>>m;
    string s;
    cin>>s;
    int n = s.size();
    vector<int> track(10,-1);
    vector<int> order(n,-1);
    int cur = -1;
    int mini = 0;
    int ans = 0;
    int size = 0;
    for(auto &it:s){
         if(track[it-'0'] == -1){
             ++ans;
             if(size == m){
                    while(order[mini] == -1)++mini;
                    track[order[mini]] = -1;
                    order[mini] = -1;
                    track[it-'0'] = ++cur;
                    order[cur] = it-'0';
             }else{
                ++size;
                track[it-'0'] = ++cur;
                order[cur] = it-'0';
             }
             
         }else{
            order[track[it-'0']] = -1;
            track[it-'0'] = ++cur;
            order[cur] = it-'0';
         }
    }
    cout<<ans<<endl;

}

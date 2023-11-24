#include<bits/stdc++.h>

using namespace std;

int main(){
    int head , n;
    cin>>head>>n;
    vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
    }
    sort(v.begin() , v.end());
    int head_moments = 0;
    vector<int> sequence;
    sequence.push_back(head);
    //right
    int r = n;
    for(int i = n-1;i>=0;i--){
        if(v[i]>=head)r = i;
    }
    int l = r-1;
    while(r < n){
       head_moments += abs(head - v[r]);
       head = v[r];
       sequence.push_back(head);
       ++r;
    }
    while(l >= 0){
       head_moments += abs(head - v[l]);
       head = v[l];
       sequence.push_back(head);
       --l;  
    }
    cout<<head_moments<<endl;
    for(auto it:sequence){
        cout<<it<<" ";
    }
    cout<<endl;

}

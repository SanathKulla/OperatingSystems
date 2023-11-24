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
    head_moments += 200 - head;
    head = 0;
   for(int i=0; i<=l; i++){
           head_moments += abs(head - v[i]);
           head = v[i];
          sequence.push_back(head);
   }
    cout<<head_moments<<endl;
    for(auto it:sequence){
        cout<<it<<" ";
    }
    cout<<endl;

}

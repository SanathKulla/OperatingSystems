#include<bits/stdc++.h>

using namespace std;

int main(){
    int head , n;
    cin>>head>>n;
    queue<int> q;
    while(n--){
        int x;
        cin>>x;
        q.push(x);
    }
    vector<int> sequence;
    sequence.push_back(head);
    int head_moments = 0;
    while(q.size()){
       head_moments += abs(head - q.front());
       head = q.front();
       q.pop();
       sequence.push_back(head);
    }

    cout<<head_moments<<endl;

    for(auto it:sequence){
        cout<<it/<<" ";
    }
    cout<<endl;
}

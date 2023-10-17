#include<bits/stdc++.h> 
using namespace std;

signed main(){
	int n,m;
	cin>>n>>m;
	vector<int> process(n);
	set<array<int,2>> blocks;
	for(int i=0; i<n; i++){
	     cin>>process[i];
	}
	for(int i=0; i<m; i++){
		    int x;
	        cin>>x;
	        blocks.insert({x,i});    
	}
	vector<int> waiting;
	vector<int> ans(m,-1);
	for(int i=0; i<n; i++){
	        auto it = blocks.lower_bound({process[i],0});
	        if(it == blocks.end()){
	        	waiting.push_back(i+1);
	        	continue;
	        }
	        ans[(*it)[1]] = i+1;
	        blocks.erase(it);
	}
	for(int i=0; i<m; i++){
	        cout<<ans[i]<<endl;
	}
	if(waiting.size()){
		cout<<"The waiting processes are\n";
		for(auto &it:waiting){
			cout<<it<<" ";  
		}
	}

	
}
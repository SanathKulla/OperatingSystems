#include<bits/stdc++.h> 
using namespace std;

signed main(){
	int n,m;
	cin>>n>>m;
	vector<int> process(n);
	vector<array<int,2>> blocks(m);
	for(int i=0; i<n; i++){
	     cin>>process[i];
	}
	for(int i=0; i<m; i++){
		    cin>>blocks[i][0];
	        blocks[i][1] = i;  
	}
	vector<int> waiting;
	sort(blocks.begin() , blocks.end());
	reverse(blocks.begin() , blocks.end());

	vector<int> ans(m,-1);
	int j = 0;
	for(int i=0; i<n; i++){
		    if(j >= m)break;
	        if(blocks[j][0] >= process[i]){
                 ans[blocks[j][1]] = i+1;
                 j++;
	        }else{
	        	waiting.push_back(i+1);
	        }
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
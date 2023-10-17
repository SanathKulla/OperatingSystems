#include <bits/stdc++.h>
using namespace std;

template <class T>
ostream& operator<<(ostream &o , vector<T> &v){
	for(auto &it:v)cout<<it<<"\n";
    return o;
}


int main(){
	int n,m;
	cin>>n>>m;
	vector<int> p(n);
	vector<int> b(m);
	vector<int> waiting;
	for(int i=0; i<n; i++){
	        cin>>p[i];
	}
	for(int i=0; i<m; i++){
	        cin>>b[i];
	}

	vector<int> ans(m,-1);
	vector<bool> free(m,1);
	for(int i = 0;i<n;i++){
		bool found = false;
		for(int j = 0;j<m;j++){
			if(!free[j])continue;
			if(b[j] >= p[i]){
				free[j] = 0;
				ans[j] = i+1;
				found = true;
				break;
			}
		}
		if(!found){
			waiting.push_back(i+1);
		}
	}
	cout<<ans<<endl;
	if(waiting.size()){
	cout<<"waiting processes are "<<endl;
	cout<<waiting<<endl;
}

}
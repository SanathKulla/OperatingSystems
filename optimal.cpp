// N^2 code

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
        int val = s[i]-'0';
        if(vis[val]){
            ++hits;
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

/*           Nlog(10) code        */
// using sanath = __int128;
// #include<bits/stdc++.h>
// using namespace std;
// using namespace chrono;
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,fma")
// template <typename T>istream& operator>>(istream &input,vector<T>&v){for(auto &i:v) cin>>i;return input;}
// template <typename T>ostream& operator<<(ostream &output,vector<T>&v){for(auto &i:v) cout<<i<<" ";return output;} 
// using ll = long long;
// #define ff first
// #define ss second
// #define all(s) s.begin(),s.end()
// #define fsort(v) sort(all(v))
// #define bsort(v) sort(all(v),greater<int>())
// const ll mod = 1e9+7;
// #define nline "\n"
// #define endl "\n"
// void fastio(){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}
// ll bits(ll x) { ll cnt = 0; while(x > 0) { cnt++; x >>= 1; } return cnt; }
// ll setbits(ll x) { ll cnt = 0; while(x > 0) { cnt += (x & 1); x >>= 1; } return cnt; }
// ll pow(ll a, ll b) {ll res = 1;while (b > 0) {if (b & 1)res = res * a;a = a * a;b >>= 1;}return res;}
// ll pow(ll a, ll b, ll m) {a %= m;ll res = 1;while (b > 0) {if (b & 1)res = res * a % m;a = a * a % m;b >>= 1;}return res;}
// ll add(ll a, ll b, ll m){a %= m , b %= m; return (a + b) % m;}
// ll sub(ll a, ll b, ll m){a %= m , b %= m; return (a - b + m) % m;}
// ll mul(ll a, ll b, ll m){a %= m , b %= m; return (1ll * a * b) % m;}
// ll div(ll a, ll b, ll m){a %= m , b %= m; return mul(a , pow(b , m - 2 , m) , m);}
// vector<int> sieve(int n){int *arr = new int[n + 1]();vector<int> vect;for (int i = 2; i <= n; i++)if (arr[i] == 0){vect.push_back(i);for (int j = 2 * i; j <= n; j += i)arr[j] = 1;}return vect;}
// template <typename T> void put(T s){ cout<<s<<'\n';}
// template <typename T> void puts(T s){ cout<<s<<" ";}
// template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
// template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
// template<class T> using pqs = priority_queue<T>;
// template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
// #define inf 1000000000
// #define INF 1000000000000000000

// void solve(){
//    string s;
//    cin>>s;
//    int m;
//    cin>>m;
//    int n = s.size();
//    vector<int> track(10 , 1e9);
//    vector<int> cur_suf(10 , 1e9);
//    vector<bool> vis(10, 0);
//    int ans = 0;
//    vector<int> suf(n,1e9);
//    for(int i = n-1;i>=0;i--){
//         suf[i] = track[s[i]-'0'];
//         track[s[i]-'0'] = i;
//    }
//    set<pair<int,int>> st;
//    for(int i = 0 ; i<n;i++){
//        if(vis[s[i] - '0'] == 0){
//           ++ans;
//           if(st.size() == m){
//               auto it = st.begin();
//               vis[(*it).second] = 0;
//               st.erase(it);
//          }
//      }else{
//             auto it  = st.find({cur_suf[s[i] - '0'] , s[i] - '0'});
//             st.erase(it);
//      }
//               vis[s[i] - '0'] = 1;
//               st.insert({-suf[i] , s[i]-'0'});
//               cur_suf[s[i] - '0'] = -suf[i];

//  }
//  cout<<ans<<endl;

// }

// signed main()
// {
//     fastio();
//     auto start1 = high_resolution_clock::now();  
//     int T = 1;      
//     // cin >> T;
//     while (T--)
//     {
//         solve();
//     }
//     auto stop1 = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(stop1 - start1);
//     cerr << "Time: " << duration . count() / 1000 << " ms" << endl;        
// }



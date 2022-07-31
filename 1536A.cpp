// #include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
#define endl "\n"
typedef long double ld;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
// g++ -DXOX --std=c++14 main.cpp && ./a.out
// ./a.out < input_file > output_file

/** debug starts **/
vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while (!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if (idx > 0)
        cerr << ", ";
    else
        cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss;
    ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
// #ifndef ONLINE_JUDGE // dangerous for other platforms, might print debug
// lines. Change to #ifdef XOX and use -DXOX compiler flag
#ifdef XOX
#define debug(...) \
    debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
/** debug ends **/

void run() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // srand(time(NULL));
}

ll gcd(ll n1, ll n2) {
    if (n2 != 0)
        return gcd(n2, n1 % n2);
    else
        return n1;
}

int main() {
    run();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        map<int,int> p;
        bool ok = true;
        for(int i = 0; i < n ; i++){
            int x;
            cin>>x;
            v.push_back(x);
            if(x < 0) ok = false;
            p[x] = 1;
        }
        if(!ok) {
            cout<<"NO"<<endl;
            continue;
        }
        while(true){
            vector<int> extra;
            for(int i = 0; i < v.size() ; i++){
                for(int j = i+1; j < v.size() ; j++){
                    int newnum = abs(v[i] - v[j]);
                    if(p.find(newnum) == p.end()){
                        extra.push_back(newnum);
                    }
                }
            }
            if(extra.size()){
                for(auto i: extra){
                    if(p.find(i) == p.end()){
                        p[i] = 1;
                        v.push_back(i);
                    }
                }
            }
            else break;
            if(v.size() > 300) { ok = false; break; }
        }
        if(ok){
            cout<<"YES"<<endl;
            cout<<v.size()<<endl;
            for(int i = 0; i < v.size() ; i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
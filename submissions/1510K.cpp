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

bool checkS(vector<int> &v){
    int n = v.size();
    for(int i = 0; i < n-1 ; i++){
        if(v[i] > v[i+1]) return false;
    }
    return true;
}

bool checkEq(vector<int> &v, vector<int> &orig){
    int n = v.size();
    for(int i = 0; i < n ; i++){
        if(v[i] != orig[i]) return false;
    }
    return true;
}

int main() {
    run();
    int n;
    cin>>n;
    n = n * 2;
    vector<int> v(n);
    for(int i = 0; i < n ; i++){
        cin>>v[i];
    }
    vector<int> orig = v;

    int ans = 0;
    int temp = 1;
    while(true){
        if(checkS(v)){
            break;
        }
        if(checkEq(v, orig) && temp > 1){
            ans = -1;
            break;
        }
        if(temp % 2){
            for(int i = 0; i < n ; i+=2){
                swap(v[i], v[i+1]);
            }
        }
        else {
            for(int i = 0; i < n/2 ; i++){
                swap(v[i], v[n/2+i]);
            }
        }
        // debug(temp);
        // for(int i = 0; i < n ; i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        temp++;
        ans++;
    }

    v = orig;
    temp = 1;
    int newans = 0;
    while(true){
        if(checkS(v)){
            break;
        }
        if(checkEq(v, orig) && temp > 1){
            newans = -1;
            break;
        }
        if(temp % 2 == 0){
            for(int i = 0; i < n ; i+=2){
                swap(v[i], v[i+1]);
            }
        }
        else {
            for(int i = 0; i < n/2 ; i++){
                swap(v[i], v[n/2+i]);
            }
        }
        // debug(temp);
        // for(int i = 0; i < n ; i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        temp++;
        newans++;
    }

    if(ans == -1 && newans == -1){
        cout<<-1<<endl;
    }
    else if(ans == -1 || newans == -1)
        cout<<max(ans, newans)<<endl;
    else
        cout<<min(ans,newans)<<endl;
    return 0;
}
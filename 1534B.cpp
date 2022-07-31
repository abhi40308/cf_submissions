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

bool compare(int a, int b){
    if(a % 2 == 0 && b % 2 == 0) return b < a;
    else if(a % 2 == 0) return true;
    else if(b % 2 == 0) return false;
    else return b < a;
}

int main() {
    run();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> v(n);
        for(int i = 0; i < n ; i++){
            cin>>v[i];
        }
        ll dec = 0;
        if(n == 1){
            cout<<v[0]<<endl;
            continue;
        }
        for(int i = 0; i < n ; i++){
            if(i == 0 && n > 1 && v[i+1] < v[i]){
                ll temp = v[i] - v[i+1];
                dec += temp;
                v[i] -= temp;
            }
            else if(i == n-1 && n > 1 && v[i-1] < v[i]){
                ll temp = v[i] - v[i-1];
                dec += temp;
                v[i] -= temp;
            }
            else if(v[i] > v[i-1] && v[i] > v[i+1]) {
                ll temp = v[i] - max(v[i-1], v[i+1]);
                v[i] = v[i] - temp;
                dec += temp;
            }
        }

        for(int i = 0; i < n ; i++){
            debug(v[i]);
        }
        debug(dec);

        // count heights
        ll ans = dec;
        for(int i = 0; i < n ; i++){
            if(i == 0 || i == n-1){
                ans += v[i];
            }
            if(i > 0 && v[i] != v[i-1]){
                ans += abs(v[i] - v[i-1]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
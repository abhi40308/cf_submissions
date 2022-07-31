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
    vector<ll> v[10];
    v[1].push_back(2);
    v[1].push_back(5);
    v[2].push_back(11);
    v[2].push_back(13);
    v[3].push_back(109);
    v[3].push_back(113);
    v[4].push_back(1051);
    v[4].push_back(1061);
    v[5].push_back(10009);
    v[5].push_back(10037);
    v[6].push_back(109579);
    v[6].push_back(109583);
    v[7].push_back(1000099);
    v[7].push_back(1000037);
    v[8].push_back(10000019);
    v[8].push_back(10000079);
    v[9].push_back(100000007);
    v[9].push_back(100000049);

    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        ll gc = 1, x, y;
        int temp = c-1;
        while(temp--)
            gc = gc * 10;
        x = v[a+1-c][0] * gc;
        y = v[b+1-c][1] * gc;
        // debug(x,y,gc);
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}
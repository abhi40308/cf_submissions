// #include <bits/stdc++.h>
#include <math.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
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
// #define endl "\n"
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
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

#ifdef XOX
#define debug(...) \
    debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

// std::bitset<32>(2).to_string() = 00000000000000000000000000000010 (convert 10 to binary string)
// bitset<32>(binary).to_ulong(); = convert binary string to decimal

template <class F>
void print(vector<F> &v) {
    cout << "\nvector : ";
    for (F i : v) {
        cout << i << " ";
    }
    cout << endl;
}

void print(vector<pi> &v) {
    cout << "\nvector : ";
    for (pi i : v) {
        cout << "<" << i.first << ", " << i.second << "> ";
    }
    cout << endl;
}

template <class F>
void print(vector<vector<F> > &v) {
    cout << "\n2-D vector :\n";
    for (vector<F> i : v) {
        for (F j : i) cout << j << " ";
        cout << endl;
    }
    cout << endl;
}

/** debug ends **/

void fastIO() {
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

ll power(ll a, ll b, ll mod) {
    if (b == 0) {
        return 1;
    }
    ll ans = power(a, b / 2, mod);
    ans *= ans;
    ans %= mod;
    if (b % 2) {
        ans *= a;
    }
    return ans % mod;
}

bool checkPalin(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

bool isValid(int i, int j, int n, int m) {
    if (i >= 0 && i < n && j >= 0 && j < m) return true;
    return false;
}

int N = 1e5 + 1;
int mod = 1e9 + 7;

void rec(vl &v, int i, ll prod, ll x, vl &cur) {
    int n = v.size();
    if (prod % x == 1 && prod > 1) {
        if (cur.size() > 0) {
            for (auto i : cur) cout << i << " ";
            cout << endl;
        }
    }
    if (i >= n) return;
    cur.push_back(v[i]);
    rec(v, i + 1, prod * v[i], x, cur);
    cur.pop_back();
    rec(v, i + 1, prod, x, cur);
}

int main() {
    fastIO();
    ll n; cin>>n;
    set<ll> ans;
    ans.insert(1);
    ll prod = 1;
    for(ll i = 2; i < n - 1 ; i++){
        if(gcd(n, i) == 1) {
            prod = (prod * i) %  n;
            ans.insert(i);
        }
    }
    prod = (prod * (n-1)) % n;
    if(prod % n == 1) ans.insert(n-1);
    cout<<ans.size()<<endl;
    for(auto i : ans) cout<<i<<" ";
    return 0;
}
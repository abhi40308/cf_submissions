// #include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <iomanip>
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

int N = 1e9 + 1;
int mod = 1e9 + 7;

int main() {
    fastIO();
    int t;
    cin >> t;
    while (t--) {
        int n; cin>>n;
        multiset<int> a, b;
        for(int i = 0; i < n ; i++){
            int x; cin>>x;
            while(x % 2 == 0) {
                x = x / 2;
            }
            a.insert(x);
        }
        for(int i = 0; i < n ; i++){
            int x; cin>>x; 
            while(x % 2 == 0) {
                x = x/2;
            }
            auto it = a.find(x);
            if(it != a.end()) a.erase(it);
            else b.insert(x);
        }

        vector<int> v;
        // delete all duplicates
        for(auto i : a) {
            auto it = b.find(i);
            if(it != b.end()) {
                v.push_back(i); b.erase(it);
            }
        }
        for(auto i : v) {
            auto it = a.find(i);
            if(it != a.end()) {
                a.erase(it);
            }
        }

        while(b.size() > 0) {
            vector<int> temp;
            for(auto i : b) temp.push_back(i);
            for(int i = 0; i < temp.size() ; i++){
                temp[i] = temp[i] / 2;
                while(temp[i] > 0 && temp[i] % 2 == 0) temp[i] = temp[i] / 2;
            }
            b.clear();
            for(auto i : temp) {
                // debug(i);
                if(i != 0) b.insert(i);
            }

            v.clear();
            // delete all duplicates
            for(auto i : b) {
                auto it = a.find(i);
                if(it != a.end()) {
                    v.push_back(i); a.erase(it);
                }
            }
            for(auto i : v) {
                auto it = b.find(i);
                if(it != b.end()) {
                    b.erase(it);
                }
            }
            // debug(b.size());
        }    
        if(a.size() == 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}
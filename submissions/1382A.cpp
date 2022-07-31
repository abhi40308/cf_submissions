// #include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
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
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
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

// std::bitset<32>(2).to_string() = 00000000000000000000000000000010 (convert 10 to binary string)
// bitset<32>(binary).to_ulong(); = convert binary string to decimal

void print(vector<int> &v) {
    cout << "vector : ";
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}
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

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool compare(pi a, pi b) {
    if (a.first < b.first)
        return true;
    else if (a.first > b.first)
        return false;
    else {
        if (a.second > b.second)
            return true;
        else
            return false;
    }
}

bool isValid(int i, int j, int n, int m) {
    if (i >= 0 && j >= 0 && i < n && j < m)
        return true;
    return false;
}

bool ok = true;

void recurse(vector<vector<int> > &v, int i, int j, int n, int num, int times) {
    if (times == 0) return;
    v[i][j] = num;
    times--;
    if (isValid(i, j - 1, n, n) && v[i][j - 1] == 0) {
        recurse(v, i, j - 1, n, num, times);
    } else if (isValid(i + 1, j, n, n) && v[i + 1][j] == 0) {
        recurse(v, i + 1, j, n, num, times);
    }
}

ll minDigit(ll a) {
    string s = to_string(a);
    sort(s.begin(), s.end());
    return s[0] - '0';
}
ll maxDigit(ll a) {
    string s = to_string(a);
    sort(s.begin(), s.end());
    return s[s.size() - 1] - '0';
}

int main() {
    run();
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        set<int> a;
        int x;
        for(int i = 0; i < n ; i++){
            cin>>x;
            a.insert(x);
        }
        int ans = -1;
        for(int i = 0; i < m ; i++){
            cin>>x;
            if(ans == -1 && a.find(x) != a.end()){
                ans = x;
            }
        }
        if(ans == -1)
            cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            cout<<1<<" "<<ans<<endl;
        }

    }
    return 0;
}
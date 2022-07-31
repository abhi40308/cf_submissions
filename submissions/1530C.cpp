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
        vector<int> a(n);
        for(int i = 0; i < n ; i++){
            cin>>a[i];
        }
        vector<int> b(n);
        for(int i = 0; i < n ; i++){
            cin>>b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for(int i = 1; i < n ; i++){
            a[i] += a[i-1];
            b[i] += b[i-1];
        }

        ll cur_n = n;
        while(true){
            ll valid_n = cur_n - cur_n/4;
            ll b_sum;
            if(valid_n >= n) {
                b_sum = b[n-1];
            }
            else {
                int bind = n - 1 - valid_n;
                if(bind >= 0)
                    b_sum = b[n-1] - b[bind];
                else 
                    b_sum = b[n-1];
            }

            ll a_sum = 0;
            ll n_hu = cur_n - n;
            a_sum += (n_hu * 100);
            
            ll valid_n_a = valid_n - n_hu;
            ll aind = n - 1 - valid_n_a;
            if(aind >= 0)
                a_sum += a[n-1] - a[aind];
            else 
                a_sum += a[n-1];

            debug(cur_n, valid_n, b_sum, a_sum, n_hu);
            if(a_sum >= b_sum){
                break;
            }
            else {
                ll diff = b_sum - a_sum;
                cur_n += diff / 100;
                if(diff % 100) cur_n++;
            }
        }
        cout<<cur_n - n <<endl;
    }
    return 0;
}
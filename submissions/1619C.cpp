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

void inputSides(vector<int> &v){
    int x, n;
    cin>>n;
    for(int i = 0; i < n ; i++){
        cin>>x;
        if(i == 0 || i == n-1) v.push_back(x);
    }
}

int main() {
    run();
    int t;
    cin>>t;
    while(t--){
        ll a,s;
        cin>>a>>s;

        string as = to_string(a);
        string ss = to_string(s);
        int j = as.size()-1;
        int k = ss.size()-1;

        string bs = "";
        bool ok = true;
        while(j >= 0){
            if(ss[k] >= as[j]){
                int anum = as[j] - '0';
                int snum = ss[k] - '0';
                int bnum = snum - anum;
                bs = to_string(bnum) + bs;
                j--;
                k--;
            }
            else {
                if(k < 1) {
                    ok = false;
                    break;
                }
                string snums = "";
                snums = snums + ss[k-1] + ss[k];
                int snum = stoi(snums);
                if(snum == 0){
                    ok = false;
                    break;
                }
                int anum = as[j] - '0';
                int bnum = snum - anum;
                if(bnum > 9 || bnum < 0){
                    ok = false;
                    break;
                }
                bs = to_string(bnum) + bs;
                k-=2;
                j--;
            }
        }

        if(k >= 0){
            while(k >= 0){
                bs = ss[k] + bs;
                k--;
            }
        }

        int index = -1;
        for(int i = 0; i < bs.size() ; i++){
            if(bs[i] != '0') break;
            else index = i;
        }
        if(index > -1){
            bs = bs.substr(index+1);
        }

        if(ok){
            if(bs.size() == 0) cout<<0<<endl;
            else cout<<bs<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}
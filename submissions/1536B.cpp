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

bool compare(string a, string b){
    int n = a.length();
    int m = b.length();
    if(n == m) return a < b;
    else {
        return n < m;
    }
}

string buildAns(string s){
    int n = s.size();
    int on = n;
    n--;
    if(s[n] == 'z'){
        while(s[n] == 'z'){
            n--;
            if(n < 0) break;
        }
        if(n < 0){
            on++;
            s = "";
            while(on--){
                s = s + "a";
            }
        }
        else {
            int dif = on - n - 1;
            s[n] = s[n] + 1;
            string news = s.substr(0, n + 1);
            while(dif--){
                news = news + "a";
            }
            s = news;
        }
    }
    else {
        s[n] = s[n] + 1;
    }
    return s;
}

int main() {
    run();
    int t;
    cin>>t;
    // string s = "a";
    // while(t--){
    //     debug(s);
    //     s = buildAns(s);
    // }
    // return 0;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        set<string> subs;
        for(int i = 0; i < n ; i++){
            string sub = "";
            for(int j = i; j < n ; j++){
                sub = sub + s[j];
                if(sub.size() > 5) break;
                subs.insert(sub);
            }
        }
        // sort(subs.begin(), subs.end());
        // for(int i = 0; i < subs.size() ; i++){
        //     debug(subs[i]);
        // }
        vector<string> v;
        for(auto i : subs){
            v.push_back(i);
        }
        sort(v.begin(), v.end(), compare);
        
        string ans = "a";
        for(int i = 0; i < v.size() ; i++){
            if(v[i] != ans) break;
            // ans builder code
            ans = buildAns(ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
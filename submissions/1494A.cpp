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

bool checkPalindrome(string s){
    int n = s.size();
    for(int i = 0; i < n/2 ; i++){
        if(s[i] != s[n-i-1])
            return false;
    }
    return true;
}

ll digSum(ll n){
    ll sum = 0;
    while(n > 0){
        sum += n % 10;
        n/=10;
    }
    return sum;
}

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first == a.second) return true;
    else if(b.first == b.second) return false;
    else {
        int adiff = a.second - a.first;
        int bdiff = b.second - b.first;
        if(adiff > bdiff)
            return false;
        else
            return true;
    }
}

bool checkStr(string s){
    stack<char> st;
    for(auto i : s){
        if(i == '('){
            st.push(i);
        }
        else {
            if(st.size() > 0){
                st.pop();
            }
            else return false;
        }
    }
    if(st.size() > 0)
        return false;
    else return true;
}

int main() {
    run();
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        bool ok = false;
        for(int i = 0 ; i < 2; i++){
            char a = (i%2) ? '(' : ')';
            for(int j = 0; j < 2 ; j++){
                char b = (j%2) ? '(' : ')';
                for(int k = 0 ; k < 2 ; k++){
                    char c = (k%2) ? '(' : ')';
                    string s1 = s;
                    for(int l = 0 ; l < s.size() ; l++){
                        if(s1[l] == 'A')
                            s1[l] = a;
                        if(s1[l] == 'B')
                            s1[l] = b;
                        if(s1[l] == 'C')
                            s1[l] = c;
                    }
                    if(checkStr(s1)){
                        ok = true;
                        break;
                    }
                }
            }
        }
        cout<< (ok ? "YES" : "NO")<<endl;
    }
    return 0;
}
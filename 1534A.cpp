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

bool ok = true;

void colorStr(vector<string> &v, int x, int y, int m, char cl){
    // color the current string
    // color from 0 to y
    char nextCl = cl == 'W' ? 'R' : 'W';
    for(int i = y-1; i >= 0 ; i--){
        if(v[x][i] != '.' && v[x][i] != nextCl){
            ok = false;
            return;
        }
        else {
            v[x][i] = nextCl;
        }
        nextCl = nextCl == 'W' ? 'R' : 'W';
    }
    if(!ok) return;

    // color from y+1 to m
    nextCl = cl == 'W' ? 'R' : 'W';
    for(int i = y+1; i < m ; i++){
        if(v[x][i] != '.' && v[x][i] != nextCl){
            ok = false;
            return;
        }
        else {
            v[x][i] = nextCl;
        }
        nextCl = nextCl == 'W' ? 'R' : 'W';
    }
}

void colorFull(vector<string> &v, int x, int y, int n, int m, char cl){
    v[x][y] = cl;
    colorStr(v, x, y, m, cl);

    // color the full column
    // color the top part
    char nextCl = cl == 'W' ? 'R' : 'W';
    for(int i = x-1; i >= 0 ; i--){
        if(!ok) return;
        if(v[i][y] != '.' && v[i][y] != nextCl){
            ok = false;
            return;
        }
        else {
            v[i][y] = nextCl;
            colorStr(v, i, y, m, nextCl);
        }
        nextCl = nextCl == 'W' ? 'R' : 'W';
    }
    if(!ok) return;

    // color the bottom part
    nextCl = cl == 'W' ? 'R' : 'W';
    for(int i = x+1; i < n ; i++){
        if(!ok) return;
        if(v[i][y] != '.' && v[i][y] != nextCl){
            ok = false;
            return;
        }
        else {
            v[i][y] = nextCl;
            colorStr(v, i, y, m, nextCl);
        }
        nextCl = nextCl == 'W' ? 'R' : 'W';
    }
}

int main() {
    run();
    int t;
    cin>>t;
    while(t--){
        ok = true;
        int n,m;
        cin>>n>>m;
        vector<string> v(n);
        for(int i = 0; i < n ; i++){
            cin>>v[i];
        }

        bool flag = false;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(v[i][j] != '.'){
                    flag = true;
                    colorFull(v, i, j, n, m, v[i][j]);
                }
            }
        }

        if(!flag) colorFull(v, 0, 0, n, m, 'W');

        if(!ok) cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            for(int i = 0; i < n ; i++){
                cout<<v[i]<<endl;
            }
        }

    }
    return 0;
}
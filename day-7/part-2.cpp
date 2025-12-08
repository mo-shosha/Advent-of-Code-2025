#include <algorithm>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long
#define e "\n"
#define all(v) ((v).begin()), ((v).end())
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nn(x) ((int)(x).size())

void solve() {
    vector<string>arr;
    string x;
    while(getline(cin,x)){
        arr.push_back(x);
    }
    int n = arr.size();
    int m = arr[0].size();
    map<pair<int,int>,ll>curr;
    int startX=arr[0].find('S');
    curr[{0,startX}]=1;
    ll ans=0;
    for(int i=0;i<n-1;i++){
        map<pair<int,int>,ll> next;
        for (auto &it : curr) {
            int c = it.first.second;
            ll count = it.second;

            char tile = arr[i+1][c];

            if (i+ 1 == n - 1) {
                ans += count;
                continue;
            }

            if (tile == '^') {
                if (c - 1 >= 0)
                    next[{i + 1, c - 1}] += count;
                if (c + 1 < m)
                    next[{i + 1, c + 1}] += count;
            } else {
                next[{i + 1, c}] += count;
            }
        }

        curr.swap(next);
    }
   
    cout<<ans<<e;
   
}
 
int main() {
    //freopen("masks.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
} 

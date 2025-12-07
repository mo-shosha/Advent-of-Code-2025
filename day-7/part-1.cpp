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
    map<ll,ll>mp;
    int startX=arr[0].find('S');
    mp[startX]=1;
    ll ans=0;
    for(int i=0;i<(int)arr.size()-1;i++){
        vector<pair<int,ll>> current(all(mp)); 
        for(auto[xPos,count]:current){
            if (!mp.count(xPos))continue;
            char tile=arr[i+1][xPos];
            if (tile=='^'){
                mp[xPos-1]+=count;
                mp[xPos+1]+=count;
                mp.erase(xPos);
                ans++;
            }
        }
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

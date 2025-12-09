#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define ll long long
#define e "\n"
#define all(v) ((v).begin()), ((v).end())
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nn(x) ((int)(x).size())
bool can(int x){
    int s = sqrt(x);
    return s*s == x;
}

string trim(const string &s){
    ll i = 0, j = s.size() - 1;
    while (i <= j && isspace(s[i])) i++;
    while (j >= i && isspace(s[j])) j--;
    return s.substr(i, j - i + 1);
}

void solve() {
    string x;
    vector<pair<ll,ll>>points;
    while(cin>>x){
        x = trim(x);
        if(x.empty())continue;
        int dashPos=x.find(',');
        ll L=stoll(x.substr(0,dashPos));
        ll R=stoll(x.substr(dashPos+1));

        points.push_back({L, R});
    }


    ll ans=0;
    for(int i=0;i<points.size();i++){
        for(int j=i+1;j<points.size();j++){
            ll x1 = points[i].first;
            ll y1 = points[i].second;
            ll x2 = points[j].first;
            ll y2 = points[j].second;
            ll area = (abs(x1 - x2) + 1) * (abs(y1 - y2) + 1);
            ans=max(ans,area);
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

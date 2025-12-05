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

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

string trim(const string &s){
    ll i = 0, j = s.size() - 1;
    while (i <= j && isspace(s[i])) i++;
    while (j >= i && isspace(s[j])) j--;
    return s.substr(i, j - i + 1);
}
void solve() {
    string x;
    vector<pair<ll,ll>>ranges;
    vector<ll>ids;
    while(true){
        if (!getline(cin, x)) break;
        x = trim(x);
        if(x.empty())break;
        int dashPos=x.find('-');
        ll L=stoll(x.substr(0,dashPos));
        ll R=stoll(x.substr(dashPos+1));
        ranges.push_back({L,R});
    }
    while (true) {
        if (!getline(cin, x)) break;
        x = trim(x);
        if (x.empty()) continue;
        ids.push_back(stoll(x));
    }

    if(ranges.empty()){
        cout<<0<<e;
        return;
    }
    /*
    ll mx = 0;
    for (auto &r : ranges) mx = max(mx, r.second);
    for (auto &v : ids) mx = max(mx, v);

    vector<bool>idx(mx+1,false);
    for(auto &r : ranges){
        for(ll i=r.first;i<=r.second;i++){
            idx[i]=true;
        }
    }

    ll ans=0;
    for(ll id:ids){
        if(id>=0&&id<=mx&&idx[id])ans++;
    }
    cout<<ans<<e;*/

    sort(all(ranges));
    vector<pair<ll,ll>>merged;
    for (auto &r : ranges){
        if(merged.empty()||r.first>merged.back().second+1){
            merged.push_back(r);
        }
        else{
            merged.back().second = max(merged.back().second, r.second);
        }
    }

    ll ans=0;
    for(ll id:ids){
        int l=0,r=merged.size()-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(id < merged[mid].first){
                r = mid - 1;
            } 
            else if(id > merged[mid].second){
                l = mid + 1;
            }
            else {
                ans++;
                break;
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

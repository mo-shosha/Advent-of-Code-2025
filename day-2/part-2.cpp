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


bool is_valid(vector<int>arr){
    bool all_odd=1,all_even=1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]&1){
            all_even=0;
        }
    }

    for(int i=0;i<arr.size();i++){
        if(arr[i]%2==0){
            all_odd=0;
        }
    }

    if(all_even||all_odd)return true;
    else return false;
}
string trim(const string &s){
    ll i = 0, j = s.size() - 1;
    while (i <= j && isspace(s[i])) i++;
    while (j >= i && isspace(s[j])) j--;
    return s.substr(i, j - i + 1);
}

vector<pair<ll,ll>>parseRanges(const string &x) {
    vector<pair<ll,ll>>ranges;
    stringstream ss(x);
    string part;
    while(getline(ss,part,',')){
        part = trim(part);
        if(part.empty())continue;
        int dashPos=part.find('-');
        ll L=stoll(part.substr(0,dashPos));
        ll R=stoll(part.substr(dashPos+1));

        ranges.push_back({L, R});
    }

    return ranges;
}
bool is_in_valid(string x){
    ll n=nn(x);
    //if(n%2==1)return false; 

    for(int k=1;k<=n/2;k++){
        if(n%k!=0)continue;

        string pattern=x.substr(0,k);
        string built="";

        int repeat=n/k;
        for(int i=0;i<repeat;i++){
            built+=pattern;
        }

        if(built==x)return true;
    }

    return false;
}
void solve() {
    string x;
    getline(cin,x);
    //cout<<x<<e;
    vector<pair<ll,ll>>ranges=parseRanges(x);
    ll ans=0;

    for (auto &p : ranges){
        //cout<<p.first<<" "<<p.second<<e;
        for(ll i=p.first;i<=p.second;i++){
            string curr=to_string(i);
            if(curr.size()>1&&is_in_valid(curr)){
                ans+=i;
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
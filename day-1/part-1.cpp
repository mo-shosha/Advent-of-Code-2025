#include <algorithm>
#include <bits/stdc++.h>
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
void solve() {
    // part-1
    string x;
    int cnt{},start=50;
    while (cin>>x) {
        char c=x[0];
        int num = stoi(x.substr(1));
        if(c=='L'){
            start=(start-num)%100;
            if(start<0){start+=100;}
        }
        else if(c=='R'){
            start=(start+num)%100;
        }
        if(start==0)cnt++;
    }
    cout<<cnt<<e;

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
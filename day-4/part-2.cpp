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


void solve() {
    string x;
    vector<string>arr;
    ll ans=0;
    while(cin>>x){
        arr.push_back(x);
    }
    int n=arr.size();
    int m=arr[0].size();
    vector<pair<int,int>> toRemove;
    while(true){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]=='@'){
                    int cnt=0;
                    for(int k=0;k<8;k++){
                        int ni=i+dx[k];
                        int nj=j+dy[k];
                        if(ni>=0&&ni<n&&nj>=0&&nj<m){
                            if(arr[ni][nj]=='@')cnt++;
                        }
                    }
                    if(cnt<4)toRemove.push_back({i,j});

                }
            }
        }
        if(toRemove.empty())break;
        for(auto it:toRemove){
            arr[it.first][it.second] = '.';
        }

        ans+=toRemove.size();
        toRemove.clear();

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
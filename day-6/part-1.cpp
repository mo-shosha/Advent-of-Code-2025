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
vector<int> spilnumber(string x){
    vector<int> result;
    string cur = "";

    for(char c : x){
        if(c == ' '){
            if(cur.size()){
                if(isdigit(cur[0]) || (cur[0]=='-' && cur.size()>1)){
                    result.push_back(stoi(cur));
                }
                cur = "";
            }
        } 
        else {
            if(isdigit(c) || c=='-')  
                cur += c;
        }
    }

    if(cur.size() && (isdigit(cur[0]) || (cur[0]=='-' && cur.size()>1))){
        result.push_back(stoi(cur));
    }

    return result;
}

vector<char> spiloperation(string x){
    vector<char> result;
    for(char c : x){
        if(c == '+' || c == '*'){
            result.push_back(c);
        }
    }
    return result;
}

void solve() {
    string x;
    map<int, vector<int>> mp;
    vector<char>operation;
    vector<string> lines;
    while(getline(cin,x)){
        lines.push_back(x);
    }   

    operation=spiloperation(lines.back());
    
    for (int r = 0; r < lines.size() - 1; r++) {
        vector<int> row = spilnumber(lines[r]);
        for (int c = 0; c < row.size(); c++) {
            mp[c].push_back(row[c]);
        }
    }

    ll ans=0;
    for(auto [i,nums]:mp){
        char op=operation[i];
        ll curr=nums[0];
        for(int j=1;j<nums.size();j++){
            if(op=='+')curr+=nums[j];
            else curr*=nums[j];
        }
        ans+=curr;
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

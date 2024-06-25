#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MOD= 1e9+7;



int main() {
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,u,v;
    cin>>n>>m;
    map<int,pair<int, int>> edge;
    map<pair<int,int>,bool> edge_vis;
    int degree[n+1];
    memset(degree,0,sizeof(degree));
    for(int i=0; i<m;i++){
        cin>>u>>v;
        edge[i]= make_pair(u,v);
        degree[u]++;
        degree[v]++;
    }
    
    int total_group =0;
    while(1){
        vector<pair<int,int>>v;
        bool group= false;
        for(int i=0; i<m; i++){
            pair<int,int> p= edge[i];
            if(degree[p.first]==1 || degree[p.second]==1 && edge_vis[p]==false){
                v.push_back(p);
                group= true;
            }
        }
        for(int j=0; j<v.size(); j++){
            degree[v[j].first]--;
            degree[v[j].second]--;
            edge_vis[v[j]] = true;
        }
        if(group==false){
            break;
        }
        else{
            total_group++;
        }

    }
    cout<<total_group;

    return 0;
}

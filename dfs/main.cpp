#include <bits/stdc++.h>
using namespace std;

set <int> q;

void dfs(int v,  vector <vector <int>> &g, vector<int> &used, set<int>&q , int flag){



used[v] = 1;




for(int i = 0; i < g[v].size();i++)
        if(!used[g[v][i]]){
                if(flag == 0) q.insert(g[v][i]);
        dfs(g[v][i] ,g , used,q,flag);
        //flag ++;
}}




int main()
{

    int n, m, k, k1;
    cin >> n >> m;

    vector<vector<int>> g(1000, vector<int>());
    int start = 1;
    g.resize(n+1);
    vector <int> used(g.size(), 0);
    for(int i = 0; i < m; i++){
        cin >> k >> k1;
        if(k != k1)
        g[k].push_back(k1);
        g[k1].push_back(k);
    }
  /*  for(int i = 0; i < m; i++){
        cout << i << ":";
        for(int j = 0; j < g[i].size();j++)
            cout << g[i][j]<< " ";
        cout << endl;
    }*/
q.insert(1);
int flag = 0;
dfs(start,g,used,q,flag);
cout << q.size() << endl;
for(auto r : q)
cout << r << " ";
    return 0;
}

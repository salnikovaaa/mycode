#include <bits/stdc++.h>
using namespace std;

vector <int> p;
int endd;
int startt;
bool cycle = false;
vector<int>used;
  vector<vector<int>> g;
int n;


void dfs (int v){
used[v]=1;

for (size_t i=0; i<g[v].size(); ++i) {
int to = g[v][i];
if (used[to] == 0){
p[to] = v;
dfs (to);

}
else if (used[to] == 1&&to!=p[v]){
cycle=true;
endd = v; //Текущая вершина – конец цикла
startt = to;
}
}
 used[v] = 2;
}


int main()
{

    int a;
    cin >> n ;
g.resize(n);
used.resize(n);
p.resize(n);
 for (int i=0; i<n;++i)
for (int j=0;j<n;++j){
cin>>a;
if (a) g[i].push_back(j);
}
dfs(0);
for (int i=0;i<n;++i){
if (!used[i]){
dfs(i);
}
}


if(cycle == true) {cout << "YES" << endl;
int k = endd;
queue <int> answer;
while (k!=startt){
answer.push(k+1);
k=p[k];
}
answer.push(startt+1);
cout << answer.size() << endl;
while(answer.size()!=0){
    cout << answer.front() <<" ";
    answer.pop();
}
}
else cout << "NO";
    return 0;
}

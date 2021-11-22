#include <bits/stdc++.h>
using namespace std;


const int inf = 1000000000;
int main(){
 int n;
 cin>>n;
 vector<vector<pair<int,int>>> g(n);

 int s;
 cin >> s;
 s--;
 int endd;
 cin >> endd;
 endd--;
int a;
  for (int i=0; i<n;++i)
for (int j=0;j<n;++j){
cin>>a;
if (a!=-1) g[i].push_back(make_pair(j,a));
}




 vector <int> d (n, inf), p(n);
 vector<int> u(n);

 d[s]=0;
 for (int i=0; i<n;++i) {
int v=-1;
for (int j=0; j<n;++j)
if (!u[j]&&(v==-1||d[j]<d[v]))
v=j;
if (d[v]==inf) break;
u[v]=true;
 for (size_t j=0; j<g[v].size();++j){
int to=g[v][j].first;
int len =g[v][j].second;
if (d[v]+len<d[to]){
d[to]=d[v]+len;
p[to]=v; }
}
 }

if(d[endd]<inf)
 cout << d[endd];
 else cout << -1;
}


#include <bits/stdc++.h>

using namespace std;
long long L_B(vector <long long> &q, long long s){
long long l = 0, r = q.size();
while(l < r){
    long long m = (l + r)/2;
    if(s > q[m]) l = m + 1;
    else r = m;}
    return r;
}

vector <long long> ans, q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        q.push_back(x);
    }
    sort(q.begin(),q.end());

    long long x;
    cin >> x;

    for(int i = 0; i < x; i++){
    cin >> N;
    ans.push_back(L_B(q, N));}

    for(auto i: ans) cout << i << " ";

    return 0;
}

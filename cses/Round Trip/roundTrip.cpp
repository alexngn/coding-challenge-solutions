#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
using namespace std;

static int mod = 1e9 + 7;
static vector<ll> memo;


vector<vi> adj;
vi sizes;
vi ans;
vi path{0};
bool dfs(int no, int par) {
    sizes[no] = sz(path);
    path.PB(no);
    trav(i, adj[no]) {
        if (i == par) continue;
        int weight = sizes[i];
        if (weight) {
            path.PB(i);
            ans = vi(path.begin()+weight, path.end());
            return 1;
        }
        if (dfs(i,no)) return 1;
    }
    path.pop_back();
    return 0;

}

int main()
{
    int n, m;
    cin >> n >> m;
    adj = vector<vi> (n+1);
    sizes = vi(n+1);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;

        adj[a].PB(b);
        adj[b].PB(a);
    }
   rep(i, 1, n+1) {
       vi path;
       if(!sizes[i] && dfs(i, 0)) {
           int m = sz(ans);
           cout << m << endl;
           rep(i, 0, m) cout << ans[i] << " ";
           return 0;
       }
   }
   cout << "IMPOSSIBLE" << endl;

}
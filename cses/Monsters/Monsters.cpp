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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
using namespace std;

static int INF = 1e9;
static int mod = 1e9 + 7;
static vector<ll> memo;

vector<vector<pii>> adj;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    rep(i, 0, n) cin >> g[i];
    queue<pii> q;
    pii start;
    pii exit;
    rep(i, 0, n) rep(j, 0, m) {
        if(g[i][j] == 'M') q.push({i, j});
        if(g[i][j] == 'A') start = {i, j};
    }

    int init = INF;
    vector<vi> steps (n, vi(m, init));
    vi dir {-1, 0, 1, 0, 0, -1, 0, 1};
    int currStep = 0;

    while(!q.empty()) {
        int size = q.size();
        
        rep(i, 0, size) {
            pii p = q.front();
            q.pop();
            steps[p.F][p.S] = currStep;
            
            for(int j = 0; j < 8; j += 2) {
                int nr = p.F+dir[j];
                int nc = p.S+dir[j+1];
                if(nr < 0 || nr == n || nc < 0 || nc == m) continue;
                else if(g[nr][nc] == '#') continue;
                else if(steps[nr][nc] < init) continue;
                else q.push({nr, nc});
            }
        }
        currStep++;
    }

    vector<vector<char>> path (n, vector<char>(m, 'x'));
    path[start.F][start.S] = 'A';
    q.push(start);
    currStep = 0;
    vector<char> udlr{'U', 'D', 'L', 'R'};
    while (!q.empty()) {
        int size = q.size();
        rep(i, 0, size) {
            
            pii p = q.front();
            q.pop();
            if(p.F < 0 || p.F == n || p.S < 0 || p.S == m) continue;
            if (steps[p.F][p.S] <= currStep) continue;
            if (g[p.F][p.S] == '#') continue;
            if (p.F == 0 || p.F == n-1 || p.S == 0 || p.S == m-1) {
                cout << "YES" << endl;
                cout << currStep << endl;
                int r = p.F;
                int c = p.S;
                stack<char> ans;
                while (path[r][c] != 'A') {
                    char d = path[r][c];
                    ans.push(path[r][c]);
                    if (d == 'U') r++;
                    if (d == 'D') r--;
                    else if (d == 'L') c++;
                    else if (d == 'R') c--;
                }
                while (!ans.empty()) {
                    cout << ans.top();
                    ans.pop();
                }
                return 0;
            }
            for (int j = 0; j < 8; j +=2) {
                
                q.push({p.F+dir[j], p.S+dir[j+1]});
                char loc = path[p.F+dir[j]][p.S+dir[j+1]];
                if (loc == 'x') path[p.F+dir[j]][p.S+dir[j+1]] = udlr[j/2];
            }
        }
        currStep++;
    }
    cout << "NO" << endl;
}
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class twoSat {
    int n;
    vector<vector<int>> adj;
    stack<int> s{};
    bool dfs(int x, int& cnt) {
        if (mark[x ^ 1]) return false;
        if (mark[x]) return true;
        mark[x] = true;
		if (!(x & 1)) ++cnt;
        s.push(x);
        for (auto& y : adj[x]) if (!dfs(y, cnt)) return false;
        return true;
    }
public:
    vector<bool> mark;
    twoSat(int _n) : n{_n}, adj(2 * n), mark(2 * n, false) {}
    void xor_clause(int x, bool xv, int y, bool yv) { // ((x == xv) xor (y == yv))
        x = 2 * x + xv, y = 2 * y + yv;
        adj[x].push_back(y ^ 1), adj[x ^ 1].push_back(y);
        adj[y].push_back(x ^ 1), adj[y ^ 1].push_back(x);
    }
    bool solve() {
        for (int i{0}; i < n; ++i) {
            if (mark[2 * i] || mark[2 * i + 1]) continue;
            while (!s.empty()) s.pop();
			int cnt1{0}, cnt2{0};
			if (!dfs(2 * i, cnt1)) cnt1 = -1;
			while (!s.empty()) mark[s.top()] = false, s.pop();
			if (!dfs(2 * i + 1, cnt2)) cnt2 = -1;
			while (!s.empty()) mark[s.top()] = false, s.pop();

			if (cnt1 == -1 && cnt2 == -1) return false;
			else if (cnt1 >= cnt2) dfs(2 * i, cnt1);
			else dfs(2 * i + 1, cnt2);
        }
        return true;
    }
};

void solve() {
	int n, m;
	cin >> n >> m;

	twoSat ts{n};
	while (m--) {
		int i, j;
		string c;
		cin >> i >> j >> c, --i, --j;
		if (c == "imposter"s) ts.xor_clause(i, true, j, true);
		else ts.xor_clause(i, true, j, false);
	}

	if (!ts.solve()) return cout << "-1\n"s, []{}();

	int ans{0};
	for (int i{0}; i < n; ++i)
		if (ts.mark[2 * i]) ++ans;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

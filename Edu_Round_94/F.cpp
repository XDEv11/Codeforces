//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <utility>
#define fi first
#define se second
#include <queue>
#include <algorithm>

using namespace std;

template<size_t k = 26>
class AC_automaton {
    struct vertex_t {
        int pa;
        bool exit{false};
        int tag;
        array<int, k> next{}, go;
        int slink, elink, ecnt;
        explicit vertex_t(int _pa = 0) : pa{_pa} { }
    };
    vector<vertex_t> t;
public:
    explicit AC_automaton(const vector<pair<vector<int>, int>>& dict) : t(1) {
        for (auto& [s, x] : dict) {
            int v{0};
            for (auto& c : s) {
                if (!t[v].next[c]) {
                    t[v].next[c] = t.size();
                    t.emplace_back(v);
                }
                v = t[v].next[c];
            }
            if (v) t[v].exit = true, t[v].tag = x;
        }
        queue<int> qu{};
        qu.push(0), t[0].slink = 0;
        for (size_t c{0}; c < k; ++c) t[0].go[c] = 0;
        t[0].elink = 0, t[0].ecnt = 0;
        while (!qu.empty()) {
            auto u{qu.front()}; qu.pop();
            if (u) {
                int w{t[u].slink};
                for (size_t c{0}; c < k; ++c) t[u].go[c] = (t[w].next[c] ? t[w].next[c] : t[w].go[c]);
                t[u].elink = (t[w].exit ? w : t[w].elink), t[u].ecnt = t[w].ecnt + t[w].exit;
            }
            for (size_t c{0}; c < k; ++c) {
                auto v{t[u].next[c]};
                if (v) qu.push(v), t[v].slink = t[u].go[c];
            }
        }
    }
	size_t size() const { return t.size(); }
    bool exit(int v) const { return t[v].exit; }
    int tag(int v) const { return t[v].tag; }
    int next(int v, int c) const { return t[v].next[c]; }
    int go(int v, int c) const { return t[v].go[c]; }
    int slink(int v) const { return t[v].slink; }
    int elink(int v) const { return t[v].elink; }
    int ecnt(int v) const { return t[v].ecnt; }
};

void dfs(vector<vector<int>>& res, vector<int>& tmp, int x, int r) {
	if (!r) return res.push_back(tmp), []{}();
	for (int i{1}; i <= min(9, r); ++i) {
		tmp.push_back(i);
		bool f{false};
		for (int k{tmp.size() - 1}, s{}; k >= 0 && s + tmp[k] < x; --k) {
			s += tmp[k];
			if (x % s == 0) {
				f = true;
				break;
			}
		}
		if (!f) dfs(res, tmp, x, r - i);
		tmp.pop_back();
	}
}

void solve() {
	string _s{};
	cin >> _s;
	int n{_s.size()};
	vector<int> s(n);
	for (int i{0}; i < n; ++i) s[i] = _s[i] - '0';
	int x;
	cin >> x;

	vector<vector<int>> res{};
	{
		vector<int> tmp{};
		dfs(res, tmp, x, x);
	}

	vector<pair<vector<int>, int>> dict(res.size());
	for (int i{0}; i < res.size(); ++i) dict[i] = {res[i], i};
	AC_automaton<10> aca{dict};

	vector<vector<int>> dp(n + 1, vector<int>(aca.size(), n));
	dp[0][0] = 0;
	for (int i{0}; i < n; ++i) {
		for (int u{0}; u < aca.size(); ++u) {
			int v{aca.next(u, s[i])};
			if (!v) v = aca.go(u, s[i]);
			dp[i + 1][u] = min(dp[i + 1][u], dp[i][u] + 1);
			if (aca.exit(v) || aca.elink(v)) continue;
			dp[i + 1][v] = min(dp[i + 1][v], dp[i][u]);
		}
	}

	int ans{n};
	for (int v{0}; v < aca.size(); ++v) ans = min(ans, dp[n][v]);
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}

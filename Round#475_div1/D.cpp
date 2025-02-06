//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#define fi first
#define se second
#include <deque>

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
	bool exit(int v) const { return t[v].exit; }
	int tag(int v) const { return t[v].tag; }
	int next(int v, int c) const { return t[v].next[c]; }
	int go(int v, int c) const { return t[v].go[c]; }
	int slink(int v) const { return t[v].slink; }
	int elink(int v) const { return t[v].elink; }
	int ecnt(int v) const { return t[v].ecnt; }
};

void solve() {
	string s{};
	cin >> s;
	int n;
	cin >> n;
	vector<int> q(n);
	vector<pair<vector<int>, int>> v(n);
	for (int i{0}; i < n; ++i) {
		string t{};
		cin >> q[i] >> t;
		auto& [x, y]{v[i]};
		for (auto& c : t) x.push_back(c - 'a');
		y = i;
	}

	AC_automaton aca{v};
	vector<deque<int>> rec(n);
	vector<int> ans(n, s.size() + 1);
	int x{0};
	for (int i{0}; i < s.size(); ++i) {
		int t;
		if (t = aca.next(x, s[i] - 'a')) x = t;
		else x = aca.go(x, s[i] - 'a');
		for (int y{x}; y; y = aca.elink(y)) {
			if (!aca.exit(y)) continue;
			t = aca.tag(y);
			if (rec[t].size() == q[t]) rec[t].pop_back();
			rec[t].push_front(i);
			if (rec[t].size() == q[t]) ans[t] = min(ans[t], rec[t].front() - rec[t].back());
		}
	}

	for (int i{0}; i < n; ++i) {
		if (ans[i] == s.size() + 1) cout << "-1\n";
		else cout << ans[i] + v[i].fi.size() << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}

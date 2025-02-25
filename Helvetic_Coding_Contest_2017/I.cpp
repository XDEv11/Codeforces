//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class SAM {
	struct vertex_t {
		int len, fp, link;
		bool cloned;
		map<int, int> next{};
		explicit vertex_t(int l, int f, int lk = -1, bool c = false, const map<int, int>& n = {})
			: len{l}, fp{f}, link{lk}, cloned(c), next{n} {}
	};
	vector<vertex_t> st{vertex_t{0, 0}};
	int lst{0};
public:
	explicit SAM() {}
	void add_back(int ch) {
		int cur{st.size()}; st.emplace_back(st[lst].len + 1, st[lst].len);
		int p{lst};
		while (p != -1 && !st[p].next.count(ch)) st[p].next[ch] = cur, p = st[p].link;
		if (p != -1) {
			int q{st[p].next[ch]};
			if (st[p].len + 1 != st[q].len) {
				int c{st.size()}; st.emplace_back(st[p].len + 1, st[q].len, st[q].link, true, st[q].next);
				while (p != -1 && st[p].next[ch] == q) st[p].next[ch] = c, p = st[p].link;
				st[q].link = st[cur].link = c;
			} else st[cur].link = q;
		} else st[cur].link = 0;
		lst = cur;
	}
	size_t size() const { return st.size(); }
	int last() const { return lst; }
	int len(int v) const { return st[v].len; }
	int fp(int v) const { return st[v].fp; }
	int link(int v) const { return st[v].link; }
	int cloned(int v) const { return st[v].cloned; }
	const map<int, int>& next(int v) const { return st[v].next; }
	int next(int v, int ch) const {
		auto it{st[v].next.find(ch)}; return it == st[v].next.end() ? -1 : it->second;
	}
};

void solve() {
	using ll = long long;
	string s{};
	cin >> s;

	SAM sam{};
	for (auto& ch : s) sam.add_back(ch);

	vector<pair<int, int>> tmp(sam.size());
	for (int v{0}; v < sam.size(); ++v) tmp[v] = {sam.len(v), v};
	sort(tmp.rbegin(), tmp.rend());

	vector<ll> cnt(sam.size());
	for (int v{0}; v < sam.size(); ++v) {
		if (!sam.cloned(v)) cnt[v] = 1;
	}
	for (auto& [len, v] : tmp) {
		if (v == 0) continue;
		cnt[sam.link(v)] += cnt[v];
	}

	ll ans{};
	for (int v{1}; v < sam.size(); ++v) {
		ll l{sam.len(sam.link(v)) + 1}, r{sam.len(v)};
		ans += (r - l + 1) * cnt[v] * cnt[v];
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

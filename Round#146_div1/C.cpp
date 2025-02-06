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
	string s{};
	cin >> s;
	int n{s.size()};

	SAM sam{};
	for (auto& c : s) sam.add_back(c);

	vector<pair<int, int>> tmp(sam.size());
	for (int v{0}; v < sam.size(); ++v) tmp[v] = {sam.len(v), v};
	sort(tmp.rbegin(), tmp.rend());

	vector<long long> cnt(sam.size());
	for (int v{0}; v < sam.size(); ++v) {
		if (!sam.cloned(v)) cnt[v] = 1;
	}
	for (auto& [len, v] : tmp) {
		if (v == 0) continue;
		cnt[sam.link(v)] += cnt[v];
	}

	int q;
	cin >> q;
	while (q--) {
		string t{};
		cin >> t;
		int m{t.size()};

		int v{0}, len{0};
		for (int i{0}; i < m; ++i) {
			while (v != -1 && sam.next(v, t[i]) == -1) v = sam.link(v), len = sam.len(v);
			if (v != -1) v = sam.next(v, t[i]), ++len;
			else v = 0;
		}

		vector<int> vis{};
		for (int i{0}; i < m; ++i) {
			if (len == m) {
				len -= 1;
				if (sam.len(sam.link(v)) == len) v = sam.link(v);
			}
			while (v != -1 && sam.next(v, t[i]) == -1) v = sam.link(v), len = sam.len(v);
			if (v != -1) v = sam.next(v, t[i]), ++len;
			else v = 0;
			if (len == m) vis.push_back(v);
		}

		long long ans{};
		sort(vis.begin(), vis.end());
		vis.erase(unique(vis.begin(), vis.end()), vis.end());
		for (auto& w : vis) ans += cnt[w];

		cout << ans << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}

//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

template<typename T>
vector<int> Manacher(const vector<T>& _v, T s = T{}) {
    int n{_v.size()};
    vector<T> v(2 * n + 1, s);
    for (int i{0}; i < n; ++i) v[2 * i + 1] = _v[i];

    vector<int> r(2 * n + 1, 1);
    int c{0}, b{1};
    for (int i{1}; i < 2 * n; ++i) {
        if (i < b) r[i] = min(b - i, r[c - (i - c)]);
        while (i - r[i] >= 0 && i + r[i] < 2 * n + 1
            && v[i - r[i]] == v[i + r[i]]) ++r[i];
        if (i + r[i] > b) c = i, b = i + r[i];
    }
    return r;
}

class SAM {
    struct vertex_t {
        int len, fp, link;
        bool cloned;
        map<int, int> next{};
        explicit vertex_t(int l, int f, int lk = -1, bool c = false, const map<int, int>& n = {}) : len{l}, fp{f}, link{lk}, cloned(c), next{n} {}
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
                int c{st.size()}; st.emplace_back(st[p].len + 1, st[q].fp, st[q].link, true, st[q].next);
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
	string _s{};
	cin >> _s;
	int n{_s.size()};
	vector<char> s{_s.begin(), _s.end()};

	auto r{Manacher(s)};

	SAM sam{};
	for (auto& ch : s) sam.add_back(ch);
	vector<int> len(n), pos(n);
	int v{0};
	for (int i{n - 1}; i >= 0; --i) {
		if ((v = sam.next(v, s[i])) == -1) break;
		int j{sam.fp(v)};
		len[j] = n - i, pos[j] = j + 1 - (n - i);
	}
	for (int i{1}; i < n; ++i) {
		if (len[i - 1] > len[i]) len[i] = len[i - 1], pos[i] = pos[i - 1];
	}

	int ans1{}; vector<pair<int, int>> ans2{};
	for (int i{0}; i < n; ++i) {
		int l1{r[2 * i + 1] / 2}, l2{min(i - l1 >= 0 ? len[i - l1] : 0, n - (i + l1))};
		if (2 * l1 - 1 + 2 * l2 > ans1) {
			ans1 = 2 * l1 - 1 + 2 * l2;
			ans2.clear();
			if (l2) ans2.emplace_back(pos[i - l1], l2);
			ans2.emplace_back(i + 1 - l1, 2 * l1 - 1);
			if (l2) ans2.emplace_back(n - l2, l2);
		}
	}

	cout << ans2.size() << '\n';
	for (auto& [p, l] : ans2) cout << p + 1 << ' ' << l << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}

//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <limits>
#include <algorithm>

using namespace std;

template<typename T>
vector<int> suffix_array(const vector<T>& _v, T s = T{}) {
    int n{_v.size()};
    vector<pair<T, int>> v(n);
    for (int i{0}; i < n; ++i) v[i] = {_v[i], i};
    v.emplace_back(s, n++);

    sort(v.begin(), v.end());
    vector<int> c(n), p(n);
    c[v[0].se] = 0;
    for (int i{1}; i < n; ++i) c[v[i].se] = c[v[i - 1].se] + (v[i - 1].fi < v[i].fi);
    for (int i{0}; i < n; ++i) p[i] = v[i].se;

    for (int k{0}; (1 << k) < n; ++k) {
        vector<int> t(n);
        for (int i{0}; i < n; ++i) t[i] = (p[i] - (1 << k) + n) % n;
        vector<int> cnt(n, 0);
        for (int i{0}; i < n; ++i) ++cnt[c[t[i]]];
        for (int i{1}; i < n; ++i) cnt[i] += cnt[i - 1];
        for (int i{n - 1}; i >= 0; --i) p[--cnt[c[t[i]]]] = t[i];

        vector<int> nc(n);
        nc[p[0]] = 0;
        for (int i{1}; i < n; ++i) {
            nc[p[i]] = nc[p[i - 1]] + (c[p[i - 1]] < c[p[i]] ||
                c[(p[i - 1] + (1 << k)) % n] < c[(p[i] + (1 << k)) % n]);
        }
        c.swap(nc);
    }

    return p.erase(p.begin()), p;
}

// longest common prefix of consecutive suffixes
template<typename T>
vector<int> lcp_array(const vector<T>& v, const vector<int>& p) {
    int n{v.size()};
    vector<int> r(n);
    for (int i{0}; i < n; ++i) r[p[i]] = i;

    vector<int> lcp(n - 1, 0);
    for (int i{0}, k{0}; i < n; ++i, k = k ? k - 1 : 0) {
        if (r[i] == n - 1) continue; // k should be 0
        int j{p[r[i] + 1]};
        while (i + k < n && j + k < n && v[i + k] == v[j + k]) ++k;
        lcp[r[i]] = k;
    }

    return lcp;
}

// sparse table
template<typename value_t, class merge_t>
class ST {
    int n;
    vector<int> log2;
    vector<vector<value_t>> t;
    merge_t merge; // associative & idempotent function for ST
public:
    explicit ST(const vector<value_t>& v, const merge_t& _merge = merge_t{})
        : n{v.size()}, log2(n + 1), merge{_merge} {
        log2[1] = 0;
        for (int i{2}; i <= n; ++i) log2[i] = log2[i / 2] + 1;

        t.assign(n, vector<value_t>(log2[n] + 1));
        for (int i{n - 1}; i >= 0; --i) {
            t[i][0] = v[i];
            for (int j{1}; i + (1 << j) <= n; ++j)
                t[i][j] = merge(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
        }
    }
    value_t query(int l, int r) { // [l:r)
        int j{log2[r - l]};
        return merge(t[l][j], t[r - (1 << j)][j]);
    }
};

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v{}, st(n), ed(n);
	for (int i{0}; i < n; ++i) {
		string s{};
		cin >> s;
		st[i] = v.size();
		for (auto& x : s) v.push_back(x);
		ed[i] = v.size();
		v.push_back(-v.size());
	}
	int m{v.size()};

	auto sa{suffix_array(v, numeric_limits<int>::min())};
	vector<int> isa(m);
	for (int i{0}; i < m; ++i) isa[sa[i]] = i;
	struct st_merge_t { int operator()(int a, int b) const { return min(a, b); } };
	ST<int, st_merge_t> lcp{lcp_array(v, sa)};
	vector<int> kl(m);
	{
		vector<int> idx(m);
		for (int i{0}; i < n; ++i)
			for (int j{st[i]}; j <= ed[i]; ++j) idx[j] = i;
		vector<int> cnt(n);
		for (int i{0}, j{0}; i < m; ++i) {
			k -= !cnt[idx[sa[i]]]++;
			while (k < 0 || (k == 0 && cnt[idx[sa[j]]] > 1)) k += !--cnt[idx[sa[j++]]];
			kl[i] = k ? -1 : j;
		}
	}

	auto check{[&](int i, int len) {
		int l{isa[i]}, r{m};
		while (r - l > 1) {
			int m{(l + r) / 2};
			if (lcp.query(isa[i], m) < len) r = m;
			else l = m;
		}
		return isa[i] <= kl[l] || (kl[l] != -1 && lcp.query(kl[l], isa[i]) >= len);
	}};

	for (int i{0}; i < n; ++i) {
		long long ans{};
		for (int j{st[i]}; j < ed[i]; ++j) {
			int lf{0}, rt{ed[i] - j + 1};
			while (rt - lf > 1) {
				int md{(lf + rt) / 2};
				if (check(j, md)) lf = md;
				else rt = md;
			}
			ans += lf;
		}
		cout << ans << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}

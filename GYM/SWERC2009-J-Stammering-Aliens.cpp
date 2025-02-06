//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>
#include <deque>

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

bool solve() {
	int m;
	if (cin >> m, m == 0) return false;
	string s{};
	cin >> s;
	if (m-- == 1) return cout << s.size() << " 0\n", true;

	int n{s.size()};
	vector<char> v(n);
	for (int i{0}; i < n; ++i) v[i] = s[i];

	auto sa{suffix_array(v)};
	auto lcp{lcp_array(v, sa)};

	int ans1{}, ans2{};
	deque<pair<int, int>> mn{}, mx;
	for (int i{0}; i + 1 < n; ++i) {
		while (!mn.empty() && mn.front().fi < i + 1 - m) mn.pop_front();
		while (!mn.empty() && lcp[i] <= mn.back().se) mn.pop_back();
		mn.emplace_back(i, lcp[i]);
		while (!mx.empty() && mx.front().fi < i + 1 - m) mx.pop_front();
		while (!mx.empty() && max(sa[i], sa[i + 1]) >= mx.back().se) mx.pop_back();
		mx.emplace_back(i, max(sa[i], sa[i + 1]));
		if (i + 1 - m >= 0 && (mn.front().se > ans1
			|| (mn.front().se == ans1 && mx.front().se > ans2)))
		ans1 = mn.front().se, ans2 = mx.front().se;
	}

	if (!ans1) cout << "none\n";
	else cout << ans1 << ' ' << ans2 << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}

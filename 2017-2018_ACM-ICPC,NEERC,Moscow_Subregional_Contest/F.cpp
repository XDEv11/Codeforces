//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <utility>
#define fi first
#define se second
#include <set>
#include <algorithm>

using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	using state_t1 = tuple<char, int, int>;
	vector<pair<string, vector<state_t1>>> fz(m), fn(k);
	for (auto& [s, v] : fz) {
		cin >> s;
		v.resize(n);
		for (auto& [c, a, t] : v) cin >> c >> a >> t;
	}
	for (auto& [s, v] : fn) {
		cin >> s;
		v.resize(n);
		for (auto& [c, a, t] : v) cin >> c >> a >> t;
	}

	using state_t2 = tuple<int, int, int, string>;
	auto t2_cmp{[](const state_t2& s1, const state_t2& s2) {
		if (get<0>(s1) != get<0>(s2)) return get<0>(s1) > get<0>(s2);
		if (get<1>(s1) != get<1>(s2)) return get<1>(s1) < get<1>(s2);
		if (get<2>(s1) != get<2>(s2)) return get<2>(s1) < get<2>(s2);
		return get<3>(s1) < get<3>(s2);
	}};
	vector<state_t2> bs(m), ws(m), v(k);
	for (int j{0}; j < m; ++j) {
		{
			int c2{}, c3{};
			for (auto [c, a, t] : fz[j].se) {
				if (c != '+') a += 1, t = 240;
				c2 += t + (a - 1) * 20, c3 = max(c3, t);
			}
			bs[j] = {n, c2, c3, fz[j].fi};
		}
		{
			int c1{}, c2{}, c3{};
			for (auto [c, a, t] : fz[j].se) {
				if (c != '+') continue;
				++c1, c2 += t + (a - 1) * 20, c3 = max(c3, t);
			}
			ws[j] = {c1, c2, c3, fz[j].fi};
		}
	}
	for (int j{0}; j < k; ++j) {
		int c1{}, c2{}, c3{};
		for (auto [c, a, t] : fn[j].se) {
			if (c != '+') continue;
			++c1, c2 += t + (a - 1) * 20, c3 = max(c3, t);
		}
		v[j] = {c1, c2, c3, fn[j].fi};
	}

	set<string> st{};
	for (int j{0}; j < k; ++j) st.insert(fn[j].fi);
	for (int j{0}; j < m; ++j) {
		if (st.count(fz[j].fi)) continue;
		if (t2_cmp(bs[j], v.front()) || t2_cmp(v.back(), ws[j])) continue;
		return cout << "Fake\n", []{}();
	}
	cout << "Leaked\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}

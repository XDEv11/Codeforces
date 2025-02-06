#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <utility>
#define fi first
#define se second
#include <queue>
#include <algorithm>

using namespace std;

bool solve1() {
	using ll = long long;

	int n; ll c;
	if (!(cin >> n >> c)) return false;
	vector<ll> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	vector<int> ans(n);

	set<pair<ll, int>> st1{}, st2{}, st3{};

	vector<pair<ll, int>> t(n);
	for (int i{0}; i < n; ++i) t[i] = {a[i], i};
	sort(t.begin(), t.end());
	for (int i{0}; i < n && c >= t[i].fi; ++i) ans[t[i].se] = 1, c -= t[i].fi;
	for (int i{0}; i < n; ++i) {
		if (ans[i]) st1.emplace(b[i] - a[i], i), st2.emplace(a[i], i);
		else st3.emplace(b[i], i);
	}

	while (!st1.empty() || (!st2.empty() && !st3.empty())) {
		if (st2.empty() || st3.empty() || st1.begin()->fi < st3.begin()->fi - st2.rbegin()->fi) {
			int i{st1.begin()->se};
			if (c < b[i] - a[i]) break;
			ans[i] = 2, c -= b[i] - a[i];
			st1.erase(st1.begin());
			st2.erase({a[i], i});
		} else {
			int i{st2.rbegin()->se}, j{st3.begin()->se};
			if (c < b[j] - a[i]) break;
			ans[i] = 0, ans[j] = 2, c -= b[j] - a[i];
			st1.erase({b[i] - a[i], i});
			st2.erase(prev(st2.end()));
			st3.erase(st3.begin());
			st3.emplace(b[i], i);
		}
	}

	for (auto& x : ans) cout << x;
	cout << '\n';
	return true;
}

bool solve2() {
	using ll = long long;

	int n; ll c;
	if (!(cin >> n >> c)) return false;
	vector<pair<pair<ll, ll>, int>> v1(n);
	for (int i{0}; i < n; ++i) v1[i].se = i;
	for (int i{0}; i < n; ++i) cin >> v1[i].fi.fi;
	for (int i{0}; i < n; ++i) cin >> v1[i].fi.se;

	sort(v1.begin(), v1.end());
	auto v2{v1};
	sort(v2.begin(), v2.end(), [](const pair<pair<ll, ll>, int>& a, const pair<pair<ll, ll>, int>& b) {
		return a.fi.se < b.fi.se;
	});
	vector<int> i1(n);
	for (int i{0}; i < n; ++i) i1[v1[i].se] = i;

	vector<int> s(n);
	int k{0};
	while (k < n && v1[k].fi.fi <= c) c -= v1[k].fi.fi, s[v1[k].se] = 1, ++k;

	auto run{[n, v1, i1, v2](ll c, vector<int> s, int k, vector<int>& ans, int r = -1) {
		int m{k}; --k;
		int mx{};
		vector<bool> ck1(n);
		for (int i{0}; i < m; ++i) ck1[i] = true;
		priority_queue<pair<ll, int>> pq{};
		for (int j{0}; j < m; ++j) {
			{
				int i{i1[v2[j].se]};
				if (ck1[i]) {
					ck1[i] = false;
					c += v1[i].fi.fi;
					s[v1[i].se] = 0;
				} else {
					while (!ck1[k]) --k;
					ck1[k] = false;
					c += v1[k].fi.fi;
					s[v1[k].se] = 0;
				}
				c -= v2[j].fi.fi;
				s[v2[j].se] = 1;
			}
			while (c < 0 && !pq.empty()) {
				auto [d, i]{pq.top()}; pq.pop();
				c += d, s[i] = 1;
			}
			if (c < 0) break;
			ll d{v2[j].fi.se - v2[j].fi.fi}; int i{v2[j].se};
			if (c - d >= 0) {
				c -= d, s[i] = 2, pq.emplace(d, i);
			} else if (!pq.empty() && pq.top().fi > d) {
				auto [_d, _i]{pq.top()}; pq.pop();
				c += _d, s[_i] = 1;
				c -= d, s[i] = 2, pq.emplace(d, i);
			}
			mx = max(mx, int(pq.size()));
			if (mx == r) {
				ans = s;
				break;
			}
		}
		return mx;
	}};

	vector<int> ans{};
	int r{run(c, s, k, ans)};
	if (r) run(c, s, k, ans, r);
	else ans = s;

	for (auto& x : ans) cout << x;
	cout << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve2()) ;
}


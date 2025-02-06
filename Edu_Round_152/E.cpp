//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<int> p(n);
	for (auto& x : p) cin >> x, --x;

	vector<int> idx(n);
	for (int i{0}; i < n; ++i) idx[p[i]] = i;

	vector<int> pl(n);
	{
		stack<pair<int, int>> s{};
		s.emplace(-1, -1);
		for (int i{0}; i < n; ++i) {
			while (s.top().fi > p[i]) s.pop();
			pl[i] = s.top().se;
			s.emplace(p[i], i);
		}
	}
	vector<int> pg(n);
	{
		stack<pair<int, int>> s{};
		s.emplace(n, -1);
		for (int i{0}; i < n; ++i) {
			while (s.top().fi < p[i]) s.pop();
			pg[i] = s.top().se;
			s.emplace(p[i], i);
		}
	}

	using ll = long long;
	ll ans{}, cnt{};
	vector<pair<int, int>> r{};
	for (int i{1}; i < n; ++i) {
		if (p[i - 1] < p[i]) {
			while (!r.empty() && r.back().fi >= pg[i] + 1) cnt -= r.back().se - r.back().fi, r.pop_back();
			if (!r.empty() && r.back().se >= pg[i] + 1) cnt += i - r.back().se, r.back().se = i;
			else cnt += i - (pg[i] + 1), r.emplace_back(pg[i] + 1, i);
		} else {
			while (!r.empty() && r.back().fi >= pl[i] + 1) cnt -= r.back().se - r.back().fi, r.pop_back();
			if (!r.empty() && r.back().se > pl[i] + 1) cnt -= r.back().se - (pl[i] + 1), r.back().se = pl[i] + 1;
		}
		ans += cnt;
	}

	return cout << ans << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}

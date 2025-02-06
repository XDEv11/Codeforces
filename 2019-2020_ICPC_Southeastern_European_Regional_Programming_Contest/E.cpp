//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

bool solve() {
	using ll = long long;

	ll n, k, lc, pc, lm, pm, t, d;
	if (!(cin >> n >> k >> lc >> pc >> lm >> pm >> t >> d)) return false;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());

	ll rq{}, mr{}, ic{};
	auto ifm{[&](ll x, bool add = true) {
		if (x >= lm) mr += (add ? 1 : -1) * min(d, x - lm);
		else if (x + d >= lm) rq += (add ? 1 : -1) * (lm - x);
		else ic += (add ? 1 : -1);
	}};
	for (auto& x : v) ifm(x);

	ll ans{numeric_limits<ll>::max()};
	ll i{0}, j{n - 1};
	while (i <= j + 1) {
		if (!ic && mr >= rq) ans = min(ans, (n - 1 - j) * pc + (j + 1 - i) * pm + rq * t);
		ifm(v[j], false);
		if (v[j] >= lc) mr += min(d, v[j] - lc); 
		else if (v[j] + d >= lc) rq += lc - v[j]; 
		else ++ic;
		j -= 1;
		ll b{min({n, j + 1, i + k - 1})};
		for (; i < b; ++i) ifm(v[i], false), mr += min(d, v[i] - 1);
	}

	return cout << (ans == numeric_limits<ll>::max() ? -1 : ans) << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}

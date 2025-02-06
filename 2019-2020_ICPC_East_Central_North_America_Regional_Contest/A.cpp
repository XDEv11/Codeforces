//#pragma GCC optimize ("O3")

#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <queue>
#include <cmath>

using namespace std;

bool solve() {
	using ll = long long;

	ll n, m, p;
	if (!(cin >> n >> m >> p)) return false;
	vector<array<ll, 2>> a(n), b(m), c(p);
	for (auto& [x, y] : a) cin >> x >> y;
	for (auto& [x, y] : b) cin >> x >> y;
	for (auto& [x, y] : c) cin >> x >> y;

	double ans{};
	auto sq{[](ll x) { return x * x; }};

	{
	priority_queue<array<ll, 3>> pq{};
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) pq.push({-(sq(a[i][0] - b[j][0]) + sq(a[i][1] - b[j][1])), -j, -i});
	vector<bool> cka(n), ckb(m);
	while (!pq.empty()) {
		auto [d2, j, i]{pq.top()}; pq.pop();
		d2 *= -1, j *= -1, i *= -1;
		if (cka[i] || ckb[j]) continue;
		cka[i] = ckb[j] = true;
		ans += sqrt(d2);
	}
	}

	{
	priority_queue<array<ll, 3>> pq{};
	for (int i{0}; i < n; ++i)
		for (int k{0}; k < p; ++k) pq.push({-(sq(a[i][0] - c[k][0]) + sq(a[i][1] - c[k][1])), -k, -i});
	vector<bool> cka(n), ckc(p);
	while (!pq.empty()) {
		auto [d2, k, i]{pq.top()}; pq.pop();
		d2 *= -1, k *= -1, i *= -1;
		if (cka[i] || ckc[k]) continue;
		cka[i] = ckc[k] = true;
		ans += sqrt(d2);
	}
	}

	cout << ans << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(7);
	
	while (solve()) ;
}

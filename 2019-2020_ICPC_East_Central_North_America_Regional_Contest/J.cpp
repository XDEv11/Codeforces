//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <queue>
#include <algorithm>

using namespace std;

bool solve() {
	using ll = long long;
	int n, k;
	if (!(cin >> n >> k)) return false;
	vector<pair<ll, ll>> v(n);
	for (auto& [y, x] : v) cin >> x >> y;

	sort(v.begin(), v.end());

	ll l{0}, r{1000000000ll * n};
	while (r - l > 1) {
		ll m{(l + r) / 2};
		int c{};
		ll s{};
		priority_queue<ll> pq{};
		for (auto& [d, x] : v) {
			s += x, pq.push(x);
			if ((s + m - 1) / m > d) s -= pq.top(), pq.pop(), ++c;
		}
		(c > k ? l : r) = m;
	}

	return cout << r << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}

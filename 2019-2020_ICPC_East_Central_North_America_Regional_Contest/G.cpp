//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve() {
	using ll = long long;
	int n; ll md, a, c, x;
	if (!(cin >> n >> md >> a >> c >> x)) return false;
	vector<ll> v(n);
	for (int i{0}; i < n; ++i) v[i] = x = (a * x + c) % md;

	auto fbs{[&](ll z) {
		int l{0}, r{n - 1};
		while (l <= r) {
			int m{(l + r) / 2};
			if (v[m] == z) return true;
			else if (v[m] < z) l = m + 1;
			else r = m - 1;
		}
		return false;
	}};

	int ans{};
	for (int i{0}; i < n; ++i) ans += fbs(v[i]);

	return cout << ans << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve()) ;
}

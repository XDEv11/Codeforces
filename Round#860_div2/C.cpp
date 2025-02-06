//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for (int i{0}; i < n; ++i) cin >> a[i] >> b[i];

	int ans{0};
	for (int i{0}; i < n; ) {
		ll lb{b[i]}, gab{a[i] * b[i]};
		int j{i + 1};
		while (j < n) {
			ll nlb{lcm(lb, b[j])}, ngab{gcd(gab, a[j] * b[j])};
			if (ngab % nlb) break;
			++j, lb = nlb, gab = ngab;
		}
		++ans, i = j;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

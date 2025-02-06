//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	using ll = long long;
	const ll mod{998244353};

	int l, r;
	cin >> l >> r;

	int k{0}, t{r / l};
	while (t > 1) t /= 2, ++k;
	if (k == 0) return cout << "1 " << (r + 1 - l) % mod << '\n', []{}();

	int m1{r / ((1 << (k - 1)) * 3)}, m2{r / (1 << k)};
	cout << (k + 1) << ' ' << (static_cast<ll>(max(0, m1 + 1 - l)) * k + (m2 + 1 - l)) % mod << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

namespace {
	using ll = long long;
	using ull = unsigned long long;
	ull Intsqrt(ull x) {
		ull l{0ULL}, r{1ULL << 32};
		while (r - l > 1) {
			auto m{(l + r) / 2};
			if (m * m <= x) l = m;
			else r = m;
		}
		return l;
	}
	bool check(ll x) {
		ll y{Intsqrt(x)};
		return y * y == x;
	}
	void solve() {
		ll n;
		cin >> n;
		if (check(n * (n + 1) / 2)) return cout << "-1\n", []{}();

		ll s{};
		bool f{false};
		for (ll i{1}; i <= n; ++i) {
			s += i;
			if (!f) {
				if (check(s)) cout << (i + 1) << ' ', f = true;
				else cout << i << ' ';
			} else cout << (i - 1) << ' ', f = false;
		}
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

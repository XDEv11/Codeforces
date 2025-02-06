//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	int k;
	pair<ll, ll> dac(int n) {
		if (n < k) return {0, 0};

		int h{n / 2};
		auto [x, y]{dac(h)};
		if (n & 1) return {1 + 2 * x, h + 2 * y + (h + 1) * x};
		else return {2 * x, 2 * y + h * x};
	}
	void solve() {
		int n;
		cin >> n >> k;

		auto [x, y]{dac(n)};

		cout << (x + y) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

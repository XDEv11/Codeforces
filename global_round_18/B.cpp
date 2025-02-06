//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <array>

using namespace std;

void solve() {
	auto calc = [](int x) {
		++x;
		array<int, 18> cnt{};
		for (int b{0}; b < 18; ++b)
			cnt[b] = x / (1 << (b + 1)) * (1 << b) + max(0, x % (1 << (b + 1)) - (1 << b));
		return cnt;
	};

	int l, r;
	cin >> l >> r;

	auto cntl{calc(l - 1)}, cntr{calc(r)};

	int ans{0};
	for (int b{0}; b < 18; ++b) ans = max(ans, cntr[b] - cntl[b]);
	cout << r - l + 1 - ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

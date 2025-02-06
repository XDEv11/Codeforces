//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

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

ull calc(ull x) {
	if (!x) return 0;
	auto s{Intsqrt(x)};
	return (s - 1) * 3 + 1 + (x - s * s) / s;
}	

void solve() {
	ull l, r;
	cin >> l >> r;

	cout << calc(r) - calc(l - 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

unsigned long long Intsqrt(unsigned long long x) {
	unsigned long long l{0ULL}, r{1ULL << 32};
	while (r - l > 1) {
		auto m{(l + r) / 2};
		if (m * m <= x) l = m;
		else r = m;
	}
	return l;
}

bool ps(unsigned long long n) {
	auto s{Intsqrt(n)};
	return s * s == n;
}

void solve() {
	int x, y;
	cin >> x >> y;

	if (!x && !y) cout << "0\n";
	else if (ps(x * x + y * y)) cout << "1\n";
	else cout << "2\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

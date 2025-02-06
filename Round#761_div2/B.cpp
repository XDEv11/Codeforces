//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <numeric>

using namespace std;

void solve() {
	int n;
	cin >> n;

	if (n & 1) {
		int x{(n - 1) / 2}, d{x & 1 ? 2 : 1};
		cout << x + d << ' ' << x - d << " 1\n"s;
	} else cout << n - 3 << " 2 1\n"s;
}

void solve2() {
	int n;
	cin >> n;

	int i{2};
	while (true) {
		if (gcd(i, n - 1 - i) == 1) return cout << i << ' ' << n - 1 - i << " 1\n"s, []{}();
		++i;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve2();

	return 0;
}

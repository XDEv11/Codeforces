//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;

	auto test{[](int x, int y, int z) {
		if (x < y) swap(x, y);
		x -= y, z += y, y = 0;
		return !((x & 1) || !z);
	}};

	cout << test(b, c, a) << ' ' << test(a, c, b) << ' ' << test(a, b, c) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

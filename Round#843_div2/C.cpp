//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	using ull = unsigned long long;

	ull n, x;
	cin >> n >> x;

	int b{63};
	while (b >= 0) {
		if ((n >> b) & 1) {
			if ((x >> b) & 1) ;
			else break;
		} else if ((x >> b) & 1) return cout << "-1\n", []{}();
		--b;
	}

	for (int c{b - 1}; c >= 0; --c) {
		if ((x >> c) & 1) return cout << "-1\n", []{}();
	}

	if (b >= 0) {
		if ((n >> b) & 2) return cout << "-1\n", []{}();
		n = (((n >> b) + 1) << b);
	}

	cout << n << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

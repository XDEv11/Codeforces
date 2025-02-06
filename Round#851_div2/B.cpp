//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	int a{0}, b{0};
	int p{1};
	bool f{true};
	while (n) {
		int d{n % 10};
		if (d & 1) {
			if (f) a += (d / 2 + 1) * p, b += d / 2 * p, f = false;
			else a += d / 2 * p, b += (d / 2 + 1) * p, f = true;
		} else a += d / 2 * p, b += d / 2 * p;
		n /= 10;
		p *= 10;
	}

	cout << a << ' ' << b << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

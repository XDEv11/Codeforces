//#pragma GCC optimize ("O3")

#include <iostream>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		unsigned x, y;
		cin >> x >> y;

		int k{29};
		while (k >= 0 && !(x & y & (1 << k))) --k;
		if (k < 0) return void(cout << x << ' ' << y << '\n');

		unsigned m{(1 << k) - 1};
		unsigned p{x ^ (x & m)}, q{(y | m) ^ (m + 1)}, ans{x - p + y - q};

		while ((x | y) & (1 << k)) ++k;
		m = (1 << k) - 1;
		if ((x & m) >= (y & m)) {
			if (m + 1 - (x & m) < ans) ans = m + 1 - (x & m), p = (x ^ (x & m)) | (m + 1), q = y;
		} else {
			if (m + 1 - (y & m) < ans) ans = m + 1 - (y & m), p = x, q = (y ^ (y & m)) | (m + 1);
		}

		cout << p << ' ' << q << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

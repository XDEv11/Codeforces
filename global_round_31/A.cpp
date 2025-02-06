//#pragma GCC optimize ("O3")

#include <iostream>
#include <numeric>

using namespace std;

namespace {
	void solve() {
		int n, a, b;
		cin >> n >> a >> b;

		int g{gcd(n, b)};
		a += (n - 1 - a) / g * g;
		cout << a << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

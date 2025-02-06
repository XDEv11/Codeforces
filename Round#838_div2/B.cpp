//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int power2(int x) {
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return x + 1;
}

void solve() {
	static const int maxn{1000000000};

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	cout << n << '\n';
	for (int i{0}; i < n; ++i) {
		cout << i + 1 << ' ' << power2(v[i]) - v[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

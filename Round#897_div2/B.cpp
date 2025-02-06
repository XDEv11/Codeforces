//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int c{};
	for (int i{0}; i < n - 1 - i; ++i) c += v[i] != v[n - 1 - i];

	for (int i{0}; i <= n; ++i) {
		if (i < c || i > n - c) cout << '0';
		else if (n & 1) cout << '1';
		else cout << ((i - c) & 1 ? '0' : '1');
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

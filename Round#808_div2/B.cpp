//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, l, r;
	cin >> n >> l >> r;

	vector<int> v(n);
	for (int i{1}; i <= n; ++i) {
		if (l % i && l / i == r / i) return cout << "NO\n", []{}();
		v[i - 1] = i * (r / i);
	}
	cout << "YES\n";
	for (auto& x : v) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

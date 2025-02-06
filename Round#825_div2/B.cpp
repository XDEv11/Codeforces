//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a) cin >> x;

	for (int i{0}; i + 2 < n; ++i) {
		if (a[i + 1] % gcd(a[i], a[i + 2])) return cout << "NO\n", []{}();
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

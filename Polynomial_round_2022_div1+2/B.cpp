//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(m);
	for (auto& x : v) cin >> x;

	int c{n % k};
	for (auto& x : v) {
		if (x == n / k + 1) --c;
		if (x > (n + k - 1) / k || c < 0) return cout << "NO\n", []{}();
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

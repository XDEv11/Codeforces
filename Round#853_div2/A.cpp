//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	for (int i{0}; i < n; ++i)
		for (int j{i + 1}; j < n; ++j) {
			if (gcd(v[i], v[j]) <= 2) return cout << "Yes\n", []{}();
		}
	cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

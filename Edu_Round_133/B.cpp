//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>
#include <utility>

using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> v(n); iota(v.begin(), v.end(), 1);
	cout << n << '\n';
	for (auto& x : v) cout << x << ' ';
	cout << '\n';
	for (int i{0}; i + 1 < n; ++i) {
		swap(v[i], v[i + 1]);
		for (auto& x : v) cout << x << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

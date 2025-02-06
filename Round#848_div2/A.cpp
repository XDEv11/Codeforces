//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	if (count(v.begin(), v.end(), -1) == 0) return cout << n - 4 << '\n', []{}();

	for (int i{0}; i + 1 < n; ++i) {
		if (v[i] == -1 && v[i + 1] == -1) {
			v[i] = v[i + 1] = 1;
			break;
		}
	}

	cout << accumulate(v.begin(), v.end(), 0) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

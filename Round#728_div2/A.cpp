#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	iota(v.begin(), v.end(), 1);

	for (int i{0}; i + 1 < n; i += 2) swap(v[i], v[i + 1]);
	if (n & 1) swap(v[n - 2], v[n - 1]);

	for (auto& x : v) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

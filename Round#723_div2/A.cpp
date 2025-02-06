#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(2 * n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());

	for (int i{0}; i < n; ++i)
		cout << v[i] << ' ' << v[n + i] << " \n"[i == n - 1];

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

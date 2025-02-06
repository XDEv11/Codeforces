#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	if (is_sorted(v.begin(), v.end())) cout << "0\n";
	else if (v[0] == 1 || v[n - 1] == n) cout << "1\n";
	else if (v[0] == n && v[n - 1] == 1) cout << "3\n";
	else cout << "2\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

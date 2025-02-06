#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	bool f{false};
	for (int i{0}; i + 1 < n; ++i)
		if (!(v[i] < v[i + 1])) f = true;

	cout << ((n & 1) && (f == false) ? "NO\n"s : "YES\n"s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

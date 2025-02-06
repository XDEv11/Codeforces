#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int s{accumulate(v.begin(), v.end(), 0)};
	for (int d{2}; d < s; ++d)
		if (s % d == 0) {
			cout << n << '\n';
			for (int i{0}; i < n; ++i) cout << i + 1 << ' ';
			return cout << '\n', []{}();
		}

	bool f{true};
	cout << n - 1 << '\n';
	for (int i{0}; i < n; ++i)
		if (f && (v[i] & 1)) f = false;
		else cout << i + 1 << ' ';
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

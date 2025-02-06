//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	long long a, b;
	cin >> n >> a >> b;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	long long c{0}, ans{0};
	for (int i{0}; i < n; ++i) {
		ans += b * (v[i] - c);
		if (a < b * (n - 1 - i)) ans += a * (v[i] - c), c = v[i];
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	long long b;
	cin >> n >> b;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());
	vector<long long> ps(n + 1);
	int i{0};
	for (; i < n; ++i) {
		ps[i + 1] = ps[i] + v[i];
		if (ps[i + 1] > b) break;
	}

	long long d{0}, ans{0};
	while (i) {
		auto dn{(b - ps[i]) / i};
		ans += i * (dn - d + 1);
		d = dn + 1, --i;
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

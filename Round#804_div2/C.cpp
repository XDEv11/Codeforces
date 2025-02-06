//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

const long long mod{1000000007};

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> p(n);
	for (int i{0}; i < n; ++i) p[v[i]] = i;

	long long ans{1};
	int l{p[0]}, r{p[0]};
	for (int i{1}; i < n; ++i) {
		if (p[i] < l) l = p[i];
		else if (r < p[i]) r = p[i];
		else ans = ans * (r - l + 1 - i) % mod;
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

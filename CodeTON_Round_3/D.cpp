//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const int mod{998244353};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	for (int i{0}; i + 1 < n; ++i) {
		if (gcd(v[i], v[i + 1]) != v[i + 1]) return cout << "0\n", []{}();
	}

	long long ans{1};
	for (int i{0}; i + 1 < n; ++i) {
		v[i] / v[i + 1];

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn{1000000000};

void solve() {
	int n;
	cin >> n;

	vector<long long> v(n);
	v[0] = 1;
	for (int i{1}; i < n; ++i) {
		v[i] = v[i - 1] * 3;
		if (v[i] > maxn) return cout << "NO\n", []{}();
	}
	cout << "YES\n";
	for (auto& x : v) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

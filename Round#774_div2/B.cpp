//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	sort(v.rbegin(), v.rend());
	long long s1{0}, s2{0};
	for (int i{0}; i < (n - 1) / 2; ++i) s1 += v[i];
	for (int i{n / 2}; i < n; ++i) s2 += v[i];

	cout << (s1 > s2 ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

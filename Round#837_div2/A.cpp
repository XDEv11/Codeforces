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

	if (v[0] == v[n - 1]) return cout << static_cast<long long>(n) * (n - 1) << '\n', []{}();

	cout << static_cast<long long>(count(v.begin(), v.end(), v[0])) * count(v.begin(), v.end(), v[n - 1]) * 2 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

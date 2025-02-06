//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int x, y, n;
	cin >> x >> y >> n;

	vector<int> v(n);
	v[n - 1] = y;
	for (int i{n - 2}, k{1}; i >= 0; --i, ++k) v[i] = v[i + 1] - k;
	if (v[0] < x) return cout << "-1\n", []{}();
	v[0] = x;

	for (auto& e : v) cout << e << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int c{0};
	for (int i{0}; i < k; ++i)
		for (int j{i}; j < n; j += k) c += ((v[j] - 1) % k != i);

	cout << (c == 0 ? "0\n" : (c == 2 ? "1\n" : "-1\n"));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

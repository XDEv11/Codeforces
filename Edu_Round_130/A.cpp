//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	cout << max(0, accumulate(v.begin(), v.end(), 0) - m) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

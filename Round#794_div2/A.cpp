//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	auto s{accumulate(v.begin(), v.end(), 0)};
	cout << (s % n == 0 && count(v.begin(), v.end(), s / n) ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

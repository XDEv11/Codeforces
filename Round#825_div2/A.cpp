//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	bool flag1{false}, flag2{false};
	for (int i{0}; i < n; ++i) {
		if (a[i] > b[i]) flag1 = true;
		if (a[i] < b[i]) flag2 = true;
	}
	cout << abs(count(a.begin(), a.end(), 1) - count(b.begin(), b.end(), 1)) + (flag1 && flag2) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

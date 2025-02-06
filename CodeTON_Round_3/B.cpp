//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	long long cnt0{0}, c0{0}, c1{0}, mx0{0}, mx1{0};
	for (auto& x : v) {
		if (x == '0') {
			++cnt0;
			++c0;
			c1 = 0;
			mx0 = max(mx0, c0);
		} else {
			++c1;
			c0 = 0;
			mx1 = max(mx1, c1);
		}
	}
	cout << max(cnt0 * (n - cnt0), max(mx0 * mx0, mx1 * mx1)) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

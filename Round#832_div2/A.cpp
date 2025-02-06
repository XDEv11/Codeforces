//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	long long ans{0};
	for (auto& x : v) ans += x;
	cout << abs(ans) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

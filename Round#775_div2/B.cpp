//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int mx{*max_element(v.begin(), v.end())};
	long long s{accumulate(v.begin(), v.end(), 0LL)};

	if (mx == 0) cout << "0\n";
	else cout << 1 + max(0LL, mx - (s - mx + 1)) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

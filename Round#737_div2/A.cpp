#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	auto mx{*max_element(v.begin(), v.end())};
	auto sum{accumulate(v.begin(), v.end(), 0ll)};

	cout << fixed << setprecision(6) << (mx + double(sum - mx) / (n - 1)) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

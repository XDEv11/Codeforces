//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	auto [_l, _r]{minmax_element(v.begin(), v.end())};
	long long l{*_l}, r{*_r + 1};

	while (r - l > 1) {
		long long m{(l + r) / 2};
		bool ok{true};
		auto t{v};
		for (int i{n - 1}; i >= 0; --i) {
			if (t[i] < m) {
				ok = false;
				break;
			}
			if (i >= 2) {
				long long g{min(v[i], t[i] - m)};
				t[i - 1] += g / 3, t[i - 2] += g / 3 * 2;
			}
		}
		ok ? (l = m) : (r = m);
	}
	cout << l << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

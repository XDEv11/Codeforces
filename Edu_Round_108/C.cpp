#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> u(n), s(n);
	for (auto& x : u) cin >> x;
	for (auto& x : s) cin >> x;

	vector<vector<long long>> t(n);
	for (int i{0}; i < n; ++i) {
		t[u[i] - 1].push_back(s[i]);
	}

	long long tot{0};
	for (auto& v : t) {
		v.push_back(0);
		sort(v.begin(), v.end());
		for (int i{1}; i < v.size(); ++i) {
			tot += v[i];
			v[i] += v[i - 1]; // prefix sum
		}
	}

	vector<long long> v1(n + 2), v2(n + 2);
	for (auto& v : t) {
		int ns{v.size() - 1};
		for (int k{1}; k < ns; ++k) {
			v1[k] += v[ns % k];
		}
		v2[ns + 1] += v[ns];
	}
	for (int k{1}; k <= n; ++k) v2[k] += v2[k - 1];

	for (int k{1}; k <= n; ++k) {
		cout << tot - v1[k] - v2[k] << " \n"[k == n];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

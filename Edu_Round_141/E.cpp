//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	vector<int> v1(n + 1);
	for (int i{0}; i < n; ++i) {
		if (a[i] <= b[i]) continue;
		v1[b[i]] += 1;
		v1[a[i]] -= 1;
	}

	vector<int> v2(n + 1);
	v2[0] = v1[0];
	for (int i{1}; i < n; ++i) v2[i] = v2[i - 1] + v1[i];

	vector<bool> v3(n + 1);
	for (int i{n}; i >= 1; --i) {
		if (!v2[i] && !v3[i]) continue;
		for (int j{1}; j * j <= i; ++j) {
			if (i % j) continue;
			v3[j] = v3[i / j] = true;
		}
	}

	cout << count(v3.begin(), v3.end(), false) - 1 << '\n';
	for (int i{1}; i <= n; ++i) {
		if (v3[i]) continue;
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

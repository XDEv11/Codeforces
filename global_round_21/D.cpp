//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> premn(n), premx(n), sufmn(n), sufmx(n);
	int mn{v[0]}, mx{v[0]};
	premn[0] = premx[0] = 0;
	for (int i{1}; i < n; ++i) {
		if (v[i] < mn) mn = v[i], premn[i] = i;
		else premn[i] = premn[i - 1];
		if (v[i] > mx) mx = v[i], premx[i] = i;
		else premx[i] = premx[i - 1];
	}
	mn = mx = v[n - 1];
	sufmn[n - 1] = sufmx[n - 1] = n - 1;
	for (int i{n - 2}; i >= 0; --i) {
		if (v[i] < mn) mn = v[i], sufmn[i] = i;
		else sufmn[i] = sufmn[i + 1];
		if (v[i] > mx) mx = v[i], sufmx[i] = i;
		else sufmx[i] = sufmx[i + 1];
	}

	int ans{0};
	int i{premx[n - 1]};
	while (i > 0) {
		i = premn[i];
		++ans;
		if (i == 0) break;
		i = premx[i];
		++ans;
	}
	i = premx[n - 1];
	while (i < n - 1) {
		i = sufmn[i];
		++ans;
		if (i == n - 1) break;
		i = sufmx[i];
		++ans;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

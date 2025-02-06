//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<long long> b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	vector<int> fire{}, frost{};
	for (int i{0}; i < n; ++i) {
		if (a[i] == 0) fire.push_back(b[i]);
		else frost.push_back(b[i]);
	}

	sort(fire.rbegin(), fire.rend());
	sort(frost.rbegin(), frost.rend());

	long long ans{0};
	int m{min(fire.size(), frost.size())};
	for (int i{0}; i < fire.size(); ++i) {
		ans += fire[i];
		if (i < m) ans += fire[i];
	}
	for (int i{0}; i < frost.size(); ++i) {
		ans += frost[i];
		if (i < m) ans += frost[i];
	}
	if (fire.size() == frost.size()) ans -= min(fire.back(), frost.back());

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

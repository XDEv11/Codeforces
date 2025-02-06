//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> odd{}, even{};
	for (int i{0}; i < n; ++i) {
		if (v[i] & 1) odd.push_back(i);
		else even.push_back(i);
	}
	if (odd.empty()) return cout << "NO\n", []{}();

	vector<int> ans{};
	ans.push_back(odd[0]);
	if (even.size() >= 2) {
		ans.push_back(even[0]);
		ans.push_back(even[1]);
	} else if (odd.size() >= 3) {
		ans.push_back(odd[1]);
		ans.push_back(odd[2]);
	} else return cout << "NO\n", []{}();

	cout << "YES\n";
	for (auto& x : ans) cout << x + 1 << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int c{count(v.begin(), v.end(), '0')};

	vector<int> ans{};
	for (int i{0}; i < c; ++i)
		if (v[i] == '1') ans.push_back(i);
	for (int i{c}; i < n; ++i)
		if (v[i] == '0') ans.push_back(i);

	if (ans.empty()) cout << "0\n";
	else {
		cout << "1\n";
		cout << ans.size() << ' ';
		for (auto& x : ans) cout << x + 1 << ' ';
		cout << '\n';
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

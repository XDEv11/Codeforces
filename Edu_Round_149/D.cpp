//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	if (count(v.begin(), v.end(), '(') != count(v.begin(), v.end(), ')')) return cout << "-1\n", []{}();

	vector<int> idx1{}, idx2{};
	int c{0};
	for (int i{0}; i < n; ++i) {
		if (v[i] == '(') ++c;
		else if (v[i] == ')') --c;
		if (c > 0 || (c == 0 && v[i] == ')')) idx1.push_back(i);
		if (c < 0 || (c == 0 && v[i] == '(')) idx2.push_back(i);
	}

	if (idx1.empty()) swap(idx1, idx2);
	vector<int> ans(n);
	for (auto& x : idx1) ans[x] = 1;
	for (auto& x : idx2) ans[x] = 2;

	cout << (idx2.empty() ? "1\n" : "2\n");
	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

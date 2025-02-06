//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> v{};
	while (n > 2) {
		if (n & 1) v.push_back(1), n = (n - 1) / 2;
		else v.push_back(2), n = (n - 2) / 2;
	}

	deque<char> ans1{'a'}, ans2{};
	for (int i{1}; i < n; ++i) ans2.push_back('a');
	for (int i{0}; i < v.size(); ++i) { // p ps
		ans1.push_back('b' + i);
		if (v[v.size() - 1 - i] == 1) ; // px pxsxx
		else ans2.push_front('b' + i); // px pxxsxx
		ans2.push_back('b' + i), ans2.push_back('b' + i);
	}

	for (auto& x : ans1) cout << x;
	for (auto& x : ans2) cout << x;
	cout << ' ';
	for (auto& x : ans1) cout << x;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}

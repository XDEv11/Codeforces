//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int cnt{0}, i{0};
	while (i + 1 < n) {
		if (v[i] == '(' || v[i + 1] == ')') i = i + 2;
		else {
			int j{i + 1};
			while (j < n && v[j] != ')') ++j;
			if (j == n) break;
			i = j + 1;
		}
		++cnt;
	}

	cout << cnt << ' ' << n - i << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

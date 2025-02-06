//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	const string pat{"FBFFBFFB"s};
	for (int i{0}; i < pat.size(); ++i) {
		int j{i};
		bool f{true};
		for (auto& x : v) {
			if (x != pat[j]) {
				f = false;
				break;
			}
			j = (j + 1) % pat.size();
		}
		if (f) return cout << "YES\n", []{}();
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

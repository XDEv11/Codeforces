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

	vector<char> v2(n);
	int c{0};
	if (v[n - 1] == '0') v2[n - 1] = '1';
	else if (v[n - 1] == '1') v2[n - 1] = '0';
	else v2[n - 1] = '0' + 11 - (v[n - 1] - '0'), c = 1;
	if (v[0] != '9') {
		for (int i{n - 2}; i >= 0; --i)
			if (!c && v[i] == '0') v2[i] = '0';
			else v2[i] = '0' + 10 - c - (v[i] - '0'), c = 1;
	} else {
		for (int i{n - 2}; i >= 0; --i) {
			if (c) {
				if (v[i] == '0') v2[i] = '0', c = 0;
				else v2[i] = '0' + 10 - (v[i] - '0');
			} else {
				if (v[i] == '0') v2[i] = '1';
				else if (v[i] == '1') v2[i] = '0';
				else v2[i] = '0' + 11 - (v[i] - '0'), c = 1;
			}
		}
	}
	for (auto& x : v2) cout << x;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int cd{0}, cr{0};
	for (auto& e : s)
		if (e == 'D') ++cd;
		else if (e == 'R') ++ cr;

	int ed{cd ? n - 1 - cd : 1}, er{cr ? n - 1 - cr : 1};
	cout << ed << ", " << er << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

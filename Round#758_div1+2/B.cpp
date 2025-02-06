//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;

	if (a > b + 1 || b > a + 1 || a + b > n - 2) return cout << "-1\n"s, []{}();

	vector<int> ans{};
	int low{1}, high{n};
	bool up{true};
	if (!a && !b) ;
	else if (a == b + 1) ans.push_back(low++), ans.push_back(high--), --a;
	else ans.push_back(high--), ans.push_back(low++), up = false, --b;

	while (true) {
		if (low > high) break;
		if (up) {
			if (b) ans.push_back(low++), --b, up = false;
			else ans.push_back(high--);
		} else {
			if (a) ans.push_back(high--), --a, up = true;
			else ans.push_back(low++);
		}
	}

	for (auto&& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

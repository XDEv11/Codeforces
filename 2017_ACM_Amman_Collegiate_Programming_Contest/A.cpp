#include <iostream>
#include <string>
#include <map>
 
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	map<int, int> mp{};
	while (n--) {
		string s{}; int f{};
		cin >> s >> f;
		++mp[f];
	}
 
	int mx{0}, ans;
	for (auto& [k, v] : mp) {
		if (v > mx) mx = v, ans = k;
	}
 
	cout << ans << '\n';
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	cin >> t;
	while (t--) solve();
}

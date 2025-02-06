#include <iostream>
#include <vector>
#include <string>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

bool solve() {
	using ll = long long;

	int n; ll d; int k;
	if (!(cin >> n >> d >> k)) return false;
	vector<pair<ll, string>> v(n);
	for (auto& [x, y] : v) cin >> y >> x;

	vector<string> ans{};
	sort(v.rbegin(), v.rend());
	for (int i{0}; i < k && d > 0; ++i) {
		auto& [x, y]{v[i]};
		d -= x, ans.push_back(y);
	}

	if (d <= 0) {
		cout << ans.size() << '\n';
		for (auto& x : ans) cout << x << ", YOU ARE FIRED!\n";
	} else cout << "impossible\n";
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}

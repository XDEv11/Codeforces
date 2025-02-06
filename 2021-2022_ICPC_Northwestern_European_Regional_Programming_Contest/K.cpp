//#pragma GCC optimize ("O3")

#include <iostream>
#include <map>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	map<string, array<int, 3>> mp{};
	while (n--) {
		string a{}, b{};
		int c;
		cin >> a >> b >> c;
		if (b == "left") mp[a][0] = c;
		else if (b == "right") mp[a][1] = c;
		else if (b == "any") mp[a][2] = c;
	}

	bool f{false};
	int ans{};
	for (auto& [k, v] : mp) {
		if ((v[0] && v[1]) || v[2] >= 2) f = true;
		ans += max({v[0], v[1], 1});
	}

	if (!f) cout << "impossible\n";
	else cout << (ans + 1) << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}

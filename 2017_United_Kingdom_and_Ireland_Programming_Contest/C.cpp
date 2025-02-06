//#pragma GCC optimize ("O3")

#include <iostream>
#include <map>
#include <array>
#include <algorithm>

using namespace std;

const map<string, int> dict{
	{"red", 0}, 
	{"yellow", 1}, 
	{"green", 2}, 
	{"brown", 3}, 
	{"blue", 4}, 
	{"pink", 5}, 
	{"black", 6}
};

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	array<int, 7> c{};
	while (n--) {
		string s{};
		cin >> s;
		++c[dict.find(s)->second];
	}

	int mx{6};
	while (!c[mx]) --mx;
	if (mx == 0) return cout << "1\n", true;

	int ans{};
	ans += c[0] * (1 + (mx + 1));
	for (int i{1}; i <= 6; ++i) ans += c[i] * (i + 1);

	return cout << ans << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}

//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class FS {
	struct node {
		int sz{};
		map<string, int> sub{};
		explicit node() {};
	};
	vector<node> v{1};
	void print(string& s, int t, int p = 0) {
		int len{s.length()};
		s += '/';
		bool f{false};
		for (auto& [x, y] : v[p].sub) {
			if (v[y].sz >= t) f = true;
		}
		if (v[p].sub.empty()) cout << ' ';
		else if (f) cout << '-';
		else cout << '+';
		cout << ' ' << s << ' ' << v[p].sz << '\n';
		if (f) {
			for (auto& [x, y] : v[p].sub) {
				s += x;
				print(s, t, y);
				s.resize(len + 1);
			}
		}
		s.resize(len);
	}
public:
	void add(const string& s, int sz, int i = 0, int p = 0) {
		v[p].sz += sz;
		++i;
		int j{i};
		while (j < s.size() && s[j] != '/') ++j;
		string name{s.begin() + i, s.begin() + j};
		if (j < s.size()) {
			if (!v[p].sub.count(name)) v[p].sub[name] = v.size(), v.emplace_back();
			add(s, sz, j, v[p].sub[name]);
		}
	}
	void print(int t) {
		string tmp{};
		print(tmp, t);
	}
};

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<pair<string, int>> v(n);
	for (auto& [x, y] : v) cin >> x >> y;
	int t;
	cin >> t;

	FS fs{};
	for (auto& [x, y] : v) fs.add(x, y);

	fs.print(t);
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}

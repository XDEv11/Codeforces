//#pragma GCC optimize ("O3")

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// longest prefix which is also suffix
template<typename T>
vector<int> prefix_func(const vector<T>& v) {
    vector<int> len(v.size());
    for (int i{1}; i < v.size(); ++i) {
        int j{len[i - 1]};
        while (j > 0 && v[i] != v[j]) j = len[j - 1];
        len[i] = j + (v[i] == v[j]);
    }
    return len;
}

bool solve(ifstream& fin, ofstream& fout) {
	int n;
	if (fin >> n, n == 0) return false;
	vector<char> v(n);
	for (auto& x : v) fin >> x;
	static int tt{0};
	fout << "Test case #" << ++tt << '\n';

	auto lps{prefix_func(v)};

	vector<pair<int, int>> ans{};
	for (int i{1}; i < n; ++i) {
		if (!lps[i] || (i + 1) % ((i + 1) - lps[i])) continue;
		ans.emplace_back(i + 1, (i + 1) / ((i + 1) - lps[i]));
	}

	for (auto& [i, c] : ans) fout << i << ' ' << c << '\n';
	fout << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ifstream fin{"period.in"};
	ofstream fout{"period.out"};
	
	int t{1};
	cin >> t;
	while (solve(fin, fout)) ;
}

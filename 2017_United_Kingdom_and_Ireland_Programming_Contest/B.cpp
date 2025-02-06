//#pragma GCC optimize ("O3")

#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <limits>
#include <algorithm>
#include <cmath>
#include <numbers>
#include <limits>

using namespace std;

struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0) : x{_x}, y{_y} {}
};
using Vector = Point;

Vector operator+(const Vector &v1, const Vector &v2) { return {v1.x + v2.x, v1.y + v2.y}; }
Vector operator-(const Vector &v1, const Vector &v2) { return {v1.x - v2.x, v1.y - v2.y}; }
Vector operator*(const Vector &v, double d) { return {v.x * d, v.y * d}; }
Vector operator/(const Vector &v, double d) { return {v.x / d, v.y / d}; }

/*
bool operator<(const Point &p1, const Point &p2) {
    if (p1.x != p2.x) return p1.x < p2.x;
    return p1.y < p2.y;
}
*/

int dcmp(double x) {
    if (fabs(x) < 1e-12) return 0;
    return x > 0 ? 1 : -1;
}

bool operator==(const Point &p1, const Point &p2) {
    return dcmp(p1.x - p2.x) == 0 && dcmp(p1.y - p2.y) == 0;
}

double dot(const Vector &v1, const Vector &v2) { return v1.x * v2.x + v1.y * v2.y; }
double length(const Vector &v) { return sqrt(dot(v, v)); }
double cross(const Vector &v1, const Vector &v2) { return v1.x * v2.y - v1.y * v2.x; }

double angle(const Vector &v1, const Vector &v2) {
    return acos(dot(v1, v2) / length(v1) / length(v2));
}

/*
// 2 * area of the triangle {p1, p2, p3}
double area2(const Point &p1, const Point &p2, const Point &p3) {
    return cross(p2 - p1, p3 - p1);
}
*/

Vector rotate(const Vector &v, double rad) {
    return {v.x * cos(rad) - v.y * sin(rad),
            v.x * sin(rad) + v.y * cos(rad)};
}

double DistanceToLine(const Point &p, const Point &a, const Point &b) {
    return cross(p - a, b - a) / length(b - a);
}

bool solve1() {
	int n;
	if (!(cin >> n)) return false;
	vector<Point> p(n);
	for (auto& [x, y] : p) cin >> x >> y;

	double ans{numeric_limits<double>::max()};
	for (int i{0}; i < n; ++i)
		for (int j{i + 1}; j < n; ++j) {
			double mn{numeric_limits<double>::max()}, mx{numeric_limits<double>::min()};
			for (int k{0}; k < n; ++k) {
				double len{DistanceToLine(p[k], p[i], p[j])};
				mn = min(mn, len), mx = max(mx, len);
			}
			ans = min(ans, mx - mn);
		}

	return cout << ans << '\n', true;
}

bool solve2() {
	int n;
	if (!(cin >> n)) return false;
	vector<Point> p(n);
	for (auto& [x, y] : p) cin >> x >> y;

	for (int i{1}; i < n; ++i) p[i] = p[i] - p[0];
	p[0] = {0, 0};

	double ans{numeric_limits<double>::max()};
	int m{1000000};
	for (int k{0}; k <= m; ++k) {
		auto q{p};
		for (int i{1}; i < n; ++i) q[i] = rotate(q[i], numbers::pi_v<double> / 2 * k / m);
		double mnx{numeric_limits<double>::max()}, mxx{numeric_limits<double>::min()}, mny{mnx}, mxy{mxx};
		for (auto& [x, y] : q) mnx = min(mnx, x), mxx = max(mxx, x), mny = min(mny, y), mxy = max(mxy, y);
		ans = min({ans, mxx - mnx, mxy - mny});
	}

	return cout << ans << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cout << fixed << setprecision(7);

	while (solve1()) ;
}

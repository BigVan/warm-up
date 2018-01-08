#include "common.h"



struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	vector<Point> outerTrees(vector<Point>& points) {

		vector<Point> ret{};
		if (points.size() <= 2) {
			ret.assign(points.begin(), points.end());
			return ret;
		}
		sort(points.begin(), points.end(), [](Point a, Point b){
			if (a.y < b.y) return true; 
			if (a.y > b.y) return false;
			return a.x <= b.x;
		});
		/*for (auto it : points) {
			cout << it.x << ' ' << it.y << endl;
		}
		cout << endl;*/
		stack<int> s;
		s.push(0);
		s.push(1);
		for (int i = 2; i < points.size(); i++) {
			s.push(i);
			while (s.size() >= 2) {				
				Point vex1(points[s.top()].x - points[s.top() - 1].x, points[s.top()].y - points[s.top() - 1].y);				
				Point vex0(points[s.top()-1].x - points[s.top() - 2].x, points[s.top()-1].y - points[s.top() - 2].y);
				if (vex0.x*vex1.y - vex0.y*vex1.y >= 0) {			
					break;
				}
				s.pop();
			}

		}
		while (!s.empty()) {
			ret.push_back(points[s.top()]);
			s.pop();
		}
		s.push(points.size() - 1);
		s.push(points.size() - 2);
		for (int i = points.size()-3; i >=0; i--) {
			s.push(i);
			while (s.size() >= 2) {

				Point vex1(points[s.top()].x - points[s.top() - 1].x, points[s.top()].y - points[s.top() - 1].y);
				Point vex0(points[s.top() - 1].x - points[s.top() - 2].x, points[s.top()-1].y - points[s.top() - 2].y);
				if (vex0.x*vex1.y - vex0.y*vex1.y >= 0) {

					break;
				}
				s.pop();
			}
		}
		s.pop();
		while (s.size()>1) {
			ret.push_back(points[s.top()]);
			s.pop();
		}
		return ret;
	}
};

int main() {
	vector<Point> points{ Point(1,1), Point(2,2), Point(2,0), Point(2,4), Point(3,3), Point(4,2) };
	auto ret = Solution().outerTrees(points);
	for (auto it : ret) {
		cout << it.x << ' ' << it.y << endl;
	}
	system("pause");
	return 0;
}
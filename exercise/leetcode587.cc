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

		set<int> ret{};
		if (points.size() <= 2) {
			return vector<Point>(points.begin(), points.end());
		}
		sort(points.begin(), points.end(), [](Point a, Point b){
			if (a.y < b.y) return true; 
			if (a.y > b.y) return false;
			return a.x <= b.x;
		});
			
		vector<int> s;
		s.push_back(0);
		s.push_back(1);
		for (int i = 2; i < points.size(); i++) {
			while (s.size() >= 2) {				
				Point vex1(points[i].x - points[s.back()].x, points[i].y - points[s.back()].y);				
				Point vex0(points[s.back()].x - points[*(s.end()-2)].x, points[s.back()].y - points[*(s.end()-2)].y);
				if (vex0.x*vex1.y - vex0.y*vex1.x >= 0) {						
					break;
				}
				s.pop_back();
			}
			s.push_back(i);
		}
		while (!s.empty()) {
		//	ret.push_back(points[s.back()]);
			ret.insert(s.back());
			s.pop_back();
		}
		s.push_back(points.size() - 1);
		s.push_back(points.size() - 2);
		for (int i = points.size()-3; i >=0; i--) {
			while (s.size() >= 2) {
				Point vex1(points[i].x - points[s.back()].x, points[i].y - points[s.back()].y);
				Point vex0(points[s.back()].x - points[*(s.end() - 2)].x, points[s.back()].y - points[*(s.end() - 2)].y);
				if (vex0.x*vex1.y - vex0.y*vex1.x >= 0) {
					break;
				}
				s.pop_back();
			}
			s.push_back(i);
		}
		s.pop_back();
		while (s.size()>1) {
			ret.insert(s.back());
			s.pop_back();
		}
		vector<Point> ans{};
		for (auto it : ret) {
			ans.push_back(points[it]);
		}
		return ans;
	}
};


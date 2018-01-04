#include "common.h"

class Solution {
public:
	int reversePairs(vector<int>& nums) {

		//sortNums.resize(nums.size());
		mergeSort(nums, 0, nums.size() - 1);
		for (auto it : nums)
			cout << it << ' ';
		cout << endl;
		return -1;
	}
private:
	int count;
	//vector<int> sortNums;
	void mergeSort(vector<int> nums, int l, int r) {

		if (l>=r) return;
		int mid = (l + r) >> 1;
		mergeSort(nums, l, mid);
		mergeSort(nums, mid + 1, r);
		int p = l, q = mid + 1, idx=l;
		vector<int> sortNums{};
		int st = l;
		cout << "l r " << l << ' ' << r << endl;
		while (p <= mid  && q <= r) {
			if (nums[p]<nums[q]){
				sortNums.push_back(nums[p++]);				
			}
			else {
				sortNums.push_back(nums[q++]);				
			}
		}
		while (p <= mid) sortNums.push_back(nums[p++]);
		while (q <= r) sortNums.push_back(nums[q++]);
		for (int i = st; i <= r; i++)
			nums[i] = sortNums[i-l];
		for (auto it : nums)
			cout << it << ' ';
		cout << endl;
	}
};

//int main() {
//	Solution obj;
//	vector<int> nums{ 2,4,3,5,1 };
//	cout << obj.reversePairs(nums);
//	system("pause");
//}	
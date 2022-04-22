
#include <vector>
using namespace std;

class Solution {

public:
	int maxDistance(vector<int>& firstInput, vector<int>& secondInput) {
		int maximumDistance = 0;
		int size = min(firstInput.size(), secondInput.size());
		for (int i = 0; i < size; i++) {
			maximumDistance = max(maximumDistance, binarySearchForCurrentMaximumDistace(i, firstInput[i], secondInput));
		}
		return maximumDistance;
	}

private:
	int binarySearchForCurrentMaximumDistace(int pivotIndex, int pivotValue, const vector<int>& secondInput) {
		int left = pivotIndex;
		int right = secondInput.size() - 1;
		int currentMaximumDistace = 0;

		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (pivotIndex <= mid && pivotValue <= secondInput[mid]) {
				currentMaximumDistace = mid - pivotIndex;
			}

			if (pivotValue <= secondInput[mid]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return currentMaximumDistace;
	}
};

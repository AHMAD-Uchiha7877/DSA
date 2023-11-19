#include <iostream>
#include <vector>
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    int size = nums.size();
    vector<int> result(size);

    for (int i = 0; i < size; i++) {
        int count = 0;

        for (int j = 0; j < size; j++) {
            if (i != j && nums[j] < nums[i]) {
                count++;
            }
        }

        result[i] = count;
    }

    return result;
}

int main() {
    vector<int> num = {1, 2, 10, 16, 199};
    vector<int> result = smallerNumbersThanCurrent(num);

   

    return 0;
}

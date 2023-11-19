#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[count] = nums[i];
            count++;
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int k = removeElement(nums, val);
    cout << "k = " << k << endl;
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << "  ";
    }

    return 0;
}

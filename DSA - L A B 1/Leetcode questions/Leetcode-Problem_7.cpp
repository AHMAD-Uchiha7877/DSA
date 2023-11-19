#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int firstcountPositive(vector<int> &nums)
{
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == count)
        {

            count++;
        }
        else if (nums[i] > count)
        {

            return count;
        }
    }

    return count;
}

int main()
{
    cout << "" << endl;
    return 0;
}
#include <iostream>
using namespace std;
#include <vector>

int removeDuplicates(vector<int> &nums)
{
    

    int count = 1; 
    int n = nums.size();

    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[count] = nums[i]; 
            count++;               
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 2, 3, 4, 4, 5, 5};
    int uniqueCount = removeDuplicates(nums);

    cout << "Unique elements count: " << uniqueCount << endl;
    cout << "Unique elements: ";
    for (int i = 0; i < uniqueCount; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

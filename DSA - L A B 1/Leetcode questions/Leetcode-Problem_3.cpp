#include <iostream>
#include <vector>
using namespace std;

class searchMatrix
{
public:
    bool Search(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m * n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int row = mid / n;
            int col = mid % n;
            if (mid == target)
            {
                return true;
            }
            else if (matrix[m][n] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return false;
    }
};

int main()
{

    vector<vector<int>> matrix = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}};

    searchMatrix search;

    int target = 5;

    bool found = search.Search(matrix, target);

    if (found)
    {
        cout << "Target " << target << " found in the matrix." << endl;
    }
    else
    {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}

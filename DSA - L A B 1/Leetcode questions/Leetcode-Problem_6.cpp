#include <iostream>
using namespace std;

bool isBadVersion(int version);

int firstBadVersion(int n)
{
    int low = 1;
    int high = n;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (isBadVersion(mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    int n, bad;
    cout << "Enter the total number of versions (n): ";
    cin >> n;
    cout << "Enter the first bad version (bad): ";
    cin >> bad;

    int result = firstBadVersion(n);

    cout << "The first bad version is: " << result << endl;

    return 0;
}

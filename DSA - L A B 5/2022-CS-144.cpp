#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
//..............................Queston1..................................//
int recursiveSum(int N)
{
    if (N == 1)
        return N;
    else
        return recursiveSum(N - 1) + N;
}

int recursiveSumOdd(int N)
{
    if (N < 1)
        return N;
    else
        return recursiveSumOdd(N - 1) + (2 * N - 1);
}
int geometricSum2(int N)
{
    if (N == 0)
    {
        return 1;
    }
    else
    {
        return pow(2, N) + geometricSum2(N - 1);
    }
}
int geometricSum3(int N)
{
    if (N == 0)
    {
        return 1;
    }
    else
    {
        return pow(3, N) + geometricSum3(N - 1);
    }
}
int series_sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n + series_sum(n / 3);
    }
}
int seriesSum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n + seriesSum(n / 2);
    }
}
//..............................Queston1 End..................................//

//..............................Queston2..................................//
int decimalToBinary(int n)
{
    if (n == 0)
        return 0;
    else
    {
        decimalToBinary(n / 2);
        cout << n % 2;
    }
}

string intToString(int num)
{
    if (num == 0)
    {
        return "0";
    }
    if (num < 0)
    {
        return "-" + intToString(-num);
    }
    return intToString(num / 10) + char('0' + num % 10);
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

//.............................. Queston2 End..................................//
//.............................. Queston3   ..................................//

int SearchFirstEntry(int arr[], int index, int find, int size)
{
    if (size < index)
    {
        return -1;
    }
    if (arr[index] == find)
    {

        return index;
    }

    return SearchFirstEntry(arr, index + 1, find, size);
}

int searchLastEntry(int arr[], int index, int find, int size)
{
    if (index < 0)
    {
        return -1;
    }
    if (arr[index] == find)
    {

        return index;
    }

    return searchLastEntry(arr, index - 1, find, size);
}

int RecursiveBinarySearch(int arr[], int low, int high, int search)
{
    if (high == low)
    {
        return arr[low];
    }
    if (high > low)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == search)
        {
            return mid;
        }

        if (search < arr[mid])
        {
            return RecursiveBinarySearch(arr, low, mid - 1, search);
        }
        else
        {
            return RecursiveBinarySearch(arr, mid + 1, high, search);
        }
    }
    return -1;
}
//.............................. Queston3 End  ..................................//
//.............................. Queston 4  ..................................//

int power(int x, int y, int m)
{
    if (y == 0)
    {
        return 1;
    }

    int temp = power(x, y / 2, m);
    int result = (temp * temp) % m;

    if (y % 2 == 1) // odd
    {
        result = (result * x) % m;
    }

    return result;
}

//.............................. Queston 4 End  ..................................//
//.............................. Queston 7      ..................................//

int Fibonacci(int n) // time complexity O(n)
{
    int a = 0, b = 1;
    for (int i = 0; i < n; ++i)
    {

        int temp = a;
        a = b;
        b = temp + b;
    }
    return b;
}

int recursiveFibonacci(int n) // time complexity O(2^n)
{
    if (n <= 1)
    {
        return n;
    }
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

vector<int> store(100, -1);

int memoizationFibonacci(int n)
{
    
    if (n <=1)
    {
        return n;
    }
    if (store[n] != -1)
    {
        return store[n];
    }
    store[n] = memoizationFibonacci(n - 1) + memoizationFibonacci(n - 2);
    return store[n];
}

int bottomUpFibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

//.............................. Queston 7 End  ..................................//

int main()
{
    cout << memoizationFibonacci(6);
    return 0;
}

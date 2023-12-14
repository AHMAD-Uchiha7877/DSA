#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <queue>
#include <random>
using namespace std;
class Compare
{
public:
    bool operator()(int &a, int &b)
    {
        return a >= b;
    }
};
void createRandomFile(string fn, int size, int RN = 100)
{
    srand(time(0));
    ofstream file(fn);
    for (int i = 0; i < size * 1024 * 1024; i++)
    {
        file << rand() % RN << " ";
    }
    file.close();
}

void LoadData(string fileName, vector<int> &v)
{
    ifstream file(fileName);
    int value;

    while (file >> value)
    {
        v.push_back(value);
    }

    file.close();
}

void printVector(const vector<int> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
template <class T>
// heap sort
void HeapSort(vector<T> &V) // O(n log n)
{
    priority_queue<T, vector<T>, Compare> PQ;

    for (int i = 0; i < V.size(); i++)
    {
        PQ.push(V[i]);
    }

    V.clear();

    while (!PQ.empty())
    {
        V.push_back(PQ.top());
        PQ.pop();
    }
}
// give 20 randoms value
void Randomized_Init(vector<int> &V)
{
    for (int i = 0; i < V.size(); i++)
    {
        V[i] = rand() % 100;
    }
}
// print funtion
void VectorPrint(vector<int> &V)
{
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << " ";
    }
    cout << endl;
}

// bubble sort
template <class T>
bool SwappingAllTheWay(vector<T> &V)
{
    bool ChangeHappen = false;

    for (int i = 0; i < V.size() - 1; i++)
    {
        if (V[i] > V[i + 1])
        {
            swap(V[i], V[i + 1]);
            ChangeHappen = true;
        }
    }

    return ChangeHappen;
}

template <class T>
void BubbleSort(vector<T> &V)
{
    while (SwappingAllTheWay(V))
    {
        // Continue until the array is sorted (no more swaps)
    }
}

template <class T>
int findMinIndexInRange(vector<T> &array, int startIndex, int endIndex)
{
    int minIndex = startIndex;
    for (int i = startIndex + 1; i <= endIndex; i++)
    {
        if (array[minIndex] > array[i])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

template <class T>
void selectionSort(vector<T> &array)
{
    for (int i = 0; i < array.size() - 1; i++)
    {
        int minIndex = findMinIndexInRange(array, i, array.size() - 1);
        swap(array[i], array[minIndex]);
    }
}

// quick sort
template <typename T>
int partition(vector<T> &array, int low, int high)
{
    T pivot = array[high]; // Choosing the pivot (usually the last element)
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]); // Placing the pivot in its correct position
    return (i + 1);                  // Returning the partitioning index
}

template <typename T>
void quickSort(vector<T> &array, int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high); // Partitioning index

        // Recursive calls to sort sub-arrays
        quickSort(array, low, pi - 1);  // Before partition
        quickSort(array, pi + 1, high); // After partition
    }
}
template <typename T>
void QuickSort(vector<T> &v)
{
    quickSort(v, 0, v.size() - 1);
}

// Function to partition the array
template <typename T>
int randomizedPartition(vector<T> &arr, int low, int high)
{
    // Randomly select a pivot index within the range [low, high]
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(low, high);
    int randomIndex = dis(gen);

    swap(arr[randomIndex], arr[high]); // Swap the pivot element to the end
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform randomized quicksort
template <typename T>
void randomizedQuickSort(vector<T> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = randomizedPartition(arr, low, high);

        randomizedQuickSort(arr, low, pivot - 1);  // Sort left partition
        randomizedQuickSort(arr, pivot + 1, high); // Sort right partition
    }
}
int main()
{
    /*
    priority_queue<int, vector<int>, Compare> pq;

    // Enqueue elements
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    // Output elements based on priority
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
   */

    /*
        vector<int> data = {30, 10, 50, 20, 25, 35, 75, 95};

        cout << "Before sorting: ";
        for (int val : data)
        {
            cout << val << " ";
        }
        cout << endl;

        // Sorting using Heap Sort with priority queue
        HeapSort(data);
        // MergeSort
        // QuickSort

        cout << "After sorting: ";
        for (int val : data)
        {
            cout << val << " ";
        }
        cout << endl;
    */
    /*
   vector<int> value(20);
   Randomized_Init(value);
   cout << "Before sorting: ";
   VectorPrint(value);
   // HeapSort(value);
   // BubbleSort(value);
   // selectionSort(value);
   QuickSort(value);

   cout << "After sorting: ";
   VectorPrint(value);

  */
    vector<int> v;

    createRandomFile("randomFile.txt", 1024);
    cout << "Time Before sorting: " << time(0) << endl;
    LoadData("randomFile.txt", v); // Pass the vector to load the data into it
    // Sort the loaded data
    // cout << "\t\t Selection Sort" << endl;
    // selectionSort(v);
    // cout << "Time After sorting: \n\n"
    //      << time(0) << endl;
    // cout << "\t\t QUICK  Sort" << endl;
    // QuickSort(v);
    // cout << "Time After sorting: \n\n"
    //      << time(0) << endl;
    // cout << "\t\t BUBBLE  Sort" << endl;
    // BubbleSort(v);
    // cout << "Time After sorting: \n\n"
    //      << time(0) << endl;
    cout << "\t\t HEAP sort Sort" << endl;
    HeapSort(v);
    cout << "Time After sorting: \n\n"
         << time(0) << endl;

    return 0;
}

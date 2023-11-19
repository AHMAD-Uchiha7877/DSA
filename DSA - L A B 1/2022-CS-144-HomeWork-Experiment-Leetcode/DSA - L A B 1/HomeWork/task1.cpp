#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

template <typename T>
class AutoGrowingArray
{
private:
    int size;
    int capacity;
    T *DA;

public:
    AutoGrowingArray()
    {
        size = 0;
        capacity = 1;
        DA = new T[capacity];
    }

    ~AutoGrowingArray()
    {
        delete[] DA;
    }

    void PushBack(T Value)
    {
        if (size >= capacity)
        {
            capacity = capacity + 1; // Increase the capacity by 1
            T *newDA = new T[capacity];
            for (int i = 0; i < size; i++)
            {
                newDA[i] = DA[i];
            }
            delete[] DA;
            DA = newDA;
        }
        DA[size] = Value;
        size++;
    }

    T operator[](int index) const
    {
        if (index >= 0 && index < size)
        {
            return DA[index];
        }
        else
        {
            throw out_of_range("Invalid Input");
        }
    }

    T &operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return DA[index];
        }
        else
        {
            throw out_of_range("Invalid Input");
        }
    }

    friend ostream &operator<<(ostream &Cout, const AutoGrowingArray &DynamicArray)
    {
        Cout << "[";
        for (int i = 0; i < DynamicArray.size; i++)
        {
            Cout << DynamicArray.DA[i];
            if (i < DynamicArray.size - 1)
            {
                Cout << ", ";
            }
        }
        Cout << "]";
        return Cout;
    }

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

    void LoadData(string fileName)
    {
        ifstream file(fileName);
        int value;

        while (file >> value)
        {
            PushBack(value);
        }

        file.close();
    }
};

int main()
{
    cout << "            Question 1             " << endl;
    AutoGrowingArray<int> arr;
    arr.createRandomFile("file.txt", 2); // 2 MB file
    cout << "Before Loading " << time(0) << endl;
    arr.LoadData("file.txt");
    cout << "After Loading " << time(0) << endl;

    // arr.PushBack(1);
    // arr.PushBack(2);

    // cout << arr[0] << endl;
    // cout << arr[1] << endl;

    // cout << arr << endl;

    return 0;
}

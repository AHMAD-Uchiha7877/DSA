#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

template <typename T>
class Vector
{
private:
    int size;
    int capacity;
    T *DA;

public:
    Vector()
    {
        size = 0;
        capacity = 1;
        DA = new T[capacity];
    }

    ~Vector()
    {
        delete[] DA;
    }

    void PushBack(T Value)
    {
        if (size >= capacity)
        {
            // If the current capacity is equal to the size, double the capacity.
            capacity *= 2;
            T *newDA = new T[capacity];

            // Copy existing elements to the new array.
            for (int i = 0; i < size; i++)
            {
                newDA[i] = DA[i];
            }

            // Deallocate memory used by the old array and update the pointer to the new array.
            delete[] DA;
            DA = newDA;
        }

        // Add the new value to the end of the array and increment the size.
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
            cout << "Invalid Input";
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
            cout << "Invalid Input";
        }
    }

    friend ostream &operator<<(ostream &Cout, const Vector &v)
    {
        Cout << "[";
        for (int i = 0; i < v.size; i++)
        {
            Cout << v.DA[i];
            if (i < v.size - 1)
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
    cout << "            Question 2             " << endl;
    Vector<int> v;

    v.createRandomFile("file.txt", 20);
    cout << "Before Loading " << time(0) << endl;
    v.LoadData("file.txt");
    cout << "After Loading " << time(0) << endl;

    // v.PushBack(1);
    // v.PushBack(2);
    // v.PushBack(3);

    // cout << v[0] << endl;
    // cout << v[1] << endl;

    return 0;
}

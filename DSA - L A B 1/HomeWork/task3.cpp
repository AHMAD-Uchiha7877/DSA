#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

template <typename T>
class ArrayList
{
private:
    int size;
    int capacity;
    T *DA;

public:
    ArrayList()
    {
        size = 0;
        capacity = 2;
        DA = new T[capacity];
    }

    ~ArrayList()
    {
        delete[] DA;
    }

    void pushBack(T value)
    {
        if (size >= capacity)
        {
            int newCapacity = capacity * 1.5;
            T *newDA = new T[newCapacity];
            for (int i = 0; i < size; i++)
            {
                newDA[i] = DA[i];
            }
            delete[] DA;
            DA = newDA;
            capacity = newCapacity;
        }
        DA[size] = value;
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
            throw out_of_range("Index out of range");
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
            throw out_of_range("Index out of range");
        }
    }

    friend ostream &operator<<(ostream &Cout, const ArrayList &arrayList)
    {
        Cout << "[";
        for (int i = 0; i < arrayList.size; i++)
        {
            Cout << arrayList.DA[i];
            if (i < arrayList.size - 1)
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
            pushBack(value);
        }

        file.close();
    }
};

int main()
{
    cout << "            Question 3            " << endl;
    ArrayList<int> a;
    a.createRandomFile("file.txt", 2);
    cout << "Before Loading " << time(0) << endl;
    a.LoadData("file.txt");
    cout << "After Loading " << time(0) << endl;

    // a.pushBack(1);
    // a.pushBack(2);
    // a.pushBack(3);

    // cout << a[0] << endl;
    // cout << a[2] << endl;

    // cout << a << endl;

    return 0;
}

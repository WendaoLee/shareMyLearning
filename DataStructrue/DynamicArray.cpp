#include <iostream>
// DynamicArray,and other Cpp files in this folder are practices of MIT6.006.I try to achieve the concept mentioned in the class,just out of interesting,whether it is useful.

/*
    Because I just used A Tour of C++ as my C++ learning guidebook.So in the origin commit of this file,I coded this as index of the pointer to array:

    *p = new int[size]; //it points to p[0]
    *p +=4; //I coded like this to index p[1];

    It is dangerous,because not every compiler or runtime-eviroment will allocate truly 4bytes to a interger.
    It can be passed through compiling.But it may cause some unexpected erorrs.For instance,'delete' operator.

    The correct way is used as normal array:
      p[1]
      p[2]
*/

/*
  Dynamic Array:
    Operations:
        - get_at(int i)
        - set_at(int i,int value)

        - insert_first(int value)
        - delete_first(int value)
        - insert_last(int value)
        - delete_last(int value)

        - insert_at(int i,int value)
        - delete_at(int i,int value)
*/
class DynamicArray
{
public:
    DynamicArray(int max);
    DynamicArray(const int x[], int size);

    int get_at(int i);
    bool set_at(int i, int value);

    bool insert_first(int value);
    bool delete_first();
    bool insert_last(int value);
    bool delete_last();

    bool insert_at(int i, int value);
    bool delete_at(int i);

    void reAllocated();
    void reAllocated(int space);
    void output();

private:
    int array_size; // array_size is to point out the truly nums of defined-elements it used.
    int array_max;  // array_max is to point out the array's containing space.
    int *array;
};

DynamicArray::DynamicArray(int max)
{
    array = new int[max];
    array_max = max;
    array_size = 0;
}

DynamicArray::DynamicArray(const int x[], int size)
{
    array_size = size;
    array_max = 2 * size;

    array = new int[array_max];
    for (int i = 0; i < array_size; i++)
    {
        array[i] = x[i];
    }
};

int DynamicArray::get_at(int i)
{
    return array[i];
}

void DynamicArray::reAllocated(int space)
{
    if (array_max > space)
    {
        return;
    }
    else
    {
        int *temp = new int[space];

        array_max = space;

        for (int i = 0; i < array_size; i++)
        {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
        return;
    }
}

bool DynamicArray::set_at(int i, int value)
{
    if (i >= array_max)
    {
        reAllocated(i + 1);

        array[i] = value;
        array_size = i + 1;
        return true;
    }
    else if (i > array_size)
    {
        array[i] = value;
        array_size = i + 1;
        return true;
    }
    else
    {
        array[i] = value;
        return true;
    }
    return false;
};

bool DynamicArray::insert_first(int value)
{
    int *temp = new int[array_max];
    for (int i = 0; i < array_size; i++)
    {
        temp[i + 1] = array[i];
    }

    temp[0] = value;

    delete[] array;
    array = temp;
    array_size++;
};

bool DynamicArray::delete_first()
{
    for (int i = 0; i < array_size; i++)
    {
        array[i] = array[i + 1];
    }

    array_size--;
}

bool DynamicArray::insert_last(int value)
{
    if (array_size >= array_max)
    {
        reAllocated(2 * array_max);
        set_at(array_size - 1, value);
        array_size++;
    }
    else
    {
        array[array_size - 1] = value;
    }
}

bool DynamicArray::delete_last()
{
    array[array_size - 1] = NULL;
    array_size--;
}

bool DynamicArray::insert_at(int i, int value)
{
    if (i > array_max)
    {
        set_at(i, value);
        return true;
    }
    else if ((array_size + 1) >= array_max)
    {
        reAllocated(2 * array_max);
        for (int i = array_size; i > i; i--)
        {
            array[i] = array[i - 1];
        }
        array[i] = value;
        array_size++;
    }
    else
    {
        for (int i = array_size; i > i; i--)
        {
            array[i] = array[i - 1];
        }
        array[i] = value;
        array_size++;
    }
}

bool DynamicArray::delete_at(int i)
{
    for (int i = i; i < array_size; i++)
    {
        array[i] = array[i + 1];
    }
    array_size--;
}

void DynamicArray::output()
{
    {
        int *p = array;
        for (int i = 0; i <= array_size - 1; i++)
        {
            std::cout << p[i] << std::endl;
        }
    }
}

int main()
{
    int x[] = {1, 2, 3, 4, 5, 6};
    DynamicArray v(x, 6);
    std::cout << "Delete first:" << std::endl;
    v.delete_first();
    v.output();
    std::cout << "Insert first 10:" << std::endl;
    v.insert_first(10);
    v.output();
    std::cout << "Get index 4:" << v.get_at(4) << std::endl;
    std::cout << "Insert 100 at index 20:" << std::endl;
    v.insert_at(20, 100);
    v.output();
    std::cout << "set 1 at index 0:" << std::endl;
    v.set_at(0,1);
    v.output();
}
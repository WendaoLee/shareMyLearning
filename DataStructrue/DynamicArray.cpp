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
    bool delete_at(int i, int value);

    void output();

private:
    int array_size; // array_size is to point out the what is the (be used)end---With minus 1.
    int array_max;  // array_max is to point out the array's truly end(no matter if valued)
    int *array;
};

DynamicArray::DynamicArray(int max)
{
    array = new int[max];
    array_max = max;
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

bool DynamicArray::set_at(int i, int value)
{

    if (i >= array_max)
    {
        array_max = array_max * 2;
        int *temp = new int[array_max]; // temp contains new array

        // Copy old values to new array.
        for (int i = 0; i < array_size; i++)
        {
            temp[i] = array[i];
        }

        delete[] array; // delete old array

        array = temp; // point to new array

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
};

bool DynamicArray::delete_first()
{
    int *temp = new int[array_max];
    for (int i = 0; i < array_size; i++)
    {
        temp[i] = array[i + 1];
    }

    delete[] array;
    array = temp;
}

bool DynamicArray::insert_last(int value)
{
    if (array_size >= array_max)
    {
        set_at(array_size - 1,value);
    }
    else{
        array[array_size - 1] = value;
    }
    
}

bool DynamicArray::delete_last()
{
    array[array_size - 1] = NULL;
}

bool DynamicArray::insert_at(int i,int value)
{
    
}

void DynamicArray::output()
{
    {
        int *p = array;
        for (int i = 0; i <= array_size; i++)
        {
            std::cout << p[i] << std::endl;
        }
    }
}

int main()
{
    int x[] = {1, 2, 3, 4, 5, 6};
    DynamicArray v(x, 6);
    v.set_at(30, 999);
    v.output();
}
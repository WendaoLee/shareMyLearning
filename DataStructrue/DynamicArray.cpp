#include <iostream>

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
    int array_size;
    int array_max;
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
    int *p = array;
    for (int i = 0; i < array_size; i++)
    {
        *p = x[i];
        p += 4; // Interger occurs 4 bytes.
    }
};

int DynamicArray::get_at(int i)
{
    int *p = array;
    if (i == 0)
    {
        return *p;
    }
    else
    {
        p += 4 * i;
        return *p;
    }
}

bool DynamicArray::set_at(int i, int value)
{
    /*
    p points to the ARRAY.
    */
    int *p = array;

    if (i >= array_max)
    {
        array_max = array_max * 2;
        array = new int[array_max];

        // define temp pointer to operate new array
        int *temp = array;

        // Copy old value to new array.
        for (int i = 0; i < array_size; i++)
        {
            *temp = *p;
            p += 4;
            temp += 4;
        }

        p-= 4*array_size;

        delete[] p; // delete old array

        int *p = array;
        p += i * 4; // Make p points to target place.

        *p = value;
        array_size = i + 1;

        return true;
    }
    else if (i > array_size)
    {
        p += i * 4;
        *p = value;
        array_size = i + 1;
        return true;
    }
    else
    {
        p += i * 4;
        *p = value;
        return true;
    }
    return false;
};

bool DynamicArray::insert_first(int value)
{
    //p operates old array
    int *p = array;
    

    array = new int[array_size + 1];
    array_size+=1;

    //temp operates new array
    int *temp = array;
    *temp = value; //set the first
    temp+=4;

    /*
      Copy old values.
      The loops were controled by new array_size,so it minus 1,or it will point a unknow address.
    */
    for (int i = 0; i < array_size - 1; i++)
    {
        *temp = *p;
        p += 4;
        temp += 4;
    }

    delete[] p;

    return true;
};

void DynamicArray::output()
{
    {
        int *p = array;
        for (int i = 0; i < array_size; i++)
        {
            std::cout << *p << std::endl;
            p += 4;
        }
    }
}

int main()
{
    int x[] = {1, 2, 3, 4, 5, 6};
    DynamicArray v(x, 6);
    v.set_at(30,999);
}
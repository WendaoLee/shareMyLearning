#include <iostream>

/*
  This file contains:
    - Insertion Sorting
    - Selection Sorting
    - Merge Sort
*/

void Insertion_Sorting(int array[],int len)
{
    int selector; //point to the selected element

    selector = 0;
    for (int i = 1; i < len; i++)
    {
        selector = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > selector )
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j+1] = selector;
    }

}

void output(const int array[],int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << array[i] << ",";
    }
    std::cout << std::endl;
}

int main()
{
    int x[6] = {8,5,6,2,4,8};
    int len = sizeof(x)/sizeof(x[0]);
    output(x,len);
    Insertion_Sorting(x,len);
    output(x,len);
}
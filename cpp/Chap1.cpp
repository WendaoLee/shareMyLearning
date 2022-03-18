#include <iostream>
#include <vector>



void show_pointer() // function of show what is pointer and basic use of it
{
    int v[5] = {0, 1, 2, 3, 4};
    int *p = &v[3]; // With '&',the pointer get the address of v[3];the p store v[3]'s address,and the *p means operating the p's stored address's value(or bit?);

    std::cout << v[3] << std::endl;
    std::cout << p << std::endl; // p's value is v[3]'s address

    *p = 233; //*p can be thought as v[3]

    std::cout << v[3];
}

void show_reference()
{
    int v[] = {0, 1, 2, 3, 4, 5};
    int i = 0;

    /*The '&' means reference to;
    In this statement,the cpp creates two pointers,the one points to v[0]'s address named _for_begin,the one points to v's final address named _for_end;
    And the x exactly gets _for_begin,which means change x is equals to change v[.]'s value.
    Besides,one array's address is continuous.For instance,0x24309ffba0-0x24309ffbb8.

    (?)'Reference to' == '*p = xxxxxxxx'
    */
    for (auto &x : v)
    {
        // x+=10;
        std::cout << v[i] << std::endl;
        i++;
    }
}

/*The reference in the function's arguments will point to origin data,which means you won't take copy's costs.
By default,the array as arguments will all be reference.
Below the first is the book's example
*/
void show_referenceOfFunctionArguments(std::vector<double>& v)
{
    std::cout << v[0] << std::endl;
    v[0] = 0;
}

void show_referenceOfFunctionArguments(int x[],int size)
{
    std::cout << x[0] << std::endl;
    x[0] = 100;
    
}

//Here you would see how to use array just for reading but not take costs.
void show_referenceOfFunctionArguments(const int x[])
{
    std::cout << x[0] << std::endl;
    // x[0] = 300; //
}

void test_show_referenceOfFunc()
{
    std::vector<double> test_referOfFuncArg ={1.1,2.2,3.3};
    show_referenceOfFunctionArguments(test_referOfFuncArg);

    std::cout << test_referOfFuncArg[0] <<std::endl;

    int a[2] = {0,1};
    show_referenceOfFunctionArguments(a,2);
    std::cout << a[0] << std::endl;
}

int main()
{
    int a[3] = {1,2,3};
    
}
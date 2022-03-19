#include <iostream>

/*
As Google's C++ Style Guide,only when here are data members using struct,else using class

The 'class' and 'struct' almost have the same meaning in C++.
*/

// struct Vector
// {
//     int sz;
//     double* elm;
// };

// void vector_init(Vector& v,int s)
// {
//     v.elm = new double[s]; //new allocates memory from heap/free store/dynamic memory.It lives until 'delete' or the v's create scope ends.
//     v.sz = s;
// }

// double read_and_sum(int s)
// {
//     Vector v;
//     vector_init(v,s);

//     for (int i = 0; i != s; i++)
//     {
//         std::cin >> v.elm[i];
//     }

//     double sum = 0;

//     for (int i = 0; i != s; i++)
//     {
//         sum+=v.elm[i];
//     }

//     return sum;
// }

class Vector{
    public:
    /*
    In the book
        Vector(int s):elem{new double[s]},sz{s}{}
    is just syntactic sugar.
    It's the same as below:
    */
        Vector(int s){elem = new double[s];sz = s;}

        double& operator[](int i){return elem[i];}
        int size(){return sz;}

    /*
    Here I can't understand why we write
        double& operator[](int i){return elem[i];}
    so I write this.
    But now I still don't understand.I guess it is a code convention in C++.
    */
        double& test(int i){return elem[i];}

    private:
        double* elem;
        int sz;
};

void test_class()
{
    Vector v(6);
    double& ref_test = v.operator[](3);
    ref_test = 9.0;
    std::cout << "test of operator:" << v.operator[](3) << std::endl;
    std::cout << "test of operator:" << v.test(3);
}

/*
The UNIONS,the book suggests using standard library type,variant.

The unions like a class,but it designed for A VALUE who less use,that is,you had better use one member at a time because its menmbers shared the same space.If one be valued,the other's valuation would change in the former's taken space,which would made unexpected mistakes.

The unions will be allocated a fixed space depends on its defined member.
For example,one union:
    union test{
        int a;
        double b;
    }
It would be allocated 12 bytes.

But it's not simply adds the declared member.It is flexible.
For example,one union:
    union test{
        int a;
        double b;
        char c;
    }
It would be allocated 12 bytes too;

The regulation of it I can't simply deduce with above tests.I just take a mention here.

As for struct,the thing should be noticed is 'Memory Alignment'.

In the instance below(test_costsOf_union),I run it on Visual Studio to watch the memory storge.
The int's size is 4 bytes and the double's is 8 bytes.As usual,the 'p' should take 4+4+8=16 bytes.
But actually it takes 8+4+8=20 bytes because of the MEMORY ALIGNMENT.


In the VS,it looks like below:

(As for a better reading,I give some variants a value.)

0x00D9FA18  0a  .
0x00D9FA19  00  .
0x00D9FA1A  00  .
0x00D9FA1B  00  .
//Above is variant 'g',value 10,int

0x00D9FA1C  cc  ?
0x00D9FA1D  cc  ?
0x00D9FA1E  cc  ?
0x00D9FA1F  cc  ?

//Above is the space which created because of the Memory Alignment 

0x00D9FA20  02  .
0x00D9FA21  00  .
0x00D9FA22  00  .
0x00D9FA23  00  .
//Above is variant 'i',value 2,int,defined in union 'Value'

0x00D9FA24  cc  ?
0x00D9FA25  cc  ?
0x00D9FA26  cc  ?
0x00D9FA27  cc  ?
0x00D9FA28  cc  ?
0x00D9FA29  cc  ?
0x00D9FA2A  cc  ?
0x00D9FA2B  cc  ?
//Above is variant 'a',undefined

*/

union  Value{
    int i;
    double a;
};

struct test_union
{
    int g;
    Value v_test;
};

void test_costsOf_union()
{
    test_union p;

    int* point_to_g = &p.g;
    Value* point_to_v_test = & p.v_test;
    
    
    // int*p point_to_i = &p.v_test.i; //error

}

/*
 Now,I can't understand why we define enum.Maybe it used in the program's struction-designed.
*/
enum class Color{
    red,blue,green
};

int main()
{
    Color col = Color::red;
    Color* p = &col;

}
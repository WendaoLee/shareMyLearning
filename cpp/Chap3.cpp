/*
The 3.2 narrates about the Separate Compilation.
Its content you should take care of is in some IDE,likes the Visual Studio Code I used,its default debug setting will only compile the opened file.

That means,for instance,this file named Chap3.cpp,when it debugging in the VSCode,it excecute likes this:
    $ g++ -c Chap3.cpp
    $ g++ Chap3.o -o prog
But it should be:
    $ g++ -c Chap3.cpp
    $ g++ -c Vector.cpp
    & g++ Chap3.o Vector.o -o prog

Without the link of Vector.o,it will cause undefined reference error.This is what the book not mentioned.


You can visit the https://hackingcpp.com/cpp/lang/separate_compilation.html to get details.
I also saved its content in the folder 'Chap3' as 'C++ Separate Compilation Introduction _ hacking C++.pdf'.

[Short Notes]I guess I should learn more about g++ and the config of VSCode.
[Short Notes]Learing here,I start learning makefile.Maybe CMake is also a interesting thing?
[Short Notes]I think I should write a doc to summarize what I have learned.CPP,so complicated but fascinating.
*/

#include <iostream>
#include <cmath>

/*
    According to Google's style guide book,the header files would avoid using UNIX's convenient folder (such as './' '../')
    So we define the header file 'Vector.h' mentioned in the book as 'Chap3/Vector.h'
*/

#include "Chap3/Vector.h"
// import "Chap3/Vector.cpp/Vector"

double sqrt_sum(Vector& v)
{
    double sum = 0;
    for (int i = 0; i != v.size(); i++)
    {
        sum += std::sqrt(v[i]);
    }
    return sum;
}

int main()
{
   
}
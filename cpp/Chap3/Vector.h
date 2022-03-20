#ifndef CPP_CHAP3_VECTOR_H
#define CPP_CHAP3_VECTOR_H

class Vector{
    public:
        Vector(int s);
        double&operator[](int i);
        int size();
    private:
        double* elem;
        int sz;
        const int t; //You must notice that the constant only can be valued at the declation time.It cannot be valued liked a variant.The Chap3.cpp will give a glance.
}; //Here,don't forget to end with ';'

#endif
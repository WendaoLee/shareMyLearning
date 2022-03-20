// #include "Vector.h"

module;

export module Vector;

export class Vector{
    public:
        Vector(int s);
        double& operator[](int i);
        int size();
    private:
        double* elem;
        int sz;
};

Vector::Vector(int s) //The 'Vector::' using the class Vector defined in the Vector.h.There,we can see we have defined the constructor Vector(int s)
    :elem{new double[s]},sz{s},t{2} //The operator ':' used here is to value the member in the CLASS VECTOR
{
}

double& Vector::operator[](int i)
{
    return elem[i];
}

int Vector::size()
{
    return sz;
}

export int size(const Vector& v){
    return v.size();
}
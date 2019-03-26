#ifndef POO_TEMA_1_H_INCLUDED
#define POO_TEMA_1_H_INCLUDED

using namespace std;

class VectorIntregi
{
    int nr;
    int *v;

public:
    int suma();
    int maxim();
    int poz_maxim();
    void sortare();

    void set_Nr(int i);
    void set_Dim_Vector(int nr);
    int get_Nr();
    int * get_Vect();
    int operator* (VectorIntregi w);
    int & operator [] (int i);
    friend std::ostream & operator << (std::ostream &out, const VectorIntregi &vect);
    friend std::istream & operator >> (std::istream &in, VectorIntregi &vect);
    friend class MatriceIntregi;

    VectorIntregi(int nr)
    {
        v = new int[nr];
    }

    ~VectorIntregi() {}
};

class MatriceIntregi
{
    int nr_linii, nr_coloane;
    VectorIntregi *a;

public:
    MatriceIntregi operator+ (MatriceIntregi);
    void set_Dimensiuni(int i, int j);
    VectorIntregi * get_A();
    int get_Nr_linii();
    VectorIntregi & operator [] (int i);

    friend std::ostream & operator << (std::ostream &out, const VectorIntregi &vect);
    friend std::istream & operator >> (std::istream &in, VectorIntregi &vect);
    friend std::ostream & operator << (std::ostream &out, const MatriceIntregi &matrice);
    friend std::istream & operator >> (std::istream &in,  MatriceIntregi &matrice);

    MatriceIntregi(int nr_linii)
    {
        a = new VectorIntregi(nr_linii);
    }

    ~MatriceIntregi() {}
};

#endif // POO_TEMA_1_H_INCLUDED

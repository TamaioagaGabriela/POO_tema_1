#include <iostream>
#include <string>
#include <fstream>
#include "POO_tema_1.h"

using namespace std;

void VectorIntregi::set_Nr(int i)                      // setare nr elemente vector
{
    nr = i;
}

void VectorIntregi::set_Dim_Vector(int nr)             // alocare dinamica vector de tip int
{
    v = new int[nr];
}

int VectorIntregi::get_Nr()                            // obtin nr de elemente
{
    return nr;
}

int * VectorIntregi:: get_Vect()                       // obtin vectorul cu elemente de tip int
{
    return v;
}

int VectorIntregi:: suma()
{
    int suma = 0;
    for(int i = 0; i < nr; i++)
        suma = suma + v[i];
    return suma;
}

int VectorIntregi:: maxim()
{
    int max_vector = v[0];
    int i = 1;
    while(i < nr)
    {
        if (max_vector < v[i])
            max_vector = v[i];
        i++;
    }
    return max_vector;
}

int VectorIntregi:: poz_maxim()
{
    int poz_max_vector = 0;
    int max_vector = v[0];
    int i = 1;
    while(i < nr)
    {
        if (max_vector < v[i])
        {
            max_vector = v[i];
            poz_max_vector = i;
        }
        i++;
    }
    return poz_max_vector;
}

void VectorIntregi::sortare()
{
    int i,j;
    for(i = 0; i < nr-1; i++)
        for(j = 0; j < nr-i-1; j++)
        {
            if (v[j] > v[j+1])
                swap(v[j], v[j+1]);
        }
}

int VectorIntregi:: operator*(VectorIntregi w)                                // produsul scalar dintre 2 vectori
{
    int i, prod_sc = 0;
    for(i = 0; i < nr; i++)
        prod_sc = v[i] * w.v[i] + prod_sc;
    return prod_sc;
}

std::istream & operator >> (std::istream &in,  VectorIntregi &vect)           // supraincarcarea op. de citire pt VECTORI
{
    for(int j = 0; j < vect.nr; j++)
    {
        in >> vect.v[j];
    }
    return in;
}

std::ostream & operator << (std::ostream &out, const VectorIntregi &vect)      // supraincarcarea op. de afisare pt VECTORI
{
    for(int j = 0; j < vect.nr; j++)
        out << vect.v[j] << " ";
    out << endl;
    return out;
}

VectorIntregi * MatriceIntregi:: get_A()                                       // obtin vectorul a de tip vectorintreg => matricea
{
    return a;
}

int MatriceIntregi:: get_Nr_linii()                                            // obtin nr de linii ale matricei
{
    return nr_linii;
}

void MatriceIntregi::set_Dimensiuni(int i, int j)                              // setez dimensiunile pt matrice
{
    nr_linii = i;
    nr_coloane = j;
}

int &VectorIntregi::operator [] (int i)
{
    return v[i];
}

VectorIntregi &MatriceIntregi:: operator[](int i)
{
    return a[i];
}

std::istream & operator >> (std::istream &in,  MatriceIntregi &matrice)        // supraincarcarea op. de citire pt MATRICE
{

    for(int j = 0; j < matrice.nr_linii; j++)
    {
        matrice.a[j].set_Nr(matrice.nr_coloane);
        matrice.a[j].set_Dim_Vector(matrice.nr_coloane);                       // pentru fiecare vector de pe linie aloc memorie pt elementele lui (total elem = nr_col)
        in >> matrice.a[j];
    }
    return in;
}

std::ostream & operator << (std::ostream &out, const MatriceIntregi &matrice)  //supraincarcarea op. de afisare pt MATRICE
{
    for(int j = 0; j < matrice.nr_linii; j++)
    {
        out << matrice.a[j];
    }
    return out;
}

MatriceIntregi MatriceIntregi:: operator+ (MatriceIntregi B)                    // suma a doua matrice
{
    MatriceIntregi rezultat(this->nr_linii);
    rezultat.set_Dimensiuni(this -> nr_linii, this -> nr_coloane);
    for(int j = 0; j < this->nr_linii; j++)
    {
        rezultat.a[j].set_Nr(this -> nr_coloane);                               // pt fiecare vector linie aloc memorie si setez nr de elemente
        rezultat.a[j].set_Dim_Vector(this -> nr_coloane);

        for (int k = 0; k < this->nr_coloane; k++)
        {
            rezultat.a[j].v[k] = B.a[j].v[k] + this->a[j].v[k];
        }
    }
    return rezultat;
}

int verificare(MatriceIntregi A, VectorIntregi x, VectorIntregi y)               // calculez produsul dintre o matrice si vector cu ajutorul prod. scalar
{
    int ok = 1;
    int nr_linii = A.get_Nr_linii();
    for(int j = 0; j < nr_linii; j++)
    {
        if (x * A.get_A()[j] != y.get_Vect()[j])
            ok=0;
    }
    return ok;
}

int main()
{
    int i, cerinta;
    cout << "Alegeti modul de citire a vectorilor si a matricilor(1-consola, 2-fisier): ";
    cin >> i;
    if (i == 1)
    {
        cout << "Alegeti numarul cerintei (1-operatii vector, 2-operatii matrice, 3-functia verificare, 4-toate cerintele): ";
        cin >> cerinta;
        if (cerinta == 1)
        {
            //SUBPUNCT 1
            int nr, poz_elem;
            cout << "Dati numarul de elemente ale vectorului: ";
            cin >> nr;
            VectorIntregi v1(nr);                                   // apelez constructorul prin care aloc memorie
            VectorIntregi v2(nr);
            v1.set_Nr(nr);
            v2.set_Nr(nr);
            cout << "Scrieti elementele vectorului nr. 1: ";
            cin >> v1;
            cout << "Dati pozitia elementului(incepand cu zero): ";
            cin >> poz_elem;
            cout << "Elementul de pe pozitia " << poz_elem << " este: ";
            cout << v1[poz_elem] << endl;
            cout << "Suma: " << v1.suma() << endl;
            cout << "Maxim: " << v1.maxim() << endl;
            cout << "Pozitie maxim: " << v1.poz_maxim() << endl;
            cout << "Scrieti elementele vectorului nr. 2: ";
            cin >> v2;
            cout << "Produs scalar dintre cei doi vectori este: " << v1 * v2 << endl;
            v1.sortare();
            cout << "Vectorul nr. 1 este sortat: " << v1 << endl;
            delete &v1;                                               // eliberez memoria
            delete &v2;
        }

        else if (cerinta == 2)
        {
            //SUBPUNCT 2
            int nr_linii, nr_coloane, poz_elem;
            cout << "Dati numarul de linii si de coloane ale matricii: ";
            cin >> nr_linii >> nr_coloane;
            MatriceIntregi m1(nr_linii);
            MatriceIntregi m2(nr_linii);                                    // apelez constructorul prin care aloc memorie
            MatriceIntregi m3(nr_linii);
            m1.set_Dimensiuni(nr_linii,nr_coloane);
            m2.set_Dimensiuni(nr_linii,nr_coloane);
            m3.set_Dimensiuni(nr_linii,nr_coloane);
            cout << "Scrieti matricea nr. 1:" << endl;
            cin >> m1;
            cout << "Dati pozitia liniei(incepand cu 0): ";
            cin >> poz_elem;
            cout << "Linia de pe pozitia " << poz_elem << " este: ";
            cout << m1[poz_elem] << endl;
            cout << "Scrieti matricea nr. 2:" << endl;
            cin >> m2;
            cout << "Suma celor doua matrici este: " << endl;
            cout << m1+m2;
            delete &m1;                                                     // eliberez memoria
            delete &m2;
            delete &m3;
        }

        else if(cerinta == 3)
        {
            //  SUBPUNCT 3
            int nr_linii_a, nr_coloane_a, ok;
            cout << "Dati numarul de linii si de coloane ale matricii A: ";
            cin >> nr_linii_a >> nr_coloane_a;
            MatriceIntregi a(nr_linii_a);
            VectorIntregi x(nr_coloane_a);                                          // apelez constructorii
            VectorIntregi y(nr_linii_a);
            a.set_Dimensiuni(nr_linii_a,nr_coloane_a);
            cout << "Scrieti matricea A:" << endl;
            cin >> a;
            x.set_Nr(nr_coloane_a);
            y.set_Nr(nr_linii_a);
            cout << "Scrieti elementele vectorului X (" << nr_coloane_a << " elemente):";
            cin >> x;
            cout << "Scrieti elementele vectorului Y (" << nr_linii_a << " elemente):";
            cin >> y;
            ok = verificare( a, x, y);
            if (ok == 0)
                cout << "Nu, nu se verifica ecuatia Ax=y!" << endl;
            else cout << "Da,se verifica ecuatia Ax=y!" << endl;
            delete &x;
            delete &y;                                                              // eliberez memoria
            delete &a;
        }
        else if (cerinta == 4)
        {
            //SUBPUNCT 1
            int nr;
            cout << "Dati numarul de elemente ale vectorului: ";
            cin >> nr;
            VectorIntregi v1(nr);
            VectorIntregi v2(nr);
            v1.set_Nr(nr);
            v2.set_Nr(nr);
            cout << "Scrieti elementele vectorului nr. 1: ";
            cin >> v1;
            cout << "Suma: " << v1.suma() << endl;
            cout << "Maxim: " << v1.maxim() << endl;
            cout << "Pozitie maxim: " << v1.poz_maxim() << endl;
            cout << "Scrieti elementele vectorului nr. 2: ";
            cin >> v2;
            cout << "Produs scalar dintre cei doi vectori este: " << v1 * v2 << endl;
            v1.sortare();
            cout << "Vectorul nr. 1 este sortat: " << v1 << endl;
            delete &v1;
            delete &v2;

            //SUBPUNCT 2
            int nr_linii, nr_coloane;
            cout << "Dati numarul de linii si de coloane ale matricii: ";
            cin >> nr_linii >> nr_coloane;
            MatriceIntregi m1(nr_linii);
            MatriceIntregi m2(nr_linii);
            MatriceIntregi m3(nr_linii);
            m1.set_Dimensiuni(nr_linii,nr_coloane);
            m2.set_Dimensiuni(nr_linii,nr_coloane);
            m3.set_Dimensiuni(nr_linii,nr_coloane);
            cout << "Scrieti matricea nr. 1:" << endl;
            cin >> m1;
            cout << "Scrieti matricea nr. 2:" << endl;
            cin >> m2;
            m3 = m2 + m1;
            cout << "Suma celor doua matrici este: " << endl;
            cout << m3 << endl;
            delete &m1;
            delete &m2;
            delete &m3;

            //  SUBPUNCT 3
            int nr_linii_a, nr_coloane_a, ok;
            cout << "Dati numarul de linii si de coloane ale matricii A: ";
            cin >> nr_linii_a >> nr_coloane_a;
            MatriceIntregi a(nr_linii_a);
            VectorIntregi x(nr_coloane_a);
            VectorIntregi y(nr_linii_a);
            a.set_Dimensiuni(nr_linii_a,nr_coloane_a);
            cout << "Scrieti matricea A:" << endl;
            cin >> a;
            x.set_Nr(nr_coloane_a);
            y.set_Nr(nr_linii_a);
            cout << "Scrieti elementele vectorului X (" << nr_coloane_a << " elemente):";
            cin >> x;
            cout << "Scrieti elementele vectorului Y (" << nr_linii_a << " elemente):";
            cin >> y;
            ok = verificare( a, x, y);
            if (ok == 0)
                cout << "Nu, nu se verifica ecuatia Ax=y!" << endl;
            else cout << "Da,se verifica ecuatia Ax=y!" << endl;
            delete &x;
            delete &y;
            delete &a;
        }
    }

    else if (i == 2)
    {
        std::ifstream f("tema_1.in");       // fisierul din care citesc
        std::ofstream g("tema_1.out");      // fisierul in care afisez
        //SUBPUNCT A
        int nr_elem;
        f >> nr_elem;
        VectorIntregi v1(nr_elem);
        v1.set_Nr(nr_elem);
        VectorIntregi v2(nr_elem);
        v2.set_Nr(nr_elem);
        f >> v1;
        g << "Vectorul nr. 1 este: ";
        g << v1;
        g << "Suma: " << v1.suma() << endl;
        g << "Maxim: " << v1.maxim() << endl;
        g << "Pozitie maxim: " << v1.poz_maxim() << endl;
        f >> v2;
        g << "Vectorul nr. 2 este: ";
        g << v2;
        g << "Produs scalar: " << v1*v2 << endl;
        v1.sortare();
        g << "Vectorul este sortat: " << v1;
        g << endl;

        //SUBPUNCT 2
        int nr_linii, nr_coloane;
        f >> nr_linii >> nr_coloane;
        MatriceIntregi m1(nr_linii);
        m1.set_Dimensiuni(nr_linii, nr_coloane);
        MatriceIntregi m2(nr_linii);
        m2.set_Dimensiuni(nr_linii, nr_coloane);
        MatriceIntregi m3(nr_linii);
        m3.set_Dimensiuni(nr_linii, nr_coloane);
        f >> m1;
        f >> m2;
        g << "Matricea nr. 1 este: " << endl << m1;
        g << "Matricea nr. 2 este: " << endl << m2;
        g << "Suma matricilor este: " << endl;
        g << m2 + m1 << endl;

        //SUBPUNCT 3
        int nr_linii_a, nr_coloane_a, ok;
        f >> nr_linii_a >> nr_coloane_a;
        MatriceIntregi a(nr_linii_a);
        a.set_Dimensiuni(nr_linii_a, nr_coloane_a);
        f >> a;
        g << "Matricea A este:" << endl <<a;
        VectorIntregi x(nr_coloane_a);
        x.set_Nr(nr_coloane_a);
        VectorIntregi y(nr_linii_a);
        y.set_Nr(nr_linii_a);
        f >> x;
        g << "Vectorul x este:" << endl << x;
        f >> y;
        g << "Vectorul y este:" << endl << y;
        ok = verificare( a, x, y);
        if (ok == 0)
            g << "Nu, nu se verifica ecuatia Ax=y!";
        else g << "Da,se verifica ecuatia Ax=y!";
        g.close();          // inchid fisierele
        f.close();
        delete &v1;
        delete &v2;
        delete &m1;
        delete &m2;         // eliberez memoria
        delete &m3;
        delete &x;
        delete &y;
        delete &a;
    }
    return 0;
}

#include <iostream>
#include <iomanip>
#include <type_traits>
#include <typeinfo>
#include <typeindex>

class A { };

class A1 {  char c;  };

class A2 {  char c1; char c2; };

class B {  char c;    int i; };

class C {  char c;    int i;    double d; };

class D {  int i;     char c;    double d; };

class E {  char c[6];  int i;    double d;  };

class F {  char c[6];  int i;  };

using namespace std;


template<class T> class AlignmentSizeInfo;


template <class T>
ostream& operator<<(ostream& out, const AlignmentSizeInfo<T>& alignsize)
{
    out << right
    << setw(3) << alignment_of<T>::value << " "
    << setw(3) << sizeof(T) <<  "  "
    << left << setw(13) << type_index(typeid(T)).name() 
    << endl;
    
    return out;
}


template <class T>
class AlignmentSizeInfo 
{
    public:
        AlignmentSizeInfo() {
            cout << *this;
        }
};


int main(int argc, char *argv[]) 
{
    AlignmentSizeInfo<char> asChar;
    AlignmentSizeInfo<int> asInt;
    AlignmentSizeInfo<double> asDouble;
    AlignmentSizeInfo<A> asA;
    AlignmentSizeInfo<A1> asA1;
    AlignmentSizeInfo<A2> asA2;
    AlignmentSizeInfo<B> asB;
    AlignmentSizeInfo<C> asC;
    AlignmentSizeInfo<D> asD;
    AlignmentSizeInfo<E> asE;
    AlignmentSizeInfo<F> asF;
}



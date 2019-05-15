#include "iostream"

namespace itertools
{

template <class myType>
class range
{
private:
    myType a;
    myType b;

    class iterator
    {
    public:
        myType it;


        iterator(myType t) : it(t) {} //ctor



        bool operator!=(iterator const &x) const
        {
            return it != (x.it);
        }
        iterator &operator++()
        {
           ++it;
           return *this;
        }
        myType operator*() const
        {
            return it;
        }
    };

public:
    range(myType start, myType stop): a(start), b(stop){}


    
    iterator begin() const
    {
        return iterator(a);
    }
    iterator end() const
    {
        return iterator(b);
    }
};
} // namespace itertools



#include "iostream"
#include <cmath>
#include <set>
namespace itertools
{
template <class typePow>
class powerset
{
private:
    typePow pow;

public:
    powerset(typePow a) : pow(a) {} //ctor

    auto begin()
    {
        return iterator<decltype(pow.begin())>(pow.begin(), pow.end());
    }

    auto end()
    {
        return iterator<decltype(pow.begin())>(pow.end(), pow.end());
    }

    template <class typeIter>
    class iterator
    {
    private:
        typeIter iterStart;
        typeIter iterEnd;
        unsigned i;
        unsigned numElements;

    public:
        iterator(typeIter a, typeIter b) : iterStart(a), iterEnd(b), i(0), numElements(0)
        {

            typeIter temp = iterStart;
            while (temp != iterEnd)
            {
                ++numElements;
                ++temp;
            }
            numElements = std::pow(2, numElements);
        }

        iterator<typeIter> &operator++()
        {
            ++i;
            return *this;
        }

        set<decltype(*iterStart)> operator*() const
        {
            typeIter temp = iterStart;
            std::set<decltype(*iterStart)> x;
            unsigned int j = i;
            while (i != 0 && temp != iterEnd)
            {
                unsigned int l = j % 2;
                j = j >> 1;

                if (l == 1)
                    x.insert(*temp);
                ++temp;
            }
            return x;
        }

        bool operator!=(iterator<typeIter> const &x) const
        {
            return ((numElements - i) != (x.numElements - x.i - 1));
        }
    };
};

template <typename s>
std::ostream &operator<<(std::ostream &out, const std::set<s> &x)
{
    out << "{";

    auto iter = x.begin();
    if (iter != x.end())
    { // first element is without comma seperator.
        out << *iter;
        ++iter;
    }

    while (iter != x.end())
    {
        out << ',' << *iter;
        ++iter;
    }

    out << "}";

    return out;
}

} // namespace itertools
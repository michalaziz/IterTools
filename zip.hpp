#include "iostream"
namespace itertools
{
template <typename typeZip1, typename typeZip2>
class zip
{
private:
    typeZip1 z1;
    typeZip2 z2;

public:
    zip(typeZip1 a, typeZip2 b):z1(a),z2(b){}

    template <typename typeT1, typename typeT2>
    class iterator
    {
    private:
        typeT1 iter1;
        typeT2 iter2;

    public:
        iterator(typeT1 it1, typeT2 it2) : iter1(it1), iter2(it2) {} //ctor

        //operators
        iterator<typeT1, typeT2> &operator++()
        {
            ++iter1;
            ++iter2;
            return *this;
        }

        std::pair<decltype(*iter1), decltype(*iter2)> operator*() const
        {

            return std::pair<decltype(*iter1), decltype(*iter2)>(*iter1, *iter2);
        }

        bool operator!=(iterator < typeT1, typeT2> x)
        {
            return (iter1 != x.iter1) && (iter2 != x.iter2);
        }
    };

    auto begin()
    {
        return iterator<decltype(z1.begin()), decltype(z2.begin())>(z1.begin(), z2.begin());
    }

    auto end()
    {
        return iterator<decltype(z1.end()), decltype(z2.end())>(z1.end(), z2.end());
    }
};

template <typename A, typename B>
std::ostream &operator<<(std::ostream &os, const std::pair<A, B> &x)//https://en.cppreference.com/w/cpp/utility/pair
{
    os << x.first << ',' << x.second;
}
} // namespace itertools
#include "iostream"
namespace itertools
{
template <typename typePro1, typename typePro2>
class product
{
private:
    typePro1 p1;
    typePro2 p2;

public:
    product(typePro1 a, typePro2 b) :p1(a), p2(b){}


    template <typename typeIter1, typename typeIter2>

    class iterator
    {
    private:
        typeIter1 iter1;
        typeIter2 iter2;
        typeIter2 temp;

    public:
        iterator(typeIter1 start, typeIter2 stop) :iter1(start), iter2(stop){}

        //operators

        iterator<typeIter1, typeIter2> &operator++()
        {
            ++iter2;
            return *this;
        }
        std::pair<decltype(*iter1), decltype(*iter2)> operator*() const
        {

            return std::pair<decltype(*iter1), decltype(*iter2)>(*iter1, *iter2);
        }

        bool operator!=(iterator<typeIter1,typeIter2> x)
        {
            if ((iter1 != x.iter1) && !(iter2 != x.iter2))
            {
                iter2 = temp;
                ++iter1;
            }
            return (iter1 != x.iter1);
        }
    };
auto begin()
{
    return iterator<decltype(p1.begin()),decltype(p2.begin())>(p1.begin(), p2.begin());
}

auto end()
{
    return iterator<decltype(p1.end()),decltype(p2.end())>(p1.end(), p2.end());
}
};
} // namespace itertools
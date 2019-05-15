#include "iostream"
namespace itertools
{
template <typename typeChain1, typename typeChain2>
class chain
{
private:
    typeChain1 c1;
    typeChain2 c2;

public:
    chain(typeChain1 a, typeChain2 b) :c1(a),c2(b){}
    template <typename typeIter1, typename typeIter2>

    class iterator
    {
    private:
        typeIter1 iter1;
        typeIter2 iter2;
        bool flag;

    public:
        iterator(typeIter1 a, typeIter2 b):iter1(a),iter2(b),flag(true){}
        //operators

        bool operator!=(iterator<typeIter1, typeIter2> x)
        {
            if ((flag) && !(iter1 != x.iter1))
                flag = false;
            if (flag)
                return iter1 != x.iter1;
            else
            {
                return iter2 != x.iter2;
            }
        }

        iterator<typeIter1, typeIter2> &operator++()
        {
            if (flag)
                ++iter1;
            else
                ++iter2;
            return *this;
        }

        decltype(*iter1) operator*() const
        {
            if (flag)
                return *iter1;
            else
                return *iter2;
        }

        const iterator operator++(int)
        {
        }
        bool operator==(iterator itr) const
        {
        }
    };
auto begin()
{
    return iterator<decltype(c1.begin()),decltype(c2.begin())> (c1.begin(), c2.begin());
}

auto end()
{
    return iterator<decltype(c1.end()),decltype(c2.end())>(c1.end(),c2.end());
}


};

} // namespace itertools


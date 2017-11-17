#include <iostream>
#include <vector>

template <typename T>
class CArr
{
private:
    std::vector<T> elements;
    std::vector<T> cummulative;

public:
    CArr(const std::vector<T>& other) :
        elements(other)
    {
        cummulative.reserve(elements.size() + 1);
        cummulative.push_back(T());
        for (const T& x: elements)
        {
            cummulative.push_back(cummulative.back()+x);
        }
        /*!
        for (int i = 0; i < elements.size(); ++i)
        {
            cummulative.push_back(cummulative[i] + elements[i]);
        }
        */
    }
    void change(const T& x, size_t ind)
    {
        elements[ind] = x;
        for (size_t i = ind; i < elements.size(); ++i)
        {
            cummulative[ind+1] = cummulative[ind] + elements[ind];
        }
    }
    T sum(size_t l, size_t r)
    {
        return cummulative[r+1] - cummulative[l];
    }
};

void test()
{
    std::vector<int> x;
    x.push_back(3);
    x.push_back(-3);
    x.push_back(9);
    x.push_back(30);
    x.push_back(20);
    x.push_back(41);
    CArr<int> cummulative(x);
    std::cout << cummulative.sum(0, 5) << std::endl;
    std::cout << cummulative.sum(2, 5) << std::endl;
    std::cout << cummulative.sum(3, 5) << std::endl;
}

int main()
{
    test();
    return 0;
}

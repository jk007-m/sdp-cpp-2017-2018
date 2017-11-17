#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

template <typename T>
class Stack
{
private:
    std::vector<T> elements;

public:
    bool empty() { return elements.empty(); }
    const T& top()
    {
        assert(!empty());
        return elements.back();
    }
    T pop()
    {
        assert(!empty());
        T top = elements.back();
        elements.pop_back();
        return top;
    }
    void push(const T& x)
    {
        elements.push_back(x);
    }
    int size() { return elements.size(); }
};

void test()
{
    Stack<int> s;
    s.push(8);
    s.push(6);
    s.push(3);
    s.push(-3);
    s.push(118);
    s.push(0);
    s.push(1024);
    s.push(37);
    s.push(-1117);
    s.push(681);
    while (!s.empty())
    {
        std::cout << s.pop() << std::endl;
    }

}

int main()
{
    test();
    return 0;
}

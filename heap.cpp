#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

class Heap /// Min-heap, max-heap
{
private:
    bool minFlag = true;
    std::vector<int> tree;
    inline int parent(int ind)
    {/// ind / 2
        return (ind >> 1);
    }
    inline int left(int ind)
    { /// ind * 2
        return (ind << 1);
    }
    inline int right(int ind)
    { /// ind * 2 + 1
        return ((ind << 1) | 1);
    }
    void siftUp(int ind)
    {
        if ((ind == 1) ||
            (tree[parent(ind)] <= tree[ind]))
        {
            return;
        }
        std::swap(tree[ind], tree[parent(ind)]);
        siftUp(parent(ind));
    }
    void siftDown(int ind)
    {
        if (left(ind) >= tree.size()) return;
        int minChildInd = left(ind);
        if (right(ind) < tree.size() &&
            tree[right(ind)] < tree[minChildInd])
        {
            minChildInd = right(ind);
        }
        if (tree[ind] <= tree[minChildInd]) return;
        std::swap(tree[ind], tree[minChildInd]);
        siftDown(minChildInd);
    }

public:
    Heap(bool _minFlag = true) :
        minFlag(_minFlag)
    {
        tree.push_back(0);
    }
    Heap(const std::vector<int>& other, bool _minFlag = true) :
        minFlag(_minFlag)
    {
        build_heap(other);
    }
    void insert(int x)
    {
        if (!minFlag) x = -x;
        tree.push_back(x);
        siftUp(tree.size() - 1);
    }
    int top()
    {
        assert(tree.size() > 1);
        if (!minFlag) return -tree[1];
        return tree[1];
    }
    int pop()
    {
        assert(tree.size() > 1);
        int ret = tree[1];
        if (!minFlag) ret = -ret;
        tree[1] = tree.back();
        tree.pop_back();
        siftDown(1);
        return ret;
    }
    void build_heap(const std::vector<int>& arr)
    {
        tree.clear();
        tree.push_back(0);
        for (int x: arr)
        {
            if (!minFlag) x = -x;
            tree.push_back(x);
        }
        for (int i = (tree.size() - 1)/2; i > 0; --i)
        {
            siftDown(i);
        }
    }
    bool empty()
    {
        return tree.size() == 1;
    }
};

std::vector<int> heapSort(const std::vector<int>& arr)
{
    std::vector<int> ret;
    Heap h(arr);
    while(!h.empty())
    {
        ret.push_back(h.pop());
    }
    return ret;
}

void test()
{
    std::vector<int> test;
    test.push_back(15);
    test.push_back(-5);
    test.push_back(48);
    test.push_back(122);
    test.push_back(0);
    test.push_back(-2);
    Heap heapy(test, false);
    while (!heapy.empty())
    {
        std::cout << heapy.pop() << std::endl;
    }
    /*std::vector<int> test2 = heapSort(test);
    for (int x: test2)
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;*/
}

int main()
{
    test();
    return 0;
}

#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

template <typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node(const T& _data, Node<T>* _next=nullptr) :
        data(_data), next(_next) {}
};

template <typename T>
class Stack
{
private:
    Node<T>* _top;
    int _size;
    /// Deletes elements from start including.
    void deleteElements(Node<T>* start)
    {
        if (start == nullptr) return;
        Node<T>* toDelete;
        while (start != nullptr)
        {
            toDelete = start;
            start = start->next;
            delete toDelete;
        }
    }
    /// Copies the elements from other to the beginning of this list.
    void copyElementsToBeginning(const Stack<T>& other)
    {
        unsigned long long newSize = 0;
        Node<T>* prev = nullptr;
        Node<T>* curr = _top;
        Node<T>* otherCurr = other._top;
        // While we have storage we can reuse
        while (curr != nullptr && otherCurr != nullptr)
        {
            curr->data = otherCurr->data;
            ++newSize;
            prev = curr;
            curr = curr->next;
            otherCurr = otherCurr->next;
        }
        /// This list was longer than the list other.
        if (curr != nullptr)
        {
            if (prev != nullptr) /// The list other was not empty.
            {
                prev->next = nullptr;
                deleteElements(curr);
            }
            else /// The list other was empty.
            {
                _top = nullptr;
                deleteElements(curr);
            }
        }
        /// The list other was longer than this list.
        while (otherCurr != nullptr)
        {
            prev->next = new Node<T>(otherCurr->data, nullptr);
            ++newSize;
            prev = prev->next;
            otherCurr = otherCurr->next;
        }
        _size = newSize;
    }

public:
    Stack() : _top(nullptr), _size(0) {}

    /// operator=,copy constructor & eventually move semantics need to be added

    const T& top()
    {
        assert(_top!=nullptr);
        return _top->data;
    }
    T pop()
    {
        assert(_top!=nullptr);
        T top = _top->data;
        Node<T>* toDelete = _top;
        _top = _top->next;
        delete toDelete;
        --_size;
        return top;
    }
    void push(const T& x)
    {
        _top = new Node<T>(x, _top);
        ++_size;
    }
    int size() { return _size; }
    bool empty() { return _top == nullptr; }
    ~Stack()
    {
        deleteElements(_top);
        _top = nullptr;
    }
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

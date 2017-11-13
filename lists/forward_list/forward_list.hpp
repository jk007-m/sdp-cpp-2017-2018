#ifndef FORWARD_LIST_H_
#define FORWARD_LIST_H_

#include <stdexcept>

namespace data_structures {

template <typename T>
struct Node
{
    T data;
    Node<T>* next;
    Node(T _data=T(), Node<T>* _next=nullptr) : data(_data), next(_next) {}
};

template <typename T>
class ForwardList
{
private:
    Node<T>* head_;
    unsigned long long size_;
    // Deletes elements from start including.
    void deleteListElements(Node<T>* start)
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
    // Copies the elements from other to the beginning of this list.
    void copyElementsToBeginning(const ForwardList<T>& other)
    {
        unsigned long long newSize = 0;
        Node<T>* prev = nullptr;
        Node<T>* curr = head_;
        Node<T>* otherCurr = other.head_;
        // While we have storage we can reuse
        while (curr != nullptr && otherCurr != nullptr)
        {
            curr->data = otherCurr->data;
            ++newSize;
            prev = curr;
            curr = curr->next;
            otherCurr = otherCurr->next;
        }
        // This list was longer than the list other.
        if (curr != nullptr)
        {
            if (prev != nullptr) // The list other was not empty.
            {
                prev->next = nullptr;
                deleteListElements(curr);
            }
            else // The list other was empty.
            {
                head_ = nullptr;
                deleteListElements(curr);
            }
        }
        // The list other was longer than this list.
        else if (otherCurr != nullptr)
        {
            while (otherCurr != nullptr)
            {
                prev->next = new Node<T>(otherCurr->data, nullptr);
                ++newSize;
                prev = prev->next;
                otherCurr = otherCurr->next;
            }
        }
        size_ = newSize;
    }

public:
    ForwardList() : head_(nullptr), size_(0) {}
    // ForwardList(some other array or something) {}

    ForwardList(const ForwardList& other) : head_(nullptr), size_(0)
    {
        copyElementsToBeginning(other);
    }
    ForwardList(ForwardList&& other) : head_(other.head_), size_(other.size_)
    {
        other.head_ = nullptr;
        other.size_ = 0;
    }
    ForwardList& operator=(const ForwardList& other) // copy assignment
    {
        if (this != &other) copyElementsToBeginning(other);
        return *this;
    }
    ForwardList& operator=(ForwardList&& other) noexcept // move assignment
    {
        if (this != &other)
        {
            Node<T>* temp = head_;
            head_ = other.head_;
            size_ = other.size_;
            other.head_ = temp;
            other.size_ = 0;
            deleteListElements(temp);
        }
        return *this;
    }
    ~ForwardList()
    {
        deleteListElements(head_);
    }
    bool isEmpty() { return size_ == 0; }
    T front()
    {
        if (isEmpty())
            throw std::out_of_range("List is empty - no front element present.");
        //std::cerr << "List is empty - no front element present.\n";
        return head_->data;
    }
    void pushFront(const T& data)
    {
        ++size_;
        head_ = new Node<T>(data, head_);
    }
    void popFront()
    {
        if (isEmpty()) return; // Could throw exception.
        --size_;
        Node<T>* toDelete = head_;
        head_ = head_->next;
        delete toDelete;
    }
    void pushBack(const T& data)
    {
        ++size_;
        if (isEmpty())
        {
            head_ = new Node<T>(data, nullptr);
        }
        else
        {
            Node<T>* curr = head_;
            while (curr->next != nullptr) curr = curr->next;
            curr->next = new Node<T>(data, nullptr);
        }
    }
    void popBack()
    {
        if (isEmpty()) return; // Could throw exception.
        --size_;
        Node<T>* toDelete = head_;
        while (toDelete->next != nullptr) toDelete = toDelete->next;
        delete toDelete;
    }

	class iterator
	{
	private:
		Node<T>* current;
	public:
		iterator(const ForwardList<T>& fl) : current(fl.head_) {}
		iterator(Node<T>* start=nullptr) : current(start) {}
		iterator& next_element()
		{
			current = current->next;
			return *this;
		}
		bool operator==(const iterator& rhs) const {return current == rhs.current; }
        bool operator!=(const iterator& rhs) const {return current != rhs.current; }
		T& get_value() { return current->data; }

	};

	iterator begin() { return iterator(head_); }
	iterator end() { return nullptr; }
};


} // data_structures

#endif  // FORWARD_LIST_H_

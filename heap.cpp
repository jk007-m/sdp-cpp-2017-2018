#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int val = 0, Node* left = NULL, Node* right = NULL):val(val), left(left), right(right){}
};

Node* Merge(Node* left, Node* right)
{
    if (!left || !right) return left ? left : right;
    if (left -> val > right -> val) swap(left, right);
    if (rand() & 1) swap(left -> left, left -> right); /// rand keeps it log(n)
    left -> right = Merge(left -> right, right);
    return left;
}

Node* Push(Node* heap, int el)
{
    return Merge(heap, new Node(el));
}

int top(Node* heap)
{
    return heap -> val;
}

Node* Pop(Node* heap)
{
    Node* left = heap -> left;
    Node* right = heap -> right;
    delete heap;
    return Merge(left, right);
}

int main()
{
	return 0;
}

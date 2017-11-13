#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Heap {
    vector<int> tree;
    bool flag; /// true -> min heap, false -> max heap
    Heap(bool flag = true) {
        tree.push_back(0);
        this -> flag = flag;
    }
    void siftUp(int ind) {
        if (ind == 1) return;
        if (this -> tree[ind / 2] > this -> tree[ind]) {
            swap(this -> tree[ind / 2], this -> tree[ind]);
            siftUp(ind / 2);
        }
    }
    void siftDown(int ind) {
        while (ind * 2 < this -> tree.size()) {
            int minChildInd = ind * 2;
            if ((minChildInd + 1 < this -> tree.size()) && (this -> tree[minChildInd + 1] < this -> tree[minChildInd])) minChildInd++;
            if (this -> tree[minChildInd] < this -> tree[ind])
            {
                swap(this -> tree[minChildInd], this -> tree[ind]);
                ind = minChildInd;
            }
            else return;
        }
    }
    void push(int element) {
        if (flag) this -> tree.push_back(element);
        else this -> tree.push_back(-element);
        siftUp(this -> tree.size() - 1);
    }
    int top() {
        if (flag) return this -> tree[1];
        return -(this -> tree[1]);
    }
    void pop() {
        this -> tree[1] = this -> tree.back();
        this -> tree.pop_back();
        siftDown(1);
    }
    /*!void printHeap() { /// Temporary!
        for (int i = 1; i < this -> tree.size(); i++)
            if (flag) cout << this -> tree[i] << ' ';
            else cout << -(this -> tree[i]) << ' ';
        cout << endl;
    }*/
};

int main() {
    return 0;
}

/*!
    Heap input(false);
    for (int i = 0; i < 7; i++) {
        int a;
        cin >> a;
        input.push(a);
        input.printHeap();
    }
    cout << "Top element = " << input.top() << endl;
    input.pop();
    input.printHeap();

    cout << "Top element = " << input.top() << endl;
    input.pop();
    input.printHeap();
Test:
-5 1 6 3 2 4 3
*/

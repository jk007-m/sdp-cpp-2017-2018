#include "./forward_list.hpp"
#include <iostream>

int main()
{
    data_structures::ForwardList<int> fl;
    fl.pushFront(5);
    fl.pushFront(7);
    fl.pushFront(5);
    fl.pushFront(-45);
    fl.pushFront(0);

    for (data_structures::ForwardList<int>::iterator it = fl.begin(); it != fl.end(); it=it.next_element())
    {
        std::cout << it.get_value() << std::endl;
    }

    for (data_structures::ForwardList<int>::iterator it = fl.begin(); it != fl.end(); it=it.next_element())
    {
        it.get_value() = 4345;
    }

    std::cout << "\n\n\n";

    for (data_structures::ForwardList<int>::iterator it = fl.begin(); it != fl.end(); it=it.next_element())
    {
        std::cout << it.get_value() << std::endl;
    }

    /*int x = fl.front();
    fl.popFront();
    fl.popFront();
    fl.popBack();
    std::cout << x << std::endl;
    std::cout << fl.front() << std::endl;*/
    return 0;
}

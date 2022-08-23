#ifndef COP4530_STACK_H
#define COP4530_STACK_H

#include <iostream>
#include <stdexcept>
#include <iterator>
#include <vector>

using namespace std;
namespace cop4530
{
template <typename T>
class Stack {
public:

    using iterator = T*;
    using const_iterator = const T*;

    Stack();
    Stack(const Stack &rhs);
    Stack(Stack &&rhs);
    Stack& operator=(const Stack &rhs);
    Stack& operator=(Stack &&rhs);
    bool empty()const;
    T& top();
    const T& top() const;
    void pop();
    void push(const T& val);
    void push(T&& val);
    int size() const;

    iterator begin(); // iterator to first element
    const_iterator begin() const;
    iterator end(); // end marker iterator
    const_iterator end() const;

private:
    int stackSize;
    vector<T> container;
};
#include "Stack.hpp"
}
#endif


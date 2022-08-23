#include <iostream>
#include <iterator>
#include <vector>

using namespace cop4530;

template <typename T>
Stack<T>::Stack()
{
    vector<T> array(1);
    container = array;
    stackSize = 0;
}

template <typename T>
Stack<T>::Stack(const Stack &rhs)
{
    container = rhs.container;
    stackSize = rhs.stackSize;
}

template <typename T>
Stack<T>::Stack(Stack &&rhs)
{
    stackSize = rhs.stackSize;
    container = rhs.container;
    rhs.container = nullptr;
    rhs.stackSize = 0;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack &rhs)
{
    container = rhs.container;
    stackSize = rhs.stackSize;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack &&rhs)
{
    stackSize = rhs.stackSize;
    container = rhs.container;
    rhs.container = nullptr;
    rhs.stackSize = 0;
}

template <typename T>
bool Stack<T>::empty()const
{
    if(stackSize == 0)
        return true;
    else
        return false;
}

template <typename T>
T& Stack<T>::top()
{
    return container[stackSize];
}

template <typename T>
const T& Stack<T>::top() const
{
    return container[stackSize];
}

template <typename T>
void Stack<T>::pop()
{
    --stackSize;
    container.pop_back();
}

template <typename T>
void Stack<T>::push(const T& val)
{
    container.push_back(val);
    ++stackSize;
}

template <typename T>
void Stack<T>::push(T&& val)
{
    container.push_back(val);
    ++stackSize;
}

template <typename T>
int Stack<T>::size() const
{
    return stackSize;
}

template <typename T>
T* Stack<T>::begin()
{
    return &container[stackSize];
}

template <typename T>
const T* Stack<T>::begin() const
{
    return &container[stackSize];
}

template <typename T>
T* Stack<T>::end()
{
    return &container[0];
}

template <typename T>
const T* Stack<T>::end() const
{
    return &container[0];
}

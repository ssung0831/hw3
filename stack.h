#ifndef STACK_H
#define STACK_H
#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary

private:
    std::vector<T> s;
};

template <typename T>
Stack<T>::Stack(){
}

template <typename T>
Stack<T>::~Stack(){
}

template <typename T>
bool Stack<T>::empty() const{
    if(s.size() == 0){
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
size_t Stack<T>::size() const{
    return s.size();
}

template <typename T>
void Stack<T>::push(const T& item){
    s.push_back(item);
}

template <typename T>
void Stack<T>::pop(){
    if(size() == 0){
        throw std::underflow_error("Stack is empty");
    }
    s.pop_back();
}

template <typename T>
const T& Stack<T>::top() const{
    if(size() == 0){
        throw std::underflow_error("Stack is empty");
    }
    return s.back();
}

#endif
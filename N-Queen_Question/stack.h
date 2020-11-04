#pragma once
#include <vector>
using namespace std;

template <typename T, class Container = std::vector<T> > 
class Stack {
private:
    Container _data;
public:
    void push(T const& e) {
        _data.insert(_data.end(), e);
    }

    T pop() {
        T tmp = _data[_data.size() - 1];
        _data.pop_back();
        return tmp;
    }
    
    T& top() {
        return _data.back();
    }

    //e首次出现的索引
    int find(T e);

    void traverse(void (*)(T&));

    int size() { return _data.size(); }
};

template <typename T, class Container>
int Stack<T, Container>::find(T e) {
    int index = -1;
    typename std::vector<T>::iterator it = std::find(_data.begin(), _data.end(), e);
    if (it != _data.end()) {
        index = it - _data.begin();
    }
    return index;
}

template <typename T, class Container>
void Stack<T, Container>::traverse(void (*visit)(T&)) {
    for (auto i : _data) {
        visit(i);
    }
}
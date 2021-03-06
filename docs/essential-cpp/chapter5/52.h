#include <iostream>
#include <vector>

using namespace std;

typedef string elemType;

class Stack {
public:
    Stack(int capacity=0) : _top(0) {
        if (capacity) {
            _stack.reserve(capacity);
        }
    }
    virtual ~Stack() {}

    bool pop(elemType&);
    bool push(const elemType&)
    virtual bool peek(int, elemType&) {
        return false;
    }
    int size() const {
        return _stack.size();
    }
    int top() const {
        return _top;
    }

    bool empty() const {
        return !_top;
    }
    bool full() const {
        return (size_t) size() >= _stack.max_size();
    }
    void print(ostream &os=cout) const;

protected:
    vector<elemType> _stack;
    int _top;
};

class Peekback_Stack : public Stack {
public:
    Peekback_Stack(int capacity=0) : Stack(capacity) {}
};

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//       CSCI 112 - Extra Credit - Templated Stack Class - Joel Cressy
//                Headers and definitions - Array Version
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

template <class T>
class arrstack
{
  private:
    static const int maxstack = 100;
    T stackarr[maxstack];
    int top;
    int count;
  public:
    arrstack();
    arrstack(T);
    bool full();
    bool empty();
    int size();
    void push(T);
    T getTop();
    void pop();
};

#include "arrstack.cpp"
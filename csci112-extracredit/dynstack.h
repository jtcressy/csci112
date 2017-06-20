//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//       CSCI 112 - Extra Credit - Templated Stack Class - Joel Cressy
//                Headers and definitions - Dynamic Version
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

template <class T>
class dynstack
{
  private:
    struct linktype
    {
        T data;
        linktype *link;
    };
    linktype *top;
    int count;
  public:
    dynstack();
    dynstack(T);
    bool empty();
    int size();
    void push(T);
    T getTop();
    void pop();
};

#include "dynstack.cpp"
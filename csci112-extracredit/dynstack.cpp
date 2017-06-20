template <class T>
dynstack<T>::dynstack()
{
    top = NULL;
    count = 0;
}

template <class T>
dynstack<T>::dynstack(T data)
{
    top = new linktype;
    top->data = data;
    top->link = NULL;
    count = 1;
}

template <class T>
void dynstack<T>::push(T data)
{
    if (!empty())
    {
        linktype *temp;
        temp = new linktype;
        temp->data = top->data;
        temp->link = top->link;
        top->data = data;
        top->link = temp;
    }
    else
    {
        top = new linktype;
        top->data = data;
        top->link = NULL;
    }
    count++;
}

template <class T>
void dynstack<T>::pop()
{
    if (top -> link == NULL)
    {
        top = NULL;
    }
    else 
    {
        linktype *prev;
        prev = top->link;
        top->data = prev->data;
        top->link = prev->link;
        delete prev;
    }
    count--;
}

template <class T>
bool dynstack<T>::empty()
{
    return top == NULL;
}

template <class T>
int dynstack<T>::size()
{
    return count;
}

template <class T>
T dynstack<T>::getTop()
{
    return top->data;
}
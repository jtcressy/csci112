template <class T>
arrstack<T>::arrstack()
{
    top = -1;
    for (int i = 0; i < maxstack; i++)
        stackarr[i] = {};
}

template <class T>
arrstack<T>::arrstack(T data)
{
    push(data);
}

template <class T>
void arrstack<T>::push(T data)
{
    top++;
    stackarr[top] = data;
    count++;
}

template <class T>
void arrstack<T>::pop()
{
    if (top >= 0)
    {
        stackarr[top] = {};
        top--;
    }
    else
        std::cerr << "Stack already empty" << std::endl;
}

template <class T>
bool arrstack<T>::full()
{
    return top == maxstack - 1;
}

template <class T>
bool arrstack<T>::empty()
{
    return top == -1;
}

template <class T>
int arrstack<T>::size()
{
    return top+1;
}

template <class T>
T arrstack<T>::getTop()
{
    return stackarr[top];
}
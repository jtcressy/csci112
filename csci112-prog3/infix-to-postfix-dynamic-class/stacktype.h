
class stacktype
{
  public:
    stacktype();
    stacktype(char ch);
    void push(char ch);
    char pop();
    bool isEmpty();
    int size();
    char getTop();
  private:
    const char initstack = '~';
    struct linkedstack {
        int count;
        char data;
        linkedstack *link;
    };
    linkedstack *top;

};

stacktype::stacktype()
{
    top = new linkedstack;
    top -> count = 0;
    top -> data = initstack;
    top -> link = NULL;
}
stacktype::stacktype(char ch)
{
    top = new linkedstack;
    top -> count = 1;
    top -> data = ch;
    top -> link = NULL;
}
void stacktype::push(char ch)
{
    linkedstack *pushed;
    pushed = new linkedstack;
    pushed -> count = top -> count;
    pushed -> data = top -> data;
    pushed -> link = top -> link;
    top -> count++;
    top -> data = ch;
    top -> link = pushed;
}
char stacktype::pop()
{
    char answer = '~';
    answer = top -> data;
    linkedstack *next;
    next = top -> link;
    top -> count = next -> count;
    top -> data = next -> data;
    top -> link = next -> link;
    delete next;
    return answer;
}
bool stacktype::isEmpty()
{
    return top -> count < 1;
}
int stacktype::size()
{
    return top -> count;
}
char stacktype::getTop()
{
    return top -> data;
}
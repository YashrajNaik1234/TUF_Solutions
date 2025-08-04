struct stackNode
{
    int data;
    stackNode *next;
    int size;
    stackNode(int d)
    {
        data = d;
        next = NULL;
    }
};
class LinkedListStack
{
    stackNode *ele;
    int size;
public:
    LinkedListStack()
    {
        ele = NULL;
        size = 0;
    }

    void push(int x)
    {
        stackNode *element = new stackNode(x);
        element -> next = ele;
        ele = element; size++;
    }

    int pop()
    {
        if(ele == nullptr) return -1;
        int  eleData = ele -> data;
        stackNode *temp = ele;
        ele = ele -> next;
        delete temp;
        size--; return eleData;
    }

    int top()
    {
        return ele -> data;
    }

    bool isEmpty()
    {
        return (size == 0);
    }
};

struct queueNode
{
    int data;
    queueNode *next;
    int size;
    queueNode(int d)
    {
        data = d;
        next = NULL;
    }
};

class LinkedListQueue
{
    queueNode *st;
    queueNode *en;
    int size;

public:
    LinkedListQueue()
    {
        st = NULL;
        en = NULL;
        size = 0;
    }

    void push(int x)
    {
        queueNode *element = new queueNode(x);
        
        if(st == NULL){
            st = en = element;
        }
        else en -> next = element;

        size++;
    }

    int pop()
    {
        if(st == nullptr) return -1;
        int x = st -> data;
        queueNode *temp = st;
        st = st -> next;
        delete temp; size--;
        return x;
    }

    int peek()
    {
        if (st == nullptr) return -1;
        return st -> data;
    }

    bool isEmpty()
    {
        return (size == 0);
    }
};

class ArrayQueue
{
    int st;
    int en;
    int cursize;
    int size;
    int *arr;

public:
    ArrayQueue()
    {
        st = -1;
        en = -1;
        size = 1000;
        cursize = 0;
        arr = new int[size];
    }

    void push(int x)
    {
        if (cursize == 0)
        {
            st = 0;
            en = 0;
        }
        else
        {
            en = (en + 1) % size;
        }

        arr[en] = x;
        cursize++;
    }

    int pop()
    {
        if (cursize == 0) return -1;

        int x = arr[st];
        if (cursize == 1)
            st = en = -1;
        else
            st = (st + 1) % size;

        cursize--;
        return x;
    }

    int peek()
    {
        return arr[st];
    }

    bool isEmpty()
    {
        if (st != en)
            return false;
        return true;
    }
};

class ArrayStack {
    int size;
    int * arr;
    int t;
    public:
    ArrayStack() {
        t = -1;
        size = 1000;
        arr = new int[size];
    }
    
    void push(int x) {
        t++;
        arr[t] = x;
    }
    
    int pop() {
        int y = arr[t];
        t--;
        return y;
    }
    
    int top() {
        return arr[t];
    }
    
    bool isEmpty() {
        if(t != -1) return true;
        return false;
    }
};

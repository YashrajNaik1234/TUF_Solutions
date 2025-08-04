class ArrayStack {
    int size;
    int * arr;
    int top;
    public:
    ArrayStack() {
        top = -1;
        size = 1000;
        arr = new int[size];
    }
    
    void push(int x) {
        top++;
        arr[top] = x;
    }
    
    int pop() {
        int y = arr[top];
        top--;
        return y;
    }
    
    int top() {
        return arr[top];
    }
    
    bool isEmpty() {
        if(top != -1) return true;
        return false;
    }
};

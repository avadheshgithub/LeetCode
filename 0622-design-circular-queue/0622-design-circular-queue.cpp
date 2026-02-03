class MyCircularQueue {
public:

    int F=0,R=-1,size=0;
    int capacity;
    vector<int>arr;

    MyCircularQueue(int k) {
        capacity = k;
        arr.resize(k);
    }
    
    bool enQueue(int value) {
        if(!isFull()){
            R = (R+1)%capacity;
            arr[R]= value;
            size++;
        }
        else return false;
        return true;
    }
    
    bool deQueue() {
        if(!isEmpty()){
            F = (F+1)%capacity;
            size--;
        }
        else return false;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[F];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[R];
    }
    
    bool isEmpty() {
        if(size==0) return true;
        return false;
    }
    
    bool isFull() {
        if(size==capacity) return true;
        return false;
    }
};

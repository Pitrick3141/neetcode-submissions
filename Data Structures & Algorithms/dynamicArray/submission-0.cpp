class DynamicArray {
    int* arr_ = nullptr;
    int capacity_ = 0;
    int used_ = 0;
public:

    DynamicArray(int capacity) {
        arr_ = new int[capacity];
        capacity_ = capacity;
    }

    int get(int i) {
        return *(arr_ + i);
    }

    void set(int i, int n) {
        *(arr_ + i) = n;
    }

    void pushback(int n) {
        if(used_ == capacity_) resize();
        *(arr_ + used_++) = n;
    }

    int popback() {
        return *(arr_ + --used_);
    }

    void resize() {
        int* resized = new int[2*capacity_];
        for(int i=0; i<used_; i++) *(resized + i) = *(arr_ + i);
        delete[] arr_;
        arr_ = resized;
        capacity_ *= 2;
    }

    int getSize() {
        return used_;
    }

    int getCapacity() {
        return capacity_;
    }
};

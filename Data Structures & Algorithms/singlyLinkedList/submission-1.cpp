class LinkedList {
    int val_;
    LinkedList* next_ = nullptr;
public:
    LinkedList() {
    }

    int get(int index) {
        if(!next_) return -1;
        if(!index) return val_;
        return next_ -> get(index - 1);
    }

    void insertHead(int val) {
        if(!next_) {
            val_ = val;
            next_ = new LinkedList();
            return;
        }
        LinkedList* inserted = new LinkedList();
        inserted -> val_ = val_;
        inserted -> next_ = next_;
        val_ = val;
        next_ = inserted;
    }
    
    void insertTail(int val) {
        if(!next_) {
            val_ = val;
            next_ = new LinkedList();
        }
        else next_ -> insertTail(val);
    }

    bool remove(int index) {
        if(!next_) return false;
        if(!index) {
            LinkedList* tmp = next_;
            val_ = next_ -> val_;
            next_ = next_ -> next_;
            delete tmp;
            return true;
        }
        return next_ -> remove(index - 1);
    }

    vector<int> getValues() {
        vector<int> vec;
        LinkedList* cur = this;
        while(cur -> next_) {
            vec.push_back(cur -> val_);
            cur = cur -> next_;
        }
        return vec;
    }
};

class MinStack {
private:
    struct Node {
        int data;
        int currMin;
        Node* next;
        Node* prev;
        Node(int val, int currMin, Node* p) : data(val), currMin(currMin), next(nullptr), prev(p) {}
    };

    Node* tail;
    
public:
    MinStack() {
        tail = new Node(INT_MAX, INT_MAX, nullptr);
    }
    
    void push(int val) {
        Node* newNode = new Node(
            val,                            // value
            min(val, tail->currMin),   // global minimum after insertion
            tail                     // current tail
        );
        
        tail->next = newNode;
        tail = newNode;
    }
    
    void pop() {
        if (tail->prev == nullptr) return;

        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
    
    int top() {
        return tail->data;
    }
    
    int getMin() {
        return tail->currMin;
    }
};

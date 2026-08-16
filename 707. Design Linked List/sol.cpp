class MyLinkedList {
    Node *root, *tail;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        root = new Node();
        tail = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node* cur = root->next;
        
        for(int i = 0; i < index and cur; i++)
            cur = cur->next;
        
        return cur ? cur->val : -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* head = root->next;
        
        if(not head) {
            root->next = new Node(val);
            tail = root->next;
            return;
        }
        
        root->next = new Node(val);
        root->next->next = head;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(not tail) {
            root->next = new Node(val);
            tail = root->next;
            return;
        }
        
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index == 0) {
            addAtHead(val);
            return;
        }
        
        Node* cur = root->next;
        for(int i = 0; i < index - 1; i++)
            cur = cur->next;
        
        Node* temp = cur->next;
        cur->next = new Node(val);
        cur->next->next = temp;
        
        if(not temp)
            tail = cur->next;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        Node* cur = root->next, *prev = root;
        for(int i = 0; i < index and cur; i++)
            prev = cur, cur = cur->next;
        
        if(not cur) return;
        Node* temp = cur->next;
        
        prev->next = cur->next;
        if(not temp)
            tail = prev;
        
        temp = nullptr;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

// --- alternate solution ---

struct Node {
    int val;
    Node* next;
    Node() {val = 0, next = nullptr;}
    Node(int data) {val = data, next = nullptr;}
};

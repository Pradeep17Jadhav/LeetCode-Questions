class MyLinkedList {
public:
    ListNode* head = NULL; //to maintain head of the list
    ListNode* ptr; //temporary pointer for traversal
    int size = 0; //maintains size of linked list

    MyLinkedList() {
    }
    
    int get(int index) {
        if(index < 0 || index >= size)
            return -1;  
        
        ptr = head;
        while(index--) {
            ptr = ptr->next;
        }
        return ptr->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size)
            return;
        
        ListNode* newNode = new ListNode(val);
        if(index == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            ptr = head;
            while(--index) {
                ptr = ptr->next;
            }
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;  
        
        if(index == 0)
        {
            ListNode* temp = head;
            head = head->next;
            delete(temp);
        }
        else
        {
            ptr = head;
            while(--index) {
                ptr = ptr->next;
            }
            ListNode* temp = ptr->next; //0 1 2
            ptr->next = ptr->next->next;
            delete(temp);
        }
        size--;
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
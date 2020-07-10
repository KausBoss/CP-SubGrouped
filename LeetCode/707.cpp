class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

class MyLinkedList {
    Node *head;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int id=0;
        Node* temp=head;
        while(id!=index){id++; temp=temp->next;}
        return temp?temp->data:-1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *n= new Node(val);
        n->next=head;
        head = n;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* n= new Node(val);
        Node* temp = head;
        while(temp->next){temp = temp->next;}
        temp->next=n;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index==0){
            addAtHead(val);
            return;
        }
        Node* n= new Node(val);
        int id=0;
        Node* temp=head;
        while(id<index-1){temp=temp->next; id++;}
        if(temp){
            n->next=temp->next;
            temp->next=n;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index == 0){head=head->next;}
        int i=0;
        Node* temp=head;
        while((i<index-1)&&(temp->next)){
            temp=temp->next;
            i++;
        }
        if(temp==NULL||temp->next==NULL){return;}
        if(temp->next!=NULL){
            temp->next=temp->next->next;
        }
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
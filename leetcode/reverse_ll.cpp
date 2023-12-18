class Node{
public:
   int data;
   Node *next;
   Node(int data){
    this->data=data;
    this->next=nullptr;
   }
};

Node* reverseLL(Node *head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node *smallAns=reverseLL(head->next);
    Node *temp=smallAns;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=head;
    head->next=nullptr;
    return smallAns;
}
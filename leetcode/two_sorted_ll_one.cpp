class Node{
public:
   int data;
   Node *next;
   Node(int data){
    this->data=data;
    this->next=nullptr;
   }
};

Node* merge_two_lls(Node *head1,Node *head2){
    Node* temp1=head1;
    Node* temp2=head2;
    Node* fHead=nullptr;
    Node* ftail=nullptr;
    while(temp1!=nullptr && temp2!=nullptr){
        if(fHead==nullptr){
            if((temp1->data)>(temp2->data)){
                fHead=temp2;
                ftail=temp2;
                temp2=temp2->next;
            }
            else{
                fHead=temp1;
                ftail=temp1;
                temp1=temp1->next;
            }
        }
        else{
            if(temp1->data <temp2->data){
                ftail->next=temp1;
                ftail=temp1;
                temp1=temp1->next;
            }
            else{
                ftail->next=temp2;
                ftail=temp2;
                temp2=temp2->next
            }
        }
    }
    if(temp1!=nullptr){
        ftail->next=temp1;
    }
    if(temp2!=nullptr){
        ftail->next=temp2;
    }
    return fHead;
}
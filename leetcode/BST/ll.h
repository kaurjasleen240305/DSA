template <typename T>
class Node{
    public:
    int data;
    Node<T>* next;
    Node(T data){
        this->data=data;
        this->next=nullptr;
    }
};
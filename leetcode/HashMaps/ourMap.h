#include<string>
template<typename V>
class MapNode{
   public:
   string key;
   V value;
   MapNode* next;

   MapNode(string key,V value){
    this->key=key;
    this->value=value;
    next=NULL;
   }
   ~MapNode(){
    delete next;
   }
};
template<typename V>
class ourmap{
   MapNode<V>** buckets;
   int size;
   int numBuckets;

   public:
   ourmap(){
    size=0;
    numBuckets=5;
    buckets=new MapNode<V>*[numBuckets];
    for(int i=0;i<numBuckets;i++){
        buckets[i]=NULL;
    }
   }

   ~ourmap(){
    for(int i=0;i<numBuckets;i++){
        delete buckets[i];
    }
    delete[] buckets;
   }
   int size(){
    return count;
   }
   
   V getValue(string key){

   }
   void insert(string key ,V val){
       int bucketIndex=getBucketIndex(key);
       MapNode<V>* head=buckets[bucketIndex];
       while(head!=NULL){
        if(head->key==key){
            head->value=val;
            return;
        }
        head=head->next;
       }
       head=buckets[bucketIndex];
       MapNode<V>* node=new MapNode<V>(key,value);
       node->next=head;
       buckets[bucketIndex]=node;
       count++;
   }
   V remove(string key){

   }
   private:
   int getBucketIndex(string key){
    int hashCode=0;
    int currentcoeff=1;
    for(int i=key.length()-1;i>=0;i--){
        hashCode+=key[i]*currentcoeff;
        hashCode=hashCode%currentcoeff;
        currentcoeff=currentcoeff%numBuckets;
        currentcoeff*=37;
    }
    return hashCode%numBuckets;
   }
};
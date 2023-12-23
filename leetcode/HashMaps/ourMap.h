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
     int bindex=getBucketIndex(key);
     MapNode<V>* head=buckets[bindex];
     while(head!=NULL){
        if(head->key==key){
        return head->value;
        }
        head=head->next;
     }
     return 0;
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
       double loadFactor=(1.0*count)/numBuckets;
       if(loadFactor>0.7){
        rehash();
       }

   }
   V remove(string key){
      int bIndex=getBucketIndex(key);
      MapNode<V> head=buckets[bIndex];
      MapNode<V> prev=NULL;
      while(head!=NULL){
        if(head->key==key &){
            if(prev==NULL){
            buckets[bIndex]=head->next;
        }
        else{
            prev->next=head->next;
        }
        V value=head->value;
        head->next=NULL;
        delete head;
        count--;
        return value;
      }
      prev=head;
      head=head->next;
   }
   return 0;
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
   void reHash(){
    MapNode<V>** temp=buckets;
    buckets=new MapNode<V>*[2*numBuckets];
    for(int i=0;i<(2*numBuckets);i++){
        buckets[i]=NULL;
    }
    int oldBSize=numBuckets;
    numBuckets*=2;
    count=0;
    for(int i=0;i<oldBSize;i++){
        MapNode<V> head=temp[i];
        while(head!=NULL){
            string key=head->key;
            V value=head->value;
            insert(key,value);
            head=head->next;
        }
        for(int i=0;i<oldBSize;i++){
            MapNode<V> head=temp[i];
            delete head;
        }
        delete[] temp;
    }
   }
};
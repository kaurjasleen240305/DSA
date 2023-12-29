#include<bits/stdc++.h>
using namespace std;


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum1=0;
        int sum2=0;
        ListNode* head1=l1;
        ListNode* head2=l2;
        int i=0;
        while(head1!=NULL){
            // cout<<head1->val<<" ";
            sum1=sum1+pow(10,i)*(head1->val);
            i=i+1;
            head1=head1->next;
        }
        i=0;
        while(head2!=NULL){
            sum2=sum2+pow(10,i)*(head2->val);
            i=i+1;
            head2=head2->next;
        }
        int sum3=sum1+sum2;
        // cout<<sum1<<" "<<sum2<<endl;
        // cout<<sum3<<endl;
        int valh=sum3%10;
        sum3=sum3/10;
        ListNode* h3=new ListNode();
        ListNode* temp=h3;
        h3->val=valh;
        while(sum3!=0){
            ListNode* newh=new ListNode();
            newh->val=sum3%10;
            sum3=sum3/10;
            h3->next=newh;
            h3=newh;
        }
        return temp;

        
    }

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> v;
        // map<pair<int,int>,int> when;
        int x,y;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            v.push_back({x,y});
        }
        
    }
}
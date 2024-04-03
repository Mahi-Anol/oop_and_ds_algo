#include <iostream>
#include<vector>
using namespace std;

template<typename l>class sll{//singly link list
    public:
        l data;
        sll *next;
        sll():next(nullptr){};
        sll(l data):data(data),next(nullptr){}
        void add_node(sll<l>& next){

            this->next=&next;
        };
};
template<typename l> void printsll(sll<l> *head){
    while(head!=nullptr)
    {
        if(head->next==nullptr)cout<<head->data<<endl;
        else cout<<head->data<<"->";
        head=head->next;
    }
}
//template<typename l>sll<l>* take_input_back(){
//
//    int i=0;
//    sll<l>* head=nullptr;
//    sll<l>* tail=nullptr;
//
//    cout<<"If you want to stop anytime, type \"yes\"."<<endl;
//    cout<<"Enter Value of "<<i<<" th node : ";
//    l val;
//    cin>>val;
//    while(val!="yes")
//    {
//        sll<l> *newnode=new sll<l>(val);
//        if(head==nullptr)
//        {
//
//            head=newnode;
//            tail=newnode;
//        }
//        else
//        {
//
//            tail->next=newnode;
//            tail=newnode;
//        }
//        i++;
//        cout<<"Enter Value of "<<i<<" th node : ";
//        cin>>val;
//    }
//
//    return head;
//}

template<typename t>sll<t>* take_input_front(){

    int i=0;
    sll<t>* head=nullptr;
    sll<t>* tail=nullptr;

    cout<<"If you want to stop anytime, type \"yes\"."<<endl;
    cout<<"Enter Value of "<<i<<" th node : ";
    t val;
    cin>>val;
    while(val!="yes")
    {
        sll<t> *newnode=new sll<t>(val);
        if(head==nullptr)
        {

            head=newnode;
            tail=newnode;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }
        i++;
        cout<<"Enter Value of "<<i<<" th node : ";
        cin>>val;
    }

    return head;
}

int main()
{
    sll<string>node1("node1");
    sll<string>node2("node2");
    sll<string>node3("node3");
    node1.add_node(node2);
    node2.add_node(node3);
    sll<string> *head;
    head=&node1;
    printsll(head);


//    sll<string>* head2(take_input_back<string>());
//    printsll(head2);

    sll<string>* head3(take_input_front<string>());
    printsll(head3);
    return 0;
}

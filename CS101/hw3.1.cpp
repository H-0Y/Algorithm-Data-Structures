#include <stdlib.h>
#include <iostream>
using namespace std;

class Node{
    private:
        
    public:
        int retrieve() ;
        Node *next();
        Node *pre();
        Node(int m_subs=0,Node *next_node=NULL,Node *pre_node=NULL);
		int m_subs;
        Node *pre_node;
        Node *next_node;
};

Node::Node(int subs,Node *next,Node *prenode){

    m_subs=subs;
    next_node=next;
    pre_node=prenode;
    
}

int Node::retrieve() {
    return m_subs;
}

Node *Node::next() {
    return next_node;
}

Node *Node::pre() {
    return pre_node;
}

class LinkedList{
    private:
        
    public:
        LinkedList();
       // ~LinkedList();
        Node *head() const;
        void push_front(int subs,int layers);
        void push_tail( int subs );
        int front() const;
        Node *tail() const;
        bool empty() const;
        int pop_front();
        void show();
        int count(LinkedList &L,int m,int n) const;
        void erase(Node *n);
        void next_ptr();
        int currentsubs();
        int size() const;
        Node *current_ptr();
		Node *list_tail;
	    Node *list_head;
        Node *list_current;
        int length;


};

class underflow{

};

void LinkedList::erase(Node *n){
    Node *deleteptr=n;
    if(n->next_node!=nullptr&&n->pre_node!=nullptr){
        n->pre_node->next_node=n->next_node;
         n->next_node->pre_node=n->pre_node;
        delete deleteptr;
    }
    else if(n->pre_node==nullptr&&n->next_node!=nullptr){
        list_head=n->next_node;
        n->next_node->pre_node=nullptr;
        delete deleteptr;

    }
    else if(n->next_node==nullptr&&n->pre_node!=nullptr){
        list_tail=n->pre_node;
        n->pre_node->next_node=nullptr;
        delete deleteptr;
    }
    else{
        list_tail=nullptr;
        list_head=nullptr;
        delete deleteptr;
    }
    length--;
}

Node *LinkedList::tail() const{
    return list_tail;
}


void LinkedList::push_tail(int subs){
     if(length==0){
        Node *new_node=new Node(subs,NULL,NULL);
        list_current=new_node;
        list_head=new_node;
        list_tail=new_node;
        length++;
    }
    else{
        Node *new_node=new Node(subs,NULL,list_tail);
        list_current=new_node->pre_node;
        list_current->next_node=new_node;;
        list_tail=new_node;
        length++;
    }
}

LinkedList::LinkedList():list_head(NULL){
    length=0;
}

Node *LinkedList::head() const{
    return list_head;
}

bool LinkedList::empty() const{
    return (list_head==NULL);
}

int LinkedList::size() const{
    return length;
}

int LinkedList::front() const {
    if(empty()){
        throw underflow();
    }

    return head()->retrieve();
}

int LinkedList::pop_front(){
    if(empty()){
        throw underflow();
    }
    int e= front();
   Node *ptr=list_head;
   list_head=list_head->next();
   delete ptr;
   return e;
}

int main(){
    LinkedList aaa;
    long n,nums;
    cin>>n;

    int *pp=new int[2*n]();
    for(long i=0;i<2*n;i++){
        cin>>pp[i];
    }
    for(int k=n;k<2*n;k++){
                aaa.push_tail(pp[k-n]);
                long count=0;
                for(Node *p=aaa.list_head;p!=nullptr;p=p->next_node){
                    if(p->m_subs-pp[k]>0){
                        p->m_subs=p->m_subs-pp[k];
                        count+=pp[k];
                    }
                    else if(p->m_subs-pp[k]<=0){
                        count+=p->m_subs;
                        aaa.erase(p);
                    }
                }
                printf("%ld ",count);
        
    }

    /*long *p=new long[2*n]();
    for(long i=0;i<2*n;i++){
        cin>>p[i];
    }
    for(long k=n;k<2*n;k++){
        long count=0;
        for(long i=0;i<k-n+1;i++){
            if(p[i]-p[k]>0){
                p[i]=p[i]-p[k];
                count+=p[k];
            }
            else if(p[i]-p[k]<=0&&p[i]!=0){
                count+=p[i];
                p[i]=0;
            }
            else if(p[i]==0){
                continue;
            }
             //printf("%d ",count);
        }
        printf("%ld ",count);
    }
    */
}
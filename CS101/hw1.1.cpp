#include <stdlib.h>
#include <iostream>
using namespace std;

class Node{
    public:
        int element;
        Node *next_node;
    public:
        Node(int element=0,Node *next_node=nullptr);

};

Node::Node(int e,Node *n):
    element(e),
    next_node(n){
    
}

int Node::retrieve() const{
    return element;
}

Node *Node::next() const{
    return next_node;
}

class LinkedList{
    private:
        Node *list_head;
        Node *list_current;
        int length;
    public:
        LinkedList();
       // ~LinkedList();
        Node *head() const;
        void push_front(int n);
        int front() const;
        bool empty() const;
        int pop_front();
        void show();
        int count(LinkedList &L,int m,int n) const;
        void erase(Node *n);
        void next_ptr();
        int current();
        int size() const;
        Node *current_ptr();


};

class underflow{

};

void LinkedList::push_front(int n){
    Node *new_node=new Node(n,head());
    list_head=new_node;
    list_current=list_head;
    length++;
}

LinkedList::LinkedList():list_head(nullptr){
    length=0;
}

Node *LinkedList::head() const{
    return list_head;
}

bool LinkedList::empty() const{
    return (list_head==nullptr);
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

void LinkedList::show(){
    int node_count=0;
    Node *ptr;
    Node *p=list_head->next_node;
    for(ptr=list_head;node_count<=length;ptr->next_node){
        printf("%d",p->element);
        p=p->next_node;
        node_count++;
    }
    printf("%d",node_count);
}

void LinkedList::erase(Node *n){
        Node *ptr=n;
            if(ptr->next_node!=nullptr){
                Node *deleteptr;
                    deleteptr=ptr->next_node;
                    ptr->next_node=ptr->next()->next();
                    delete deleteptr;
            }
            else{
                ptr->next_node=list_head;
                Node *deleteptr;
                    deleteptr=ptr->next_node;
                   ptr->next_node=ptr->next()->next();
                    delete deleteptr;
            }
        
    next_ptr();
    
    length--;
                
       
}

void LinkedList::next_ptr(){
    if(list_current->next_node==nullptr){
        list_current->next_node=list_head;
    }
    else{
    list_current=list_current->next_node;
    }
}

int LinkedList::current(){
   if(list_current->next_node==nullptr){
       list_current->next_node=list_head;
   }
    
    return (list_current->element);
    
}

Node *LinkedList::current_ptr(){
    return list_current;
}


int main(){
   LinkedList aaa;

  int m,n,i=1;
  scanf("%d %d",&m,&n);
    //aaa.show();
        for(int i=m;i!=0;i--){

            aaa.push_front(i);
        }
    while(m>1){
        for( i=0;i<n;i++){
            //cout<<aaa.current()<<endl;
   
             if(i==n-2){
                aaa.erase(aaa.current_ptr()); 
                n--;
                m--;
                i=0;   
                break;

            }
            else{
            aaa.next_ptr();
            }
            
            
        }
    }
    //printf("helloworld");
    cout<<aaa.current()+1<<endl;
    return 0;
}
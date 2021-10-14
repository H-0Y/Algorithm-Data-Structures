#include <stdlib.h>
#include <iostream>
using namespace std;

class Node{
    private:
        
    public:
        int retrieve() ;
        Node *next();
        Node *pre();
        Node(int m_subs=-5,int m_layers=0,Node *next_node=NULL,Node *pre_node=NULL);
		int m_subs;
        int m_layers;
        Node *pre_node;
        Node *next_node;
};

Node::Node(int subs,int layers,Node *next,Node *prenode){

    m_subs=subs;
    m_layers=layers;
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
        void push_tail( int subs, int layers );
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



Node *LinkedList::tail() const{
    return list_tail;
}


void LinkedList::push_tail(int subs,int layers){
     if(length==0){
        Node *new_node=new Node(subs,layers,NULL,NULL);
        list_current=new_node;
        list_head=new_node;
        list_tail=new_node;
        length++;
    }
    else{
        Node *new_node=new Node(subs,layers,NULL,list_tail);
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

void LinkedList::show(){
    int output=0;
    int output2=list_current->m_subs;
    for(Node *p=list_head;p!=NULL;p=p->next_node){
        output+=p->m_layers;
    }
    printf("%d ",output);
}

void LinkedList::erase(Node *n){
        Node *ptr=n;
            if(ptr->next()!=NULL){
                Node *deleteptr;
                deleteptr=ptr->next();
                ptr->next_node=ptr->next_node->next_node;
                delete deleteptr;
            }
            else{
                ptr->next_node=list_head;
                Node *deleteptr;
                deleteptr=ptr->next_node;
                ptr->next_node=ptr->next_node->next_node;
                delete deleteptr;
            }
        
    next_ptr();
    
    length--;
                
       
}

void LinkedList::next_ptr(){
    if(list_current->next()==NULL){
        list_current->next_node=list_head;
    }
    else{
    list_current=list_current->next();
    }
}

int LinkedList::currentsubs(){
   if(list_current->next()==NULL){
       list_current->next_node=list_head;
   }
    
    return (list_current->m_subs);
    
}

Node *LinkedList::current_ptr(){
    return list_current;
}

void reaction(LinkedList &a,int **aa){
    if(aa[a.list_current->retrieve()][a.list_current->next_node->retrieve()]!=-1&&a.list_current->m_layers!=0&&a.list_current->next_node->m_layers!=0){
        if(a.list_current->m_subs==a.list_current->next_node->m_subs){
            a.list_current->next_node->m_layers=a.list_current->m_layers+a.list_current->next_node->m_layers;
            a.list_current->m_layers=0;
        }
        else {
            if(a.list_current->m_layers<a.list_current->next_node->m_layers){
                        a.list_current->m_subs=aa[a.list_current->retrieve()][a.list_current->next_node->retrieve()];
                        a.list_current->next_node->m_layers=a.list_current->next_node->m_layers-a.list_current->m_layers;   
            }  
            else{
                        a.list_current->m_layers=a.list_current->m_layers-a.list_current->next_node->m_layers;
                        a.list_current->next_node->m_subs=aa[a.list_current->retrieve()][a.list_current->next_node->retrieve()];
                }     
            }
                
        }
    else{
        return;
    }
}


int main(){
    int subs,rules,ops;
    int a,b;
    LinkedList aaa;
    scanf("%d %d %d",&subs,&rules,&ops);

    int *p = new int[3*rules]();
    for(int i=0;i<3*rules;i++){
        cin>>p[i];
    }

    int **swp;      
	swp=new int*[rules];
	for(int i=0;i<rules;i++)
	swp[i]=new int[rules];
    for(int i=0;i<rules;i++){
        for(int j=0;j<rules;j++){
            swp[i][j]=-1;
        }
    }
    for(int i=0;i<3*rules;i+=3){        //give the value
        swp[p[i]][p[i+1]]=p[i+2];
        swp[p[i+1]][p[i]]=p[i+2];
    }
    Node *newnode;
    for(int i=0;i<ops;i++){
        scanf("%d %d",&a,&b);
        if(a!=-1){
            aaa.push_tail(a,b);
                while(aaa.list_current!=aaa.list_tail){
                    if(swp[aaa.list_current->m_subs][aaa.list_current->next_node->m_subs]==-1){
                        aaa.list_current=aaa.list_current->next_node;
                        //aaa.list_current->pre_node=aaa.list_current->pre_node->next_node;
                    }
                    else{ 
                        reaction(aaa,swp);
                        aaa.list_current=aaa.list_current->pre_node;
                    }
                    /*printf("\nbegin:\n");
                    for(newnode=aaa.list_head;newnode!=NULL;newnode=newnode->next_node){
                        printf("%d %d\n",newnode->m_subs,newnode->m_layers);
                    }
                    printf("end!\n");*/
                }                   
            
        }
        else{
            aaa.list_head->m_layers-=b;
        }
        //aaa.show();
    }
    aaa.show();
}
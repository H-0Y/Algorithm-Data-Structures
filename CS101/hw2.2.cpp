#include <stdlib.h>
#include <iostream>
using namespace std;

template<typename Type>
class Node{
    public:
        Type element;
        int next_node;

};


template<typename Type>
class Single_list{
    public:
    int m_size;
    int list_head;
    int list_tail;
    int list_current;
    Node<Type> *node_pool;
    Single_list(int =0);
    int size() const; 
    void push_back(Type const & );
    void show();
    static const int NULLPTR;
};

template<typename Type>
Single_list<Type>::Single_list(int n):
list_head(NULLPTR),
list_tail(NULLPTR),
list_current(NULLPTR),
m_size(0),
node_pool(new Node<Type>[n]){
    
}

template<typename Type>
int Single_list<Type>::size() const{
    return m_size;
}

template<typename Type>
void Single_list<Type>::push_back(Type const &obj){
    if(m_size==0){
        Node *new_node=new Node(obj,NULL);
        list_head=new_node;
        list_tail=new_node;
        list_current=new_node;
        m_size++;
    }
    else{
    Node *new_node=new Node(obj,NULL);
    list_tail->next_node=new_node;
    list_tail=new_node;
    m_size++;
    }
}

template<typename Type>
void Single_list<Type>::show(){
    Node *ptr;
    Node *p=list_head->next_node;
    for(ptr=list_head;ptr!=list_tail;ptr->next_node){
        printf("%d",p->element);
        p=p->next_node;
    }
}


template<typename Type>
class Tree{
    private:

    public:
        Type signal;
        Tree *parent_node;
        Single_list <Tree *> children;
        Tree(Type const & = Type(),Tree * = nullptr);
        Tree *parent() const;
        int degree() const;
        bool is_leaf() const;
        Tree *child(int n) const;
        bool is_root() const;
        void insert(Type const &);
};

template <typename Type>
Tree<Type>::Tree(Type const &obj, Tree *p):
signal(obj),
parent_node(p){

}

template<typename Type>
int Tree<Type>::degree() const{
    return children.size();
}

template<typename Type>
bool Tree<Type>::is_leaf() const{
    return(degree()==0);
}

template<typename Type>
bool Tree<Type>::is_root() const{
    return (parent()==nullptr);
}

template<typename Type>
void Tree<Type>::insert(Type const & obj){
    children.push_back(new Tree(obj,this));
}

template<typename Type>
Tree<Type> *Tree<Type>::child(int n) const{
    if(n<0||n>=degree()){
        return nullptr;
    }
    Node *ptr=children->list_head;

    for(int i=1;i<n;++i){
        ptr=ptr->next_node;
    }
    return ptr->element;
}

int main(){
    Tree<int> aaa;
    int totalNodes;
    int Nodes;
    cin>>totalNodes;
    for(int i=0;i<totalNodes;i++){
        cin>>Nodes;
        if(Nodes==0){
            continue;
        }
        else{
            for(int j=0;j<Nodes;j++){
                int order,decay;
                cin>>order,decay;
                aaa.insert(decay);
            }
        }
        aaa.children.list_current=aaa.children.list_current->next_node;
    }

    aaa.children.show();
}

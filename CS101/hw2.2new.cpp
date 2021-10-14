#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;


class Node{
    public:
        int m_decay;
        int m_value;
        Node *parent;
        Node *children;
        Node *brother;
    public:
        Node(int value=0,int decay=0,Node *parent=nullptr, Node *children=nullptr, Node *brother=nullptr);

};

Node::Node(int e,int decay,Node *p,Node *c, Node *b):
    m_value(e),
    m_decay(decay),
    parent(p),
    children(c),
    brother(b){
    
}

class Tree{
    public:
        int count=0;
        int count2=0;
        int minnum=0;
        Node *pRoot;
        Tree();
        Tree(int value,int decay);
        int m_size; 
        void push(int parentvalue,int childrenvalue,int decay);
        void PushBrother(Node *brotherNode,int brotherValue,int decay);
        Node *Search(Node *pNode,int value);
        void postorder(Node *pNode);
        void replace(int value);
        void output(Node *pNode);
        void pass(Node *pNode);
};

Tree::Tree(){
    pRoot=NULL;
}

Tree::Tree( int value,int decay){
    pRoot=new Node(value,decay,NULL,NULL,NULL);
    if(pRoot==NULL){
        return;
    }
}

Node *Tree::Search(Node *pNode,int value){
    if(pNode==NULL){
        return NULL;
    }
    if(pNode->m_value==value){
        return pNode;
    }
    if(pNode->children==NULL&&pNode->brother==NULL){
        return NULL;
    }
    else{
        if(pNode->children!=NULL){
            Node *temp=Search(pNode->children,value);
            if(temp!=NULL){
                return temp;
            }
            else{
                return Search(pNode->brother,value);
            }
        }
        else{
            return Search(pNode->brother,value);
        }
    }
}

void Tree::push(int parentvalue,int childrenValue,int decay){
    if(pRoot==NULL){
        return;
    }

    Node *pfindNode=Search(pRoot,parentvalue);
    if(pfindNode==NULL){
        return;
    }
    if(pfindNode->children==NULL){
        Node *new_node=new Node(childrenValue,decay);
        pfindNode->children=new_node;
        new_node->parent=pfindNode;

        return;
    }
    else{
        PushBrother(pfindNode->children,childrenValue,decay);
        return;
    }
}

void Tree::PushBrother(Node *BrotherNode,int brotherValue,int decay){
    if(BrotherNode->brother!=NULL){
        PushBrother(BrotherNode->brother,brotherValue,decay);
        return;
    }
    else{
        Node *new_node=new Node(brotherValue,decay);
        BrotherNode->brother=new_node;
        new_node->parent=BrotherNode->parent;
        return;
    }
}

void Tree::postorder(Node *pNode){
    if(pNode==NULL){
        return;
    }
    postorder(pNode->children);
    cout<<" "<<pNode->m_value<<" ";
    postorder(pNode->brother);
}

void Tree::replace(int value){
    pRoot->m_decay=value;
}

void Tree::output(Node *pNode){
    if(pNode==NULL){
         return;
    }
    
    output(pNode->children);
    if(pNode->children==NULL){
        count=0;
    }
    if(pNode->children!=NULL&&pNode->children->brother!=NULL){
         pNode->m_decay=pNode->m_decay+max(pNode->children->m_decay,pNode->children->brother->m_decay);
     } 
    count+=pNode->m_decay;
    if(count>pRoot->m_decay){
            count=pNode->m_decay;
            minnum++;
            pNode->m_decay=0;
    }

    //printf(" " "%d" " ",count);
    //printf("*******%d*******\n",minnum);  
    output(pNode->brother);
}

void Tree::pass(Node *pNode){

}

int main(){
    Tree *aaa=new Tree(1,0);
    int inistrength;
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
                scanf("%d %d",&order,&decay);
                aaa->push(i+1,order,decay);
            }
        }
    }
    cin>>inistrength;
    aaa->replace(inistrength);
    aaa->output(aaa->pRoot);
    printf("%d",aaa->minnum-1);
}
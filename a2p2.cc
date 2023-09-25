#include <string>
#include <vector>
#include <cassert>

#include "a2p2.h"

using namespace std;

Node* makeList (const std::vector<std::string> v) {
    Node* next = new Node{};
    next->next = nullptr;      
    if(!v.size()){
        next = nullptr;
        return next;
    }  
    for(int i = v.size()-1; i >0; i--){ 
        next->val = v[i];   
        Node* cur = new Node{};
        cur->next = next;   
        next = cur;
    }
    if(v.size())next->val = v[0];
    return next;
}

std::string list2string (const Node *first) {
    string s = "";
    while(first){
        s.append(first->val);
        if(first->next)s.append(" ");
        first = first->next;
    }
    
    return s;
}

std::string pair2sortedString (const Node *p1, const Node *p2) {
    assert(p1 != nullptr && p2 != nullptr);

    string s;

    if(p1->val < p2->val || p1->val == p2->val){
        s.append(p1->val);
        s.append(" ");
        s.append(p2->val);
    }
    else{
        s.append(p2->val);
        s.append(" ");
        s.append(p1->val);
    }
    return s;
}

Node* sortPair (Node *p1, Node *p2) {
    assert(p1 != nullptr && p2 != nullptr);

    if(p1->val > p2->val){
        p2->next = p1;
        p1->next = nullptr;
        return p2;
    }
    else{
        p1->next = p2;
        p2->next = nullptr;
        return p1;
    }
}

Node* makeSortedPairList (const std::string s1, const std::string s2) {
    Node* first = new Node{};
    Node* second = new Node{};

    if(s1 < s2){
        first->val = s1;
        second->val = s2;
    }
    else{
        first->val = s2;
        second->val = s1;
    }
    first->next = second;
    second->next = nullptr;
    return first;
}

Node* append (Node *p1, Node *p2) {
    if(p1 == nullptr){
        return p2;
    }
    if(p2 == nullptr){
        return p1;
    }

    Node* node = p1;
    while(node->next){
        node = node->next;
    }
    node->next = p2;
    return p1;
}

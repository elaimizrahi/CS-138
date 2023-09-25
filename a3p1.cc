#include "a3p1.h"

#include <string>
#include <cassert>

using namespace std;

// provided for you
void initStew(Stew& q) {
    // no preconditions
    // implementation
    q.first = nullptr;
    q.last = nullptr;
    // postconditions
    assert(isEmpty(q));
    assert(isValidStew(q));
}

// provided for you
bool isEmpty(const Stew& q) {
    // no preconditions
    // note: if we called isValidStew(q) here we would likely get
    // stuck in an infinite loop, because isValidStew(q) might
    // call isEmpty(q)
    return (q.first == nullptr) && (q.last == nullptr);
}

// @TODO: define what a wellformed node looks like
// Note that simply returning true will pass some tests.
// Similarly, simply triggering an assertion will pass some tests.
// That is inherent in any procedure that returns bool.
// The challenge is to pass all the tests.
bool isValidNode(const Node& n) {
    // either trip an assertion or return true
    // never return false
    assert(n.next != &n);    
    assert(n.prev != &n);  
    if(n.next != nullptr && n.prev != nullptr){
        assert(n.next != n.prev);
    } 
    // make this more interesting
    // no assertions tripped, so return true
    return true;
}

// @TODO: define what a wellformed stew looks like
// Note that simply returning true will pass some tests.
// Similarly, simply triggering an assertion will pass some tests.
// That is inherent in any procedure that returns bool.
// The challenge is to pass all the tests.
bool isValidStew(const Stew& s) {
    // either trip an assertion or return true
    // never return false
    if(isEmpty(s)){
        return true;
    }
    if(s.first != nullptr){
        assert(s.last != nullptr);
    }
    if(s.last != nullptr){
        assert(s.first != nullptr);
    }

    Node *node = s.first;

    while(node->next != nullptr){
        assert(node->next != node);        
        assert(node->prev != node);    
        node = node->next;
    }
    assert(node == s.last);

    Node *secondnode = s.last;

    while(secondnode->prev != nullptr){
        assert(secondnode->prev != secondnode);        
        assert(secondnode->next != secondnode);    
        secondnode = secondnode->prev;
    }
    assert(secondnode == s.first);
    // make this more interesting
    // no assertions tripped, so return true
    return true;
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
void addFront(Stew& q, string val) {
    // preconditions
    assert(isValidStew(q));

    // implementation
    Node *newnode = new Node{};
    Node *firstnode = q.first;
    newnode->val = val;    
    if(isEmpty(q)){
        newnode->next = nullptr;
        newnode->prev = nullptr;
        q.first = newnode;
        q.last = newnode;
        delete firstnode;
    }
    else{
        newnode->next = firstnode;
        newnode->prev = nullptr;
        firstnode->prev = newnode;
        q.first = newnode;
    }

    // postconditions
    assert(isValidStew(q));

}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
void addBack(Stew& q, string val) {
    // preconditions
    assert(isValidStew(q));
    // implementation
    Node *newnode = new Node{};
    newnode->val = val;
    if(isEmpty(q)){
        newnode->next = nullptr;
        newnode->prev = nullptr;
        q.first = newnode;
        q.last = newnode;    
    }
    else{    
        Node *lastnode = q.last;
        newnode->next = nullptr;
        newnode->prev = lastnode;
        lastnode->next = newnode;
        q.last = newnode;
    }
    // postconditions
    assert(isValidStew(q));
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
void leaveFront(Stew& q) {
    // preconditions
    assert(isValidStew(q));
    assert(!isEmpty(q));
    // implementation
    Node *node = q.first;
    Node *nextnode = node->next;

    q.first = nextnode;
    if(nextnode != nullptr){
        nextnode->prev = nullptr;
    }
    else{
        q.last = nextnode;
    }
    delete node;
    // postconditions
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
void leaveBack(Stew& q) {
    // preconditions
    assert(isValidStew(q));
    assert(!isEmpty(q));   
    // implementation
    Node *node = q.last;
    Node *prevnode = node->prev;

    q.last = prevnode;
    if(prevnode != nullptr){
        prevnode->next = nullptr;
    }
    else{
        q.first = prevnode;
    }
    delete node;
    // postconditions
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
string peekBack(const Stew& q) {
    // preconditions
    assert(!isEmpty(q));
    // implementation
    string s = q.last->val;
    // postconditions
    // return result
    return s; // so this stub compiles and runs
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
string peekFront(const Stew& q) {
    // preconditions
    assert(!isEmpty(q));
    // implementation
    string s = q.first->val;
    // postconditions
    // return result
    return s; // so this stub compiles and runs
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
string toString(const Stew& q, char direction) {
    // preconditions
    assert(isValidStew(q));
    // implementation
    string s;
    if(direction == 'f'){
        s = "[";
        Node *node = q.first;
        while(node != nullptr){
            s.append(node->val);
            if(node->next == nullptr){
                s.append("]");
                return s;
            }
            s.append(", ");
            node = node->next;
        }
        s.append("]");
    }
    else if (direction == 'r'){
        s = "[";
        Node *node = q.last;
        while(node != nullptr){
            s.append(node->val);
            if(node->prev == nullptr){
                s.append("]");
                return s;
            }
            s.append(", ");
            node = node->prev;
        }
        s.append("]");

    }
    else{
        return "Error, illegal direction: (k)";
    }
    // postconditions
    // return result
    return s; // so this stub compiles and runs
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
void nuke(Stew& q) {
    // preconditions
    assert(isValidStew(q));
    // implementation
    Node *node = q.first;
    while(node != nullptr){
        Node *nextnode = node->next;
        delete node;
        node = nextnode;
    }
    q.first = nullptr;
    q.last = nullptr;
    // postconditions
    assert(isEmpty(q));
}

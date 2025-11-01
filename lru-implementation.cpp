#include <bits/stdc++.h>
using namespace std;

// DLL Node
struct Node{
    int key;
    int value;
    Node * next;
    Node * prev;


    Node(int k, int v){
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
    }

};


class LRUCache{

public:
    int capacity;
    
    // Hasdmap with k : key, V: Node*
    unordered_map<int, Node* > mp;
    Node * head;
    Node* tail;


    LRUCache(int cap){
        this->capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;

    }



    int get(int key){

        if(mp.find(key)!=mp.end()){

            Node * targetNode = mp[key];
            remove(targetNode);
            add(targetNode);
            return targetNode->value;

        }

        return -1;

    }


    void put(int key, int val){

        if(mp.find(key)!=mp.end()){
            Node * node = mp[key];
            remove(node);
            add(node);
        }else{

            if(mp.size() >= capacity){
                Node * nodeToRemove = tail->prev;
                remove(nodeToRemove);
                mp.erase(nodeToRemove->key);
                cout<<"Removed :" <<nodeToRemove->key<<endl;
                delete(nodeToRemove); 
            }


            Node * newNode = new Node(key, val);
            mp[key] = newNode;
            
            add(newNode);

        }

    }


    void add(Node *node){

        Node* temp = head->next;
        head->next = node;
        temp->prev = node;
        node->next = temp;
        node->prev = head;
    }


    void remove(Node * node){
        Node * prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
};


int main(){
    LRUCache cache(3);
  
    cache.put(1, 1); 
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout  << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}


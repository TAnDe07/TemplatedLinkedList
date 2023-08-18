//
// Created by tanad on 2/9/2022.
//

#ifndef PROJECT1_LINKEDLIST_H
#define PROJECT1_LINKEDLIST_H

#endif //PROJECT1_LINKEDLIST_H

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// part 1 //

template<typename T>
class LinkedList {
    //public
public:
    struct Node {
    public:
        T data; //stores current node data
        Node *next; //store next node data
        Node *prev; //stores previous node data
    };

    //constructor: sets Node and count to default value
    LinkedList() {
        count1 = 0; //tracks number of data in list
        head = nullptr; //default value for head
        tail = nullptr; //default value for tail

    }

    //copy constructor: creates a copy of list
    LinkedList(const LinkedList<T> &list) {
        unsigned int temp = 0; //tracks how many data were added

        //gets the data of each node and adds it as this copy's head
        while(temp >= 0 && temp <= count1) {
            AddHead(list.GetNode(temp)->data);
            temp--;
        }
        temp = list.count1 - 1;

        //gets the data of each node and adds it as this copy's tail
        while(temp < list.count1) {
            AddTail(list.GetNode(temp)->data);
            temp++;
        }

        count1 /= 2;

        this->count1 = list.count1; //sets this copy's count to the original count

    }

    //assignment operator
    LinkedList<T>& operator=(const LinkedList<T> &rhs) {

        unsigned int temp = 0; //tracks how many data were added
        unsigned int temp2 = rhs.count1; //tracks rhs data count
        count1 = 0; //resets count to default value

        //gets the data of each rhs node and adds it to this tail
        while(temp < temp2) {
            AddTail(rhs.GetNode(temp)->data);
            temp++;
        }

        temp = rhs.count1 - 1;
        count1 = 0;

        //gets the data of each rhs node and adds it to this head
        while(temp >= 0 && temp <= temp2) {
            AddHead(rhs.GetNode(temp)->data);
            temp--;
        }

        this->count1 = temp2;


        return *this; //return this pointer
    }

    //destructor
    ~LinkedList() {
        Node *currentHead;

        //deletes current head and sets the pointer after current head equal to head
        while (head != nullptr && head->next != nullptr) {
            currentHead = head->next;
            delete head;
            head = currentHead;

        }

        if(tail != nullptr) {
            delete tail; //deletes tail pointer
        }
        head = nullptr; //sets head pointer to default value
        tail = nullptr; //sets tail pointer to default value
        count1 = 0; //sets count to default value
    }
    //public

    //private
private:
    Node *head = nullptr; //tracks first data of list
    Node *tail = nullptr; //tracks last data of list
    unsigned int count1; //tracks number of data in list
    //private

    //public
public:
    //Create a new Node at the front of the list to store the passed in parameter.
    void AddHead(const T &data) {
        Node *currentData = new Node;
        currentData->data = data; //stores current value

        //if head and tail are null, sets head and tail equal to data, sets pointer next to data and pointer before data to nullptr
        if (head == nullptr || tail == nullptr) { //change
            head = currentData;
            head->next = nullptr;
            head->prev = nullptr;
            tail = currentData;
        }
        // if head is not null, sets pointer before head equal to data and sets head equal to the pointer after data
        else {
            head->prev = currentData;
            currentData->next = head;
            head = currentData;
        }
        head->prev = nullptr; //sets current head previous pointer equal to nullptr
        count1++; // increments count
    }

    //Create a new Node at the end of the list to store the passed in parameter.
    void AddTail(const T &data) {
        Node *currentData = new Node;
        currentData->data = data;

        //if tail and head are null, sets head and tail equal to data and sets pointer before data and pointer after data to nullptr
        if (tail == nullptr || head == nullptr) {
            tail = currentData;
            tail->next = nullptr;
            tail->prev = nullptr;
            head = currentData;
        }
        //if tail is not null, sets pointer after tail equal to data, and sets tail equal to the pointer before data
        else {
            tail->next = currentData;
            currentData->prev = tail;
            tail = currentData;
        }
        tail->next = nullptr;  //sets current tail next pointer equal to nullptr
        count1++; //increments count
    }

    //Given an array of values, insert a node for each of those at the beginning of the list, maintaining the original order.
    //(same as AddHead, but adds each element of an array to head, element by element)
    void AddNodesHead(const T *data, unsigned int count) {
        //adds the array to head element by element
        for (int i = int(count - 1); i >= 0; i--) {
            AddHead(data[i]);
        }
    }

    // Given an array of values, insert a node for each of those at the end of the list, maintaining the original order.
    //(same as AddTail, but adds each element of an array to tail, element by element)
    void AddNodesTail(const T *data, unsigned int count) {
        //adds array to tail element by element
        for (int i = 0; i < (int) count; ++i) {
            AddTail(data[i]);
        }
    }

    //Iterator through all the nodes and print out their values, one a time.
    void PrintForward() const {
        Node *ptr1; //stores current node's pointer

        //prints head of linkedList
        cout << head->data << endl;

        //if tail is not null and head is null, starts from tail, goes to node after the previous node printed, prints that node
        if (tail != nullptr && head == nullptr) {
            ptr1 = tail;
            for (unsigned j = count1 - 1; j > 0; j--) {
                for (unsigned int i = j; i > 1; i--) {
                    ptr1 = ptr1->prev;
                }
                cout << ptr1->data << endl;
                ptr1 = tail;
            }
        }
        //if head is not null, start from head and print normally
        else {
            ptr1 = head->next;
            for (unsigned int j = count1 - 1; j > 0; j--) {
                cout << ptr1->data << endl;
                ptr1 = ptr1->next;
            }
        }
    }

    //Exactly the same as PrintForward, except completely the opposite.
    void PrintReverse() const {
        Node *ptr1; //stores current node's pointer

        // if head is not null, starts from head, goes to node before the previous node printed, prints that node
        if (head != nullptr) {
            ptr1 = head;
            for (unsigned j = count1; j > 0; j--) {
                for (unsigned int i = j; i > 1; i--) {
                    ptr1 = ptr1->next;
                }
                cout << ptr1->data << endl;
                ptr1 = head;
            }
        }
    }

    //return number of data in linkedList
    unsigned int NodeCount() const {
        return count1;
    }

    // part 2 //

    //return head of linkedList
    Node *Head() {
        return head;
    }

    //return const Head of linkedList
    const Node *Head() const {
        return head;
    }

    //return tail of linkedList
    Node *Tail() {
        return tail;
    }

    //return const tail of linkedList
    const Node *Tail() const {
        return tail;
    }

    // Given an index, return a pointer to the node at that index. Throws an exception of type out_of_range if the index is out of range. Const and non-const versions.
    Node *GetNode(unsigned int index) {
        Node *ptr;
        Node* ptr2;

        //if index is larger than size of linkedList, or if linkedList is empty
        if (index >= count1 || index < 0) {
            throw out_of_range("Index out of Range");
        }
        //goes through list until it reached index, then return pointer to that index
        else {
            for (unsigned i = 0; i < index + 1; ++i) {
                if(i ==0) { //if first index, returns head
                    ptr = head;
                }
                else { //goes through all the nodes until it reaches the index
                    ptr2 = ptr->next;
                    ptr = ptr2;
                }
            }
            return ptr;
        }
    }

    // same thing as previous but read-only
    const Node *GetNode(unsigned int index) const {
        if (index >= count1 || index < 0) {
            throw out_of_range("Index out of Range");
        }
        else {
            Node *ptr = head;
            Node* ptr2;

            for (int i = 0; i < (int)index + 1; ++i) {
                if(index == 0) {
                    ptr = head;
                }
                else if(index == 1) {
                    ptr = head->next;
                }
                else {
                    ptr2 = ptr->next;
                    ptr = ptr2;
                }
            }
            return ptr;
        }
    }

    //Overloaded subscript operator. Takes an index, and returns data from the index-th node. Throws an out_of_range exception for an invalid index. Const and non-const versions.
    T &operator[](unsigned int index) {
        int i = (int) count1;

        // if index is greater than count1, throws exception
        if (i < (int)index) {
            throw out_of_range("Index out of Range");
        }
        //goes through list until it reached index, then return data of that index
        else {
            Node *ptr;
            Node* ptr2;
            ptr = head;
            for (i = 0; i < (int)index; ++i) {
                if(i == 0) { //if first index, returns data of head
                    ptr2 = head;
                }
                else { //otherwise, goes through all the nodes until it reaches index, and returns data of that index
                    ptr2 = ptr->next;
                    ptr = ptr2;
                }
            }
            return ptr->data; //return the data
        }

    }

    //Find the first node with a data value matching the passed in parameter, returning a pointer to that node. Returns nullptr if no matching node found.
    Node* Find(const T &data) {
        Node *ptr;
        Node* ptr2; //stores node of current index
        ptr = head;

        for (int i = 0; i < (int)count1; ++i) {
            if(i == 0) { //if at first index, node is head
                ptr2 = head;
            }
            else { //goes through all the nodes
                ptr2 = ptr->next;
                ptr = ptr2;
            }
            // if it reaches a data that matches data of a node, returns the node of that data
            if (ptr->data == data) {
                return ptr;
            }
        }
        return nullptr; //returns nullptr if there are no data of nodes that match data

    }

    //same thing as previous but read-only
    const Node *Find(const T &data) const {
        Node *ptr;
        Node* ptr2;
        ptr = head;

        for (int i = 0; i < (int)count1; ++i) {
            if(i == 0) {
                ptr2 = head;
            }
            else {
                ptr2 = ptr->next;
                ptr = ptr2;
            }
            if (ptr->data == data) {
                return ptr;
            }
        }
        return nullptr;
    }

    //Find all nodes which match the passed in parameter value, and store a pointer to that node in the passed in vector.
    void FindAll(vector<Node *> &outData, const T &value) const {
        Node *ptr;
        Node* ptr2; //stores current node
        ptr = head;

        for (int i = 0; i < (int)count1; ++i) {
            if(i == 0) { //if at first index, current node is head
                ptr2 = head;
            }
            else { //goes through list node by node
                ptr2 = ptr->next;
                ptr = ptr2;
            }
            // adds all node to matching value to vector
            if (ptr->data == value) {
                outData.push_back(ptr);
            }
        }
    }

    // part 3 //

    //Given a pointer to a node, create a new node to store the passed in value, after the indicated node.
    void InsertAfter(Node* node, const T& data) {
        int nodeCount = 0;
        bool TorF = false;

        //checks to see if node exists in linkedList
        while (TorF == false) {
            if (Find(node->data) == node) {
                TorF = true;
            }
            nodeCount++;
        }

        //if node exists inserts data after node
        if (TorF == true) {
            Node* temp = new Node; //stores data
            Node* before = node; //stores node before data (current node)
            Node* after = node->next; //stores node after data (node next to current node)

            //sets temp equal to data, data previous pointer to current node, and data next pointer to node after current node
            temp->data = data;
            temp->prev = before;
            temp->next = after;
            before->next = temp; //sets node next to node before to temp(data)
            after->prev = temp;  //sets node previous to node after to temp(data)
        }
        count1++;//increments count
    }

    //Ditto, except insert the new node before the indicated node.
    void InsertBefore(Node* node, const T& data) {
        int nodeCount = 0;
        bool TorF = false;

        //checks to see if node exists in linkedList
        while (TorF == false) {
            if (Find(node->data) == node) {
                TorF = true;
            }
            nodeCount++;
        }

        //if node exists, adds data before node
        if (TorF == true) {
            Node* temp = new Node; //stores data
            Node* before = node->prev; //stored node before data(node previous to current node)
            Node* after = node; //stores node after data(current node)

            //sets temp equal to data, data previous pointer to node before current node, and data next pointer to current node
            temp->data = data;
            temp->prev = before;
            temp->next = after;
            before->next = temp; //sets node next to node before to temp(data)
            after->prev = temp; //sets node previous to node after to temp(data)
        }
        count1++; //increments count
    }

    //Inserts a new Node to store the first parameter, at the index-th location.
    //Throws an out_of_range exception if given an invalid index.
    void InsertAt(const T& data, unsigned int index) {
        Node *node = nullptr;
        int temp = 0; //tracks if index is head or tail

        // if index is greater than count1, throws an exception
        if (index > count1) {
            throw out_of_range("Index out of range");
        }

        //gets node of index of where to insert data
        //if index  is zero, node will be head, so sets temp to 1 to indicate that
        if (index == 0) {
            temp = 1;
        }
        //if index is equal to count, node will be tail, so sets temp to 2 to indicate that
        else if (index == count1) {
            temp = 2;
        }
        //otherwise, looks for node of that index
        else {
            node = GetNode(index);
        }

        //if index is 0(temp is 1), adds data to head
        if (temp == 1) {
            AddHead(data);
        }
        //if index is count(temp is 2), adds data to tail
        else if (temp == 2) {
            AddTail(data);
        }
        // if both previous cases are false, and list is not empty, and node is not nullptr
        else if (node != nullptr && temp != 1 && temp != 2) {
            Node *temp = new Node; //create new node for data
            Node *before = node->prev; //stores node previous to current node
            Node *after = node; //stores current node

            //sets temp to data, data next to data to node after, and data previous to data to node before
            temp->data = data;
            temp->prev = before;
            temp->next = after;
            before->next = temp; //sets node next to node before to temp(data)
            after->prev = temp; //sets node to previous node to temp(data)
            count1++; //increments count
        }
    }

    // Overloaded equality operator. (Similar to comparing two arrays, just with non-contiguous data).
    bool operator==(const LinkedList<T>& rhs) {
        for (unsigned int i = 0; i < rhs.count1; ++i) {
            unsigned int temp = rhs.count1;
            T A_head = head->data; //stores list head data
            T B_head = rhs.head->data; //stores rhs head data
            bool equal = false; //checks if lists are equal or not

            //checks if each element of each list are equal, returns true if they are equal and false otherwise
            for (unsigned int j = 0; j < temp; ++j) {
                if (A_head == B_head) {
                    equal = true;
                    A_head = head->next->data;
                    B_head = rhs.head->next->data;
                }
                else {
                    equal = false;
                    return equal;
                }
            }
            return equal;
        }
    }

    //removes head of list, if successful returns true and false otherwise
    bool RemoveHead() {
        // if list is empty, returns false
        if (head == nullptr) {
            return false;
        }
        //removes current head, and sets data next to current head to head
        else {
            Node *temp = head;
            head = temp->next;
            Node *newHead = temp->next;
            if (newHead != nullptr){
                newHead->prev = nullptr;
            }
            delete temp;
            count1--; // decrements count
            return true; //returns true if successful
        }
    }

    //removes tail of list, if successful return true, otherwise return false
    bool RemoveTail() {
        //if list is empty return false
        if (tail == nullptr) {
            return false;
        }
        //removes current tail and set data previous to tail equal to tail
        else {
            Node* temp = tail;
            tail = temp->prev;
            Node* newTail = temp->prev;
            if (newTail != nullptr) {
                newTail->next = nullptr;
            }
            delete temp;
            count1--; //decrements count
            return true; //returns true if successful
        }

    }

    //removes data at an index
    bool RemoveAt(unsigned int index) {
        //if index is out of range, return false
        if (index >= count1) {
            return false;
        }
        //otherwise, gets node for current index and removes that node by setting next pointer of data before that node to data after that node, and vice-versa
        else {
            Node* temp = GetNode(index); //gets node of the current index and stores it
            Node* dataBefore = temp->prev; //stores node before current node
            Node* dataAfter = temp->next; //stores node after current node
            dataBefore->next = dataAfter; //next pointer of node before current node points to node after current node
            dataAfter->prev = dataBefore; //previous pointer of node after current node points to node before current node
            count1--; // decrements count
            delete temp; //deletes current node
            return true; // returns true if successful
        }
    }

    //removes all node containing data and returns how many instance were removed
    unsigned int Remove(const T& data) {
        Node* temp = head;
        Node* temp2;
        unsigned int instances = 0;

        for (unsigned int i = 0; i < count1; ++i) {
            temp2 = temp->next;

            //if data of current node is equal to data
            if (temp->data == data) {
                //if current node is head, removes head and sets head equal to next pointer
                if (temp == head) {
                    head = temp->next; //sets head equal to current head next node
                    Node* newHead = temp->next; //creates new node head and sets it equal to current head next node
                    newHead->prev = nullptr; //sets previous node of new head equal to nullptr
                    instances++; //increments instances
                }
                //if current node is tail, removes tail and sets tail equal to previous pointer
                else if (temp == tail) {
                    tail = temp->prev; //sets tail equal to current tail previous node
                    Node* newTail = temp->prev; //creates a new node tail and sets it equal to tail's previous node
                    newTail->next = nullptr; //sets next node of new tail to nullptr
                    instances++; //increments instances
                }
                //if previous cases are false, sets data before current data's next pointer equal to data after current data, and vice-versa
                else if (temp != head && temp != tail) {
                    Node* dataBefore = temp->prev; //stores current node's previous node
                    Node* dataAfter = temp->next; //stores current node's next node
                    dataAfter->prev = dataAfter; //sets next node's previous node equal to the node before current node
                    dataBefore->next = dataAfter; //sets previous node's next node equal to the node after the current node
                    instances++; //increments instances
                }
                delete temp;// delete current node
            }
            temp = temp2; //sets temp equal to next node
        }
        count1 = count1 - instances; //sets new count
        return instances; //returns number of instances
    }

    //destructor 2.0
    void Clear() {
        Node *currentHead = head;

        while (head != nullptr && head->next != nullptr) {
            currentHead = head->next;
            delete head;
            head = currentHead;
        }
        if(tail != nullptr) {
            delete tail;
        }
        head = nullptr;
        tail = nullptr;
        count1 = 0;
    }

    //prints forward recursively from node
    void PrintForwardRecursive(const Node* node) const {
        //base case, if node is null
        if(node == nullptr) {
            return;
        }
        else {
            cout << node->data << endl;
            PrintForwardRecursive(node->next);
        }
    }

    //prints reverse recursively form node
    void PrintReverseRecursive(const Node* node) const {
        //base case, if node is null
        if(node == nullptr) {
            return;
        }
        else {
            cout << node->data << endl;
            PrintReverseRecursive(node->prev);
        }

        return;
    }
    //public
};

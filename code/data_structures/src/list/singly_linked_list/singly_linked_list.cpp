// C++ program to print the reverse of a singly linked list
#include <iostream>

template<typename T>
class Node
{
private:
    T data;
    Node *next;
public:
    void print_reverse();
    void push(const T&); //lvalue
    void push(const T&&); //rvalue
    Node(const T&);
    Node(const T&&);
    ~Node();
};

template<typename T> Node<T>::Node(const T& data_) : data{data_}, next{nullptr}
{}
template<typename T> Node<T>::Node(const T&& data_) : data{data_}, next{nullptr}
{}

template<typename T> Node<T>::~Node()
{
 if(next) delete next;
}

template<typename T> void Node<T>::push(const T &data_)
{
 Node *newNode = new Node<T>{data_};
 Node *current_node = this;

 while(current_node->next != nullptr)
  current_node = current_node->next;

 current_node->next = newNode;
}
template<typename T> void Node<T>::push(const T &&data_)
{
 Node *newNode = new Node<T>{data_};
 Node *current_node = this;

 while(current_node->next != nullptr)
  current_node = current_node->next;

 current_node->next = newNode;
}

template<typename T> void Node<T>::print_reverse()
{
    if(next)
     next->print_reverse();
    std::cout << data << " ";
}


/*
This sample main instantiates a list of ints {4,3,2,1} using the Node<T>::push member function.
*/
int main()
{
    Node<int> *list{new Node<int>(4)};
    list->push(3);
    list->push(2);
    list->push(1);
    list->print_reverse();
    delete list;

    return 0;
}

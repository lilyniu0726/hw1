/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include "list"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  Node* in = new Node(1, 
    new Node(2,
    new Node(3,
    new Node(4,
    new Node(5, nullptr)
    )))
  );
  Node* odds = nullptr;
  Node* evens = nullptr;

  split(in, odds, evens);

  Node*curr = odds;
  while(curr != nullptr){
    cout<<curr->value << " ";
    curr = curr->next;
  }
  cout<<endl;

  curr = evens;
  while(curr != nullptr){
    cout<<curr->value << " ";
    curr = curr->next;
  }

  curr = odds;
  while(curr != nullptr){
    Node* temp = curr;
    curr = curr->next;
    delete temp;
  }

  curr = evens;
  while(curr != nullptr){
    Node* temp = curr;
    curr = curr->next;
    delete temp;
  }

  return 0; 
}


#include <string>
#include "ulliststr.h"
#include <iostream>


int main(int argc, char* argv[])
{
  ULListStr list;

  //push_back check:
  for(int i = 0; i< 11; i++){
    list.push_back(std::to_string(i));
  }

  std::cout << "After push_back: ";
  for(size_t i = 0; i < list.size(); i++){
    std::cout << list.get(i) << " ";
  }
  std::cout<< "\nFront: " << list.front();
  std::cout<< "\nBack: " << list.back();
  std::cout<< "\nSize: " << list.size() <<std::endl;

  //check pop_back
  list.pop_back();
  list.pop_back();
  list.pop_back();

  std::cout<< "After popback:" <<std::endl;
  for(size_t i = 0; i < list.size(); i++){
    std::cout<< list.get(i)<< " ";
  }
  std::cout<<std::endl;

    list.clear();

  //check push_front:
  for(int i = 0; i< 11; i++){
    list.push_front(std::to_string(i));
  }

  std::cout << "After push_front: ";
  for(size_t i = 0; i < list.size(); i++){
    std::cout << list.get(i) << " ";
  }
  
  std::cout<< "\nFront: " << list.front();
  std::cout<< "\nBack: " << list.back();
  std::cout<< "\nSize: " << list.size() << std::endl;

  // check pop_front
  list.pop_front();
  list.pop_front();

  std::cout<< "After 2 pop_front: ";
  for(size_t i = 0; i < list.size(); i++){
    std::cout << list.get(i) << " ";
  }
  std::cout<<std::endl;

  // Check: removing the only value and popping an empty list:
  list.clear();
  list.push_back("only");
  list.pop_front();
  list.pop_front();

  list.push_front("only");
  list.pop_back();
  list.pop_back();

  std::cout<<"Final size: " << list.size() <<std::endl;
  return 0;

}
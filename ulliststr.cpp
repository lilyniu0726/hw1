#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc >= size_){
    return nullptr;
  }
  Item* curr = head_;
  while(curr!= nullptr){
    size_t num_val = curr->last-curr->first;
    if(loc<num_val){
      return &(curr->val[curr->first + loc]);
    }
    loc -= num_val;
    curr = curr->next;
  }
  return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::push_back(const std::string& val){
  if (empty()){
    Item* newit = new Item;
    head_ = newit;
    tail_ = newit;
    newit->val[0]=val;
    newit->first = 0;
    newit->last=1;
    newit->prev = nullptr;
    newit->next = nullptr;
  }
  else if (tail_->last == ARRSIZE){
    Item* newit = new Item;
    newit->val[0]=val;
    newit->first = 0;
    newit->last=1;
    Item*temp = tail_;
    tail_ = newit;
    tail_->prev = temp;
    tail_->next = nullptr;
    temp->next = tail_;
  }
  else{
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  size_++;
}

void ULListStr::pop_back(){
  if(empty()){
    return;
  }
  if(tail_->last-tail_->first == 1){
    if(head_==tail_){
      Item* temp = tail_;
      tail_ = nullptr;
      head_ = nullptr;
      delete temp;
    }
    else{
      Item* temp = tail_;
      tail_ = tail_->prev;
      tail_->next = nullptr;
      delete temp;
    }
  }
  else{
    tail_->last--;
    tail_->val[tail_->last] = "";
  }
  size_--;
}

void ULListStr::push_front(const std::string& val){
  if(empty()){
    Item* newit = new Item;
    head_ = newit;
    tail_ = newit;
    newit->val[9]=val;
    newit->first = 9;
    newit->last=10;
    newit->prev = nullptr;
    newit->next = nullptr;
  }
  else if (head_->first == 0){
    Item* newit = new Item;
    newit->val[9]=val;
    newit->first = 9;
    newit->last=10;
    Item*temp = head_;
    head_ = newit;
    head_->prev = nullptr;
    head_->next = temp;
    temp->prev = head_;
  }
  else{
    head_->first--;
    head_->val[head_->first] = val;
  }
  size_++;
}

void ULListStr::pop_front(){
  if(empty()){
    return;
  }
  if(head_->last - head_->first == 1){
    if(head_==tail_){
      Item* temp = tail_;
      tail_ = nullptr;
      head_ = nullptr;
      delete temp;
    }
  
    else{
      Item* temp = head_;
      head_ = head_->next;
      head_->prev = nullptr;
      delete temp;
    }
  }
  else{
    head_->val[head_->first] = "";
    head_->first++;
  }
  size_--;
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

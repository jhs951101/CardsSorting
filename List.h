#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <cassert>
#include <string>

#include "Card.h"

using namespace std;

class List;
class Iterator;

class Node
{
public:

	Node(Card s);
   ~Node();
   static int getCurCount() { return  curCount; } // new
   static void setCurCount(int n) { curCount = n; } // new

   static int getMaxCount() { return  maxCount; } // new
   static void setMaxCount(int n) { maxCount = n; } // New
private:
   Card data;
   Node* previous;
   Node* next;
   static int curCount; // New
   static int maxCount; // New
friend class List;
friend class Iterator;
};

class List
{
public:
   /**
      Constructs an empty list;
   */
   List();
   /**
      Appends an element to the list.
      @param s the value to append
   */
   List(const List& right);
   ~List();
   List& operator=(const List& right);

   void push_back(Card s);
   void push_front(Card s);
   void insert(Iterator iter, Card s);
   Iterator erase(Iterator i);
   Iterator begin() const;
   Iterator end() const;

   bool empty() const;
   int size() const;
private:
   Node* first;
   Node* last;
};

class Iterator
{
public:
   /**
      Constructs an iterator that does not point into any list.
   */
   Iterator();
   Card get() const;
   void next();
   void previous();

   bool equals(Iterator b) const;
   Iterator& operator++(int);
   Iterator& operator--(int);
   Card operator*() const;
   Card& operator*();
   Card* operator->();
   bool operator==(const Iterator& b) const;
   bool operator!=(const Iterator& b) const;
private:
   Node* position;
   Node* last;
friend class List;
};

#endif

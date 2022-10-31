#ifndef list_h
#define list_h
#include <iostream>
#include <initializer_list>
#include <iterator> 
#include <vector>
#include <sstream>

/*
TODO:
Node som parameter, returtyp eller medlem får inte förekomma i det publika gränssnittet.

Man ska ej kunna skapa en iterator mha konstruktorn utanför klassen. Detta ska endast kunna göras med 
medlemsfunktioner i listan (begin och end). 

Ni har minnesläckor som måste hanteras. Man hittar dessa genom att köra erat program genom valgrind (valgrind ./a.out)

Printlist ska inte skriva till terminal utan till ström. Till exempel: stringstream = printlist(list)

Erat program går inte igenom era egna tester. Varför är inte sånt fixat innan inlämning? 

En testfil ska aldrig skriva till terminalen. I en testfil ska strömmar användas för att simulera I/O ifall detta
ska testas och allt som skrivs ut när programmet körs ska vara hur många tester som gick igenom.

Ni måste implementera eran flyttoperator. Ni måste även testa: 
(Flytttilldelning/konstruktor samt Kopieringstilldelning/konstruktor) 4 tester och att djup kopia har gjorts vid båda kopieringar

*/

class listIterator;

// Class List
//-----------------------------------------------------------------------
class List
{

private:
  friend class listIterator;

  //Class Node
//-----------------------------------------------------------------------
  class Node
  { 
  public:
    Node(Node* prev, const int data, Node* next);
    
    
    Node* prev;
    int data;
    Node* next;
  };
  //End of class Node
//----------------------------------------------------------------------

  Node* last;
  Node* first;

public:
  //Konstruktor
  List();
  ~List();

  //Copy
  List( List& L);
  List & operator=( List& L);

  //Flytt
  List(List&& L);
  List & operator=(List&& L);

  //INIT_List
  List(std::initializer_list<int> const& l);

  std::stringstream printList();
  void insertAfter(int index, int value);
  void push(int new_data);
  void remove(int index);
  int at(int index);
  listIterator begin();
  listIterator end();

};
//End of class List
// -----------------------------------------------------------------------

// Class listIterator 
class listIterator 
  {
  public:
    friend class List;
      
    listIterator& operator =(listIterator const& n);
    listIterator& operator ++();
    bool operator !=(listIterator const& it);
    int operator *();
    
  private:
    listIterator(List::Node* const& n);
    List::Node* current;
  };
  // End of class listIterator
//-----------------------------------------------------------------------

#endif

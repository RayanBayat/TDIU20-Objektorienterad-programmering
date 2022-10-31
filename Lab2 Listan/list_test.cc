#include <iostream>
#include <initializer_list>
#include <iterator> 
#include <vector>
#include <sstream>

#include "catch.hpp"
#include "list.h"

using namespace std;


TEST_CASE ("Default")
{
  List L;
  L.push(8);
  L.push(154);
  CHECK(L.at(2) == 154);
  L.push(63);
  L.push(56);
  L.push(14);
  L.push(6);
  CHECK(L.at(4) == 56);
  L.push(5);
  L.push(786);
  L.push(7);
  CHECK(L.at(2) == 6);
}

TEST_CASE ("Default + remove + insertafter")
{
  List L;
  L.push(8);
  L.push(154);
  L.push(63);
  L.push(56);
  L.push(14);
  L.push(6);
  L.push(5);
  L.push(786);
  L.push(7);
  L.remove(1);
  L.remove(1);
  L.remove(1);
  L.remove(1);
  L.insertAfter(1,754);
  CHECK(L.at(2) == 754);
}

TEST_CASE ("Copy Konstruktor")
{
  List L;
  L.push(8);
  L.push(154);
  L.push(63);

  List L1{L};
  CHECK(L.at(2) == 63);
  CHECK(L1.at(2) == 63);
  CHECK(L1.at(3) == 154);
}

TEST_CASE ("Flytt Konstruktor")
{
  List L;
  L.push(8);
  L.push(154);
  L.push(63);
  List L1{move(L)};

  CHECK(L1.at(2) == 63);
  CHECK(L1.at(3) == 154);
}

TEST_CASE ("Copy tilldelning")
{
  List L;
  List L1;

  L.push(8);
  L.push(154);
  L.push(63);

  L1.push(56);
  L1.push(14);
  L1.push(6);
  L = L1;
  CHECK(L.at(3) == 56);
  CHECK(L1.at(2) == 14);
}

TEST_CASE ("Flytt tilldelning")
{
  List L;
  List L1;

  L.push(8);
  L.push(154);
  L.push(63);

  L1.push(56);
  L1.push(14);
  L1.push(6);
  L = move(L1);
  CHECK(L.at(3) == 56);
  CHECK(L1.at(3) == 154);
}

TEST_CASE ("initializer_list")
{
  List L{2,5,721,324,76,3254,8742};
 CHECK(L.at(1) == 2);
 CHECK(L.at(2) == 5);
 CHECK(L.at(3) == 76);
 CHECK(L.at(4) == 324);
 CHECK(L.at(5) == 721);
 CHECK(L.at(6) == 3254);
 CHECK(L.at(7) == 8742);
}

TEST_CASE ("Bonus")
{
  List L{2,5,7};
  for (listIterator it = L.begin(); it != L.end(); ++it)
  {
    CHECK(L.at(1) == 2);
    CHECK(L.at(2) == 5);
    CHECK(L.at(3) == 7);
    /*if (i == 1)
    {
      CHECK(*it == 2);
    }
    else if (i == 2)
    {
      CHECK(*it == 5);
    }
    else 
    {
      CHECK(*it == 7);
    }*/
  }
}




#if 0
#endif


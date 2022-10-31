#include <string>
#include <iostream>
#include <sstream>
#include "catch.hpp"
#include "time.h"

using namespace std;


// Kommentar: Kan vara bra att ni tänker på att testa special fall, t.ex. när tiden slår över från 23:59:59 till 00:00:00 i era operatorer etc.


// här lägger ni era testfall. 
// Jobba enligt TDD; 
//  1. Lägg till testfall
//  2. Testa
//  3. Lägg till (minsta möjliga) implementation
//  4. Testa alla testfall
//  5. Refaktorera (skriv om) så att allt ser bra ut

TEST_CASE ()
{
    Time t;

    CHECK(t.hour() == 0);
    CHECK(t.minute() == 0);
    CHECK(t.second() == 0);
}

TEST_CASE ()
{
    Time t{12,13,14};

    CHECK(t.hour() == 12);
    CHECK(t.minute() == 13);
    CHECK(t.second() == 14);
}

TEST_CASE ("Constructor with faulty argument")
{
    CHECK_THROWS( Time{41,0,0} );
    CHECK_THROWS( Time{0,99,0} );
    CHECK_THROWS( Time{0,0,99} );
    CHECK_THROWS( Time{-1,0,0} );

}

TEST_CASE ("String constructor")
{
    Time t{"12:23:12"};
    CHECK(t.hour() == 12);
    CHECK(t.minute() == 23);
    CHECK(t.second() == 12);

    SECTION ("Throws as well")
    {
        CHECK_THROWS( Time{"02:11:74"} );
        CHECK_THROWS( Time{"-01:00:40"} );
        CHECK_THROWS( Time{"02:-20:25"} );


    }
}

TEST_CASE ("am or pm")
{
    Time t{12,12,31};
    CHECK_FALSE(t.is_am());
    Time t2{1,2,3};
    CHECK(t2.is_am());
    Time t3{12,00,00};
    CHECK_FALSE(t3.is_am());
    Time t4{0,0,0};
    CHECK(t4.is_am());

}

TEST_CASE ("Convert to string" )
{
    CHECK( Time{12,12,12}.to_string()     ==    "12:12:12" );
    CHECK( Time{11, 1, 2}.to_string()     ==    "11:01:02" );
    CHECK( Time{14,33,12}.to_string(true) == "02:33:12 pm" );
    
}


TEST_CASE ("Output operator" )
{
    stringstream ss;
    SECTION("Simple output")
    {
        ss << Time{2,5,1};
        CHECK(ss.str() == "02:05:01");
    }
    SECTION("Chained output")
    {
        ss << Time{23,10,32} << "---";
        CHECK(ss.str() == "23:10:32---");
    }
    SECTION("Const time")
    {
        Time const t{23,23,23};
        ss << t;

        CHECK(ss.str() == "23:23:23");
    }
}

TEST_CASE ("Conversion to string" )
{
    CHECK( string(Time{2,4,1}) == "02:04:01");

}
TEST_CASE("add ")
{
  Time t{15,46,18};
 t= t +636456543 ;
    CHECK(t.hour() == 01);
    CHECK(t.minute() == 15);
    CHECK(t.second() == 21);
  Time t1{15,46,18};
t1=t1 -636456543 ;
 CHECK(t1.to_string()== "06:17:15");
}

TEST_CASE("sub ")
{
    Time t{22,11,42};
  t= t -235453421;
    CHECK(t.hour() == 18);
    CHECK(t.minute() == 28);
    CHECK(t.second() == 01);
    Time t1{22,11,42};
   t1= t1 +235453421;
      CHECK(t1.hour() == 01);
    CHECK(t1.minute() == 55);
    CHECK(t1.second() == 23);
}
TEST_CASE("add 1")
{
    Time t{23,59,59};
    ++t;
    CHECK(t.hour() == 00);
    CHECK(t.minute() == 00);
    CHECK(t.second() == 00);
    CHECK(t.to_string() == "00:00:00");
    t++;
    CHECK(t.hour() == 00);
    CHECK(t.minute() == 00);
    CHECK(t.second() == 01);
     CHECK(t.to_string() == "00:00:01");
}
TEST_CASE("sub 1")
{
  Time t{00,00,00};
  --t;
  CHECK(t.hour() == 23);
  CHECK(t.minute() == 59);
  CHECK(t.second() == 59);
  t--;
  CHECK(t.hour() == 23);
  CHECK(t.minute() == 59);
  CHECK(t.second() == 58);
}
TEST_CASE("compare")
{
  Time t{23,59,03};
  Time t1{23,59,2};
Time t2{23,59,4};
  Time t3{23,59,03};

  CHECK((t > t1));
   
   CHECK((t < t2));
CHECK((t == t3));
CHECK((t >= t3));
CHECK((t <= t3));

 CHECK((t != t2));
  CHECK((t <= t2));
   CHECK((t >= t1));
 // CHECK_FALSE(t.compare("23:59:4"));
}

// Kommentar: Du ska skriva tester för DITT library och DIN kod, inte för någon annans, d.v.s. ctime ska inte inkluderas.
TEST_CASE("current time")
{

}
#if 0
#endif


#include "doctest.h"
#include "Direction.hpp"
#include <string>
#include "Notebook.hpp"
#include <algorithm>

TEST_CASE("good inputs"){
    ariel::Notebook tempBook;

    // check read enpty

    CHECK(tempBook.read(100,100,10,ariel::Direction::Vertical,10) == "~~~~~~~~~~");
    CHECK(tempBook.read(0,0,19,ariel::Direction::Horizontal,18) == "~~~~~~~~~~~~~~~~~~");
    
    //check test write, read , delet horizontal

    tempBook.write(0,0,0,ariel::Direction::Horizontal,"the best work ever");
    CHECK(tempBook.read(0,0,0,ariel::Direction::Horizontal,18) == "the best work ever");
    tempBook.erase(0,0,0,ariel::Direction::Horizontal,18);
    CHECK(tempBook.read(0,0,0,ariel::Direction::Horizontal,18) == "~~~~~~~~~~~~~~~~~~");

    tempBook.write(10,1,90,ariel::Direction::Horizontal,"ten colum");
    CHECK(tempBook.read(10,1,90,ariel::Direction::Horizontal,9) == "ten colum");
    tempBook.erase(10,1,90,ariel::Direction::Horizontal,9);
    CHECK(tempBook.read(10,1,90,ariel::Direction::Horizontal,9) == "~~~~~~~~~");

    tempBook.write(105,149,50,ariel::Direction::Horizontal,"my name is michael");
    CHECK(tempBook.read(105,149,50,ariel::Direction::Horizontal,18) == "my name is michael");
    tempBook.erase(105,149,50,ariel::Direction::Horizontal,18);
    CHECK(tempBook.read(105,149,50,ariel::Direction::Horizontal,18) == "~~~~~~~~~~~~~~~~~~");

    // check write read delet vertical

    tempBook.write(1,0,0,ariel::Direction::Vertical,"the best work ever");
    CHECK(tempBook.read(1,0,0,ariel::Direction::Vertical,18) == "the best work ever");
    tempBook.erase(1,0,0,ariel::Direction::Vertical,18);
    CHECK(tempBook.read(1,0,0,ariel::Direction::Vertical,18) == "~~~~~~~~~~~~~~~~~~");

    tempBook.write(11,1,90,ariel::Direction::Vertical,"ten colum");
    CHECK(tempBook.read(11,1,90,ariel::Direction::Vertical,9) == "ten colum");
    tempBook.erase(11,1,90,ariel::Direction::Vertical,9);
    CHECK(tempBook.read(11,1,90,ariel::Direction::Vertical,9) == "~~~~~~~~~");

    tempBook.write(106,149,50,ariel::Direction::Vertical,"my name is michael");
    CHECK(tempBook.read(106,149,50,ariel::Direction::Vertical,18) == "my name is michael");
    tempBook.erase(106,149,50,ariel::Direction::Vertical,18);
    CHECK(tempBook.read(106,149,50,ariel::Direction::Vertical,18) == "~~~~~~~~~~~~~~~~~~");
    
}

TEST_CASE("bad inputs"){
    ariel::Notebook tempBook2;
    //bad start colum
    CHECK_THROWS(tempBook2.write(0,0,101,ariel::Direction::Horizontal,"this is a to mach long input"));
    CHECK_THROWS(tempBook2.read(106,149,110,ariel::Direction::Horizontal,18));
    CHECK_THROWS(tempBook2.erase(106,150,120,ariel::Direction::Horizontal,20));

    //over row
    CHECK_THROWS(tempBook2.write(0,0,90,ariel::Direction::Horizontal,"this is a to mach long input"));
    CHECK_THROWS(tempBook2.read(106,149,90,ariel::Direction::Horizontal,18));
    CHECK_THROWS(tempBook2.erase(106,150,85,ariel::Direction::Horizontal,20));

    //delet empty
    CHECK_THROWS(tempBook2.erase(106,149,90,ariel::Direction::Vertical,20));
    CHECK_THROWS(tempBook2.erase(0,0,0,ariel::Direction::Horizontal,7));
    
    //write in the same place
    tempBook2.write(0,0,0,ariel::Direction::Horizontal,"this is the firest input");
    CHECK_THROWS(tempBook2.write(0,0,5,ariel::Direction::Horizontal,"this is the second input"));
    CHECK_THROWS(tempBook2.write(0,0,5,ariel::Direction::Vertical,"this is the second input"));

    //write in place that was deleted
    tempBook2.erase(0,0,0,ariel::Direction::Horizontal,24);
    CHECK_THROWS(tempBook2.write(0,0,5,ariel::Direction::Horizontal,"this after delet input"));
    CHECK_THROWS(tempBook2.write(0,0,5,ariel::Direction::Vertical,"this after delet input"));
}
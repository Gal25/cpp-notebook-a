#include <stdlib.h>
#include <iostream>
#include <string>
#include "Direction.hpp"
#include "Notebook.hpp"
#include "doctest.h"
using namespace std;
using namespace ariel;

TEST_CASE("Good input") {
    Notebook notebook;
    notebook.write(0,0,0,Direction::Horizontal,"hello my name is Gal");
    CHECK(notebook.read(0,0,0,Direction::Horizontal,20) == "hello my name is Gal");
    notebook.erase(0,0,0,Direction:: Horizontal,1);
    CHECK(notebook.read(0,0,0,Direction::Horizontal,20) == "~ello my name is Gal");
    notebook.write(0,50,90,Direction::Vertical,"Whats up?");
    CHECK(notebook.read(0,50,90,Direction::Vertical,9) == "Whats up?");
    notebook.erase(0,55,90,Direction:: Vertical,4);
    CHECK(notebook.read(0,50,90,Direction::Vertical,9) == "Whats~~~~");
    notebook.write(0,1,0,Direction::Horizontal,"I'm a computer science student");
    CHECK(notebook.read(0,1,0,Direction::Horizontal,30) == "I'm a computer science student");
    notebook.erase(0,1,0,Direction:: Horizontal,30);
    CHECK(notebook.read(0,1,0,Direction::Horizontal,30) == "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    CHECK(notebook.read(0,1,100,Direction::Horizontal,1) == "_");
    notebook.write(0,1,98,Direction::Horizontal,"**");
    CHECK(notebook.read(0,1,98,Direction::Horizontal,2) == "**");
    notebook.erase(0,1,98,Direction:: Horizontal,2);
    CHECK(notebook.read(0,1,98,Direction::Horizontal,2) == "~~");
    notebook.write(100,5,10,Direction:: Horizontal,"hello");
    CHECK(notebook.read(100,5,10,Direction:: Horizontal,5) == "hello");
    notebook.erase(100,5,10,Direction:: Horizontal,5);
    CHECK(notebook.read(100,5,10,Direction:: Horizontal,5) == "~~~~~");
    notebook.write(5,0,0,Direction:: Horizontal,"hey");
    CHECK(notebook.read(5,0,0,Direction:: Horizontal,3) == "hey");


    

}

TEST_CASE("Bad input") {
    Notebook notebook;
    CHECK_THROWS(notebook.write(0,1,0,Direction::Horizontal,"I'm a computer science student"));
    CHECK_THROWS(notebook.write(0,0,0,Direction::Horizontal,"hello"));
    CHECK_THROWS(notebook.write(0,55,90,Direction:: Vertical,"hey"));
    CHECK_THROWS(notebook.write(100,5,10,Direction:: Horizontal,"Gal"));
    CHECK_THROWS(notebook.read(0,0,95,Direction::Horizontal,10));
    CHECK_THROWS(notebook.write(0,0,0,Direction::Horizontal,"hello"));
    CHECK_THROWS(notebook.write(100,0,8,Direction::Horizontal,0));
    CHECK_THROWS(notebook.write(0,0,100,Direction::Horizontal,"hello"));
    CHECK_THROWS(notebook.write(-2,0,8,Direction::Horizontal,""));
    CHECK_THROWS(notebook.write(-2,-1,8,Direction::Horizontal,""));
    CHECK_THROWS(notebook.write(0,0,-8,Direction::Horizontal,""));
    CHECK_THROWS(notebook.write(-2,-1,-8,Direction::Horizontal,""));





}

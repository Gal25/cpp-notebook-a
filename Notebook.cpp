#include <stdlib.h>
#include <iostream>
#include <string>
#include "Direction.hpp"
#include "Notebook.hpp"

using namespace std;
namespace ariel{

    void Notebook::write(int page, int line, int col, Direction dir, string const &std){}
    string Notebook::read( int page, int line, int col, Direction dir, int numToRead){
        return "";
    }
    void Notebook::erase( int page, int line, int col, Direction dir, int len){}
    void Notebook::show( int page){}


}
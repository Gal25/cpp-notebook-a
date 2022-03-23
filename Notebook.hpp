#include <stdlib.h>
#include <iostream>
#include <string>
#include "Direction.hpp"


using namespace std;
namespace ariel{
    class Notebook{
        public:
            void write( int page, int line, int col, Direction dir, string const &std);
            string static read( int page, int line, int col, Direction dir, int numToRead);
            void erase( int page, int line, int col, Direction dir, int len);
            void show( int page);
    };
}
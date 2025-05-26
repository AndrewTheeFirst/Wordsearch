// do not modify

#include <iostream>
#include <string>
#include <vector>

#include "lettermatrix.h"


// Prints a 2D matrix of letters.  Used to print the puzzle or key.
// os: the output stream to send the data (can be the console 
// or a text file).
// grid: the matrix to print.
// Returns the output stream object (for chaining purposes).
std::ostream& operator<<(std::ostream& os, const LetterMatrix& grid) {
    for (auto row : grid) {
        for (auto letter : row)
            os << letter << ' ';
        os << std::endl;
        
    }
    return os;
}


// Reads a 2D matrix of letters from an input stream.
// is: the input stream providing the letters (can be the 
// console or a text file).
// grid: the matrix to fill.
// Does not return anything; therefore, it does not support chaining.
void operator>>(std::istream& is, LetterMatrix& grid) {
    grid.clear();  //  Empty out the current puzzle
    while (is) {
        std::string line;
        std::getline(is, line);
        if (line != "") {
            std::vector<char> vec;
            for (char ch : line) {
                if ('A' <= ch && ch <= 'Z')
                    vec.push_back(ch);
            }
            grid.push_back(vec);
        }
    }
}

// Make and return an empty size x size matrix of letters.
// A period ('.') indicates "no letter."
LetterMatrix empty_puzzle(size_t size) {
    return {size, std::vector<char>(size, '.')};
}

#include <string>
#include <vector>
#include <iostream>
#include "wordsearch.h"

#define UP 1
#define DOWN 2
#define LEFT 4
#define RIGHT 8

using dir = unsigned char;

dir directions[8] = {UP, DOWN, LEFT, RIGHT, UP | LEFT, UP | RIGHT, DOWN | LEFT, DOWN | RIGHT};

// returns a rod in wordlist that matches given a direction and a col, row position -- returns a empty string otherewise
std::string check_direction(size_t col, size_t row, const LetterMatrix &puzzle, const std::vector<std::string> &wordlist, dir direction){
    size_t puzzle_width = puzzle[0].size();
    size_t puzzle_height = puzzle.size();

    int col_mod = 0, row_mod = 0;
    if ((direction & UP) == UP){row_mod = -1;} 
    else if ((direction & DOWN) == DOWN){row_mod = 1;};
    if ((direction & LEFT) == LEFT){col_mod = -1;}
    else if ((direction & RIGHT) == RIGHT){col_mod = 1;};

    // loop through every word
    for (size_t word_index = 0; word_index < wordlist.size(); word_index++){
        std::string current_word = wordlist[word_index];
        size_t word_length = current_word.length();
        
        size_t row_end = row + row_mod * (word_length - 1);
        size_t col_end = col + col_mod * (word_length - 1);
        // check space contraints
        if ((puzzle_height <= row_end || row_end < 0) || 
            (puzzle_width  <= col_end || col_end < 0)){
            continue;
        }
        // check for matching letters
        for (size_t letter_index = 0; letter_index < word_length; letter_index++){
            if (current_word[letter_index] != puzzle[row + letter_index * row_mod][col + letter_index * col_mod]){
                break;
            }
            if (letter_index == word_length - 1){
                return current_word;
            }
        }
    }
    return "";
}

// inserts a word in a given direction at col, row position into solution matrix
void insert_word(size_t col, size_t row, LetterMatrix& solution, std::string word, dir direction){
    int row_mod = 0, col_mod = 0;
    if ((direction & UP) == UP){row_mod = -1;} 
    else if ((direction & DOWN) == DOWN){row_mod = 1;};
    if ((direction & LEFT) == LEFT){col_mod = -1;}
    else if ((direction & RIGHT) == RIGHT){col_mod = 1;};

    // place each letter of word into solution matrix
    for(size_t letter_index = 0; letter_index < word.length(); letter_index++){
        solution[row + row_mod * letter_index][col + col_mod * letter_index] = word[letter_index];
    }
}

LetterMatrix solve(const LetterMatrix& puzzle, const std::vector<std::string>& wordlist){
    std::string found_word;
    LetterMatrix solution = empty_puzzle(puzzle.size());
    for (size_t col = 0; col < puzzle.size(); col++){
        for (size_t row = 0; row < puzzle[col].size(); row++){
            for (dir direction: directions){
                found_word = check_direction(col, row, puzzle, wordlist, direction);
                if (found_word != ""){
                    insert_word(col, row, solution, found_word, direction);
                }
            }
        }
    }
    return solution;
}
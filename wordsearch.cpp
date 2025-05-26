#include <string>
#include <vector>
#include <iostream>
#include "wordsearch.h"

#define UP 1
#define DOWN 2
#define LEFT 4
#define RIGHT 8

std::string check_up(size_t column, size_t row, const LetterMatrix& puzzle, const std::vector<std::string>& wordlist);
std::string check_down(size_t column, size_t row, const LetterMatrix& puzzle, const std::vector<std::string>& wordlist);
std::string check_left(size_t column, size_t row, const LetterMatrix& puzzle, const std::vector<std::string>& wordlist);
std::string check_right(size_t column, size_t row, const LetterMatrix& puzzle, const std::vector<std::string>& wordlist);

std::string check_up_left(size_t column, size_t row, const LetterMatrix &puzzle, const std::vector<std::string> &wordlist);
std::string check_up_right(size_t column, size_t row, const LetterMatrix &puzzle, const std::vector<std::string> &wordlist);
std::string check_down_left(size_t column, size_t row, const LetterMatrix &puzzle, const std::vector<std::string> &wordlist);
std::string check_down_right(size_t column, size_t row, const LetterMatrix &puzzle, const std::vector<std::string> &wordlist);

void insert_word(size_t column, size_t row, LetterMatrix& solution, std::string word, unsigned short direction);

LetterMatrix solve(const LetterMatrix& puzzle, const std::vector<std::string>& wordlist){
    std::string found_word;
    LetterMatrix solution = empty_puzzle(puzzle.size());
    
    for (size_t column = 0; column < puzzle.size(); column++){
        for (size_t row = 0; row < puzzle[column].size(); row++){

            found_word = check_up(column, row, puzzle, wordlist);
            if (found_word != ""){
                insert_word(column, row, solution, found_word, UP);
            }
            found_word = check_down(column, row, puzzle, wordlist);
            if (found_word != ""){
                insert_word(column, row, solution, found_word, DOWN);
            }
            found_word = check_left(column, row, puzzle, wordlist);
            if (found_word != ""){
                insert_word(column, row, solution, found_word, LEFT);
            }
            found_word = check_right(column, row, puzzle, wordlist);
            if (found_word != ""){
                insert_word(column, row, solution, found_word, RIGHT);
            }

            found_word = check_up_left(column, row, puzzle, wordlist);
            if (found_word != ""){
                insert_word(column, row, solution, found_word, LEFT|UP);
            }
            found_word = check_up_right(column, row, puzzle, wordlist);
            if (found_word != ""){
                insert_word(column, row, solution, found_word, RIGHT|UP);
            }
            found_word = check_down_left(column, row, puzzle, wordlist);
            if (found_word != ""){
                insert_word(column, row, solution, found_word, LEFT|DOWN);
            }
            found_word = check_down_right(column, row, puzzle, wordlist);
            if (found_word != ""){
                insert_word(column, row, solution, found_word, RIGHT|DOWN);
            }
        }
    }
    return solution;
}

std::string check_up(size_t column, size_t row, const LetterMatrix &puzzle, const std::vector<std::string> &wordlist){
    std::string current_word;
    size_t word_length;

    // check every word
    for (size_t word_index = 0; word_index < wordlist.size(); word_index++){
        current_word = wordlist[word_index];
        word_length = current_word.length();
        if (row + 1 < word_length){ // skip if word cannot fit within space
            break;
        }
        for (size_t letter_index = 0; letter_index < word_length; letter_index++){
            if (current_word[letter_index] != puzzle[row - letter_index][column]){
                break;
            }
            if (letter_index == word_length - 1){
                return current_word;
            }
        }
    }
    return "";
}

std::string check_down(size_t column, size_t row, const LetterMatrix &puzzle, const std::vector<std::string> &wordlist){
    std::string current_word;
    size_t word_length;
    size_t puzzle_height = puzzle.size();

    // check every word
    for (size_t word_index = 0; word_index < wordlist.size(); word_index++){
        current_word = wordlist[word_index];
        word_length = current_word.length();
        if (row + word_length > puzzle_height){ // skip if word cannot fit within space
            continue;
        }
        for (size_t letter_index = 0; letter_index < word_length; letter_index++){
            if (current_word[letter_index] != puzzle[row + letter_index][column]){
                break;
            }
            if (letter_index == word_length - 1){
                return current_word;
            }
        }
    }
    return "";
}

std::string check_left(size_t column, size_t row, const LetterMatrix &puzzle, const std::vector<std::string> &wordlist){
    std::string current_word;
    size_t word_length;
    // check every word at position
    for (size_t word_index = 0; word_index < wordlist.size(); word_index++){
        current_word = wordlist[word_index];
        word_length = current_word.length();
        if (column + 1 < word_length){ // skip if word cannot fit within space 
            continue;
        }
        // check if each letter matches current word
        // try: index = 0 word = 6, column = 5
        for (size_t letter_index = 0; letter_index < word_length; letter_index++){ 
            if (current_word[letter_index] != puzzle[row][column - letter_index]){ // skip if letter doesnt match
                break;
            }
            if (letter_index == word_length - 1){ 
                return current_word;
            }
        }
    }
    return "";
}

std::string check_right(size_t column, size_t row, const LetterMatrix &puzzle, const std::vector<std::string> &wordlist){
    std::string current_word;
    size_t word_length;
    size_t puzzle_width = puzzle[0].size();

    // check every word
    for (size_t word_index = 0; word_index < wordlist.size(); word_index++){
        current_word = wordlist[word_index];
        word_length = current_word.length();
        if (column + word_length > puzzle_width){ // skip if word cannot fit within space
            continue;
        }
        for (size_t letter_index = 0; letter_index < word_length; letter_index++){
            if (current_word[letter_index] != puzzle[row][column + letter_index]){
                break;
            }
            if (letter_index == word_length - 1){
                return current_word;
            }
        }
    }
    return "";
}

std::string check_up_left(size_t column, size_t row, const LetterMatrix &puzzle, const std::vector<std::string> &wordlist){
    std::string current_word;
    size_t word_length;
    size_t puzzle_width = puzzle[0].size();

    // check every word
    for (size_t word_index = 0; word_index < wordlist.size(); word_index++){
        current_word = wordlist[word_index];
        word_length = current_word.length();
        if (column + 1 < word_length || row + 1 < word_length){ // skip if word cannot fit within space
            break;
        }
        for (size_t letter_index = 0; letter_index < word_length; letter_index++){
            if (current_word[letter_index] != puzzle[row - letter_index][column - letter_index]){
                break;
            }
            if (letter_index == word_length - 1){
                return current_word;
            }
        }
    }
    return "";
}

std::string check_up_right(size_t column, size_t row, const LetterMatrix &puzzle, const std::vector<std::string> &wordlist){
    std::string current_word;
    size_t word_length;
    size_t puzzle_width = puzzle[0].size();

    // check every word
    for (size_t word_index = 0; word_index < wordlist.size(); word_index++){
        current_word = wordlist[word_index];
        word_length = current_word.length();
        if (column + word_length > puzzle_width || row + 1 < word_length){ // skip if word cannot fit within space
            continue;
        }
        for (size_t letter_index = 0; letter_index < word_length; letter_index++){
            if (current_word[letter_index] != puzzle[row - letter_index][column + letter_index]){
                break;
            }
            if (letter_index == word_length - 1){
                return current_word;
            }
        }
    }
    return "";
}

std::string check_down_left(size_t column, size_t row, const LetterMatrix &puzzle, const std::vector<std::string> &wordlist){
    std::string current_word;
    size_t word_length;
    size_t puzzle_height = puzzle.size();

    // check every word
    for (size_t word_index = 0; word_index < wordlist.size(); word_index++){
        current_word = wordlist[word_index];
        word_length = current_word.length();
        if (row + word_length > puzzle_height || column + 1 < word_length){ // skip if word cannot fit within space
            continue;
        }
        for (size_t letter_index = 0; letter_index < word_length; letter_index++){
            if (current_word[letter_index] != puzzle[row + letter_index][column - letter_index]){
                break;
            }
            if (letter_index == word_length - 1){
                return current_word;
            }
        }
    }
    return "";
}

std::string check_down_right(size_t column, size_t row, const LetterMatrix &puzzle, const std::vector<std::string> &wordlist){
    std::string current_word;
    size_t word_length;
    size_t puzzle_height = puzzle.size();
    size_t puzzle_width = puzzle[0].size();

    // check every word
    for (size_t word_index = 0; word_index < wordlist.size(); word_index++){
        current_word = wordlist[word_index];
        word_length = current_word.length();
        if (column + word_length > puzzle_width || row + word_length > puzzle_height){ // skip if word cannot fit within space
            continue;
        }
        for (size_t letter_index = 0; letter_index < word_length; letter_index++){
            if (current_word[letter_index] != puzzle[row + letter_index][column + letter_index]){
                break;
            }
            if (letter_index == word_length - 1){
                return current_word;
            }
        }
    }
    return "";
}

void insert_word(size_t column, size_t row, LetterMatrix& solution, std::string word, unsigned short direction){
    size_t row_mod = 0, col_mod = 0;
    if ((direction & UP) == UP){ // up
        row_mod = -1;
    }
    if ((direction & DOWN) == DOWN){ // down
        row_mod = 1;
    }
    if ((direction & LEFT) == LEFT){ // left
        col_mod = -1;
    }
    if ((direction & RIGHT) == RIGHT){ // right
        col_mod = 1;
    }
    for(size_t letter_index = 0; letter_index < word.length(); letter_index++){
        solution[row][column] = word[letter_index];
        row += row_mod;
        column += col_mod;
    }
}

#include <iostream>
#include <string>
#include <vector>
#include "wordsearch.h"

constexpr int NUM_WORDS = 10;

// Reads NUM_WORDS words from the standard input stream and places them
// into a vector words.  Next it reads in a word search puzzle into 
// the LetterMatrix puzzle. 
// (You can use command-line redirection to load all this from a file.)
void get_puzzle(std::vector<std::string>& words, LetterMatrix& puzzle) {
    // Ensure word list initially is empty
    words.clear();
    // Load the word list
    std::string word;
    for (int i = 0; i < NUM_WORDS; i++) {
        std::cin >> word;
        words.push_back(word);
    }
    std::cin.ignore(1000, '\n');
    // Load puzzle
    std::cin >> puzzle;
}


int main() {
    std::vector<std::string> word_list;
    LetterMatrix puz;
    get_puzzle(word_list, puz);

    //  Print the list of words
    for (auto word : word_list)
        std::cout << word << '\n';
    std::cout << '\n';

    //  Print the puzzle
    std::cout << puz << '\n';

    // Solve the puzzle
    auto ans = solve(puz, word_list); // undo this when complete

    //  Print the solution 
    std::cout << ans << '\n'; // undo this when complete
}
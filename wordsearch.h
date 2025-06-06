#pragma once

#include "lettermatrix.h"

// Produces a solution for a word search puzzle given a
// puzzle and a list of words to find.
// puzzle: the word search puzzle to solve
// wordlist: the list of words to find within the puzzle
// Returns a new puzzle with the extraneous letters replaced
// with periods (.), revealing the locations of the words to find
LetterMatrix solve(const LetterMatrix& puzzle, 
                   const std::vector<std::string>& wordlist);


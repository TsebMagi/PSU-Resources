#!/usr/bin/env python3
# setup.py
# given a formatted question.txt,
# produce a question.cpp in a proper directory

import re

VALID_QUESTION = re.compile("^([D,P,Q]):(.*)")

FRONTMATTER= \
"""#include "list.h"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;"""
QUESTION_HEADER= \
"""//Place the prototype in the appropriate .h file
//Consider:
//Do you need helper functions?
//Is head or tail recursion better?
//Remove the block comments form the function below to get started"""

# With an input tuple,
# reorder to a proper:
# (question_string, difficulty, prompt)
def get_question_info(input_t):
    return (input_t[0], input_t[1], input_t[2])

def valid_question(input_s):
    return VALID_QUESTION.match(input_s)

def grouped(iterable, n):
    return zip(*[iter(iterable)]*n)

# Read a file and return a list of tuples:
# outparam: (question_string, difficulty, prompt)
def read_file(filename):
    valid = map(lambda s: s.rstrip(), filter(valid_question,
                open(filename, "r").readlines()))
    return map(get_question_info, grouped(valid, 3))

# Print out a question, given a valid tuple
def question_print(q_tuple):
    return "//The question is:" + q_tuple[0]

if __name__ == "__main__":
    print (FRONTMATTER)
    print (QUESTION_HEADER)
    print(list(read_file("LLL/questions.txt")))

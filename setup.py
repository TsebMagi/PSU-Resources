#!/usr/bin/env python3
# setup.py
# given a formatted question.txt,
# produce a question.cpp in a proper directory

import re, argparse

VALID_QUESTION = re.compile("^([D,P,Q]): (.*)")

FRONTMATTER= \
"""#include "list.h"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
"""
QUESTION_HEADER= \
"""//Place the prototype in the appropriate .h file
//Consider:
//Do you need helper functions?
//Is head or tail recursion better?
//Remove the block comments form the function below to get started
"""

# With an input tuple,
# reorder to a proper:
# { "Q:" question_string, "D:" difficulty, "P:" prompt }
def get_question_info(input_t):
    return (input_t[0], input_t[1], input_t[2])

def question_groups(input_s):
    return VALID_QUESTION.match(input_s)

def valid_question(input_s):
    return question_groups(input_s) is not None 

# group an iterable into n-ary tuples
def grouped(iterable, n):
    return zip(*[iter(iterable)]*n)

# Read a file and return a list of tuples:
# outparam: (question_string, difficulty, prompt)
def read_file(filename):
    valid = map(lambda s: s.rstrip(), filter(valid_question,
        open(filename, "r").readlines()))
    return map(get_question_info, grouped(valid, 3))

# Format a question, given a valid tuple
def format_question(q_tuple):
    question = VALID_QUESTION.match(q_tuple[0]).groups()[1]
    difficulty = VALID_QUESTION.match(q_tuple[1]).groups()[1]
    prompt = VALID_QUESTION.match(q_tuple[2]).groups()[1]
    return QUESTION_HEADER \
            + "//The question is:" + question \
            + "\n//The difficulty of this question is: " + difficulty \
            + "\n/*\n" \
            + prompt + "\n{\n\n}" \
            + "\n*/\n"

# From an input filename, format and question
def generate_questions(i_filename, o_filename):
    with open(o_filename, "w") as outfile:
        outfile.write(FRONTMATTER)
        for item in map(format_question, read_file(i_filename)):
            outfile.write(item + "\n")

if __name__ == "__main__":
    generate_questions("LLL/questions.txt", "test.cpp")

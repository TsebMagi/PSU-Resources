#!/usr/bin/env python3
# setup.py
# given a formatted question.txt,
# produce a question.cpp in a proper directory

import re, sys

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

# group an iterable into n-ary tuples
def grouped(iterable, n):
    return zip(*[iter(iterable)]*n)

def question_groups(input_s):
    if VALID_QUESTION.match(input_s) is not None:
        return VALID_QUESTION.match(input_s).groups()

def valid_question(input_s):
    return question_groups(input_s) is not None 

# With an input tuple,
# reorder to a proper:
# { "Q:" question_string, "D:" difficulty, "P:" prompt }
def get_question_info(input_t):
    return { question_groups(input_t[x])[0]: \
            question_groups(input_t[x])[1] \
            for x in range(3)}

# Read a file and return a dictionary:
# outparam: { Q: question_string, D: difficulty, P: prompt}
def read_file(filename):
    valid = map(lambda s: s.rstrip(), filter(valid_question,
        open(filename, "r").readlines()))
    return map(get_question_info, grouped(valid, 3))

# Format a question, given a valid dictionary
def format_question(q_dict):
    return QUESTION_HEADER \
            + "//The question is:" + q_dict["Q"]\
            + "\n//The difficulty of this question is: " + q_dict["D"]\
            + "\n/*\n" \
            + q_dict["P"] + "\n{\n\n}" \
            + "\n*/\n"

# From an input filename, format each question
# and write to file
def generate_questions(i_filename, o_filename):
    with open(o_filename, "w") as outfile:
        outfile.write(FRONTMATTER + "\n")
        for item in map(format_question, read_file(i_filename)):
            outfile.write(item + "\n")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        sys.exit(sys.argv[0] + " [input file] [output cpp] ")
    
    generate_questions(sys.argv[1], sys.argv[2])

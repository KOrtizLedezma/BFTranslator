#pragma once
#include <string>

std::string regex_cleaner(const std::string& input);
bool bracket_checker(const std::string& input);
std::string code_creator(const std::string& input);
std::string brainfuck_to_c(const std::string& source_code);

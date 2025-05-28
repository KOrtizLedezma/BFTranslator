#include <string>
#include <regex>
#include <stack>
#include "translator.h"

// Remove from code all unnecessary stuff keeping only "+-<>,.[]"
std::string regex_cleaner(const std::string& input){
  	std::string code = input;
  	std::regex pattern(R"((\+\-)|(\-\+)|(\<\>)|(\>\<)|(\[\])|([^+\-<>,.\[\]]))");
  	std::string prev;
  
  	do {
    	prev = code;
    	code = std::regex_replace(code, pattern, "");
  	} while (code != prev);
  
  	return code;
}

// Remove unpair bracket
bool bracket_checker(const std::string& input){
  	int open_bracket = 0;
  
  	for (char c : input) {
    	if (c == '['){
      		open_bracket++;
    	}
    	else if(c == ']'){
      		if (open_bracket == 0) {
        		return false;
      		}
      	open_bracket--;
    	}
  	}
  
  	if (open_bracket != 0){
    	return false;
  	}
  
  	return true;
}

// Create the c code
std::string code_creator(const std::string& input) {
    std::string text = "";
    char curr_case = input[0];
    int counter = 0;
    int shift = 0;

    auto flush = [&](char op, int count) {
		if (count == 0) return;
        std::string indent = std::string(shift, ' ');

        if (op == '+')
            text += indent + "*p += " + std::to_string(count) + ";\n";
        else if (op == '-')
            text += indent + "*p -= " + std::to_string(count) + ";\n";
        else if (op == '>')
            text += indent + "p += " + std::to_string(count) + ";\n";
        else if (op == '<')
            text += indent + "p -= " + std::to_string(count) + ";\n";
        else if (op == '.')
            for (int i = 0; i < count; i++)
                text += indent + "putchar(*p);\n";
        else if (op == ',')
            for (int i = 0; i < count; i++)
                text += indent + "*p = getchar();\n";
    };

    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];

        if (c == curr_case && std::string("+-<>.,").find(c) != std::string::npos) {
            counter++;
        } else {
            flush(curr_case, counter);
            counter = 0;

            if (c == '[') {
                text += std::string(shift, ' ') + "if (*p) do {\n";
                shift += 4;
            } else if (c == ']') {
                shift -= 4;
                text += std::string(shift, ' ') + "} while (*p);\n";
            } else {
                curr_case = c;
                counter = 1;
            }
        }
    }

    flush(curr_case, counter);

    return text;
}


std::string brainfuck_to_c(const std::string& source_code){
  	std::string code = regex_cleaner(source_code);
  
  	if (!bracket_checker(code)){
    	return "Error!";
  	}
  
  	std::string c_code = code_creator(code);

  	return 
		"#include <stdio.h>\n\n"
		"int main() {\n"
		"	char array[30000] = {0};\n"
		"	char *p = array; \n\n"
		+ c_code + 
		"	return 0;\n"
		"}\n";
}

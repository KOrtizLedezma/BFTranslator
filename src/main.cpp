#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "translator.h"

int main(int argc, char* argv[]) {

    std::string source_code;
    
    if (argc == 2) {
    	// Default Case: Read from file
        std::ifstream file(argv[1]);
	
	if (!file) {
	    std::cerr << "Error: Could not open file '" << argv[1] << "'\n";
	    return 1;
	}

	std::stringstream buffer;
	buffer << file.rdbuf();
	source_code = buffer.str();
	std::cout << "File loaded: " << argv[1] << "\n\n";
    }
    else {
	// Read from terminal input
	std::cout << "Enter Brainfuck code (end with Ctrl+D):\n";
	std::stringstream buffer;
	buffer << std::cin.rdbuf();
	source_code = buffer.str();
    }
    
    // Translate
    std::string c_code = brainfuck_to_c(source_code);

    if (c_code == "Error!") {
		std::cerr << "Bracket mismatch: Unbalanced [ or ] in input.\n";
		return 1;
    }

	std::ofstream out("output.c");
	
	if (!out) {
		std::cerr << "Failed to create output.c \n";
		return 1;
	}

	out << c_code;
	out.close();
	std::cout << "Save translated C code to output.c\n";

	std::cout << "Compiling with gcc...\n";

	int compile_status = std::system("gcc output.c -o bf_output");

	if (compile_status != 0) {
		std::cerr << "Compilation failed. Make sure gcc is installed.\n";
		return 1;
	}

	std::cout << "Compulation succeeded!\n";
	std::cout << "Running program: \n\n";
	std::system("./bf_output");
	std::cout << "\n\n";
	return 0;
}

#ifndef Trac_READER_H
#define Trac_READER_H

#include <string>
#include <cstddef>
#include <iostream>
#include <istream>
#include <sstream>
#include "./TracResult.h"

namespace parser {

class TracScanner;
class TracParser;

class TracReader {
friend class TracParser;
	
public:
	TracReader() :
		parser(nullptr),
		scanner(nullptr) {}

	virtual ~TracReader();

	TracResult parseFromFile(const std::string &filename);
	TracResult parseFromString(const std::string &str);
	TracResult parseFromStream(std::istream &stream);

private:

	////////////////////////////////////////////////////////////////////////////
	// Flex (Lex) / Bison (Yacc)
	////////////////////////////////////////////////////////////////////////////	
	
	TracParser *parser;
	TracScanner *scanner;

	
}; // end class

} // end namespace
#endif


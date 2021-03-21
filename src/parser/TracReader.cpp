#include <cctype>
#include <fstream>
#include <cassert>

#include "./TracReader.h"
#include "./Trac.tab.hh"
#include "./TracScanner.h"

namespace parser {

TracReader::~TracReader() {
	delete scanner;
	delete parser;
} // end destructor

// -----------------------------------------------------------------------------

TracResult TracReader::parseFromFile(const std::string &filename) {
	std::ifstream file(filename.c_str());
	if (!file.good()) {
		std::exit(1);
	} // end if
	return parseFromStream(file);
} // end method

// -----------------------------------------------------------------------------

TracResult TracReader::parseFromString(const std::string &str) {
	std::istringstream iss(str);
	return parseFromStream(iss);
} // end method

// -----------------------------------------------------------------------------

TracResult TracReader::parseFromStream(std::istream &stream) {
	if (!stream.good() && stream.eof()) {
		return TracResult();
	} // end if
	
	delete scanner;
	try {
		scanner = new parser::TracScanner(&stream);
	} catch (std::bad_alloc &ba) {
		std::cerr << "Failed to allocate scanner: (" <<
				ba.what() << "), exiting!!\n";
		std::exit(1);
	} // end catch

	delete parser ;
	TracResult result;
	try {
		parser = new parser::TracParser(*scanner, *this, result);
	} catch (std::bad_alloc &ba) {
		std::cerr << "Failed to allocate parser: (" <<
				ba.what() << "), exiting!!\n";
		std::exit(1);
	} // end catch
	
	if (parser->parse() != 0) {
		std::cout << "Parse failed.\n";
		std::exit(1);
	} else {
		std::cout << "Parse succeed.\n";
	} // end else
	return result;

} // end method

} // end namespace

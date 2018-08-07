#ifndef TxtWriter_h
#define TxtWriter_h

#include <iostream>
#include <string>
using namespace std;

class TxtWriter {
public:
	// default constructor
	TxtWriter();

	TxtWriter(string);

	// destructor
	~TxtWriter();

	// accessor functions
	string getFileName();
	void setFileName(string);
	void writeFile(string);
	string readFile();
	void deleteFile();

private:
	// variable del miembro
	string fileName;
};

#endif TxtWriter_h

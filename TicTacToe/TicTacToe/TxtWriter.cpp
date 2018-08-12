#include "TxtWriter.h"

#include <stdlib.h>
#include <fstream>
#include <iostream>

TxtWriter::TxtWriter() {
	setFileName("Records.txt");
}

TxtWriter::TxtWriter(string fileName) {
	setFileName(fileName);
}

TxtWriter::~TxtWriter() {
}

string TxtWriter::getFileName()
{
	return fileName;
}


void TxtWriter::setFileName(string newName)
{
	fileName = newName;
}

void TxtWriter::writeFile(string content)
{
	ofstream file(getFileName());
	if (file.is_open())
	{
		file << content;
		file.close();
	}
	else cout << "Unable to open file";
}

string TxtWriter::readFile()
{
	string content = "";
	string line;
	ifstream file(getFileName());
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (content != "") {
				content = content + "\n" + line;
			}
			else {
				content = line;
			}
		}
		file.close();
	}

	else cout << "Unable to open file";
	return content;
}

void TxtWriter::deleteFile()
{
	if (remove("Records.txt") != 0) {
		perror("Error deleting file");
	}
}
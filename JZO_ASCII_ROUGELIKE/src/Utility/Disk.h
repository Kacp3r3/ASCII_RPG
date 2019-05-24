#ifndef DISK_H
#define DISK_H
#include <string>
#include <fstream>
#include <iostream>
class Disk
{
public:
	//Open Type Enum
	enum Type
	{
		READ = 1,
		WRITE = 2,
		APPEND = 3
	};

	Disk();
	Disk(std::string x, enum Type t);
	~Disk();

	
	
	void open(std::string fileIn, Type x);
	void close();
	void readLine(std::string &lineIn);
	void readOneNumber(size_t& x);
	void readOneChar(char& x);
	bool isOpen();
	bool eof();
	void write(const std::string x);
private:
	std::fstream _file;
};
#endif


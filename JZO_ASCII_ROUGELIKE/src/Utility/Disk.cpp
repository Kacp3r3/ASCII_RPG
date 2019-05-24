#include "Disk.h"


using namespace std;
Disk::Disk() : _file{}
{
}

Disk::Disk(std::string x, enum Type t)
{
	open(x, t);
}


Disk::~Disk()
{
}

void Disk::open(std::string fileIn, Type x)
{
		if (!_file.is_open())
		{
			switch (x)
			{
				case Disk::READ:
				{
					_file.open(fileIn, ios::in);
					break;
				}
				case Disk::WRITE:
				{
					_file.open(fileIn, ios::out);
					break;
				}
				case Disk::APPEND:
				{
					_file.open(fileIn, ios::app);
					break;
				}
				default:
					throw std::runtime_error("Nie udalo sie otworzyc pliku " + fileIn);
			}
		}	
}

void Disk::close()
{
	if (_file.is_open()) _file.close();
}

void Disk::readLine(std::string & lineIn)
{
	if(_file.is_open()) getline(_file, lineIn);
}

void Disk::readOneNumber(size_t & x)
{
	if (!_file.eof())
	{
		_file >> x;
	}
	else
	{
		x = -1;
	}
}

void Disk::readOneChar(char & x)
{
	bool good = false;
	while (!good)
	{
		_file.get(x);
		switch (x)
		{
		case '0':
		case '1':
			good = true;
			break;
		default:
			continue;
		}
	}
}

bool Disk::isOpen()
{
	return _file.is_open();
}

bool Disk::eof()
{
	return _file.eof();
}

void Disk::write(const string x)
{
	//_file << t.date();
	_file << x;
}

#pragma once
#include <fstream>

class FileWorker : public std::fstream
{
private:
	std::fstream file;
public:
	FileWorker(const char *cstr, std::ios_base::openmode openmode)
	:
		file(cstr, openmode)
	{ }
	~FileWorker()
	{ }
};
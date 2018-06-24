#ifndef IOMANAGER_H
#define IOMANAGER_H

#include <string>
#include <vector>
#include <fstream>
namespace Feintgine
{

	class IOManager
	{
	public:
		static bool readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);
		static bool readFileToBuffer(std::string filePath, std::string& buffer);
	};
}

#endif // IOMANAGER_H

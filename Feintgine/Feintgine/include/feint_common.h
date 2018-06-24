#ifndef FEINT_COMMON_H
#define FEINT_COMMON_H

#include <string>
#include <glm/glm.hpp>
#include <fcntl.h>
#include <locale>
#include <clocale>

#include <iostream>
#include <SDL.h>


class feint_common
{
public:
	feint_common();

	static feint_common *Instance()
	{
		if (p_Instance == 0)
		{
			p_Instance = new feint_common;
			return p_Instance;
		}
		return p_Instance;
	}

	~feint_common();

	void testPrintUtf8(const std::wstring & msg);

	void showMessageBox(const std::string & msgtitle, const std::string & msgcontent);

	std::string convertWstringToString(const std::wstring & value);



	std::string findAndRepalce(const std::string &source,const std::string &a, const std::string & b);

	std::string convertVec2toString(const glm::vec2 & t_value);

	glm::vec2 convertStringToVec2(const std::string & x_string , const std::string & y_string);

	std::string getPathName(const std::string & str);

	std::string getFileNameFromPath(const std::string & str);

	std::string getNonTypeFile(const std::string & str);


private:

	static feint_common *p_Instance;


};


#endif // FEINT_COMMON_H

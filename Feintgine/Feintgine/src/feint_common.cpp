#include "feint_common.h"

feint_common *feint_common::p_Instance = 0;

feint_common::feint_common()
{
}


feint_common::~feint_common()
{
}


void feint_common::showMessageBox(const std::string & msgtitle, const std::string & msgcontent)
{
	const SDL_MessageBoxButtonData buttons[] = {
		{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "OK" },
	};
	const SDL_MessageBoxColorScheme colorScheme = {
		{ /* .colors (.r, .g, .b) */
		  /* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
			{ 255,   0,   0 },
			/* [SDL_MESSAGEBOX_COLOR_TEXT] */
			{ 0, 255,   0 },
			/* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
			{ 255, 255,   0 },
			/* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
			{ 0,   0, 255 },
			/* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
			{ 255,   0, 255 }
		}
	};
	const SDL_MessageBoxData messageboxdata = {
		SDL_MESSAGEBOX_INFORMATION, /* .flags */
		NULL, /* .window */
		msgtitle.c_str(), /* .title */
		msgcontent.c_str() , /* .message */
		SDL_arraysize(buttons), /* .numbuttons */
		buttons, /* .buttons */
		&colorScheme /* .colorScheme */
	};
	int buttonid;
	if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
		SDL_Log("error displaying message box");
	}
	if (buttonid == -1) {
		SDL_Log("no selection");
	}
	else {
		SDL_Log("selection was %s", buttons[buttonid].text);
	}
}




std::string feint_common::findAndRepalce(const std::string &source, const std::string &a, const std::string & b)
{
	std::string ft = source;
	std::cout << "replace" << a << " with " << b << "\n";
	while (ft.find(a[0]) < 0 || ft.find(a[0]) >= ft.size())
	{
		std::cout << "found a repalce" << ft.find(a[0]) <<"\n";
		ft[ft.find(a[0])] = b[0];
	}


	return ft;
}

std::string feint_common::convertVec2toString(const glm::vec2 & t_value)
{

	std::string result = "";
	result.append(std::to_string(t_value.x));
	result.append(",");
	result.append(std::to_string(t_value.y));
	return result;

}

 glm::vec2 feint_common::convertStringToVec2(const std::string & x_string, const std::string & y_string)
{
	//if (std::stof(x_string) && std::stof(y_string))
	//{
		return glm::vec2(std::stof(x_string.c_str()), std::stof(y_string.c_str()));
	//}
	//return glm::vec2(-1000);
}

 std::string feint_common::getPathName(const std::string & str)
 {

	// std::cout << "scan on " << str << "\n";
		 char sep = '/';

// #ifdef _WIN32
// 		 sep = '\\';
// #endif

		 size_t i = str.rfind(sep, str.length());
		 if (i != std::string::npos) {
			// std::cout << "cliped " << str << "\n";
			 return(str.substr(0, i));
		 }
		 return("");
 }

 std::string feint_common::getFileNameFromPath(const std::string & str)
 {

	 // std::cout << "scan on " << str << "\n";
	 char sep = '/';


	 size_t i = str.rfind(sep, str.length());
	 if (i != std::string::npos) {

		 return(str.substr(i + 1, str.length() - i));
	 }
	 return("");
 }

 std::string feint_common::getNonTypeFile(const std::string & str)
 {
	 std::string mystr = str.substr(0, str.find("."));

	 return mystr;
 }


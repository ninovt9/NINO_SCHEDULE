#pragma once

#include <string>
#include <sstream>

namespace NLib
{
	inline int StringToInt(std::string str)
	{
		std::stringstream stream(str);
		int result;
		stream >> result;
		return result;
	}

}


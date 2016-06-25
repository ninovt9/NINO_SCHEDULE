#include "ScoreBoard.h"

#include <Windows.h>
#include <string>
#include <vector>
#include <iostream>

using namespace ninoSchedule;

int main()
{
	std::string path;
	std::cout << "请输入文件路径：";
	std::cin >> path;
	std::cout << std::endl;

	Scanner scanner(path);
	auto tokenList = scanner.GetTokenList();
	Parser parser(tokenList.begin(), tokenList.end());	//改入口
	ScoreBoard scoreBoard(parser.GetTeamDict());

	std::cout << scoreBoard.ToString() << std::endl;

	system("pause");
	return 0;
}
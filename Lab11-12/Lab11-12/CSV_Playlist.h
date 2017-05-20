#pragma once
#include "PlayList.h"

class CSV : public PlayList
{
public:
	void writeToFilePL() override
	{
		std::ofstream fout("PlayList.csv");
		for (auto it : tutorials)
			fout << it;
		fout.close();
	}

	void executeThingsPL() override
	{
		this->writeToFilePL();
		ShellExecuteA(NULL, NULL, "E:\\Programe\\asm_tools\\npp\\notepad++.exe", "PlayList.csv", NULL, SW_SHOWMAXIMIZED);
	}
};
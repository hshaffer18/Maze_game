#ifndef file_H
#define file_H
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

//at first I made as a class but after
//graphing the problem I found that it 
//is more useful as a namespace as it 
//deals with general file I/O

static bool loadFile;

namespace file
{
	static std::map<std::string, std::vector<std::string>> playerMap, mazeMap;//creating 2 maps to store files in, will take some of the work off of the parser
	static bool loadFile;//Static because I want this to stay true as long as data is being read
	void fileImport(int fileTypeID);
	void fileExport(std::map<std::string, vector<std::string>> exportData);
	void storeData(std::unordered_map<std::string, std::vector<std::string>> dataMap, std::vector<std::string> keyVector);
	extern std::string parseData(int parserID, int index);
	std::map<std::string, std::vector<std::string>> packageData(int parserID, int index);
	//std::ifstream fileType(int type);
};

#endif
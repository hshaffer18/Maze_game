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

namespace file
{
	//creating 2 maps to store files in, will take some of the work off of the parser
	static std::map<std::string, std::vector<std::string>> playerMap, mazeMap, mergeMap;//these are static so that the data contained within remains persistant throughout execution(player and maze are input data and mergeData is for exporting
	static bool loadFile;//Static because I want this to stay true as long as data is being read
	void fileImport(int fileTypeID);
	//void fileExport(std::map<std::string, std::vector<std::string>> exportData);
	extern std::string parseData(int parserID, int index);
	//std::map<std::string, std::vector<std::string>> packageData(std::vector<std::string> keyVector, std::vector<std::string> dataVector);
};

#endif

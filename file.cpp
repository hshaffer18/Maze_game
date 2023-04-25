#include "file.h"
#include "Util.h"
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <fstream>

//Once again using explicit namespacing for readability
using namespace std;

/*
//determines the file that will be read and passed to the program
std::ifstream file::fileType(int type)
{
    try
    {
        if (type == 0)
        {
            std::ifstream dataFile("mapData.csv");
            return dataFile;
        }
        else if (type == 1)
        {
            std::ifstream dataFile("playerData.csv");
            return dataFile;
        }
        else
        {
            throw (type);
        }
    }
    catch (int errorId)
    {
        Util::dialog(errorId, true);
    }

}
*/

void file::fileImport(int fileTypeID)
{
    loadFile = true;//flips load file switch so the system knows a file has been loaded
    ifstream file("data.csv");    // Open the data file
    unordered_map<string, vector<string>> data;   // Create the data structure dynamically
    //there is most likeley an easier way to do this
    string line;
    while (getline(file, line))    //while the file is open and able to be read
    {
        istringstream iss(line);
        string key;
        getline(iss, key, ':');
        std::vector<string> valueVector;
        std::string token, temp;
        //This sorts through the file and assigns the data based on the position of the delimiter character ","
        //the stores it in a vector to be used in the map
        //This map will then be parsed and allocated when the parseData function is called
        while(iss >> token)
        {
            size_t pos = token.find(',');
            while (pos != std::string::npos) 
            {
                valueVector.push_back(token.substr(0, pos));
                token = token.substr(pos + 1);
                pos = token.find(',');
            }
            valueVector.push_back(token);
        }
        data[key] = valueVector; 
    }   
    file.close();//close file
}

/*
void file::fileExport(map<string, vector<string>> exportData) //to call use fileExport(packageData(parserID, dataVector))
{
    ofstream file("data.csv");

    for (const auto& key : exportData)
    {
        for (const auto& cell : key.second)
        {
            file << cell << ",";
        }
        file << "\n";
    }
    file.close();//close file
}
*/

string file::parseData(int parserID, int index)
{
    switch (parserID)
    {
    case seed: 
        return mazeMap["seed"][index];
        break;
    case position:
        return mazeMap["position"][index];
        break;
    case name:
        return playerMap["name"][index];
        break;
    case difficulty:
        return playerMap["difficulty"][index];
        break;
    default://if something unexpected is read an error will occur
        Util::isError = true;
        Util::dialog(fileError, Util::isError);
        return "-1";
    }
}
 
/*
map<string, vector<string>> file::packageData(vector<string> keyVector, vector<string> dataVector)//could have made this a void but I want to pass this function into another
{
    for (int index = 0; index < keyVector.size(); index++)//this gives an error because the size of keyVector is dynamic, if size works correctly this shouldnt be an issue
    {
        mergeMap[index] = keyVector;//dump data into a single static map
    }
    return mergeMap;
}
*/

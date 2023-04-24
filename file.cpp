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
    //instantiation of all variables
    // Open the file
    ifstream file("data.csv");
    // Read the first line to determine the data structure
    string firstLine;
    getline(file, firstLine);
    stringstream strstream(firstLine);
    vector<string> fieldVector;
    string field;

    while (getline(strstream, field, ','))//takes input through the string stream, pushes it into the string "field" then stops after each entery
    {
        fieldVector.push_back(field);//takes the string "field" and pushes it into "fieldVector"
    }

    // Create the data structure dynamically
    unordered_map<string, vector<string>> data;
    //while the file is open and able to be read
    while (file.good())
    {
        string line;
        getline(file, line);//takes input from file and pushes it into the string "line" this will read an entire line
        stringstream ss(line);
        string field;
        int index = 0;
        while (getline(ss, field, ','))
        {
            if (index >= fieldVector.size())
            {
                break;
            }
            data[fieldVector[index]].push_back(field);//pushes items from the "fieldVector" into the map
            index++;
        }
    }
    storeData(data, fieldVector);
    file.close();
}

void file::fileExport(map<string, vector<string>> exportData)
{
    ofstream file("data.csv");
}

//will be in charge of reading and parsing data from files
void file::storeData(unordered_map<string, vector<string>> dataMap, vector<std::string> keyVector)
{
    //implement switch statement to direct flow of data storage
    //will run this function within a class with a file ID and a
    //sub ID to identify what part of the document should be loaded
    //or where in the file to save
        for (int index = 0; index < dataMap[keyVector[0]].size(); index++)
        {
            for (string data : keyVector) 
            {
                //data is the key of the map and index is the entry
                //in the dataFile "data" can be used as an identifier to be able to index the file for specific data
                if (keyVector[index] == "seed" || keyVector[index] == "position")
                {
                    mazeMap.insert(pair<string, vector<string>>(keyVector[index], dataMap[keyVector[index]])); //pushes contents of data.csv into the mazeMap to be parsed
                }
                else if (keyVector[index] == "name" || keyVector[index] == "difficulty")
                {
                    playerMap.insert(pair<string, vector<string>>(keyVector[index], dataMap[keyVector[index]])); //pushes contents of data.csv into the playerMap to be parsed
                }
                else
                {
                    Util::isError = true;
                    Util::dialog(fileError, Util::isError);
                }
            }
        }
}

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

map<string, vector<string>> file::packageData(int parserID, int index)
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


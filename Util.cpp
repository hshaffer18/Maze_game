#include "Util.h"
#include <iostream>
#include <fstream>


void Util::scrClr()
{
	std::cout << "\x1B[2J\x1B[H";
}

//This function is used to prompt the user to enter an input and is used to store the commands
//(may move the commands to their own function or file to make it eaiser to change or add them)
int Util::getInput()
{
	std::string input;
	std::getline(std::cin, input);
	if (input == "quit" || input == "-q")
	{
		return quit;
	}
	else if (input == "help" || input == "-h")
	{
		return help;
	}
	else if (input == "start" || input == "-s")
	{
		return start;
	}
	else if (input == "load" || input == "-l")
	{
		return load;
	}
	else if (input == "delFile" || input == "-d")
	{
		return delFile;
	}
	else if (input == "profileID" || input == "-p")
	{
		return profileID;
	}
	else
	{
		return badInput;
	}
}

//This function stores all of the programs dialog
void Util::dialog(int dialogID, bool error)
{
	if (!error)
	{
		switch (dialogID)
		{
		case quit:
			std::cout << "Quitting program.\n";
			break;
		case help:
			std::cout << "This is a compression program that uses the LZW Compression algorithm.\n";
			std::cout << "Instructions: Add the file you would like to compress to this programs directory.\n";
			std::cout << "Afterwards rename the file to 'input.txt' then run the compression algorithm.\n";
			std::cout << "The compressed file will be stored as 'compression.sqsh' in this programs directory.\n";
			std::cout << "To decompress your file make sure that compression.sqsh is in the program's directory.\n";
			std::cout << "Use the decompress command then your file will be stored as output.txt in this\n";
			std::cout << "programs directory\n";
			std::cout << "The commands for this program are as follows: \n";
			std::cout << "'-c; or 'compress' will start the compression of input.txt\n of which will be stored as compression.sqsh\n";
			std::cout << "'-d' or 'decompress' will decompress compression.sqsh and stored to output.txt.\n";
			std::cout << "'-cl' or 'clear' will clear the terminal \nNote: you can scroll up at anytime to view what was previously cleared\n";
			std::cout << "'-q' or 'quit' will quit the program.\n";
			std::cout << "'-h' or 'help' will bring up these commands.\n";
			break;
		case start:
			std::cout << "!!!!!!!!!!!\n";
			break;
		case load:
			std::cout << "!!!!!!!!!!!\n";
			break;
		case delFile:
			std::cout << "!!!!!!!!!!!\n";
			break;
		case profileID:
			std::cout << "!!!!!!!!!\n";
			break;
		case endGame:
			std::cout << "!!!!!!!!!!\n";
			break;
		case splashScreen:
			std::cout << "!!!!!!!!!!\n";
			break;
		default:
			std::cout << "!!!!!!!!!\n";
			break;
		}
	}
	else if (error)
	{
		switch (dialogID)
		{
		case indexError:

			break;
		case genericError:

			break;
		case fileError:

			break;
		}
	}
}

std::string Util::getSerialID(parserID dataID)
{
	switch (dataID)
	{
	case seed:
		return "seed";
	case position:
		return "position";
	case name:
		return "name";
	case difficulty:
		return "difficulty";
	default:
		isError = true;
		dialog(indexError, isError);
	}
}
#ifndef Util_H
#define Util_H

enum dialogID { quit, help, start, load, delFile, profileID, badInput, endGame, splashScreen };
enum errorID { indexError = 14, genericError = 15, fileError = 16 };
enum parserID { seed = 61, position = 62, name = 63, difficulty = 64 };
enum inputID { up = 123, down = 124, forward = 125, left = 126, right = 127, backwards = 128 };
enum gameObjID { startLoc = 252, finishLoc = 253, playerLoc = 254, wallLoc = 255};

namespace Util
{
	//This is static because I want any error withing the program to be able to modify this to immediately clean up and end the program
	static bool isError = false;
	void scrClr();
	int getInput();
	void dialog(int dialogID, bool error);
}


#endif
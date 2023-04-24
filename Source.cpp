#include "maze.h"
#include "Util.h"
//
// 1st file
//
int main()
{
    //splash screen here
    //menu intro and information
    bool running = true;
    do
    {
        switch (Util::getInput())
        {
        case quit:
            Util::dialog(quit, Util::isError);
            running = false;//breaks loop and ends program
            break;
        case help:
            Util::dialog(help, Util::isError);
            break;
        case start:
            Util::dialog(start, Util::isError);
            //instantiates a new maze then deletes the object as soon as user exits
            delete new maze; //implementation for file 1
            break;
            //direct implementations for file 3
            //may implement deeper functionality with loading and saving
        case load:
            Util::dialog(load, Util::isError);
            break;
        case delFile:
            Util::dialog(delFile, Util::isError);
            break;
        case profileID: //might move this to its own function menu or just read from the file
            // Util::dialog(profileID, Util::isError); 
            // delete new profile;//implementation for file 2
            break;
        case badInput:
            Util::dialog(badInput, Util::isError);
            break;
        default:
            Util::isError = true;
            break;
        }
        if (Util::isError)
        {
            Util::dialog(genericError, Util::isError);
        }
    } while (running);
    return 0;
}

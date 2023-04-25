#include "maze.h"
#include "file.h"
#include "Util.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

maze::maze() // do not move this implementation, will cause linker error 2005
{
    if (!file::loadFile)
    {
        //sets random walls for the map
        mapSeed = rand();
        //Runs maze with player at the start position
        winState = runMaze(0, 0, 0);
        /* if (winState)
         {
             //add 1 to profile win count if possible
         }*/
    }
    else if (file::loadFile)
    {
        //loads the map seed from file to recreate the maze
        mapSeed = std::stoi(file::parseData(seed, NULL));
        //populates the coordinate variables to be inputed into the maze
        for (int index = 0; index < 3; index++)
        {
            switch (index)
            {
            case 0:
                loadX = std::stoi(file::parseData(seed, index));
                break;
            case 1:
                loadY = std::stoi(file::parseData(seed, index));
                break;
            case 2:
                loadZ = std::stoi(file::parseData(seed, index));
                break;
            default:
                Util::isError = true;
                Util::dialog(fileError, Util::isError);
            }
        }
        runMaze(loadX, loadY, loadZ);//loads the map at the players last position
    }
}

maze::~maze()
{
    //Whenever the maze object is destroyed(exited or by force), a copy of the users position and map seed are
    //saved. These can then be recalled in a serialized manner to bring the user back to the last state

    std::vector<std::string> keyVector, dataVector;//These will hold the keys for the data map to be exported

    //serialization for seed variable
    keyVector.push_back(Util::getSerialID(seed));//gets the serial ID for the map seed then adds an entry for the key 
    dataVector.push_back(std::to_string(mapSeed));

    //serialization for player position
    keyVector.push_back(Util::getSerialID(position));//gets serial ID for position then adds an entry for map key
    for (int index = 0; index < dataVector.size() - 1; index++)
    {
        dataVector.push_back(std::to_string(getCoords(index)));
    }
    file::fileExport(file::packageData(keyVector, dataVector));
}

void maze::generateMaze()
{
    srand(mapSeed);
    mazeMap[0][0][0] = START;//top left
    mazeMap[MAZE_SIZE - 1][MAZE_SIZE - 1][MAZE_SIZE - 1] = FINISH;//bottom right(5,5,5)
        // Set some walls randomly
        for (int index = 0; index < MAZE_SIZE; index++) {
            for (int jindex = 0; jindex < MAZE_SIZE; jindex++) {
                for (int kindex = 0; kindex < MAZE_SIZE; kindex++) {
                    if (rand() % 3 == 0 && (index != 0 || jindex != 0 || kindex != 0) && (index != MAZE_SIZE - 1 || jindex != MAZE_SIZE - 1 || kindex != MAZE_SIZE - 1)) {
                        mazeMap[index][jindex][kindex] = WALL;
                    }
                }
            }
        }
}

void maze::displayMaze(int x, int y, int z)
{
    system("cls"); // clear the console

    for (int index = 0; index < MAZE_SIZE; index++) {
        for (int jindex = 0; jindex < MAZE_SIZE; jindex++) {
            for (int kindex = 0; kindex < MAZE_SIZE; kindex++) {
                if (index == x && jindex == y && kindex == z) {//is player
                    std::cout << "P";
                }
                else if (mazeMap[index][jindex][kindex] == WALL) {//Player cannot go here
                    std::cout << (char)254u; //extended ASCII 254, the square one
                }
                else if (mazeMap[index][jindex][kindex] == PATH) {//Player can go
                    std::cout << " ";//Blank space
                }
                else if (mazeMap[index][jindex][kindex] == START) {//Start condition
                    std::cout << "S";
                }
                else if (mazeMap[index][jindex][kindex] == FINISH) {//win condition
                    std::cout << "F";
                }
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}

bool maze::movePlayer(int& x, int& y, int& z, int dx, int dy, int dz)
{
    int newX = x + dx;
    int newY = y + dy;
    int newZ = z + dz;

    // Check if the new position is out of bounds or a wall
    if (newX < 0 || newX >= MAZE_SIZE || newY < 0 || newY >= MAZE_SIZE || newZ < 0 || newZ >= MAZE_SIZE || mazeMap[newX][newY][newZ] == WALL) {
        return false;
    }

    // Update the player's position
    mazeMap[x][y][z] = PATH;
    x = newX;
    y = newY;
    z = newZ;
    mazeMap[x][y][z] = PATH;

    return true;
}

bool maze::runMaze(int coordX, int coordY, int coordZ)
{
    //generates new maze
    generateMaze();
    // Initialize the player's position
    int playerX = coordX;
    int playerY = coordY;
    int playerZ = coordZ;

    // Display the maze and player's initial position
    displayMaze(playerX, playerY, playerZ);

    // Loop until the player reaches the finish or quits the game
    while (mazeMap[playerX][playerY][playerZ] != FINISH) {
        // Get the player's input
        char input = _getch();
        // Move the player based on the input
        switch (input) {
        case 'w':
            movePlayer(playerX, playerY, playerZ, -1, 0, 0);
            break;
        case 'a':
            movePlayer(playerX, playerY, playerZ, 0, -1, 0);
            break;
        case 's':
            movePlayer(playerX, playerY, playerZ, 1, 0, 0);
            break;
        case 'd':
            movePlayer(playerX, playerY, playerZ, 0, 1, 0);
            break;
        case 'q':
            movePlayer(playerX, playerY, playerZ, 0, 0, -1);
            break;
        case 'e':
            movePlayer(playerX, playerY, playerZ, 0, 0, 1);
            break;
        case 'x':
            Util::dialog(quit, Util::isError); // quit the game
            loadX = playerX;
            loadY = playerY;
            loadZ = playerZ;
            return false;
            break;
        }
        // Display the updated maze and player's position
        displayMaze(playerX, playerY, playerZ);
    }

    // Display the win message
    std::cout << "Congratulations, you won!\n";
    return true;
}

int maze::getCoords(int index)
{
    switch (index)
    {
    case 0:
        return loadX;
        break;
    case 1:
        return loadY;
    case 2:
        return loadZ;
            break;
    default:
        Util::isError = true;
        Util::dialog(fileError, Util::isError);
    }
}
#ifndef maze_H
#define maze_H

class maze
{
public:
    maze(); // do not move this implementation, will cause linker error 2005
    ~maze();
private:
    bool winState = false;
    int loadX, loadY, loadZ;
    int mapSeed;
    static const int MAZE_SIZE = 5; //this will define dimensions of the maze, could use in difficulty modifier
    const int WALL = -1;
    const int PATH = 0;
    const int START = 1;
    const int FINISH = 2;
    int mazeMap[MAZE_SIZE][MAZE_SIZE][MAZE_SIZE] = { 0 };//Initializes all values of mazeMap to 0
    void generateMaze();
    void displayMaze(int x, int y, int z);
    bool movePlayer(int& x, int& y, int& z, int dx, int dy, int dz);
    bool runMaze(int coordX, int coordY, int coordZ);
    //int getCoords(int index);
};

#endif

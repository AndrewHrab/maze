#include <iostream>
#include <random> 
#include <iomanip>
using namespace std;

void printMaze(vector<vector<char> > maze, int rows, int columns){
    for (int i = 0; i < columns; i++) { 
        for (int j = 0; j < rows; j++){ 
            cout<< maze[i][j]<< " "; 
        } 

    cout<< "\n"; 

    } 
    cout<< "\n\n"; 
}

bool mazeTest(vector<vector<char> > maze, int columns, int rows){
    enum direction{north, south, west, east}facing;
    cout<<"test1"<<endl;
    struct position{
	    int x;
	    int y;
    }traverser;

    int startx, starty;

    if (columns == 5){
        traverser.x = 2;
        startx = 2;
    }
    else if (columns == 11){
        traverser.x = 5;
        startx = 5;
    }
    else {
        traverser.x = 7;
        startx = 7;
    }
    cout<<"test2"<<endl;

    traverser.y = rows - 1;
    starty = rows - 1;

	maze[traverser.y][traverser.x] = 'X';

    int count = 0;

    cout<<traverser.y<<endl;
    cout<<traverser.x<<endl;

	//Finding INITIAL direction
	if ((traverser.y - 1) == 0){
		facing = south;
		printf("TEST: Traverser is facing south\n");
	}

	else if ((traverser.x - 1) == 0){
		facing = east;
		printf("TEST: Traverser is facing east\n");
	}

	else if ((traverser.y + 1) == columns){
		facing = north;
		printf("TEST: Traverser is facing north\n");
	}

	else if ((traverser.x + 1) == rows){
		facing = west;
		printf("TEST: Traverser is facing west\n");
	}

	else {
		printf("ERROR: Could not find initial direction.\n");
	}
    
    while (count < 350){
        while (traverser.x >= 0 || traverser.x <= columns || traverser.y >= 0 || traverser.y <= (rows - 1)){
            if ((traverser.x == startx) && (traverser.y == starty) && (count > 1)){
                return false;
            }
            if (facing == south){
                if (maze[traverser.y + 1][traverser.x] == ' '){
                    traverser.y++;
                    maze[traverser.y][traverser.x] = 'X';
                    facing = west;
                }
                else if (maze[traverser.y][traverser.x - 1] == ' '){
                    traverser.x--;
                    maze[traverser.y][traverser.x] = 'X';
                    facing = south;
                }
                else if (maze[traverser.y - 1][traverser.x] == ' '){
                    traverser.y--;
                    maze[traverser.y][traverser.x] = 'X';
                    facing = east;
                }
                else if (maze[traverser.y][traverser.x + 1] == ' '){
                    traverser.x++;
                    //maze[traverser.y][traverser.x] = 'X';
                    facing = north;
                }
                else if (maze[traverser.y + 1][traverser.x] == 'X'){
                    maze[traverser.y][traverser.x] = 'O';
                    traverser.y++;
                    
                    facing = west;
                }
                else if (maze[traverser.y][traverser.x - 1] == 'X'){
                    maze[traverser.y][traverser.x] = 'O';
                    traverser.x--;
                    
                    facing = south;
                }
                else if (maze[traverser.y - 1][traverser.x] == 'X'){
                    maze[traverser.y][traverser.x] = 'O';
                    traverser.y--;
                    
                    facing = east;
                }
                else if (maze[traverser.y][traverser.x + 1] == 'X'){
                    maze[traverser.y][traverser.x] = 'O';
                    traverser.x++;
                    
                    facing = north;
                }
            }

            else if (facing == west){
                if (maze[traverser.y][traverser.x + 1] == ' '){ // || maze[traverser.x + 1][traverser.y] != columns
                    traverser.x++;
                    maze[traverser.y][traverser.x] = 'X';
                    facing = north;
                }
                else if (maze[traverser.y + 1][traverser.x] == ' '){
                    traverser.y++;
                    maze[traverser.y][traverser.x] = 'X';
                    facing = west;
                }
                else if (maze[traverser.y][traverser.x - 1] == ' '){
                    traverser.x--;
                    maze[traverser.y][traverser.x] = 'X';
                    facing = south;
                }
                else if (maze[traverser.y - 1][traverser.x] == ' '){
                    traverser.y--;
                    //maze[traverser.y][traverser.x] = 'X';	
                    facing = east;
                }
                else if (maze[traverser.y][traverser.x + 1] == 'X'){
                    maze[traverser.y][traverser.x] = 'O';
                    traverser.x++;
                    
                    facing = north;
                }
                else if (maze[traverser.y + 1][traverser.x] == 'X'){
                    maze[traverser.y][traverser.x] = 'O';
                    traverser.y++;
                    
                    facing = west;
                }
                else if (maze[traverser.y][traverser.x - 1] == 'X'){
                    maze[traverser.y][traverser.x] = 'O';
                    traverser.x--;
                    
                    facing = south;
                }
                else if (maze[traverser.y - 1][traverser.x] == 'X'){
                    maze[traverser.y][traverser.x] = 'O';
                    traverser.y--;
                    
                    facing = east;
                }
            }

            else if (facing == east){
                if (maze[traverser.y][traverser.x - 1] == ' '){
                    traverser.x--;
                    maze[traverser.y][traverser.x] = 'X';
                    facing = south;
                }
                else if (maze[traverser.y  - 1][traverser.x] == ' '){
                    traverser.y--;
                    maze[traverser.y][traverser.x] = 'X';
                    facing = east;
                }
                else if (maze[traverser.y][traverser.x + 1] == ' '){
                    traverser.x++;
                    maze[traverser.y][traverser.x] = 'X';
                    facing = north;
                }
                else if (maze[traverser.y + 1][traverser.x] == ' '){
                    traverser.y++;
                    //maze[traverser.y][traverser.x] = 'X';
                    facing = west;
                }
                else if (maze[traverser.y][traverser.x - 1] == 'X'){
                    maze[traverser.y][traverser.x] = 'O';
                    traverser.x--;
                    
                    facing = south;
                }
                else if (maze[traverser.y - 1][traverser.x] == 'X'){
                    maze[traverser.y][traverser.x] = 'O';
                    traverser.y--;
                    
                    facing = east;
                }
                else if (maze[traverser.y][traverser.x + 1] == 'X'){
                    maze[traverser.y][traverser.x] = 'O';
                    traverser.x++;
                    
                    facing = north;
                }
                else if (maze[traverser.y + 1][traverser.x] == 'X'){
                    maze[traverser.y][traverser.x] = 'O';
                    traverser.y++;
                    
                    facing = west;
                }
            }

            else { //if facing == south
                if (maze[traverser.y  - 1][traverser.x] == ' '){
                    traverser.y--;
                    maze[traverser.y][traverser.x] = 'X';
                    facing = east;
                }
                else if (maze[traverser.y][traverser.x + 1] == ' '){
                    traverser.x++;
                    maze[traverser.y][traverser.x] = 'X';
                    facing = north;
                }
                else if (maze[traverser.y + 1][traverser.x] == ' '){
                    traverser.y++;
                    maze[traverser.y][traverser.x] = 'X';
                    facing = west;
                }
                else if (maze[traverser.y][traverser.x - 1] == ' '){
                    traverser.x--;
                    //maze[traverser.y][traverser.x] = 'X';
                    facing = south;
                }
                else if (maze[traverser.y - 1][traverser.x] == 'X'){
                    maze[traverser.y][traverser.x] = 'O';
                    traverser.y--;
                    
                    facing = east;
                }
                else if (maze[traverser.y][traverser.x + 1] == 'X'){
                    maze[traverser.y][traverser.x] = 'O';
                    traverser.x++;
                    
                    facing = north;
                }
                else if (maze[traverser.y + 1][traverser.x] == 'X'){
                    maze[traverser.y][traverser.x] = 'O';
                    traverser.y++;
                    facing = west;
                    
                }
                else if (maze[traverser.y][traverser.x - 1] == 'X'){
                    maze[traverser.y][traverser.x] = 'O';
                    traverser.x--;
                    
                    facing = south;
                }
            }
            
            printMaze(maze, columns, rows);
            if (traverser.y == 0){return true;}
            else{
                count++;
            }
            if (count == 350){
                return false;
            }
            cout<<"Got out"<<endl;
        }   
    }
    cout<<"Got out not supposed to"<<endl;
    return false;
}

void newMaze(int rows, int columns, int level){
    vector<vector<char> > maze( rows , vector<char> (columns, 0)); 
	uniform_int_distribution<int> dis(0,2);
    bool isMaze = false;
    int seed = 0, tester = 0;
    //cout << seed << endl;

    if (level == 1){
        tester = 2; 
    }
    else if (level == 2){
        tester = 5;
    }
    else { tester = 7;}

    while (isMaze == false){
    
        mt19937 engine{seed};

        for (int i = 0; i < rows; i++) { 

            for (int j = 0; j < columns; j++){ 
                
                int num = dis(engine);
                
                if (j == (columns - 1)){
                    maze[i][j] = '#';
                }
                else if (j == tester && (i == (rows - 2))){
                    maze[i][j] = ' ';
                }
                else if (j == tester && (i == (rows - 1))){
                    maze[i][j] = ' ';
                }
                else if (i == (rows - 1)){
                    maze[i][j] = '#';
                }
                else if (j == 0){
                    maze[i][j] = '#';
                }
                else{
                    if(num == 0 || num == 1){
                        maze[i][j] = ' ';
                    }

                    else{
                        maze[i][j] = '#';
                    } 
                }
            } 
        } 
        printMaze(maze, columns, rows);
        if (mazeTest(maze, columns, rows)){
            isMaze = true;
            cout << "Maze is good" << endl;
        }
        else{
            cout << "Maze is not good" << endl;
            seed++;
        }
    }
}



int main()
{
    int rows = 5;
    int columns = 5;
    int level = 0;

    cout << "How hard would you like the maze?" << endl;
    cout << "From a scale of 1-3?" << endl;
    cin >> level;

    if(level == 1){
        rows = 5;
        columns = 5;
    }
    else if(level == 2){
        rows = 11;
        columns = 11;
    }
    else if(level == 3){
        rows = 15;
        columns = 15;
    }

    newMaze(columns, rows, level);

    cout << "Got here 1" << endl;
}
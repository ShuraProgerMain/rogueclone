#include <iostream>
#include <windows.h>
#include <conio.h>
#include "CustomMatrix.cpp"
#include "CustomVectors.h"

using namespace std;

const int width = 4;
const int height = 4;
const char player = 254;

Vector2 playerPosition = { 3, 0 };

char fuckArray[width][height]{};

void Update()
{
    system("cls");
    for (int w = 0; w < width; w++)
    {
        for (int h = 0; h < height; h++)
        {
            char current = fuckArray[w][h];
            cout << current << (char)32;
        }

        cout << endl;
    }
};

void ClearUpdate()
{
    system("cls");
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            fuckArray[h][w] = 249;
            char current = fuckArray[h][w];
            cout << current << (char)32;
        }

        cout << endl;
    }
};

void MoveVertical(bool isUp)
{
    int currentY = playerPosition.y;
    int nextY = isUp ? currentY - 1 : currentY + 1;
    
    if (nextY >= height)
    {
        nextY = 0;
    }
    else if (nextY < 0)
    {
        nextY = height - 1;
    }

    playerPosition.y = nextY;

    ClearUpdate();
    fuckArray[playerPosition.y][playerPosition.x] = player;
    Update();
};

void MoveHorizontal(bool isRight)
{
    int currentX = playerPosition.x;
    int nextX = isRight ? currentX + 1 : currentX - 1;
    
    if (nextX >= width)
    {
        nextX = 0;
    }
    else if (nextX < 0)
    {
        nextX = width - 1;
    }

    playerPosition.x = nextX;

    ClearUpdate();
    fuckArray[playerPosition.y][playerPosition.x] = player;
    Update();
};

void GenerateRoom()
{
    char vertical = char(186);
    char horizontal = char(205);

    srand(time(NULL));
    int srnd = rand() + 1000 - 123123;
    srand(srnd);
    Vector2 vec;
    vec.y = rand() % 25 + 10;
    vec.x = (vec.y / 2) + (rand() % 5);
    //cout << "x:"<< vec.x << " y:" << vec.y;
    CustomMatrix<char> cm(vec.x, vec.y);

    int minX = 0;
    int minY = 0;
    int maxX = vec.x - 1;
    int maxY = vec.y - 1;

    for (int i = 0; i < vec.x; i++)
    {
        for (int j = 0; j < vec.y; j++)
        {
            char value = char(249);
            char potentialSpace = char(32);

            if ((i == minX || i == maxX) && j < (maxY))
            {
                value = horizontal;
                potentialSpace = horizontal;
            }
            else if (j == minY || j == maxY)
            {
                value = vertical;
            }

            if (i == minX && j == minY)
            {
                value = char(201); //LeftTopAngle
            }
            else if (i == minX && j == maxY)
            {
                value = char(187); //RightTopAngle
            }
            else if (i == maxX && j == minY)
            {
                value = char(200); //LeftBottomAngle
            }
            else if (i == maxX && j == maxY)
            {
                value = char(188); //RightBottomAngle
            }

            cout << value << potentialSpace;
        }

        cout << "\n";
    }
}

int main()
{
    //ClearUpdate();
    //fuckArray[playerPosition.y][playerPosition.x] = player;
    //Update();

    //while (true)
    //{
    //    if (_kbhit()) // слушатель нажатия на клаву
    //    {

    //        switch (_getch()) // ждёт нажатия на клаву без Enter после этого
    //        {
    //        case 72: //вверх
    //            //cout << "Up" << endl;
    //            MoveVertical(true);
    //            break;
    //        case 80: //вниз
    //            //cout << "Down" << endl;
    //            MoveVertical(false);
    //            break;
    //        case 75: //влево 
    //            //cout << "left" << endl;
    //            MoveHorizontal(false);
    //            break;
    //        case 77: //вправо
    //            //cout << "Right" << endl;
    //            MoveHorizontal(true);
    //            break;
    //        }
    //    }
    //}

    GenerateRoom();
    //cout << cm.GetVectorIndex(vec) << " Index";
    /*for (int i = 0; i < 255; i++)
    {
        cout << "code = " << i << "\t" << "char = " << (char)i;
    }*/

    //cout << "Hello World!\n";
    //system("cls");
}





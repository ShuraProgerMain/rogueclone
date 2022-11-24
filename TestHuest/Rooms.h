#include "CustomVectors.h"

#ifndef Rooms
#define Rooms


enum CellType
{
	Free = 0,
	Wall = 1
};

struct Cell
{
public:
	Vector2 point;
	CellType cellType;
	char ASCIISymbol;
};
#endif
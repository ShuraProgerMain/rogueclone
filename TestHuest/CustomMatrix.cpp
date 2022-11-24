#include <vector>
#include "CustomVectors.h"
#include "Rooms.h"
#include <iostream>

using namespace std;

template <typename T>
class CustomMatrix
{
public:
	CustomMatrix(int rows, int columns);
	int GetVectorIndex(Vector2 vec);
private:
	std::vector<Cell> _currentCells;
	int _rows;
	int _columns;
};

template <typename T>
CustomMatrix<T>::CustomMatrix(int rows, int columns)
{
	_rows = rows;
	_columns = columns;
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			Cell newCell;
			Vector2 vect_2;
			vect_2.x = i;
			vect_2.y = j;
			newCell.point = vect_2;
			newCell.cellType = CellType::Free;
			newCell.ASCIISymbol = char(249);

			_currentCells.push_back(newCell);
		}
	}
}

template <typename T>
int CustomMatrix<T>::GetVectorIndex(Vector2 vec)
{
	int position = vec.x * _rows +  vec.y;
	Vector2 val = _currentCells[position].point;
	cout << val.x << (char) 32 << val.y << endl;

	return position;
}

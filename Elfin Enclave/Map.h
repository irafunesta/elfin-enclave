#pragma once
#include <string>
#include <vector>
#include <list>
#include "Entity.h"


class Map
{
public:
	Map();
	~Map();

	int LoadMap(std::string MapFile);
	char GetMapTile(int X, int Y);
	/*void SetMapTile(int x, int y, char tile)
	{
		_mapEntity;
	};*/
	std::vector<std::string> GetBaseMap() const
	{
		return _map;
	};
		
	void PrintMap(std::vector<Entity*> entities);
	void SetMapTile(int x, int y, char tile);
private:
	int  _width = 4;
	int _heigth = 4;

	std::vector<std::string> _map;
	std::vector<std::string> _mapEntity;
};


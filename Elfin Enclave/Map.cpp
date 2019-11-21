#include <iostream>
#include <cstdlib>
#include <fstream>
#include <Windows.h>
#include "Map.h"
#include "Position.h"

Map::Map()
{

}

Map::~Map()
{
}

int Map::LoadMap(std::string MapFile)
{
	//Load the map from the specified txt file
	std::ifstream InputFile;
	std::ofstream OutputFile;
	InputFile.open(MapFile);
	std::string InLine;
	if (!InputFile.fail())
	{
		while(std::getline(InputFile, InLine))
		{
			_map.push_back(InLine);
		}
	}
	else
	{
		std::perror(MapFile.c_str());
		return 1;
	}
	return 0;
}

char Map::GetMapTile(int X, int Y)
{
	return _map[Y][X];
}

void Map::PrintMap(std::vector<Entity*> entities)
{
	_mapEntity = _map;

	// Add entities to the map
	for (int i = 0; i < entities.size(); i++) {
		Position ent = entities[i]->GetPosition();
		_mapEntity[ent.y][ent.x] = entities[i]->GetSymbol();
	}

	// Draw the whole map
	for (int i = 0; i < _mapEntity.size(); i++) {
		std::cout << _mapEntity[i] << std::endl;
	}
}

void Map::SetMapTile(int x, int y, char tile)
{
	_map[y][x] = tile;
}

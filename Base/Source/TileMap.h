#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <string>
#include "Vector3.h"
#include "Character\Character.h"
#include "Enemy\EnemySpawner.h"

using std::vector;
using std::string;


struct Obstacle
{
	Obstacle(int type, int cost) { this->type = type; this->cost = cost; }
	Obstacle(int x, int y, int type, int cost) { pos.x = x; pos.y = y; this->type = type; this->cost = cost; }
	~Obstacle() {}
	int type;
	int cost;
	Vector2 pos;
};

class TileMap
{
public:
	TileMap();
	~TileMap();
	
	void Init(int screenHeight, int screenWidth, int numTilesHeight, int numTilesWidth, EnemySpawner *spawner);
	void Update(double dt);

	int screenHeight, screenWidth, numTilesHeight, numTilesWidth;
	float tileSizeX, tileSizeY;
	vector<vector<int> > theScreenMap;

	CharactersList characters;
	CharactersList enemies;
	
	vector<Obstacle> obstacleList;
	vector<Vector2> movePath;

	vector<Vector2> enemySpawnPoints;
	vector<Vector2> playerSpawnPoints;

	bool LoadMap(const string mapName);
	void Render();

	void AddCharacter(int x, int y, Character* unit);
	Character *GetCharacter(int x, int y);

	void AddEnemy(int x, int y, Character* unit);
	Character *GetEnemy(int x, int y);

	void ResetCharacters();
	void ResetEnemies();

	void AddObstacle(int x, int y, int type, int cost);
	Obstacle GetObstacle(int x, int y);
	void ClearCharacters();

	void RemovePlayer(Character *character);
	void RemoveEnemy(Character *character);
private:
	EnemySpawner *spawner;
};


#endif
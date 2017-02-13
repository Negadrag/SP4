#ifndef SCENE_TEXT_H
#define SCENE_TEXT_H

#include "Scene.h"
#include "Mtx44.h"
#include "PlayerInfo/PlayerInfo.h"
#include "GroundEntity.h"
#include "FPSCamera.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "GenericEntity.h"
#include "SceneGraph/UpdateTransformation.h"
#include "Enemy\Enemy.h"
#include <vector>
#include "Sounds/Music.h"
#include "Ally\Turret.h"
#include "Lua\LuaInterface.h"

class ShaderProgram;
class SceneManager;
class TextEntity;
class Light;

using std::vector;

class SceneText : public Scene
{	
public:
	SceneText();
	~SceneText();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

private:
	//SceneText(SceneManager* _sceneMgr); // This is used to register to SceneManager

	ShaderProgram* currProg;
	CPlayerInfo* playerInfo;
	GroundEntity* groundEntity;
	FPSCamera camera;
	TextEntity* textObj[6];
	Light* lights[2];

	GenericEntity* theCube;

	vector<CEnemy*> enemyList;

	float enemySpawnTimer;

	//static SceneText* sInstance; // The pointer to the object that gets registered

	CEnemy* SpawnEnemy();

	void ClearEnemies();

	bool spawnEnemyNext;

	int m_iLives;
	int m_iScore;

	CTurret *turret;

	ISound* BGM;

	Vector3 waypoints[4];

	bool died;
};

#endif
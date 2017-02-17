#ifndef BATTLESCENE_H
#define BATTLESCENE_H

#include "Scene.h"
#include "Mtx44.h"
#include "GroundEntity.h"
#include "FPSCamera.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "GenericEntity.h"
#include "SceneGraph/UpdateTransformation.h"
#include <vector>
#include "Sounds/Music.h"
#include "Lua\LuaInterface.h"
#include "Character/MeleeCharacter.h"
#include "Character/Weapon.h"
#include "PlayerInfo.h"
#include "DamageText.h"

class ShaderProgram;
class SceneManager;
class TextEntity;
class Light;

using std::vector;

class BattleScene : public Scene
{
public:
	BattleScene();
	~BattleScene();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

	void RunBattleAnimation(double dt, bool ranged, int dmgvalue);
	void RenderProps();
	void TakenHitAnimation(float& type_pos);
	void RenderSkyBox();

	/*RenderTextStuff 
	- runs animation and appearance of Totaldamage Counter and Effects
	- Removes completed damage text through list*/
	void RenderTextStuff(double dt, int dmgvalue);

	void SetBattleBonus(bool _isBonus) { b_bonusRush = _isBonus; }
	bool GetBattleBonus() { return b_bonusRush; }


private:
	ShaderProgram* currProg;
	//CPlayerInfo* playerInfo;
	GroundEntity* groundEntity;
	FPSCamera camera;
	//TextEntity* textObj[6];
	Light* lights[2];
	MeleeCharacter* player;

	float player_posx;
	float enemy_posx;


	vector<DamageText*> storeDmgTxt;
	TextEntity* TotalDamage;
	TextEntity* TotalDmgCheer;
	int i_totaldmg_txt;
	float f_textDelayOnScreen;

	bool b_isClashed;
	bool b_bonusRush;
	bool b_spamLock;

	float f_SceneIntroDelay;

	float fps;

	ISound* BGM;
};

#endif
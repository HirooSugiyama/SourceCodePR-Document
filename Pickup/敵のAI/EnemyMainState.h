/*
๓ิState๐วท้๑^Q
์ฌาFR
์ฌ๚F2022/02/07
*/
#pragma once



enum class EnemyMainState
{
	CREATE_BEFORE,	//ถฌO
	MOVE,			//ฺฎ
	DAMAGE,			//ฝฎ
	DISAPPEARANCE,	//มล
};


enum class EnemyCreateBeforeState
{
	APPEARANCE,	//oป
	SINKING		//พv
};

enum class EnemyMoveState
{
	WALK,		//เs
	ROTATION,	//๑]
	WALL_ATTACK	//วU
};

enum class EnemyDamageState
{
	KNOCK_BACK,	//ฝฎ
	BLINKING,	//_ล
};
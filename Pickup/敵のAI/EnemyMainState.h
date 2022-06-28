/*
���State���Ǘ�����񋓌^�Q
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#pragma once



enum class EnemyMainState
{
	CREATE_BEFORE,	//�����O
	MOVE,			//�ړ�
	DAMAGE,			//����
	DISAPPEARANCE,	//����
};


enum class EnemyCreateBeforeState
{
	APPEARANCE,	//�o��
	SINKING		//���v
};

enum class EnemyMoveState
{
	WALK,		//���s
	ROTATION,	//��]
	WALL_ATTACK	//�ǍU��
};

enum class EnemyDamageState
{
	KNOCK_BACK,	//����
	BLINKING,	//�_��
};
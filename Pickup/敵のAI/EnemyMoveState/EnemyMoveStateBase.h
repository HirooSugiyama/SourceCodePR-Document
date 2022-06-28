/*
�G�ړ�State���N���X
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#pragma once

//�O���錾
class EnemyMainStateMove;
class Enemy;

class EnemyMoveStateBase
{
private:

	//����
	static const float FRONT;

	//���L�҂̃|�C���^
	EnemyMainStateMove* mpEnemyMainState;
	Enemy* mpEnemy;

public:

	//�R���X�g���N�^
	EnemyMoveStateBase();
	//�f�X�g���N�^
	virtual ~EnemyMoveStateBase();
	//����������
	virtual void Initialize(Enemy* pEnemy, EnemyMainStateMove* pEnemyMainState) = 0;
	//���Z�b�g����
	virtual void Reset() = 0;
	//�X�V����
	virtual void Update() = 0;
	//�A�N�Z�T
	EnemyMainStateMove* GetEnemyMainState()const { return mpEnemyMainState; }
	void SetEnemyMainState(EnemyMainStateMove* pEnemyMainState) { mpEnemyMainState = pEnemyMainState; }

	Enemy* GetEnemy()const { return mpEnemy; }
	void SetEnemy(Enemy* pEnemy) { mpEnemy = pEnemy; }

	//����
	float GetFrontAngle()const { return FRONT; }
};

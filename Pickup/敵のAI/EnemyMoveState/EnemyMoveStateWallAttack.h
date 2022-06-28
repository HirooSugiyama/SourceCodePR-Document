/*
�G�ړ�State�@�`�ǍU���`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#pragma once

//���N���X
#include"EnemyMoveStateBase.h"

class Block;

class EnemyMoveStateWallAttack : public EnemyMoveStateBase
{
private:

	//�U���C���^�[�o��
	static const int ENEMY_ATTACK_INTERVAL;

	//�G�̍U����
	static const int ENEMY_ATTACK_POWER;


	//�v���ϐ�
	int mCurrentNum;

public:

	//�R���X�g���N�^
	EnemyMoveStateWallAttack();
	//�f�X�g���N�^
	~EnemyMoveStateWallAttack()override;
	//����������
	void Initialize(Enemy* pEnemy,EnemyMainStateMove* pEnemyMainState)override;
	//���Z�b�g����
	void Reset()override;
	//�X�V����
	void Update()override;

	//�U������^�C�~���O�v���֐�
	bool AttackTiming();
};

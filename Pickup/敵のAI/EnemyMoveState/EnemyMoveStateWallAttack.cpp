/*
�G�ړ�State�@�`�ǍU���`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#include"pch.h"
#include"EnemyMoveStateWallAttack.h"

//�O���錾
#include"../../Enemy.h"


//�U���C���^�[�o��
const int EnemyMoveStateWallAttack::ENEMY_ATTACK_INTERVAL = 60;

//�G�̍U����
const int EnemyMoveStateWallAttack::ENEMY_ATTACK_POWER = 1;

/*===================================
�R���X�g���N�^
�����F�Ȃ�
===================================*/
EnemyMoveStateWallAttack::EnemyMoveStateWallAttack()
	:
	EnemyMoveStateBase(),
	mCurrentNum(0)
{
}

/*===================================
�f�X�g���N�^
===================================*/
EnemyMoveStateWallAttack::~EnemyMoveStateWallAttack()
{
}

/*===================================
����������
�����F�G�̃|�C���^�A�G�̍s��State
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMoveStateWallAttack::Initialize
(
	Enemy* pEnemy,
	EnemyMainStateMove* pEnemyMainState
)
{
	//�|�C���^��ۑ�����
	EnemyMoveStateBase::SetEnemyMainState(pEnemyMainState);
	EnemyMoveStateBase::SetEnemy(pEnemy);

}

/*===================================
���Z�b�g����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMoveStateWallAttack::Reset()
{
	//���ʂ�������
	EnemyMoveStateBase::GetEnemy()->GetEnemyModel()->SetRotationY(EnemyMoveStateBase::GetFrontAngle());

}

/*===================================
�X�V����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMoveStateWallAttack::Update()
{
	bool flag = *EnemyMoveStateBase::GetEnemyMainState()->GetAttackBlock();
	if (flag)
	{
		mCurrentNum++;
	}
	//�Ώۂ̕ǂ����g�p��ԂƂȂ�����
	else
	{
		//���s��Ԃ�
		EnemyMoveStateBase::GetEnemyMainState()->ChangeStateWalk();
		
	}

}

/*=============================================
�U������^�C�~���O�v���֐�
�����F�Ȃ�
�Ԃ�l�F�U�����邩�ۂ�(true�F�U������)
=============================================*/
bool EnemyMoveStateWallAttack::AttackTiming()
{

	//�U������^�C�~���O��������
	if (mCurrentNum >= ENEMY_ATTACK_INTERVAL)
	{
		//�l������������
		mCurrentNum = 0;

		return true;
	}

	return false;
}

/*
�G�ړ�State���N���X
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#include"pch.h"
#include"EnemyMoveStateBase.h"

//�O���錾
#include"../EnemyMainStateMove.h"
#include"../../Enemy.h"


//����
const float EnemyMoveStateBase::FRONT = 180.f;

/*===================================
�R���X�g���N�^
�����F�Ȃ�
===================================*/
EnemyMoveStateBase::EnemyMoveStateBase()
	:mpEnemyMainState()
	, mpEnemy()
{
}

/*===================================
�f�X�g���N�^
===================================*/
EnemyMoveStateBase::~EnemyMoveStateBase()
{
}
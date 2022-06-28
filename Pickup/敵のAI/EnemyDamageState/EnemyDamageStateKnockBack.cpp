/*
�G�_���[�WState�@�`�����`
�쐬�ҁF���R
�쐬���F2022/02/09
*/
#include"pch.h"
#include "EnemyDamageStateKnockBack.h"

//�֐��̎g�p
#include"../../Enemy.h"


//�G���f�����W����̓����蔻��̍��̋���(�����蔻��̍��W)
const DirectX::SimpleMath::Vector3 EnemyDamageStateKnockBack::ESTATE_COLLIDER_POSITION(0.f, 0.f, 1.f);

//�g�嗦(�����蔻��)
const DirectX::SimpleMath::Vector3 EnemyDamageStateKnockBack::ESTATE_COLLIDER_SCALE(0.525f, 0.125f, 0.125f);

//�ړ����x
const float EnemyDamageStateKnockBack::ENEMY_MOVE_SPEED = 0.5f;

//���x������
const float EnemyDamageStateKnockBack::ENEMY_MOVE_SPEED_DECREASE = 0.7f;

//���x�ŏ��l
const float EnemyDamageStateKnockBack::ENEMY_MIN_VELOCITY = 0.0001f;

//�ړ��x�N�g��������������
const float EnemyDamageStateKnockBack::ENEMY_MOVE_VELOCITY_SMALL = 0.5f;

//�ړ��x�N�g���𔽓]������
const float EnemyDamageStateKnockBack::ENEMY_MOVE_VELOCITY_REVERSE = -1.f;

/*===================================
�R���X�g���N�^
�����F�Ȃ�
===================================*/
EnemyDamageStateKnockBack::EnemyDamageStateKnockBack()
	:
	EnemyDamageStateBase(),
	mMoveVec()
{
}

/*===================================
�f�X�g���N�^
===================================*/
EnemyDamageStateKnockBack::~EnemyDamageStateKnockBack()
{
}

/*==================================
����������
�����F�G�̃|�C���^�A�G�̍s��State
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyDamageStateKnockBack::Initialize(Enemy* pEnemy, EnemyMainStateDamage* pEnemyMainState)
{
	//�|�C���^��ۑ�
	EnemyDamageStateBase::SetEnemyMainState(pEnemyMainState);
	EnemyDamageStateBase::SetEnemy(pEnemy);
}

/*===================================
���Z�b�g����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyDamageStateKnockBack::Reset()
{
	mMoveVec = DirectX::SimpleMath::Vector3::Zero;
}

/*==================================
�X�V����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyDamageStateKnockBack::Update()
{
	//�ϊ��p�ϐ��̐錾
	DirectX::SimpleMath::Vector3 vel;

	vel -= mMoveVec;

	//���x������������
	mMoveVec *= ENEMY_MOVE_SPEED_DECREASE;

	//���f�����ړ�������
	EnemyDamageStateBase::GetEnemy()->GetEnemyModel()->Move(vel);

	//�������x��0�ɋ߂Â�����
	if (this->Vector3Max(mMoveVec) <= ENEMY_MIN_VELOCITY)
	{
		//������Ԃ�
		EnemyDamageStateBase::GetEnemyMainState()->ChangeStateBlinking();
	}
}

/*===================================
�`�揈��
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyDamageStateKnockBack::Draw()
{
	//���f���̕`��
	EnemyDamageStateBase::GetEnemy()->GetEnemyModel()->Draw();
}


/*=======================
�ړ��x�N�g���ۑ��p�ϐ�
�����F�ړ��x�N�g��
�Ԃ�l�F�Ȃ�
=========================*/
void EnemyDamageStateKnockBack::SetMoveVector(const DirectX::SimpleMath::Vector3& movevec)
{
	mMoveVec = movevec;
}

/*====================================================
�ړ��x�N�g�����X�P�[�����O
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
====================================================*/
void EnemyDamageStateKnockBack::MoveVectorScaling()
{
	//���K��
	mMoveVec.Normalize();

	//���]
	mMoveVec *= ENEMY_MOVE_VELOCITY_REVERSE;

	//�X�P�[�����O
	mMoveVec *= ENEMY_MOVE_VELOCITY_SMALL;
}

/*====================================================
Vector3�̂����̍ł��傫���l��Ԃ��֐�:private
�����FVector3�^�̒l
�Ԃ�l�F�������̍ő�l
====================================================*/
float EnemyDamageStateKnockBack::Vector3Max(const DirectX::SimpleMath::Vector3& num)
{
	//�����l�Ƃ���X�̒l������
	float returnnum = std::fabs(num.x);

	//Y�̂ق����傫�����
	if (returnnum < std::fabs(num.y))
	{
		//Y������
		returnnum = num.y;
	}
	//Z�̂ق����傫�����
	if (returnnum < std::fabs(num.z))
	{
		//Z������
		returnnum = num.z;
	}

	//�ő�l��Ԃ�
	return returnnum;
}


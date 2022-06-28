/*
�G�ړ�State�@�`���s�`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#include"pch.h"
#include"EnemyMoveStateWalk.h"

//�O���錾
#include"../../Enemy.h"



//�ړ����x
const float EnemyMoveStateWalk::ENEMY_MOVE_SPEED = 0.03f;

const float EnemyMoveStateWalk::SHIFT_ANGLE = 270.f;

/*===================================
�R���X�g���N�^
�����F�Ȃ�
===================================*/
EnemyMoveStateWalk::EnemyMoveStateWalk()
	:EnemyMoveStateBase()
	, mPlayerChaseFlag()
	, mChaseVelocity()
	, mEnemyMoveVelocity()
	, mChasePlayerPositon(nullptr)
{
}

/*===================================
�f�X�g���N�^
===================================*/
EnemyMoveStateWalk::~EnemyMoveStateWalk()
{
}

/*===================================
����������
�����F�G�̃|�C���^�A�G�̍s��State
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMoveStateWalk::Initialize
(
	Enemy* pEnemy,
	EnemyMainStateMove* pEnemyMainState
)
{
	//�|�C���^��ۑ�����
	EnemyMoveStateBase::SetEnemyMainState(pEnemyMainState);
	EnemyMoveStateBase::SetEnemy(pEnemy);
}

/*==================================
State�ύX�O�̃��Z�b�g����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMoveStateWalk::Reset()
{
	//�ړ��ʂ��Z�o����
	this->CalculationMoveVelocity();

	//�ǐՃt���O������
	mPlayerChaseFlag = false;
}

/*==================================
�X�V����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMoveStateWalk::Update()
{
	//�ǂ�������ԂȂ��
	if (mPlayerChaseFlag)
	{
		//�ǔ����x�ݒ�
		this->ChaseVelocity();

		//�����w��
		this->RotEnemyForTarget();

		//�ǔ�����
		this->Chase();
	}
	else
	{
		//�ړ�����
		this->Move();
	}
}

/*=====================
������ύX����
�����F�Ώۂ̍��W
�Ԃ�l�F�Ȃ�
======================*/
void EnemyMoveStateWalk::RotEnemyForTarget()
{
	//���S�_
	DirectX::SimpleMath::Vector3 nierPosition = *mChasePlayerPositon;
	//���S�_���獡�̂���ʒu�̃x�N�g��
	DirectX::SimpleMath::Vector3 toVec = nierPosition - EnemyMoveStateBase::GetEnemy()->GetEnemyModel()->GetPosition();

	//�����A�Ώۂ��G��艜�ɂ����ԂȂ�ΓG�͒��i�Ƃ���
	if (toVec.z <= 0)
	{
		//�ǐՃt���O������
		mPlayerChaseFlag = false;

		//���������Z�b�g����
		EnemyMoveStateBase::GetEnemyMainState()->ResetEnemyAngle();
	}
	else
	{
		//�@���x�N�g��
		DirectX::SimpleMath::Vector3 vel = DirectX::SimpleMath::Vector3::Left;
		//�Ȃ��p
		float angle = std::acosf(toVec.Dot(vel) / (toVec.Length() * vel.Length()));
		angle = DirectX::XMConvertToDegrees(angle) + Utility::RIGHT_ANGLE;
		//�Ȃ��p�����f���̊p�x�ɂ���
		EnemyMoveStateBase::GetEnemy()->GetEnemyModel()->SetRotationY(angle);
	}
}


/*==================================
�ړ��ʂ��Z�o
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMoveStateWalk::CalculationMoveVelocity()
{
	//���݂̊p�x���擾
	float angle = EnemyMoveStateBase::GetEnemy()->GetEnemyModel()->GetRotAngleY();

	//360�x�␳
	if (angle > 360.f)
	{
		angle = EnemyMoveStateBase::GetEnemy()->GetEnemyModel()->GetRotAngleY() - 360.f;
		EnemyMoveStateBase::GetEnemy()->GetEnemyModel()->SetRotationY(angle);
	}

	//���W�A���ϊ�
	angle = DirectX::XMConvertToRadians(angle + SHIFT_ANGLE);

	//�ړ��ʂ𐶐�
	mEnemyMoveVelocity.x = cosf(angle);
	mEnemyMoveVelocity.z = sinf(angle);
	mEnemyMoveVelocity.x *= -ENEMY_MOVE_SPEED;
	mEnemyMoveVelocity.z *= ENEMY_MOVE_SPEED;
}


/*==================================
�ǔ����x�ݒ�Fprivate
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMoveStateWalk::ChaseVelocity()
{
	//�ΏۂƂ̋����𑪒�
	DirectX::SimpleMath::Vector3 distance;
	distance = *mChasePlayerPositon - EnemyMoveStateBase::GetEnemy()->GetEnemyModel()->GetPosition();

	distance.Normalize();		//���K��

	mChaseVelocity.x = distance.x * ENEMY_MOVE_SPEED;
	mChaseVelocity.z = distance.z * ENEMY_MOVE_SPEED;
}

/*===================================
�ړ������Fprivate
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMoveStateWalk::Move()
{
	//�ړ�������
	EnemyMoveStateBase::GetEnemy()->GetEnemyModel()->Move(mEnemyMoveVelocity);
}

/*===================================
�ǔ������Fprivate
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMoveStateWalk::Chase()
{
	//�ړ�������
	EnemyMoveStateBase::GetEnemy()->GetEnemyModel()->Move(mChaseVelocity);
}

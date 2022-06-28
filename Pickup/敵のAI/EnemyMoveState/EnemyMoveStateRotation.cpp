/*
�G�ړ�State�@�`��]�`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#include"pch.h"
#include"EnemyMoveStateRotation.h"

//�O���錾
#include"../../Enemy.h"

//�g�嗦(�����蔻��)
const DirectX::SimpleMath::Vector3 EnemyMoveStateRotation::ESTATE_COLLIDER_SCALE(0.25f, 0.125f, 0.125f);

//��]�X�s�[�h
const float EnemyMoveStateRotation::ESTATE_ROT_SPEED = 1.5f;

const float EnemyMoveStateRotation::ROTATION_AFTER_ANGLE = 90.f;


/*===================================
�R���X�g���N�^
�����F�Ȃ�
===================================*/
EnemyMoveStateRotation::EnemyMoveStateRotation()
	:EnemyMoveStateBase()
	, mRotationNowAngle()
	, mRotationAngle()
	, mRotationVelocity()
{
}

/*===================================
�f�X�g���N�^
===================================*/
EnemyMoveStateRotation::~EnemyMoveStateRotation()
{
}

/*==================================
����������
�����F�G�̃|�C���^�A�G�̍s��State
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMoveStateRotation::Initialize
(
	Enemy* pEnemy,
	EnemyMainStateMove* pEnemyMainState
)
{
	//�|�C���^��ۑ�����
	EnemyMoveStateBase::SetEnemyMainState(pEnemyMainState);
	EnemyMoveStateBase::SetEnemy(pEnemy);

	//�����łǂ����������������߂�
	srand((unsigned int)time(NULL)); // ���ݎ����̏��ŏ�����
	
}
/*===================================
State�ύX�O�̃��Z�b�g����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMoveStateRotation::Reset()
{
	//���݂̊p�x��������
	mRotationNowAngle = 0.f;
	mRotationVelocity = 0.f;

	//���݂̊p�x�ŏ�����ς���
	float rotation = EnemyMoveStateBase::GetEnemy()->GetEnemyModel()->GetRotAngleY();

	//���ʂ������Ă�����
	if (rotation == EnemyMoveStateBase::GetFrontAngle())
	{
		//��]���������������
		mRotationAngle = RotationAngle::NUM;

		//��]���������߂�
		this->ConfigurationRotationAngle();
	}
	//����ȊO�̏ꍇ��
	else
	{
		//�����Đ��ʂɂȂ�ꍇ�͍������Ȃ̂�
		if (rotation + ROTATION_AFTER_ANGLE== EnemyMoveStateBase::GetFrontAngle())
		{
			mRotationAngle = RotationAngle::LEFT;
			
		}
		//�����Đ��ʂɂȂ�Ȃ��ꍇ�͉E�����Ȃ̂�
		else
		{
			mRotationAngle = RotationAngle::RIGHT;
		}
	}
	//��]��������ɂ���đ��x�����߂�
	this->ConfigurationRotationVelocity();
}

/*==================================
�X�V����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMoveStateRotation::Update()
{
	//��]������
	float angle = EnemyMoveStateBase::GetEnemy()->GetEnemyModel()->GetRotAngleY();
	EnemyMoveStateBase::GetEnemy()->GetEnemyModel()->SetRotationY(angle + mRotationVelocity);


	//�����ʂ��X�V����
	mRotationNowAngle += ESTATE_ROT_SPEED;
	//�ő�p�x�ƂȂ�����
	if (mRotationNowAngle >= ROTATION_AFTER_ANGLE)
	{
		//���s��Ԃ�
  		EnemyMoveStateBase::GetEnemyMainState()->ChangeStateWalk();
	}

}

/*===================================
��]���������߂�:private
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMoveStateRotation::ConfigurationRotationAngle()
{
	mRotationAngle =
		static_cast<RotationAngle>
		(
			static_cast<bool>(rand() % static_cast<int>(RotationAngle::NUM))
		);
}

/*===================================
�����ɉ����ĉ�]���x�����߂�:private
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMoveStateRotation::ConfigurationRotationVelocity()
{
	switch (mRotationAngle)
	{
		case RotationAngle::LEFT:
		{
			mRotationVelocity += ESTATE_ROT_SPEED;
			break;
		}
		case RotationAngle::RIGHT:
		{
			mRotationVelocity -= ESTATE_ROT_SPEED;
			break;
		}
		case RotationAngle::NUM:break;
	}
	
}

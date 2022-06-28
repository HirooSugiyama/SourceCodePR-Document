/*
�G��{State�@�`�ړ��`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#include"pch.h"
#include"EnemyMainStateMove.h"

//�O���錾
#include"EnemyMoveState/EnemyMoveStateBase.h"

//�֐��̎g�p
#include"../Enemy.h"


//�G���f�����W����̓����蔻��̍��̋���(�����蔻��̍��W)
const DirectX::SimpleMath::Vector3 EnemyMainStateMove::ESTATE_COLLIDER_POSITION(0.f, 0.f, 1.f);

//�g�嗦(�����蔻��)
const DirectX::SimpleMath::Vector3 EnemyMainStateMove::ESTATE_COLLIDER_SCALE(0.25f, 0.125f, 0.125f);

//�A���Փ˖h�~�p�ړ��萔
const DirectX::SimpleMath::Vector3 EnemyMainStateMove::HIT_STOP_SHIFT(0.5f,0.f,0.f);

//���]�p�x
const float EnemyMainStateMove::REVERSE_ANGLE = 180.f;

/*===================================
�R���X�g���N�^
�����F�Ȃ�
===================================*/
EnemyMainStateMove::EnemyMainStateMove()
	:EnemyMainStateBase()
	, mpEnemyMoveStateBase()
	, mState(EnemyMoveState::WALK)
	, mpRotation()
	, mpWalk()
	, mpAttack()
	, mMoveCollider()
	, mpFirstHitBlock()
	, mReverseNum()
	, mBlockHitFlag(EnemyBlockHit::NONE)
	, mpAttackBlockUseFlag(nullptr)
{
	mpRotation = std::make_unique<EnemyMoveStateRotation>();
	mpWalk = std::make_unique<EnemyMoveStateWalk>();
	mpAttack = std::make_unique<EnemyMoveStateWallAttack>();
}

/*===================================
�f�X�g���N�^
===================================*/
EnemyMainStateMove::~EnemyMainStateMove()
{
}

/*===================================
����������
�����F�G�̃|�C���^
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMainStateMove::Initialize(IEnemy* pEnemy)
{
	//�|�C���^��ۑ�
	EnemyMainStateBase::SetEnemy(pEnemy);

	//�e��Ԃ̏���������
	mpRotation->Initialize(dynamic_cast<Enemy*>(pEnemy),this);
	mpWalk->Initialize(dynamic_cast<Enemy*>(pEnemy),this);
	mpAttack->Initialize(dynamic_cast<Enemy*>(pEnemy),this);


	//������Ԃ�ݒ�
	this->ChangeStateWalk();
}

/*==================================
�X�V����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMainStateMove::Update()
{
	//���O�܂ŏՓ˂��Ă����ꍇ
	if (mBlockHitFlag == EnemyBlockHit::NOT_HIT&& &mpAttackBlockUseFlag==false)
	{
		//����������
		mBlockHitFlag = EnemyBlockHit::NONE;

		//��]������
		this->ChangeStateRotation();

		mpFirstHitBlock = nullptr;
	}

	//���݂̏�Ԃ̍X�V�������s��
	mpEnemyMoveStateBase->Update();


	//�Փ˂��Ȃ��Ȃ����ꍇ�̏���
	this->NotHitEnemyChangeStateRotation();

	if (mState == EnemyMoveState::WALK)
	{
		//�����蔻��X�V����
		this->SetAABBCollider();
	}
}

/*==================================
�`�揈��
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMainStateMove::Draw()
{
	//���f���̕`��
	EnemyMainStateBase::GetEnemy()->GetEnemyModel()->Draw();
}

/*==================================
�����𔽓]����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMainStateMove::ReverseAngle()
{
	float angle = EnemyMainStateBase::GetEnemy()->GetEnemyModel()->GetRotAngleY();
	EnemyMainStateBase::GetEnemy()->GetEnemyModel()->SetRotationY(angle + REVERSE_ANGLE);

	//360�x�␳
	if (EnemyMainStateBase::GetEnemy()->GetEnemyModel()->GetRotAngleY() > 360.f)
	{
		angle = EnemyMainStateBase::GetEnemy()->GetEnemyModel()->GetRotAngleY() - 360.f;
		EnemyMainStateBase::GetEnemy()->GetEnemyModel()->SetRotationY(angle);
	}

	//���]���ǉ�
	mReverseNum++;

	//�ړ��ʂ��Đݒ�
	mpWalk->CalculationMoveVelocity();

	this->Update();
}

/*============================
������������
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
============================*/
void EnemyMainStateMove::ResetEnemyAngle()
{
	//���ʂ�������
	EnemyMainStateBase::GetEnemy()->GetEnemyModel()->SetRotationY(mpEnemyMoveStateBase->GetFrontAngle());
}


/*==============================================
�Փ˂��Ȃ��Ȃ����ꍇ��]������Fprivate
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===============================================*/
void EnemyMainStateMove::NotHitEnemyChangeStateRotation()
{
	//���]�񐔂��������Ă���ꍇ���ʂ��Ȃ�
	if (mReverseNum >= 2)return;

	if (mState == EnemyMoveState::WALL_ATTACK)return;

	if (mBlockHitFlag == EnemyMainStateMove::EnemyBlockHit::NOT_HIT)
	{
		//��]�ɐ؂�ւ���
		this->ChangeStateRotation();
		this->SetBlockHitFlag(EnemyMainStateMove::EnemyBlockHit::NONE);
	}
}

/*==================================
�����蔻���ݒ肷��Fprivate
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMainStateMove::SetAABBCollider()
{
	//����p�ϐ��̐錾
	DirectX::SimpleMath::Vector3 min, max;

	//�؂����p�ϐ��̐錾
	DirectX::SimpleMath::Vector3 position, scale;

	//�ȗ���
	position = EnemyMainStateBase::GetEnemy()->GetEnemyModel()->GetPosition() + ESTATE_COLLIDER_POSITION;
	scale = ESTATE_COLLIDER_SCALE;


	//�����蔻��̍��W���Z�o
	min = position - scale;
	max = position + scale;

	//�����蔻���������
	mMoveCollider.SetCollider(min, max);
}
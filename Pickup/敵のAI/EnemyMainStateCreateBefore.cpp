/*
�G��{State�@�@�`�����O�`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#include"pch.h"
#include"EnemyMainStateCreateBefore.h"

//�O���錾
#include"../Enemy.h"

//�����O�̍���
const float EnemyMainStateCreateBefore::ENEMY_INIT_POSITION_Y = -1.5f;

/*===================================
�R���X�g���N�^
�����F�Ȃ�
===================================*/
EnemyMainStateCreateBefore::EnemyMainStateCreateBefore()
	:EnemyMainStateBase()
	, mpState()
	, mState(EnemyCreateBeforeState::SINKING)
	, mpSinking()
	, mpAppearance()
{
	mpSinking = std::make_unique<EnemyCreateBeforeStateSinking>();
	mpAppearance = std::make_unique<EnemyCreateBeforeStateAppearance>();
}

/*===================================
�f�X�g���N�^
===================================*/
EnemyMainStateCreateBefore::~EnemyMainStateCreateBefore()
{
}

/*===================================
����������
�����F�G�̃|�C���^
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMainStateCreateBefore::Initialize(IEnemy* pEnemy)
{
	//�|�C���^��ۑ�
	EnemyMainStateBase::SetEnemy(pEnemy);

	//�e���Ԃ̏���������
	mpSinking->Initialize(this, pEnemy);
	mpAppearance->Initialize(this, pEnemy);

	//�����ݒ�
	EnemyMainStateBase::GetEnemy()->GetEnemyModel()->Move
	(
		DirectX::SimpleMath::Vector3(0.f, ENEMY_INIT_POSITION_Y, 0.f)
	);

	//�ŏ��͒��v���
	this->ChangeStateSinking();
}

/*=================================
�X�V����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMainStateCreateBefore::Update()
{
	//���݂̏�Ԃ̏���
	mpState->Update();
}

/*===================================
�`�揈��
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMainStateCreateBefore::Draw()
{
	//���݂̏�Ԃ̏���
	mpState->Draw();

	//���f���̕`��
	EnemyMainStateBase::GetEnemy()->GetEnemyModel()->Draw();
}

/*===================================
��Ԃ�ύX����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMainStateCreateBefore::ChangeState()
{
	//���v��ԂȂ��
	if (mState == EnemyCreateBeforeState::SINKING)
	{
		//�o����ԂƂ���
		this->ChangeStateAppearance();
	}
}

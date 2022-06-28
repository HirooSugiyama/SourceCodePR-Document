/*
�G��{State�@�`�����`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#include"pch.h"
#include"EnemyMainStateDamage.h"

//�O���錾
#include"../Enemy.h"


/*=================================
�R���X�g���N�^
�����F�Ȃ�
===================================*/
EnemyMainStateDamage::EnemyMainStateDamage()
	:
	EnemyMainStateBase(),
	mpKnockBack(),
	mpBlinking(),
	mpEnemyDamageStateBase(),
	mState()
{
	mpKnockBack = std::make_unique<EnemyDamageStateKnockBack>();
	mpBlinking = std::make_unique<EnemyDamageStateBlinking>();
}

/*===================================
�f�X�g���N�^
===================================*/
EnemyMainStateDamage::~EnemyMainStateDamage()
{
}

/*==================================
����������
�����F�G�̃|�C���^
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMainStateDamage::Initialize(IEnemy* pEnemy)
{
	//�|�C���^��ۑ�
	EnemyMainStateBase::SetEnemy(pEnemy);


	//�e��Ԃ̏���������
	mpKnockBack->Initialize(dynamic_cast<Enemy*>(pEnemy),this);
	mpBlinking->Initialize(dynamic_cast<Enemy*>(pEnemy),this);

	//�ŏ��͔������
	this->ChangeStateKnockBack();
}

/*===================================
�X�V����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMainStateDamage::Update()
{
	//���݂̏�Ԃ̍X�V����
	mpEnemyDamageStateBase->Update();
}

/*===================================
�`�揈��
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMainStateDamage::Draw()
{
	//���݂̏�Ԃ̕`�揈��
	mpEnemyDamageStateBase->Draw();
}
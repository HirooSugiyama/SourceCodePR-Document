/*
�G��{State�@�`���Ł`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#include"pch.h"
#include"EnemyMainStateDisappearance.h"

//�O���錾
#include"../Enemy.h"

/*===================================
�R���X�g���N�^
�����F�Ȃ�
===================================*/
EnemyMainStateDisappearance::EnemyMainStateDisappearance()
	:EnemyMainStateBase()
	//,()
{
}

/*===================================
�f�X�g���N�^
===================================*/
EnemyMainStateDisappearance::~EnemyMainStateDisappearance()
{
}

/*===================================
����������
�����F�G�̃|�C���^
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMainStateDisappearance::Initialize(IEnemy* pEnemy)
{
	//�|�C���^��ۑ�
	EnemyMainStateBase::SetEnemy(pEnemy);
}

/*===================================
�X�V����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMainStateDisappearance::Update()
{

}

/*===================================
�`�揈��
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyMainStateDisappearance::Draw()
{
	//���f���̕`��
	EnemyMainStateBase::GetEnemy()->GetEnemyModel()->Draw();
}
/*
�G�����OState	�`���v�`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#include"pch.h"
#include"EnemyCreateBeforeStateSinking.h"

//�O���錾
#include"../../Enemy.h"

//�e���g��`��
const DirectX::SimpleMath::Vector2 EnemyCreateBeforeStateSinking::ENEMY_SHADOW_SCLAE_UP(1.5f, 1.5f);

//�e�̍����𒲐�
const float EnemyCreateBeforeStateSinking::ENEMY_SHADOW_SHIFT_POSITIONY = 1.f;

/*===================================
�R���X�g���N�^
�����F�Ȃ�
===================================*/
EnemyCreateBeforeStateSinking::EnemyCreateBeforeStateSinking()
	:EnemyCreateBeforeStateBase()
	//,()
{
}

/*===================================
�f�X�g���N�^
===================================*/
EnemyCreateBeforeStateSinking::~EnemyCreateBeforeStateSinking()
{
}

/*=================================
����������
�����F�G�̍s��State�A�G�̃|�C���^
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyCreateBeforeStateSinking::Initialize
(
	EnemyMainStateCreateBefore* pEnemyMainState,
	IEnemy* pEnemy
)
{
	//�|�C���^��ۑ�
	EnemyCreateBeforeStateBase::SetEnemy(pEnemy);
	EnemyCreateBeforeStateBase::SetEnemyMainState(pEnemyMainState);

	//�ȗ����ϐ��̐錾
	DirectX::SimpleMath::Vector2 baseScale = DirectX::SimpleMath::Vector2::Zero;

	//XZ���ʂɕϊ�
	baseScale.x = EnemyCreateBeforeStateBase::GetEnemy()->GetEnemyModel()->GetScale().x;
	baseScale.y = EnemyCreateBeforeStateBase::GetEnemy()->GetEnemyModel()->GetScale().z;

	//�e�̃T�C�Y��ς���
	EnemyCreateBeforeStateBase::GetEnemy()->
		GetShadow()->SetScale(baseScale * ENEMY_SHADOW_SCLAE_UP);	//XZ����
}

/*===================================
�`�揈��
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyCreateBeforeStateSinking::Draw()
{
	//�ȗ����ϐ��̐錾
	DirectX::SimpleMath::Vector3 castPosition = EnemyCreateBeforeStateBase::GetEnemy()->
										GetEnemyModel()->GetPosition();
	castPosition.y = ENEMY_SHADOW_SHIFT_POSITIONY;

	EnemyCreateBeforeStateBase::GetEnemy()->GetShadow()->Draw(castPosition);
}
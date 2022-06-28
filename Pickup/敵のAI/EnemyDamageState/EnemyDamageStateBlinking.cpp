/*
�G�_���[�WState�@�`�����`
�쐬�ҁF���R
�쐬���F2022/02/09
*/
#include"pch.h"
#include "EnemyDamageStateBlinking.h"

//�֐��̎g�p
#include"../../Enemy.h"

//�v���C���[�_�ŃC���^�[�o��
const int EnemyDamageStateBlinking::ENEMY_BLINKING_INTERVAL = 10;

/*===================================
�R���X�g���N�^
�����F�Ȃ�
===================================*/
EnemyDamageStateBlinking::EnemyDamageStateBlinking()
	:
	EnemyDamageStateBase(),
	mpDamageTimer(nullptr)
{
	mpDamageTimer = std::make_unique<DamageTimer>();
}

/*===================================
�f�X�g���N�^
===================================*/
EnemyDamageStateBlinking::~EnemyDamageStateBlinking()
{
}

/*===================================
����������
�����F�G�̃|�C���^�A�G�̍s��State
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyDamageStateBlinking::Initialize(Enemy* pEnemy, EnemyMainStateDamage* pEnemyMainState)
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
void EnemyDamageStateBlinking::Reset()
{
}

/*==================================
�X�V����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyDamageStateBlinking::Update()
{
	//�_�ŏ�����������ɑ���
	bool flag = mpDamageTimer->RegularIntervalTimer(ENEMY_BLINKING_INTERVAL);
	EnemyDamageStateBase::GetEnemy()->GetEnemyModel()->SetDrawFlag(flag);

	//���Ԃ�������
	if (mpDamageTimer->Update())
	{
		//�`��t���O�����Ă�
		EnemyDamageStateBase::GetEnemy()->GetEnemyModel()->SetDrawFlag(true);
		//���Ԃ������痧����Ԃɖ߂�
		EnemyDamageStateBase::GetEnemy()->ChangeStateMove();
		//���ʂ�������
		EnemyDamageStateBase::GetEnemy()->GetStateMove()->ResetEnemyAngle();
		//������Ԃ�
		EnemyDamageStateBase::GetEnemy()->GetStateMove()->ChangeStateWalk();
		//�ŏ��ɓ��������ǂ̃A�h���X�𖳌�������
		EnemyDamageStateBlinking::GetEnemy()->GetStateMove()->SetFirstHitBlock(nullptr);
		EnemyDamageStateBlinking::GetEnemy()->GetStateMove()->SetAttackBlock(nullptr);

		//�G�̍X�V��������x������
		EnemyDamageStateBlinking::GetEnemy()->Update();
	}
}

/*===================================
�`�揈��
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyDamageStateBlinking::Draw()
{
	//���f���̕`��
	EnemyDamageStateBase::GetEnemy()->GetEnemyModel()->Draw();
}

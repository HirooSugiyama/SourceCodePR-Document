/*
�G�����OState	�`�o���`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#include"pch.h"
#include"EnemyCreateBeforeStateAppearance.h"

//�O���錾
#include"../../Enemy.h"
#include"Game/PlayScene/Effect/Effect.h"

//�֐��̎g�p
#include"Game/PlayScene/Effect/EffectManager.h"

//���f���ړ��X�s�[�h
const float EnemyCreateBeforeStateAppearance::ENEMY_MODEL_MOVE_VELOCITY = 0.02f;
//���f��Y���ő�l
const float EnemyCreateBeforeStateAppearance::ENEMY_MODEL_MAX_POSITION_Y = 0.8f;

//�G�t�F�N�g���W
const float EnemyCreateBeforeStateAppearance::ENEMY_APPERANCE_POSITION_Y = 0.9f;

/*===================================
�R���X�g���N�^
�����F�Ȃ�
===================================*/
EnemyCreateBeforeStateAppearance::EnemyCreateBeforeStateAppearance()
	:
	EnemyCreateBeforeStateBase(),
	mpCamera(nullptr),
	mpAppearanceEffect(nullptr)
{
}

/*===================================
�f�X�g���N�^
===================================*/
EnemyCreateBeforeStateAppearance::~EnemyCreateBeforeStateAppearance()
{
}
/*=================================
����������
�����F�G�̍s��State�A�G�̃|�C���^
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyCreateBeforeStateAppearance::Initialize
(
	EnemyMainStateCreateBefore* pEnemyMainState,
	IEnemy* pEnemy
)
{
	//�|�C���^��ۑ�
	EnemyCreateBeforeStateBase::SetEnemy(pEnemy);
	EnemyCreateBeforeStateBase::SetEnemyMainState(pEnemyMainState);

	//�G�t�F�N�g�̐ݒ�
	this->SetEffect();
}

/*===================================
�X�V����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyCreateBeforeStateAppearance::Update()
{
	//�^�ϊ��p�ϐ��̐錾
	DirectX::SimpleMath::Vector3 castPosition = DirectX::SimpleMath::Vector3::Zero;
	castPosition.y += ENEMY_MODEL_MOVE_VELOCITY;

	//���f�����ړ�������
	EnemyCreateBeforeStateBase::GetEnemy()->GetEnemyModel()->Move(castPosition);

	//����Y�����ő�l�ƂȂ�����
	if (EnemyCreateBeforeStateBase::GetEnemy()->
		GetEnemyModel()->GetPosition().y >= ENEMY_MODEL_MAX_POSITION_Y)
	{
		//�ړ���ԂɕύX
		EnemyCreateBeforeStateBase::GetEnemy()->ChangeStateMove();

		//�G�t�F�N�g���̃t���O������
		mpAppearanceEffect->SetSpriteFlag(false);
	}
}

/*===================================
�`�揈��
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyCreateBeforeStateAppearance::Draw()
{
	//�G���f���̕`�揈��
	EnemyCreateBeforeStateBase::GetEnemy()->GetEnemyModel()->Draw();

}

/*==================================
�G�t�F�N�g�ݒ菈��:private
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
===================================*/
void EnemyCreateBeforeStateAppearance::SetEffect()
{
	DirectX::SimpleMath::Vector3 position = EnemyCreateBeforeStateBase::GetEnemy()->
		GetEnemyModel()->GetPosition();
	position.y = ENEMY_APPERANCE_POSITION_Y;

	//�G�t�F�N�g�}�l�[�W���[�̎擾
	auto pEM = EffectManager::GetInstance();

	mpAppearanceEffect = pEM->GetEffect(eEffectType::SPAWN);
	mpAppearanceEffect->SetPosition(position);
	mpAppearanceEffect->SetSpriteFlag(true);
}

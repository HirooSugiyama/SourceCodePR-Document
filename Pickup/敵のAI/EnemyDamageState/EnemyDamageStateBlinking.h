/*
�G�_���[�WState�@�`�_�Ł`
�쐬�ҁF���R
�쐬���F2022/02/09
*/
#pragma once

//���N���X
#include"EnemyDamageStateBase.h"
#include"../../../DamageTimer.h"

class EnemyDamageStateBlinking :public EnemyDamageStateBase
{
private:
	//�G�_�ŃC���^�[�o��
	static const int ENEMY_BLINKING_INTERVAL;

	//�v���^�C�}�[
	std::unique_ptr<DamageTimer> mpDamageTimer;


public:

	//�R���X�g���N�^
	EnemyDamageStateBlinking();
	//�f�X�g���N�^
	~EnemyDamageStateBlinking();
	//����������
	 void Initialize(Enemy* pEnemy, EnemyMainStateDamage* pEnemyMainState)override;
	//���Z�b�g����
	 void Reset()override;
	//�X�V����
	 void Update()override;
	//�`�揈��
	void Draw()override;


};

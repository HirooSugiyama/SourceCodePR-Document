/*
�G�����OState	�`���v�`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#pragma once

//���N���X
#include"EnemyCreateBeforeStateBase.h"

class EnemyCreateBeforeStateSinking : public EnemyCreateBeforeStateBase
{
private:

	//�e���g��`��
	static const DirectX::SimpleMath::Vector2 ENEMY_SHADOW_SCLAE_UP;
	//�e�̍����𒲐�
	static const float ENEMY_SHADOW_SHIFT_POSITIONY;


public:

	//�R���X�g���N�^
	EnemyCreateBeforeStateSinking();
	//�f�X�g���N�^
	~EnemyCreateBeforeStateSinking()override;
	//����������
	void Initialize(EnemyMainStateCreateBefore* pEnemyMainState, IEnemy* pEnemy)override;
	//�X�V����
	void Update()override {};
	//�`�揈��
	void Draw()override;

};

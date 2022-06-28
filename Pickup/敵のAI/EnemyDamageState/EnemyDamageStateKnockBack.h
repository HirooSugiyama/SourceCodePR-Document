/*
�G�_���[�WState�@�`�����`
�쐬�ҁF���R
�쐬���F2022/02/09
*/
#pragma once

//���N���X
#include"EnemyDamageStateBase.h"


class EnemyDamageStateKnockBack :public EnemyDamageStateBase
{
private:


	//�G���f�����W����̓����蔻��̍��̋���(�����蔻��̍��W)
	static const DirectX::SimpleMath::Vector3 ESTATE_COLLIDER_POSITION;

	//�g�嗦(�����蔻��)
	static const DirectX::SimpleMath::Vector3 ESTATE_COLLIDER_SCALE;


	//�ړ����x
	static const float ENEMY_MOVE_SPEED;

	//���x������
	static const float ENEMY_MOVE_SPEED_DECREASE;

	//���x�ŏ��l
	static const float ENEMY_MIN_VELOCITY;

	//�ړ��x�N�g��������������
	static const float ENEMY_MOVE_VELOCITY_SMALL;

	//�ړ��x�N�g���𔽓]������
	static const float ENEMY_MOVE_VELOCITY_REVERSE;

	//�ړ��x�N�g���ۑ��p�ϐ�
	DirectX::SimpleMath::Vector3 mMoveVec;



public:

	//�R���X�g���N�^
	EnemyDamageStateKnockBack();
	//�f�X�g���N�^
	~EnemyDamageStateKnockBack();
	//����������
	 void Initialize(Enemy* pEnemy, EnemyMainStateDamage* pEnemyMainState)override;
	//���Z�b�g����
	 void Reset()override;
	//�X�V����
	 void Update()override;
	//�`�揈��
	void Draw()override;

	//�ړ��x�N�g���̎擾
	void SetMoveVector(const DirectX::SimpleMath::Vector3& movevec);

	//�ړ��x�N�g�����X�P�[�����O
	void MoveVectorScaling();

private:

	//Vector3�̂����̐�Βl���ł��傫���l��Ԃ��֐�
	float Vector3Max(const DirectX::SimpleMath::Vector3& num);


};

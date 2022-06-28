/*
�G�ړ�State�@�`���s�`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#pragma once

//���N���X
#include"EnemyMoveStateBase.h"			

class EnemyMoveStateWalk : public EnemyMoveStateBase
{
private:

	//�ړ����x
	static const float ENEMY_MOVE_SPEED;

	//�X���␳
	static const float SHIFT_ANGLE;
	//�ǂ������t���O
	bool mPlayerChaseFlag;

	//�ǂ������p�ړ����x�ۑ��ϐ�
	DirectX::SimpleMath::Vector3 mChaseVelocity;

	//�ړ���
	DirectX::SimpleMath::Vector3 mEnemyMoveVelocity;

	//�v���C���[�̍��W�̃A�h���X
	DirectX::SimpleMath::Vector3* mChasePlayerPositon;

public:

	//�R���X�g���N�^
	EnemyMoveStateWalk();
	//�f�X�g���N�^
	~EnemyMoveStateWalk()override;
	//����������
	void Initialize(Enemy* pEnemy, EnemyMainStateMove* pEnemyMainState)override;
	//���Z�b�g����
	void Reset()override;
	//�X�V����
	void Update()override;

	//������ύX����
	void RotEnemyForTarget();


	//�v���C���[�̍��W�̃A�h���X
	DirectX::SimpleMath::Vector3* GetChasePlayerPositon() const { return mChasePlayerPositon; }
	void SetChasePlayerPositon(DirectX::SimpleMath::Vector3* position) { mChasePlayerPositon = position; }

	//�ǂ������t���O�̃A�N�Z�T
	bool GetPlayerChaseFlag()const { return mPlayerChaseFlag; }
	void SetPlayerChaseFlag(const bool& flag) { mPlayerChaseFlag = flag; }

	//�ړ��ʂ��Z�o
	void CalculationMoveVelocity();

private:
	//�ǔ����x�ݒ�
	void ChaseVelocity();

	//�ړ�����
	void Move();

	//�ǔ�����
	void Chase();
};

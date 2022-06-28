/*
�G�ړ�State�@�`��]�`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#pragma once

//���N���X
#include"EnemyMoveStateBase.h"

class EnemyMoveStateRotation : public EnemyMoveStateBase
{
private:

	//��]�������
	enum class RotationAngle
	{
		LEFT,
		RIGHT,
		NUM,
	};

	//�g�嗦(�����蔻��)
	static const DirectX::SimpleMath::Vector3 ESTATE_COLLIDER_SCALE;

	//��]�X�s�[�h
	static const float ESTATE_ROT_SPEED;

	//��]��̊p�x
	static const float ROTATION_AFTER_ANGLE;


	//���݂̉�]�p�x
	float mRotationNowAngle;

	//��]�������
	RotationAngle mRotationAngle;

	//��]���x
	float mRotationVelocity;

public:

	//�R���X�g���N�^
	EnemyMoveStateRotation();
	//�f�X�g���N�^
	~EnemyMoveStateRotation()override;
	//����������
	void Initialize(Enemy* pEnemy, EnemyMainStateMove* pEnemyMainState)override;
	//���Z�b�g����
	void Reset()override;
	//�X�V����
	void Update();

private:
	//��]���������߂�
	void ConfigurationRotationAngle();

	//�����ɉ����ĉ�]���x�����߂�
	void ConfigurationRotationVelocity();

};

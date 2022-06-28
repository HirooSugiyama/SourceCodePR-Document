/*
�G��{State�@�`�_���[�W�`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#pragma once

//���N���X
#include"EnemyMainStateBase.h"

//�񋓌^�̎g�p
#include"EnemyMainState.h"

//��ԕ���
#include"EnemyDamageState/EnemyDamageStateKnockBack.h"
#include"EnemyDamageState/EnemyDamageStateBlinking.h"

//�O���錾
class EnemyDamageStateBase;	//��ԕ������N���X

class EnemyMainStateDamage : public EnemyMainStateBase
{
private:
	//��ԕ���
	std::unique_ptr<EnemyDamageStateKnockBack> mpKnockBack;
	std::unique_ptr<EnemyDamageStateBlinking> mpBlinking;

	//���݂̏��
	EnemyDamageStateBase* mpEnemyDamageStateBase;
	EnemyDamageState mState;


public:

	//�R���X�g���N�^
	EnemyMainStateDamage();
	//�f�X�g���N�^
	~EnemyMainStateDamage();
	//����������
	void Initialize(IEnemy* pEnemy)override;
	//�X�V����
	void Update()override;
	//�`�揈��
	void Draw()override;

	//��ԕύX
	void ChangeStateKnockBack()
	{
		//��ԕύX
		mState = EnemyDamageState::KNOCK_BACK;
		mpEnemyDamageStateBase = static_cast<EnemyDamageStateBase*>(mpKnockBack.get());
		mpEnemyDamageStateBase->Reset();
	}
	void ChangeStateBlinking()
	{
		//��ԕύX
		mState = EnemyDamageState::BLINKING;
		mpEnemyDamageStateBase = static_cast<EnemyDamageStateBase*>(mpBlinking.get());
		mpEnemyDamageStateBase->Reset();
	}

	//�ړ��x�N�g���̃X�P�[�����O
	void MoveVectorScaling(const DirectX::SimpleMath::Vector3& movevec)
	{
		mpKnockBack->SetMoveVector(movevec);
		mpKnockBack->MoveVectorScaling();
	}
};

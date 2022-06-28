/*
�G��{State�@�`�����O�`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#pragma once

//���N���X
#include"EnemyMainStateBase.h"

//���State
#include"EnemyCreateBeforeState/EnemyCreateBeforeStateSinking.h"
#include"EnemyCreateBeforeState/EnemyCreateBeforeStateAppearance.h"

//�񋓌^�̎g�p
#include"EnemyMainState.h"

//�O���錾
class EnemyCreateBeforeStateBase;

class EnemyMainStateCreateBefore : public EnemyMainStateBase
{
private:

	//�����O�̍���
	static const float ENEMY_INIT_POSITION_Y;

	//���݂̏��
	EnemyCreateBeforeStateBase* mpState;
	EnemyCreateBeforeState mState;

	//���State
	std::unique_ptr<EnemyCreateBeforeStateSinking> mpSinking;
	std::unique_ptr<EnemyCreateBeforeStateAppearance> mpAppearance;

public:

	//�R���X�g���N�^
	EnemyMainStateCreateBefore();
	//�f�X�g���N�^
	~EnemyMainStateCreateBefore();
	//����������
	void Initialize(IEnemy* pEnemy)override;
	//�X�V����
	void Update()override;
	//�`�揈��
	void Draw()override;
	//��Ԃ�ύX����
	void ChangeState();

private:
	//��Ԑ؂�ւ�
	void ChangeStateSinking()
	{
		mState = EnemyCreateBeforeState::SINKING;
		mpState = static_cast<EnemyCreateBeforeStateBase*>(mpSinking.get());
	}

	void ChangeStateAppearance()
	{
		mState = EnemyCreateBeforeState::APPEARANCE;
		mpState = static_cast<EnemyCreateBeforeStateAppearance*>(mpAppearance.get());
	}
};

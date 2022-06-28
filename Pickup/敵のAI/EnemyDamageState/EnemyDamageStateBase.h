/*
�G�_���[�WState���N���X
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#pragma once

//�O���錾
class EnemyMainStateDamage;
class Enemy;

class EnemyDamageStateBase
{
private:

	//���L�҂̃|�C���^
	EnemyMainStateDamage* mpEnemyMainState;
	Enemy* mpEnemy;

public:

	//�R���X�g���N�^
	EnemyDamageStateBase();
	//�f�X�g���N�^
	~EnemyDamageStateBase();
	//����������
	virtual void Initialize(Enemy* pEnemy, EnemyMainStateDamage* pEnemyMainState) = 0;
	//���Z�b�g����
	virtual void Reset() = 0;
	//�X�V����
	virtual void Update() = 0;
	//�`�揈��
	virtual void Draw() {}

	//�A�N�Z�T
	EnemyMainStateDamage* GetEnemyMainState() const { return mpEnemyMainState; }
	void SetEnemyMainState(EnemyMainStateDamage* pEnemyMainState) { mpEnemyMainState = pEnemyMainState; }

	Enemy* GetEnemy() const { return mpEnemy; }
	void SetEnemy(Enemy* pEnemy) { mpEnemy = pEnemy; }
};

/*
�G�����OState���N���X
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#pragma once

//�O���錾
class EnemyMainStateCreateBefore;
class IEnemy;

class EnemyCreateBeforeStateBase
{
private:

	//���L�҂̃|�C���^
	EnemyMainStateCreateBefore* mpEnemyMainState;
	IEnemy* mpEnemy;

public:

	//�R���X�g���N�^
	EnemyCreateBeforeStateBase();
	//�f�X�g���N�^
	virtual ~EnemyCreateBeforeStateBase();
	//����������
	virtual void Initialize(EnemyMainStateCreateBefore* pEnemyMainState, IEnemy* pEnemy) = 0;
	//�X�V����
	virtual void Update() = 0;
	//�`�揈��
	virtual void Draw() {}

	//�A�N�Z�T
	EnemyMainStateCreateBefore* GetEnemyMainState()const { return mpEnemyMainState; }
	void SetEnemyMainState(EnemyMainStateCreateBefore* pEnemyMainState) { mpEnemyMainState = pEnemyMainState; }
	
	IEnemy* GetEnemy()const { return mpEnemy; }
	void SetEnemy(IEnemy* pEnemy) { mpEnemy = pEnemy; }

};

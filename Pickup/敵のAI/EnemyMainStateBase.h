/*
�G��{State���N���X
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#pragma once

//�O���錾
class IEnemy;

class EnemyMainStateBase
{
private:

	//���L�҂̃|�C���^
	IEnemy* mpEnemy;

public:

	//�R���X�g���N�^
	EnemyMainStateBase();
	//�f�X�g���N�^
	~EnemyMainStateBase();
	//����������
	virtual void Initialize(IEnemy* pEnemy) = 0;
	//�X�V����
	virtual void Update() = 0;
	//�`�揈��
	virtual void Draw() {}

	//�A�N�Z�T
	IEnemy* GetEnemy() const { return mpEnemy; }
	void SetEnemy(IEnemy* pEnemy) { mpEnemy = pEnemy; }

};

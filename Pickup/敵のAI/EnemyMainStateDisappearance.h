/*
�G��{State�@�`���Ł`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#pragma once

//���N���X
#include"EnemyMainStateBase.h"

class EnemyMainStateDisappearance : public EnemyMainStateBase
{
private:


public:

	//�R���X�g���N�^
	EnemyMainStateDisappearance();
	//�f�X�g���N�^
	~EnemyMainStateDisappearance();
	//����������
	void Initialize(IEnemy* pEnemy)override;
	//�X�V����
	void Update()override;
	//�`�揈��
	void Draw()override;

};

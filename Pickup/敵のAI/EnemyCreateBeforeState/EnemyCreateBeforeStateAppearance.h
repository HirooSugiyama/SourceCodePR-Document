/*
�G�����OState	�`�o���`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#pragma once

//���N���X
#include"EnemyCreateBeforeStateBase.h"


//�O���錾
class EffectSpriteTexture;
class Camera;

class EnemyCreateBeforeStateAppearance : public EnemyCreateBeforeStateBase
{
private:
	//���f���ړ��X�s�[�h
	static const float ENEMY_MODEL_MOVE_VELOCITY;
	//���f��Y���ő�l
	static const float ENEMY_MODEL_MAX_POSITION_Y;

	//�G�t�F�N�g���W
	static const float ENEMY_APPERANCE_POSITION_Y;



	//�|�C���^�ۑ��p�ϐ�
	Camera* mpCamera;

	//�t���O�Ǘ��p�ϐ�
	EffectSpriteTexture* mpAppearanceEffect;


public:

	//�R���X�g���N�^
	EnemyCreateBeforeStateAppearance();
	//�f�X�g���N�^
	~EnemyCreateBeforeStateAppearance()override;
	//����������
	void Initialize
	(
		EnemyMainStateCreateBefore* pEnemyMainState,
		IEnemy* pEnemy
	)override;
	//�X�V����
	void Update()override;
	//�`�揈��
	void Draw();

private:
	//�G�t�F�N�g�̐ݒ�
	void SetEffect();

};

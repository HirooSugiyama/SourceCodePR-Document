/*
���f���`��N���X
�쐬�ҁF���R
�쐬���F2021/04/18
*/
#pragma once

#include"IModel.h"

namespace DirectX
{
	class SpriteBatch;
}

//Todo:�ȗ��`�͊�{�g��Ȃ��B

class ObjectModel:public IModel
{
private:

	//�萔

	//���������̒萔
	static const DirectX::SimpleMath::Vector3 INIT_POSITION;
	//���g�p���̒萔
	static const DirectX::SimpleMath::Vector3 NOT_USE_POSITION;
	
	//�ϐ�

	// �R�����X�e�[�g
	DirectX::CommonStates* mpCommonState;
	// �X�v���C�g�o�b�`
	DirectX::SpriteBatch* mpSpriteBatch;

	//���f���֌W
	DirectX::SimpleMath::Matrix mWorld;

	//�r���[�s��
	DirectX::SimpleMath::Matrix mView;
	//�ˉe�s��
	DirectX::SimpleMath::Matrix mProj;

	//�G�t�F�N�g�t�@�N�g���[
	std::unique_ptr<DirectX::IEffectFactory> mFxFactory;
	//���f���̕ۑ���
	DirectX::Model* mModel;

	//���W
	DirectX::SimpleMath::Matrix mPosition;
	//�g�嗦
	DirectX::SimpleMath::Matrix mScale;
	//��]��
	DirectX::SimpleMath::Matrix mRotX;
	DirectX::SimpleMath::Matrix mRotY;
	DirectX::SimpleMath::Matrix mRotZ;

	//���WVector��
	DirectX::SimpleMath::Vector3 mPosition3;
	//�g�嗦Vector��
	DirectX::SimpleMath::Vector3 mScale3;

	//��]��float��
	float mRotAngleX;
	float mRotAngleY;
	float mRotAngleZ;

	//�\���t���O:true	�\��	false:��\��
	bool mDrawFlag;

	//���f���g�p�t���O
	bool mModelUseFlag;

	//�֐�
public:
	//�R���X�g���N�^
	ObjectModel();

	//�f�X�g���N�^
	~ObjectModel();

	//���f���̎w��
	void SetModel(DirectX::Model* model);
	//���f�����̃A�N�Z�T
	DirectX::Model* GetModel()const {return mModel;}

	//���W�̎w��
	void SetPosition(const DirectX::SimpleMath::Vector3& position);
	//�g�嗦�̎w��
	void SetScale(const DirectX::SimpleMath::Vector3& scale);
	//��]�̎w��
	void SetRotationX(const float& rot);
	void SetRotationY(const float& rot);
	void SetRotationZ(const float& rot);


	DirectX::SimpleMath::Matrix GetRotationX()const{return mRotX;}
	DirectX::SimpleMath::Matrix GetRotationY()const{return mRotY;}
	DirectX::SimpleMath::Matrix GetRotationZ()const{return mRotZ;}

	//��]���̊p�x�̎擾
	float GetRotAngleX() const{ return mRotAngleX; }
	float GetRotAngleY() const{ return mRotAngleY; }
	float GetRotAngleZ() const{ return mRotAngleZ; }


	//���W�̎擾
	DirectX::SimpleMath::Vector3  GetPosition()const;
	DirectX::SimpleMath::Vector3*  GetPositionAdress();
	//�g�嗦�̎擾
	DirectX::SimpleMath::Vector3  GetScale()const;

	//�ړ�
	void Move(const DirectX::SimpleMath::Vector3& vel);

	//�X�V����
	virtual void Update()override {};
	//�`��
	virtual void Draw(DirectX::SimpleMath::Matrix* world=nullptr)override;

	//�\����\���̐؂�ւ��̃A�N�Z�T
	bool GetDrawFlag()const { return mDrawFlag; }
	void SetDrawFlag(const bool& flag) { mDrawFlag = flag; }

	//���f���g�p�̐؂�ւ��t���O
	bool GetModelUseFlag() const { return mModelUseFlag; }
	void SetModelUseFlag(const bool& flag) { mModelUseFlag = flag; }

	//���[���h���W���v�Z����
	void CalculationWorldMatrix();

	//���[���h���W�̃A�N�Z�T
	DirectX::SimpleMath::Matrix GetWorld()const { return mWorld; }
	void SetWorld(const DirectX::SimpleMath::Matrix& world) { mWorld = world; }


};

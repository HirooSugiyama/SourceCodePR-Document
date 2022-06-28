/*
���f���`��N���X
�쐬�ҁF���R
�쐬���F2021/04/18
*/
#include<pch.h>
#include"ObjectModel.h"


//���������̒萔
const DirectX::SimpleMath::Vector3 ObjectModel::INIT_POSITION= DirectX::SimpleMath::Vector3::Zero;
//���g�p���̒萔
const DirectX::SimpleMath::Vector3 ObjectModel::NOT_USE_POSITION(-20.f, -20.f, -20.f);

/*==============
�R���X�g���N�^
�����F�Ȃ�
==============*/

ObjectModel::ObjectModel()
	:
	IModel(),
	mpCommonState(nullptr),
	mpSpriteBatch(nullptr),
	mWorld(),
	mView(),
	mProj(),
	mFxFactory(nullptr),
	mModel(nullptr),
	mPosition(),
	mScale(),
	mRotX(),
	mRotY(),
	mRotZ(),
	mPosition3(),
	mScale3(),
	mRotAngleX(),
	mRotAngleY(),
	mRotAngleZ(),
	mDrawFlag(true),
	mModelUseFlag(false)
{
	const auto& pDxIF = DirectXtkComponent::GetDirectXtkComponentInstance();
	mpCommonState = pDxIF.GetCommonStates();
	mpSpriteBatch = pDxIF.GetSpriteBatch();
	//�C���X�^���X�̎擾
		//�r���[�s��A�v���W�F�N�V�����s��̎擾
	const auto pDR = DX::DeviceResources::GetInstance();
	ID3D11Device1* pDevice = pDR->GetD3DDevice();
	const auto& pCiIF = CameraInfoComponent::GetCameraInfoComponentInstance();
	mView = *pCiIF.GetView();
	mProj = *pCiIF.GetProjection();

	// ���f���f�[�^�̓����Ă���t�H���_�̎w��
	std::unique_ptr<DirectX::EffectFactory> factory = std::make_unique<DirectX::EffectFactory>(pDevice);
	factory->SetDirectory(L"Resources/Models/");


	mFxFactory = std::make_unique<DirectX::EffectFactory>(pDevice);
	mWorld = DirectX::SimpleMath::Matrix::Identity;



	//������̉��
	mScale3 = DirectX::SimpleMath::Vector3::Zero;
	mPosition3 = INIT_POSITION;	//������
	mPosition3 = NOT_USE_POSITION;//���g�p�p���W�̎w��
	mScale = DirectX::SimpleMath::Matrix::CreateScale(mScale3);
	mPosition = DirectX::SimpleMath::Matrix::CreateTranslation(mPosition3);
}

/*===================================
�f�X�g���N�^
===================================*/
ObjectModel::~ObjectModel()
{
}

/*========================
���f���̎w��
�����F���f�����
�Ԃ�l�F�Ȃ�
============================*/
void ObjectModel::SetModel(DirectX::Model* model)
{
	if (mModel != nullptr)
	{
		mModel = nullptr;
	}
	mModel = model;
}

/*============
���W�̎w��
�����F���W
�Ԃ�l�F�Ȃ�
==============*/
void ObjectModel::SetPosition(const DirectX::SimpleMath::Vector3& position)
{
	mPosition = DirectX::SimpleMath::Matrix::CreateTranslation(position);

	mPosition3 = position;

}

/*============
�g�嗦�̎w��
�����F�g�嗦
�Ԃ�l�F�Ȃ�
==============*/
void ObjectModel::SetScale(const DirectX::SimpleMath::Vector3& scale)
{
	mScale = DirectX::SimpleMath::Matrix::CreateScale(scale);
	mScale3 = scale;
}

/*============
��]�̎w��
�����F�p�x
�Ԃ�l�F�Ȃ�
==============*/
void ObjectModel::SetRotationX(const float& rot)
{
	mRotAngleX = rot;
	mRotX = DirectX::SimpleMath::Matrix::CreateRotationX(DirectX::XMConvertToRadians(rot));
}
void ObjectModel::SetRotationY(const float& rot)
{
	mRotAngleY = rot;
	mRotY = DirectX::SimpleMath::Matrix::CreateRotationY(DirectX::XMConvertToRadians(rot));
}
void ObjectModel::SetRotationZ(const float& rot)
{
	mRotAngleZ = rot;
	mRotZ = DirectX::SimpleMath::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(rot));
}


/*========================
���W�̎擾
�����F�Ȃ�
�Ԃ�l�F���W(X,Y,Z)
============================*/
DirectX::SimpleMath::Vector3 ObjectModel::GetPosition()const
{
	return mPosition3;
}

DirectX::SimpleMath::Vector3* ObjectModel::GetPositionAdress() 
{
	return &mPosition3;
}

/*========================
�g�嗦�̎擾
�����F�Ȃ�
�Ԃ�l�F�g�嗦(X,Y,Z)
============================*/
DirectX::SimpleMath::Vector3 ObjectModel::GetScale()const
{
	return mScale3;
}



/*========================
�ړ�
�����F�ړ��x�N�g��
�Ԃ�l�F�Ȃ�
============================*/
void ObjectModel::Move(const DirectX::SimpleMath::Vector3& vel)
{
	DirectX::SimpleMath::Vector3 vel3 = vel;

	mPosition3 += vel3;
	
	mPosition = DirectX::SimpleMath::Matrix::CreateTranslation(mPosition3);
}

/*============
�`��
�����F���[���h���W(�����Ă���)
�Ԃ�l�F�Ȃ�
==============*/
void ObjectModel::Draw(DirectX::SimpleMath::Matrix* world)
{
	if (mDrawFlag)
	{
		//�C���X�^���X�̎擾
		const auto pDR = DX::DeviceResources::GetInstance();
		const auto& pDI = DirectXtkComponent::GetDirectXtkComponentInstance();
		const auto& pCiIF = CameraInfoComponent::GetCameraInfoComponentInstance();


		mView = *pCiIF.GetView();

		mProj = *pCiIF.GetProjection();

		if (world == nullptr)
		{
			//���낢�딽�f
			mWorld = mScale * mRotX * mRotY * mRotZ * mPosition;
		}
		else
		{
			mWorld = *world;
		}

		ID3D11DeviceContext1* pContext = pDR->GetD3DDeviceContext();

		mModel->Draw(pContext, *pDI.GetCommonStates(), mWorld, mView, mProj);
	}
}

/*=====================
���[���h���W���v�Z����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
=======================*/
void ObjectModel::CalculationWorldMatrix()
{
	//���낢�딽�f
	mWorld = mScale * mRotX * mRotY * mRotZ * mPosition;
}

/*
���\�[�X�}�l�[�W���[
���\�[�X�S�ʂ��Ǘ�����N���X���C�u����
(����A�I�[�f�B�I�͕ʃ��C�u�������g�p���邽�ߓƗ������Ă��܂��B)
�쐬�ҁF���R
�쐬���F2021/10/21
*/

#include"pch.h"
#include"Libraries/DirectXTK/Inc/Effects.h"
#include"DeviceResources.h"


#pragma warning(disable : 4996)

/*=========================================
�R���X�g���N�^
�����F�Ȃ�
=========================================*/
ResourceManager::ResourceManager()
	:mReadTiming(eLoadScene::NONE)
{
}

/*=========================================
�f�X�g���N�^
=========================================*/
ResourceManager::~ResourceManager()
{
	//�S�Ẵ��\�[�X����j��
	this->DeleteAllData();
}

/*=========================================
�I������
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
=========================================*/
void ResourceManager::Finalize()
{
	//��U�Ō�Ȃ̂ł��ׂď�����
	this->DeleteAllData();
}


/*=======================================
�e�N�X�`���̎擾
�����F�e�N�X�`���̎��ʖ�
�Ԃ�l�F�Ȃ�
=========================================*/
ID3D11ShaderResourceView* ResourceManager::GetTexture(const int& key)
{
	return mpTextureDB[key].Get();
}


/*=========================================
CMO���f���̎擾
�����FCMO���f���̎��ʖ�
�Ԃ�l�F�Ȃ�
=========================================*/
DirectX::Model* ResourceManager::GetCmoModel(const int& key)
{
	return mpCmoModelDB[key].get();
}

/*=========================================
�A�j���[�V�������f���̎擾
�����F�A�j���[�V�������f���̎��ʖ�
�Ԃ�l�F�Ȃ�
=========================================*/
AnimModel* ResourceManager::GetAnimationCmoModel(const int& key)
{
	return &mpAnimationCmoModelDB[key];
}


/*=========================================
���\�[�X�ǂݍ���
�����F�ǂݍ��ރ��\�[�X�Q�̕�
�Ԃ�l�F�Ȃ�
=========================================*/
void ResourceManager::Load(ReadRange range)
{
	int min{ 0 };
	int max{ 0 };
	//�͈͂��w�肷��
	min = ResouceDatabase::mEnumClassRange[static_cast<int>(range)].mMin;
	max = ResouceDatabase::mEnumClassRange[static_cast<int>(range)].mMax;

	std::string filePath = "Resources/";

	//�}���`�o�C�g���������C�h�����ɕϊ�
	wchar_t* wcs = L"none";//�ϊ��p�ϐ�
	const wchar_t* wideFilePath = L"none";	//�e�N�X�`���̑��΃p�X

	//�͈͓��̂ݓǂݍ���
	for (int i = min; i < max+1; i++)
	{
		//�t�@�C������ݒ肷��
		filePath += ResouceDatabase::mFilePath[i];

		wcs = new wchar_t[filePath.length() + 1];
		mbstowcs(wcs, filePath.c_str(), filePath.length() + 1);
		wideFilePath = wcs;

		//����CMO�̕������Ȃ�������(�e�N�X�`���Ȃ��)
		if (static_cast<int>(filePath.rfind(".cmo")) == Utility::EXCEPTION_NUM)
		{
			this->RegisterTexture(wideFilePath,i);
		}
		//�A�j���[�V�������f���Ȃ�
		else  if(static_cast<int>(filePath.rfind("AnimationModel")) != Utility::EXCEPTION_NUM)
		{
			this->RegisterAnimationModel(wideFilePath, i);
		}
		//�A�j���[�V�������f���Ȃ�
		else 
		{
			this->RegisterCmoModel(wideFilePath, i);
		}
		filePath = "Resources/";
		delete[] wcs;
	}	
}


/*==================================================================================
�e�N�X�`���̓o�^
�����Fpath(�e�N�X�`���̑��΃p�X(���C�h������^))�AKey(�e�N�X�`���̎��ʖ�(������))
�Ԃ�l�F�Ȃ�
==================================================================================*/
void ResourceManager::RegisterTexture(const wchar_t* path, const int& key)
{
	//�f�o�C�X���\�[�X�̎擾
	const auto pDR = DX::DeviceResources::GetInstance();
	auto device = pDR->GetD3DDevice();

	//�e�N�X�`���̓ǂݍ���	:SRV�̍쐬
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;

	DirectX::CreateWICTextureFromFile(device, path, nullptr, texture.ReleaseAndGetAddressOf());

	//DB(Map)�Ƀe�N�X�`����ǉ�
	mpTextureDB[key] = std::move(texture);

}


/*==========================================================================
CMO���f���̓o�^
�����Fpath(CMO���f���̑��΃p�X(���C�h������^))�AKey(CMO���f���̎��ʖ�(������))
�Ԃ�l�F�Ȃ�
==========================================================================*/
void ResourceManager::RegisterCmoModel(const wchar_t* path, const int& key)
{
	//�f�o�C�X���\�[�X�̎擾
	const auto pDR = DX::DeviceResources::GetInstance();
	auto device = pDR->GetD3DDevice();

	//���f���̕ۑ����W����ێ�����C���X�^���X�̐���
	std::unique_ptr<DirectX::EffectFactory> factory =
		std::make_unique<DirectX::EffectFactory>(device);

	factory->SetDirectory(L"Resources/Models/Play");
	std::unique_ptr<DirectX::Model> model = DirectX::Model::
		CreateFromCMO(device, path, *factory);

	//DB(Map)�Ƀe�N�X�`����ǉ�
	mpCmoModelDB[key] = std::move(model);
}


/*===============================================================================================
�A�j���[�V����CMO���f���̓o�^
�����Fpath(CMO���f���̑��΃p�X(���C�h������^))�AKey(CMO���f���̎��ʖ�(������))
�Ԃ�l�F�Ȃ�
===============================================================================================*/
void ResourceManager::RegisterAnimationModel(const wchar_t* path, const int& key)
{
	//�f�o�C�X���\�[�X�̎擾
	const auto pDR = DX::DeviceResources::GetInstance();
	auto device = pDR->GetD3DDevice();

	//���f���̕ۑ����W����ێ�����C���X�^���X�̐���
	std::unique_ptr<DirectX::EffectFactory> factory =
		std::make_unique<DirectX::EffectFactory>(device);



	factory->SetDirectory(L"Resources/Models");
	std::unique_ptr<DirectX::Model> model = DirectX::Model::
		CreateFromCMO(device, path, *factory);

	//�I�t�Z�b�g����
	size_t animsOffset;

	model = DirectX::Model::CreateFromCMO(device, path,
		*factory,
		DirectX::ModelLoaderFlags::ModelLoader_CounterClockwise |
		DirectX::ModelLoaderFlags::ModelLoader_IncludeBones,
		&animsOffset);


	//DB(Map)�Ƀ��f����ǉ�
	mpAnimationCmoModelDB[key].mModel = std::move(model);

	//DB�ɃA�j���[�V������ǉ�
	DX::ThrowIfFailed(
		mpAnimationCmoModelDB[key].mAnim.Load(path, animsOffset)
	);
}


/*=========================================
�S�Ẵ��\�[�X�̍폜
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
=========================================*/
void ResourceManager::DeleteAllData()
{
	mpTextureDB.clear();
	mpCmoModelDB.clear();
}

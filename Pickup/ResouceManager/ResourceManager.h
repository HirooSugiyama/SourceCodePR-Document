/*
���\�[�X�}�l�[�W���[
���\�[�X�S�ʂ��Ǘ�����N���X���C�u����
(����A�I�[�f�B�I�͕ʃ��C�u�������g�p���邽�ߓƗ������Ă��܂��B)
�쐬�ҁF���R
�쐬���F2021/10/21
*/
#pragma once

//���\�[�X�Ǘ��t�@�C��
#include"Libraries/MyLibraries/Resouce.h"

//�ǂݍ��ݕ���
enum class eLoadScene
{
	NONE = -1,
	TITLE = 1,
	MODE_SELECT,
	STAGE_SELECT,
	PLAY,
};

//�t�@�C���̏��Ԃ��܂Ƃ߂��񋓑�
enum class eFileReading
{
	READ_TIMING,
	IDENTIFIER,
	FILE_NAME,
	FILE_MAPKEY,
};


//�A�j���[�V�������f���p�\����
struct AnimModel
{
	//���f�����
	std::unique_ptr<DirectX::Model> mModel;

	//�A�j���[�V�������
	DX::AnimationCMO mAnim;
};

//���\�[�X�}�l�[�W��
class ResourceManager
{
public:
	//�C���X�^���X�̎擾
	static ResourceManager* GetInstance()
	{
		static ResourceManager instance;
		return &instance;
	}
private:

	//�ϐ�
	//�e�N�X�`���ێ��p�}�b�v
	std::unordered_map<int, Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>> mpTextureDB;

	//CMO���f���ێ��p�}�b�v
	std::unordered_map<int, std::unique_ptr<DirectX::Model>> mpCmoModelDB;

	//�A�j���[�V����CMO���f���ێ��p�}�b�v
	std::unordered_map<int, AnimModel> mpAnimationCmoModelDB;

	//�ǂݍ��݃^�C�~���O�ۑ��p������ϐ�
	eLoadScene mReadTiming;

	//�R�s�[�R���X�g���N�^�A�R�s�[������Z�q��delete�B
	ResourceManager(const ResourceManager& rm) = delete;
	ResourceManager operator=(const ResourceManager& rm) = delete;


	//�R���X�g���N�^
	ResourceManager();
	//�f�X�g���N�^
	~ResourceManager();



public:

	//�I������
	void Finalize();

	//���\�[�X�̎擾
	ID3D11ShaderResourceView* GetTexture(const int& key);
	DirectX::Model* GetCmoModel(const int& key);
	AnimModel* GetAnimationCmoModel(const int& key);


	//�w��͈̔͂̃��\�[�X�̂ݓǂݍ���
	void Load(ReadRange range);

private:
	//���\�[�X�̓o�^
	void RegisterTexture(const wchar_t* path,  const int& key);
	void RegisterCmoModel(const wchar_t* path, const int& key);
	void RegisterAnimationModel(const wchar_t* path, const int& key);

	//���ׂẴ��\�[�X�̍폜
	void DeleteAllData();
};
/*
�n�ʏ�ɂ���I�u�W�F�N�g�𓝊�����N���X
�쐬�ҁF���R
�쐬���F2021/08/19
*/
#pragma once


//����
#include"GroundObjectConifer.h"
#include"GroundObjectMoveCar.h"
#include"GroundObjectConiferGroup.h"
#include"GroundObjectShop.h"

struct AABB;					//����
class EnemyManager;				//�����蔻�����
class Player;					//�����蔻�菈��
class DetectNormalEnemy;		//����

class GroundObjectManager
{
private:

	//�I�u�W�F�N�g�̎�ނ��w��
	enum class eGroundObject
	{
		NONE,
		CONIFER,
		MOVE_CAR,
		CONIFER_GROUP,
		SHOP
	};

	//���ۑ��p�\����
	struct GroundObjectNum
	{
		int mConiferNum;
		int mMoveCarNum;
		int mConiferGroupNum;
		int mShopNum;
	};

	//�����蔻��Z�o�p�\����
	struct ColliderInfo
	{
		//���݂̏��
		enum class eColliderInfoState	//���ݓ����蔻����Z�o���Ă��邩���̂��̂�\����ԗ�
		{
			NONE,
			ACTIVE,
		};

		enum class eColliderStateMode	//���݂ǂ̍��W�����߂Ă��邩��\����ԗ�
		{
			NONE,
			MIN_XY_MAX_X,
			MAX_Y,
		};

		//���݂̃I�u�W�F�N�g�̎��
		eGroundObject mObjectType;

		//�ŏ��l
		DirectX::SimpleMath::Vector2 mMinPosition;
		//�ő�l
		DirectX::SimpleMath::Vector2 mMaxPosition;

		//���ԉ�
		eColliderInfoState mFlag;
		eColliderStateMode mState;

		//�R���X�g���N�^
		ColliderInfo()
			:mObjectType()
			,mMinPosition(DirectX::SimpleMath::Vector2(-1.f, -1.f))
			,mMaxPosition(DirectX::SimpleMath::Vector2(-1.f, -1.f))
			,mFlag()
			,mState()
		{}
	};


	//�����蔻��ۑ��p�\����
	struct SaveColliderInfo
	{
		//���݂̃I�u�W�F�N�g�̎��
		eGroundObject mObjectType;
		//�ŏ��l
		DirectX::SimpleMath::Vector2 mMinPosition;
		//�ő�l
		DirectX::SimpleMath::Vector2 mMaxPosition;

		SaveColliderInfo
		(eGroundObject objectType,
			DirectX::SimpleMath::Vector2 minPosition,
			DirectX::SimpleMath::Vector2 maxPosition)
			:mObjectType(objectType)
			,mMinPosition(minPosition)
			,mMaxPosition(maxPosition)
		{}

	};


	//���W
	//CSV�t�@�C�����_�̍��W
	static const DirectX::SimpleMath::Vector2 GOMANAGER_INIT_CSV_POSITION;

	//�ő吔
	static const int GOMANAGER_CSV_MAX_X = 39;
	static const int GOMANAGER_CSV_MAX_Y = 53;

	//�j�t�����f��
	std::vector<std::unique_ptr<GroundObjectConifer>> mpConifer;
	std::vector <DirectX::SimpleMath::Vector2> mConiferPosition;

	//�j�t���O���[�v���f��
	std::vector<std::unique_ptr<GroundObjectConiferGroup>> mpConiferGroup;
	std::vector <DirectX::SimpleMath::Vector2> mConiferGroupPosition;

	//�����ԃ��f��
	std::vector<std::unique_ptr<GroundObjectMoveCar>> mpMoveCar;
	std::vector <DirectX::SimpleMath::Vector2> mMoveCarPosition;

	//�V���b�v���f��
	std::vector<std::unique_ptr<GroundObjectShop>> mpShop;
	std::vector <DirectX::SimpleMath::Vector2> mShopPosition;

	//�\���̂����̉�
	GroundObjectNum mGroundObject;

	//MapChip�ۑ��p�ϐ�
	int mGroundObjectMapChip[GOMANAGER_CSV_MAX_X][GOMANAGER_CSV_MAX_Y];

	//���W���ۑ��p�ϐ��̐錾
	std::vector<SaveColliderInfo> mSaveInfo;

	//�����蔻��
	std::vector<AABB> mGroundObjectCollider;

	//�����蔻��ɑΉ��������f���Ǘ��p�ϐ�
	std::vector<eGroundObject> mCorresColliderObject;

	//�v���C���[���V���b�v�ɐG�ꂽ�ۂ̃t���O
	bool mPlayerShopTouchFlag;

public:

	//�R���X�g���N�^
	GroundObjectManager(const std::string & filepath);

	//�f�X�g���N�^
	~GroundObjectManager();


	//������
	void Initialize();

	//�X�V
	void Update();

	//�`��
	void Draw();

	//�G�̓����蔻�����
	void RoolNormalEnemyChackHit(DetectNormalEnemy* pEnemy);

	//�v���C���[�Ƃ̓����蔻�菈��
	void ChackHitPlayerGroundObject(Player* pPlayer);

	//�v���C���[���V���b�v�ɐG�ꂽ�ۂ̃t���O
	bool GetPlayerShopTouchFlag()const { return mPlayerShopTouchFlag; }

private:
	//CSV�t�@�C���ǂݍ���
	void LoadMapChip(const std::string & filepath);

	//�j�t���̔z�񐔂𒲐߂���
	void AdjustmentConiferVector();
	//�j�t���̍��W��ݒ肷��
	void ConfigConiferVectorPosition();

	//�j�t���O���[�v�̔z�񐔂𒲐߂���
	void AdjustmentConiferGroupVector();
	//�j�t���O���[�v�̍��W��ݒ肷��
	void ConfigConiferGroupVectorPosition();

	//�����Ԃ̔z�񐔂𒲐߂���
	void AdjustmentMoveCarVector();
	//�����Ԃ̍��W��ݒ肷��
	void ConfigMoveCarVectorPosition();

	//�V���b�v�̔z�񐔂𒲐߂���
	void AdjustmentShopVector();
	//�V���b�v�̍��W��ݒ肷��
	void ConfigShopVectorPosition();


	//CSV�t�@�C�����炠����x�̂܂Ƃ܂�̃I�u�W�F�N�g��T���o��
	void SeekLoadMapChipCohesive();

	//�������Ƃɓ����蔻����쐬����
	void CreateCollider();

	//�T��
	void Search(int& chipX,int& chipY,int objectNum);

	//�����蔻��̏d�Ȃ���`�F�b�N����
	bool OverlapCheck(int x, int y);
};

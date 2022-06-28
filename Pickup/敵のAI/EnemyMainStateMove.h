/*
�G��{State�@�`�ړ��`
�쐬�ҁF���R
�쐬���F2022/02/07
*/
#pragma once

//���N���X
#include"EnemyMainStateBase.h"

#include"EnemyMoveState/EnemyMoveStateRotation.h"
#include"EnemyMoveState/EnemyMoveStateWalk.h"
#include"EnemyMoveState/EnemyMoveStateWallAttack.h"

//�񋓌^�̎g�p
#include"EnemyMainState.h"


//�O���錾
class EnemyMoveStateBase;	//���State
class Block;				//����

class EnemyMainStateMove : public EnemyMainStateBase
{
public:

	//���݂̏Փˏ��
	enum class EnemyBlockHit
	{
		NONE,	//�ʏ�
		HIT,	//�Փ�
		NOT_HIT	//���ꂽ
	};

private:
	//�G���f�����W����̓����蔻��̍��̋���(�����蔻��̍��W)
	static const DirectX::SimpleMath::Vector3 ESTATE_COLLIDER_POSITION;

	//�g�嗦(�����蔻��)
	static const DirectX::SimpleMath::Vector3 ESTATE_COLLIDER_SCALE;

	//�A���Փ˖h�~�p�ړ��萔
	static const DirectX::SimpleMath::Vector3 HIT_STOP_SHIFT;

	//���]�p�x
	static const float REVERSE_ANGLE;

	//���݂̏��
	EnemyMoveStateBase* mpEnemyMoveStateBase;
	EnemyMoveState mState;

	//��ԕ���
	std::unique_ptr<EnemyMoveStateRotation> mpRotation;
	std::unique_ptr<EnemyMoveStateWalk> mpWalk;
	std::unique_ptr<EnemyMoveStateWallAttack> mpAttack;

	//�����蔻��
	AABB mMoveCollider;

	/*�ǍU��*/
	//���߂ďՓ˂����ǂ̃A�h���X
	Block* mpFirstHitBlock;

	//�ǔ��]��
	int mReverseNum;

	//���݂̏Փˏ��
	EnemyBlockHit mBlockHitFlag;

	//�U�����Ă���ǂ̃|�C���^
	bool* mpAttackBlockUseFlag;


public:

	//�R���X�g���N�^
	EnemyMainStateMove();
	//�f�X�g���N�^
	~EnemyMainStateMove();
	//����������
	void Initialize(IEnemy* pEnemy)override;
	//�X�V����
	void Update()override;
	//�`�揈��
	void Draw()override;

	//�����𔽓]����
	void ReverseAngle();

	//������������
	void ResetEnemyAngle();

	//��ԕύX
	void ChangeStateWalk()
	{
		mState = EnemyMoveState::WALK;
		mpEnemyMoveStateBase = static_cast<EnemyMoveStateBase*>(mpWalk.get());
		mpEnemyMoveStateBase->Reset();
	}
	void ChangeStateRotation()
	{
		mState = EnemyMoveState::ROTATION;
		mpEnemyMoveStateBase = static_cast<EnemyMoveStateBase*>(mpRotation.get());
		mpEnemyMoveStateBase->Reset();
	}
	void ChangeStateWallAttack()
	{
		mState = EnemyMoveState::WALL_ATTACK;		//��ԕύX
		mReverseNum = 0;							//���]�񐔏�����
		mpAttackBlockUseFlag = nullptr;				//�|�C���^������
		mpEnemyMoveStateBase = static_cast<EnemyMoveStateBase*>(mpAttack.get());
		mpEnemyMoveStateBase->Reset();				//�e��Ԃ̃��Z�b�g����
	}

	//���݂̏��
	EnemyMoveState GetMoveState()const { return mState; }

	//�����蔻��̃A�N�Z�T
	AABB* GetAABBCollider(){ return &mMoveCollider; }
	void SetAABBCollider(const AABB& aabb) { mMoveCollider = aabb; }

	/*�ړ�*/
	//�v���C���[�̍��W�̃A�h���X
	DirectX::SimpleMath::Vector3* GetChasePlayerPositon() const{ return mpWalk->GetChasePlayerPositon(); }
	void SetChasePlayerPositon(DirectX::SimpleMath::Vector3* position) { mpWalk->SetChasePlayerPositon(position); }
	//�v���C���[�ǂ������t���O
	bool GetChasePlayerFlag() const{ return mpWalk->GetPlayerChaseFlag(); }
	void SetChasePlayerFlag(const bool& flag) { mpWalk->SetPlayerChaseFlag(flag); }
	
	//�Փ˃t���O
	EnemyBlockHit GetBlockHitFlag()const { return mBlockHitFlag; }
	void SetBlockHitFlag(EnemyBlockHit const& flag) { mBlockHitFlag = flag; }

	//�ǔ��]��
	int GetReverseNum() const { return mReverseNum; }

	/*�ǍU��*/
	//�U���t���O
	bool AttackFlag()const { return mpAttack->AttackTiming(); }

	//���߂ďՓ˂����ǂ̃A�h���X
	Block* GetFirstHitBlock()const { return mpFirstHitBlock; }
	void SetFirstHitBlock(Block* pBlock) { mpFirstHitBlock = pBlock; }

	//�U�����Ă���ǂ̃|�C���^�̃A�N�Z�T
	bool* GetAttackBlock()const { return mpAttackBlockUseFlag; }
	void SetAttackBlock(bool* pBlock) { mpAttackBlockUseFlag = pBlock; }


private:

	//�Փ˂��Ȃ��Ȃ����ꍇ��]������
	void NotHitEnemyChangeStateRotation();

	//�����蔻���ݒ肷��
	void SetAABBCollider();
};

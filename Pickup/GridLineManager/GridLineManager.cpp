/*
�ǂ�u������p���C�����܂Ƃ߂�N���X
�쐬�ҁF���R
�쐬���F2021/08/28
*/

#include"pch.h"
#include "GridLineManager.h"


//�O���錾
#include"GridLine.h"
//�����蔻����Ŏg�p
#include"../Player/Player.h"
#include"../../PlaySceneDefence/PreparingBlock.h"


//�񋓌^�̎g�p
#include"GridLineType.h"


//�Ăяo����̊֐����g�p����e���Ŏg�p
#include"../Player/ActionStateDefenseHouse.h"
#include"../Player/Defense/DefenseActionBlockCreate.h"



//�萔
//����p���C���̐�(��)
const int GridLineManager::VERTICAL_GRID_LINE_NUM = 25;
const int GridLineManager::HORIZONTAL_GRID_LINE_NUM = 25;

//�c���ő吔
const float GridLineManager::VERTICAL_WIDTH_MAX_NUM = 40.f;
//�����ő吔		 
const float GridLineManager::HORIZONTAL_WIDTH_MAX_NUM = 50.f;


//�c���ŏ��l
const float GridLineManager::VERTICAL_MIN_NUM = -40.f;
//�����ŏ��l
const float GridLineManager::HORIZONTAL_MIN_NUM= -19.f;

//2�悷��
const int GridLineManager::SQUARE = 2;

/*====================
�R���X�g���N�^
�����F�Ȃ�
=======================*/
GridLineManager::GridLineManager()
	:
	mpVerticalGridLine{},
	mpHorizontalGridLine{}
{
	//�c���̏���
	mpVerticalGridLine.resize(VERTICAL_GRID_LINE_NUM);

	int size = static_cast<int>(mpVerticalGridLine.size());
	for (int i = 0; i < size; i++)
	{
		mpVerticalGridLine[i] = std::make_unique<GridLine>();
	}

	//�����̏���
	mpHorizontalGridLine.resize(HORIZONTAL_GRID_LINE_NUM);

	size = static_cast<int>(mpHorizontalGridLine.size());

	for (int i = 0; i < size; i++)
	{
		mpHorizontalGridLine[i] = std::make_unique<GridLine>();
	}
}

/*====================
�f�X�g���N�^
=======================*/
GridLineManager::~GridLineManager()
{
}

/*====================
����������
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
=======================*/
void GridLineManager::Initialize()
{
	//�c���̏���������
	this->InitVerticalGridLine();
	//�����̏���������
	this->InitHorizontalGridLine();


	this->ChackHitVerticalLineHorizontalLine();

}

/*====================
�`�揈��
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
=======================*/
void GridLineManager::Draw()
{
	//�T�C�Y�̎w��
	int size = static_cast<int>(mpVerticalGridLine.size());
	for (int i = 0; i < size; i++)
	{
		mpVerticalGridLine[i]->Draw();
	}


	//�T�C�Y�̎w��
	size = static_cast<int>(mpHorizontalGridLine.size());
	for (int i = 0; i < size; i++)
	{
		mpHorizontalGridLine[i]->Draw();
	}
}

/*======================================================
���{�p�u���b�N�Ƃ̏Փ˔���
�����F�v���C���[�̃|�C���^�A���{�p�u���b�N�̃|�C���^
�Ԃ�l�F�Ȃ�
=========================================================*/
void GridLineManager::ChackHitPreparingBlockGridLine(Player* pPlayer, PreparingBlock* pPreparingBlock)
{
	//�����蔻��֐��Q�̎擾
	Collider& pC = Collider::GetColliderInstance();

	//�ҏW�̊ȗ���
	int crossnum = static_cast<int>(mIntersectionNum.size());

	pPlayer->GetDefenseHouse()->GetBlockCreate()->SetGridLineFlag(false);

	//�G�̐�������������
	for (int j = 0; j < crossnum; j++)
	{
		//�������Ă����珈��������
		if (pC.Intersect(*pPreparingBlock->GetCircleCollider(),mIntersectionNum[j]))
		{
			//�u���b�N�����Ă��Ȃ��悤�ɂ���
			pPlayer->GetDefenseHouse()->GetBlockCreate()->SetGridLineFlag(true);

			break;
		}

		//�ǂ̓_�Ƃ��G��Ă��Ȃ�������
		if (j == crossnum-1)
		{
			//�u���b�N�����Ă���悤�ɂ���
			pPlayer->GetDefenseHouse()->GetBlockCreate()->SetGridLineFlag(false);

			//���Ă��Ȃ����{���f���̕ǃ��f����؂�ւ���
			pPreparingBlock->ChangeNotUseBlock();
		}
		
	}
}

/*==============================================
�n���ꂽ���W����ł��߂���_���Z�o����
�����F��ƂȂ���W
�Ԃ�l�F�����ɍł��߂����W
=================================================*/
DirectX::SimpleMath::Vector2 GridLineManager::GetIntersectionNearPosition(const DirectX::SimpleMath::Vector2& basePosition)
{
	//�Ԃ�l�p�ϐ��̐錾
	DirectX::SimpleMath::Vector2 returnPosition = mIntersectionNum[0];	//�ŏ��̓G���[����̂��ߏ��Ԃ����Ă���
	//�Z�o�p�ϐ��̐錾
	float calculationPosition1, calculationPosition2;

	//��_����̃x�N�g���̒������Z�o
	calculationPosition1 = 
		std::sqrtf
		(
			(std::abs(mIntersectionNum[0].x - basePosition.x)) * SQUARE +
			(std::abs(mIntersectionNum[0].y - basePosition.y)) * SQUARE
		);

	//�v�f���ۑ��p�ϐ��̐錾
	int saveindex = 0;

	//�ȗ����p�ϐ��̐錾
	int size = static_cast<int>(mIntersectionNum.size());


	//��_�Q����Ώۂɍł��߂���_�̍��W��ۑ�����
	for (int i = 1; i < size; i++)
	{
		//�Z�o
		calculationPosition2 =
			std::sqrtf(
				(std::abs(mIntersectionNum[i].x - basePosition.x)) * SQUARE +
				(std::abs(mIntersectionNum[i].y - basePosition.y)) * SQUARE
			);

		//�������i�K�ōł��߂���_�����������߂��ꍇ��
		if (calculationPosition2 < calculationPosition1)
		{
			//�X�V����
			calculationPosition1 = calculationPosition2;
			saveindex = i;//�v�f����ۑ�����
		}
	}

	//�ł��߂���_�̏���Ԃ�
	return mIntersectionNum[saveindex];
}

/*==============================
�c���̏���������:private
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
=================================*/
void GridLineManager::InitVerticalGridLine()
{
	//�T�C�Y�̏ȗ�
	int size = static_cast<int>(mpVerticalGridLine.size());
	//�J�n���W�̐ݒ�
	float linePositionX = HORIZONTAL_MIN_NUM;
	//��ނ̎w��
	eGridLineType lineType = eGridLineType::VERTICAL;

	for (int i = 0; i < size; i++)
	{
		mpVerticalGridLine[i]->Initialize(lineType);
		mpVerticalGridLine[i]->SetLineModelPosition(lineType,linePositionX);

		//1�{�̊Ԋu=���ő吔/�{��
		linePositionX += VERTICAL_WIDTH_MAX_NUM / size;
	}
}

/*==============================
�����̏���������:private
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
=================================*/
void GridLineManager::InitHorizontalGridLine()
{
	//�T�C�Y�̏ȗ�
	int size = static_cast<int>(mpHorizontalGridLine.size());
	//�J�n���W�̐ݒ�
	float linePositionZ = VERTICAL_MIN_NUM;
	//��ނ̎w��
	eGridLineType lineType = eGridLineType::HORIZONTAL;


	for (int i = 0; i < size; i++)
	{
		mpHorizontalGridLine[i]->Initialize(lineType);

		//1�{�̊Ԋu=���ő吔/�{��
		linePositionZ += HORIZONTAL_WIDTH_MAX_NUM/size;
		mpHorizontalGridLine[i]->SetLineModelPosition(lineType,linePositionZ);
	}
}

/*==============================
�c���Ɖ����̌�������:private
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
=================================*/
void GridLineManager::ChackHitVerticalLineHorizontalLine()
{
	//�����蔻��֐��Q�̎擾
	Collider& pC = Collider::GetColliderInstance();

	//�T�C�Y�̏ȗ�
	int hSize = static_cast<int>(mpHorizontalGridLine.size());
	int vSize = static_cast<int>(mpVerticalGridLine.size());
	//�ۑ��p�ϐ��̐錾
	DirectX::SimpleMath::Vector2 savePosition = DirectX::SimpleMath::Vector2::Zero;


	//�G�̐�������������
	for (int i = 0; i < vSize; i++)
	{
		//�G�̐�������������
		for (int j = 0; j < hSize; j++)
		{
			//�������Ă����珈��������
			if (pC.Intersect(
				*mpHorizontalGridLine[j]->GetLineCollider(),
				*mpVerticalGridLine[i]->GetLineCollider(), savePosition))
			{
				mIntersectionNum.push_back(savePosition);
			}
		}
	}
}

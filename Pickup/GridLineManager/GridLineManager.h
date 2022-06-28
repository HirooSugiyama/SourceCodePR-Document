/*
�ǂ�u������p���C�����܂Ƃ߂�N���X
�쐬�ҁF���R
�쐬���F2021/08/28
*/
#pragma once


//�O���錾
class GridLine;

class Player;			//�����蔻��Ŏg�p
class PreparingBlock;	//�����蔻��Ŏg�p


class GridLineManager
{
private:
	//�萔
	//����p���C���̐�(��)
	static const int VERTICAL_GRID_LINE_NUM;
	static const int HORIZONTAL_GRID_LINE_NUM;

	//�c���ő吔
	static const float VERTICAL_WIDTH_MAX_NUM;
	//�����ő吔
	static const float HORIZONTAL_WIDTH_MAX_NUM;

	//�c���ŏ��l
	static const float VERTICAL_MIN_NUM;
	//�����ŏ��l
	static const float HORIZONTAL_MIN_NUM;

	//2�悷��
	static const int SQUARE;


	//�c��
	std::vector<std::unique_ptr<GridLine>> mpVerticalGridLine;
	//����
	std::vector<std::unique_ptr<GridLine>> mpHorizontalGridLine;

	//�����_�ۑ��p�ϐ�
	std::vector<DirectX::SimpleMath::Vector2> mIntersectionNum;


public:

	//�R���X�g���N�^
	GridLineManager();
	//�f�X�g���N�^
	~GridLineManager();
	//������
	void Initialize();
	//�`�揈��
	void Draw();

	//���{�p�u���b�N�Ƃ̏Փ˔���
	void ChackHitPreparingBlockGridLine(Player* pPlayer, PreparingBlock* pPreparingBlock);


	//�n���ꂽ���W����ł��߂���_���Z�o����
	DirectX::SimpleMath::Vector2 GetIntersectionNearPosition
		(const DirectX::SimpleMath::Vector2& basePosition);


private:

	//�c���̏���������
	void InitVerticalGridLine();
	//�����̏���������
	void InitHorizontalGridLine();

	//�c���Ɖ����̌�������
	void ChackHitVerticalLineHorizontalLine();


};
/*
���f���C���^�[�t�F�[�X
�쐬�ҁF���R
�쐬���F2021/04/18
*/
#pragma once



class IModel
{
protected:
	//�X�V����
	virtual void Update() = 0;
	//�`�揈��
	virtual void Draw(DirectX::SimpleMath::Matrix* world = nullptr) = 0;
};
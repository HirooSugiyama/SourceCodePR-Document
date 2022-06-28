/*
�L�[�{�[�h�g���b�J�[�̎擾(�V���O���g��)
�쐬�ҁF���R
�쐬���F2021/10/21
*/
#include"pch.h"
#include "KeyTracker.h"

/*==========================================================
�R���X�g���N�^
�����F�Ȃ�
==========================================================*/
KeyTracker::KeyTracker()
	:
	mKeybord(nullptr)
{
	// �L�[�{�[�h�֘A
	mKeybord = std::make_unique<DirectX::Keyboard>();
}

/*==========================================================
�L�[����(�x�[�X�ƂȂ�֐�)(�P����������)
�����F���͂���L�[
�Ԃ�l�Ftrue�������Ă���	false��������Ă��Ȃ�
==========================================================*/
bool KeyTracker::PushKey(eUseKey key)
{
	switch (key)
	{
		case eUseKey::ENTER:
		{
			if (mTracker.pressed.Enter)
			{
				return true;
			}

			break;
		}
		case eUseKey::SPACE:
		{
			if (mTracker.pressed.Space)
			{
				return true;
			}
			break;
		}
		case eUseKey::UP:
		{
			if (mTracker.pressed.Up)
			{
				return true;
			}
			break;
		}
		case eUseKey::DOWN:
		{
			if (mTracker.pressed.Down)
			{
				return true;
			}
			break;
		}
		case eUseKey::LEFT:
		{
			if (mTracker.pressed.Left)
			{
				return true;
			}
			break;
		}
		case eUseKey::RIGHT:
		{
			if (mTracker.pressed.Right)
			{
				return true;
			}
			break;
		}
		case eUseKey::P:
		{
			if (mTracker.pressed.P)
			{
				return true;
			}
			break;
		}
		case eUseKey::R:
		{
			if (mTracker.pressed.R)
			{
				return true;
			}
			break;
		}
		case eUseKey::DEBUG_R:
		{
			if (mTracker.pressed.T)
			{
				return true;
			}
			break;
		}
		//�P���������Ȃ��L�[�������ꍇ�͏������s��Ȃ�
		default:
		{
			break;
		}
	}

	return false;
}

/*==========================================================
�L�[����(�x�[�X�ƂȂ�֐�)(����������)
�����F���͂���L�[
�Ԃ�l�Ftrue�������Ă���	false��������Ă��Ȃ�
==========================================================*/
bool KeyTracker::PressKey(eUseKey key)
{
	// �L�[���͏����擾����
	auto keyState = DirectX::Keyboard::Get().GetState();
	switch (key)
	{
		case eUseKey::W:
		{
			if (keyState.W)
			{
				return true;
			}
			break;
		}
		case eUseKey::A:
		{
			if (keyState.A)
			{
				return true;
			}
			break;
		}
		case eUseKey::S:
		{
			if (keyState.S)
			{
				return true;
			}
			break;
		}
		case eUseKey::D:
		{
			if (keyState.D)
			{
				return true;
			}
			break;
		}
		case eUseKey::SPACE:
		{
			if (keyState.Space)
			{
				return true;
			}
			break;
		}
		case eUseKey::LEFT:
		{
			if (keyState.Left)
			{
				return true;
			}
			break;
		}
		case eUseKey::RIGHT:
		{
			if (keyState.Right)
			{
				return true;
			}
			break;
		}
		case eUseKey::DEBUG_G:
		{
			if (keyState.G)
			{
				return true;
			}
			break;
		}
		//���������Ȃ��L�[�������ꍇ�͏������s��Ȃ�
		default:
		{
			break;
		}
	}

	return false;
}
/*==========================================================
�X�V����
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
==========================================================*/
void KeyTracker::KeyUpdate()
{
	// �L�[���͏����擾����
	auto keyState = mKeybord.get()->GetState();
	mTracker.Update(keyState);

	//�����I������
	this->ForcedTermination();
}


/*==========================================================
���s�I������
�����F�Ȃ�
�Ԃ�l�F�Ȃ�
==========================================================*/
void KeyTracker::ForcedTermination()
{
	// �L�[���͏����擾����
	auto keyState = DirectX::Keyboard::Get().GetState();
	//����ESC�L�[�������ꂽ��
	if (keyState.Escape)
	{
		//�����I������
		PostQuitMessage(0);
	}
}

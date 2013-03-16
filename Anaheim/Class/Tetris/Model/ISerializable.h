#pragma once

namespace Anaheim
{
	namespace Tetris
	{
		namespace Model
		{
			using namespace System;

			/**
			 * �V���A���C�Y �C���^�[�t�F�C�X
			 */
			interface class ISerializable
			{
			/**
			 * ���\�b�h
			 */
			public:
				/// �V���A���C�Y
				array<Byte>^ Serialize() abstract;
				/// �f�V���A���C�Y
				void Deserialize(array<Byte>^ bytes) abstract;
			};
			// ----------------------------------------------------------------------------------------------------
		}
	}
}

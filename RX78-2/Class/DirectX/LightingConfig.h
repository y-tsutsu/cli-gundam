#pragma once

namespace RX78_2
{
	namespace DirectX
	{
		using namespace System;
		using namespace System::Drawing;
		using namespace Microsoft::DirectX;
		using namespace Microsoft::DirectX::Direct3D;

		/**
		 * �Ɩ��ݒ�
		 */
		ref class LightingConfig
		{
		/**
		 * �t�B�[���h
		 */
		private:
			initonly int index;
			Vector3 location;
			Vector3 standardDirection;

		/**
		 * �R���X�g���N�^
		 */
		public:
			LightingConfig(Device^ device, int index);

		/**
		 * ���\�b�h
		 */
		public:
			/// �ʒu�ݒ�
			void SetLocation(Device^ device, Vector3 location);
			/// �ʒu�I�t�Z�b�g
			void OffsetLocation(Device^ device, Vector3 offset);
			/// �I�t�Z�b�g����
			void ReleaseOffset(Device^ device);

		/**
		 * �v���p�e�B
		 */
		public:
			/// �ʒu
			property Vector3 Location
			{
				Vector3 get() { return this->location; }
			}
		};
		// ----------------------------------------------------------------------------------------------------
	}
}

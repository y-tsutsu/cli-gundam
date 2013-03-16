#pragma once

#include "IMovable.h"
#include "IDrawable.h"

namespace RX78_2
{
	namespace DirectX
	{
		using namespace System;
		using namespace System::IO;
		using namespace System::Drawing;
		using namespace System::Collections::Generic;
		using namespace System::Windows::Forms;
		using namespace Microsoft::DirectX;
		using namespace Microsoft::DirectX::Direct3D;

		/**
		 * �����_���ړ��L���[�u
		 */
		ref class Deruderu : IMovable, IDrawable
		{
		/**
		 * �t�B�[���h
		 */
		private:
			initonly Material shadowMaterial;
			initonly float initHeight;

			Mesh^ mesh;
			array<ExtendedMaterial>^ materials;
			array<Texture^>^ textures;
			Vector3 scale;
			Vector3 location;
			float rotate;
			float heightAngle;
			List<Keys>^ keys;

		/**
		 * �R���X�g���N�^
		 */
		public:
			Deruderu(Device^ device);

		/**
		 * ���\�b�h
		 */
		public:
			/// ������
			bool Initialize(Device^ device);
			/// �L�[�_�E������
			void InputKeyDown(Keys key);
			/// �L�[�A�b�v����
			void InputKeyUp(Keys key);
			/// �ړ�
			virtual void Move(Device^ device);
			/// �`��
			virtual void Draw(Device^ device, LightingConfig^ lightingConfig);
			/// �e�`��
			virtual void DrawShadow(Device^ device, LightingConfig^ lightingConfig, Plane plane);

		/**
		 * �v���p�e�B
		 */
		public:
			/// �ʒu
			property Vector3 Location
			{
				Vector3 get() { return this->location; }
			}
			/// ��]
			property float Rotate
			{
				float get() { return this->rotate; }
			}
		};
		// ----------------------------------------------------------------------------------------------------
	}
}

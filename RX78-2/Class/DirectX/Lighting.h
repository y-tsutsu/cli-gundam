#pragma once

#include "IMovable.h"
#include "IDrawable.h"

namespace RX78_2
{
	namespace DirectX
	{
		using namespace System;
		using namespace System::Drawing;
		using namespace Microsoft::DirectX;
		using namespace Microsoft::DirectX::Direct3D;

		/**
		 * �Ɩ�
		 */
		ref class Lighting : IMovable, IDrawable
		{
		/**
		 * �t�B�[���h
		 */
		private:
			initonly float distance;
			Mesh^ mesh;
			Material material;
			LightingConfig^ config;

		/**
		 * �R���X�g���N�^
		 */
		public:
			Lighting(Device^ device, float distance, int index, Color color);

		/**
		 * ���\�b�h
		 */
		public:
			/// �ړ�
			virtual void Move(Device^ device);
			/// �`��
			virtual void Draw(Device^ device, LightingConfig^ lightConfig);
			/// �e�`��
			virtual void DrawShadow(Device^ device, LightingConfig^ lightingConfig, Plane plane);

		/**
		 * �v���p�e�B
		 */
		public:
			/// �ݒ�
			property LightingConfig^ Config
			{
				LightingConfig^ get() { return this->config; }
			}
		};
		// ----------------------------------------------------------------------------------------------------
	}
}

#pragma once

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
		 * ��
		 */
		ref class Floor : IDrawable
		{
		/**
		 * �t�B�[���h
		 */
		private:
			literal int TILE_COUNT = 5;

			Material material1;
			Material material2;
			VertexBuffer^ vertex1;
			VertexBuffer^ vertex2;

		/**
		 * �R���X�g���N�^
		 */
		public:
			Floor(Device^ device, float size, Color color1, Color color2);

		/**
		 * ���\�b�h
		 */
		public:
			/// �`��
			virtual void Draw(Device^ device, LightingConfig ^lightingConfig);
			/// �e�`��
			virtual void DrawShadow(Device^ device, LightingConfig^ lightingConfig, Plane plane);

		/**
		 * �v���p�e�B
		 */
		public:
			/// ���ʏ��i�e�`��p�j
			property Plane PlaneInfomation
			{
				Plane get() { return Plane(0.0f, 1.0f, 0.0f, 0.0f); }
			}
		};
		// ----------------------------------------------------------------------------------------------------
	}
}

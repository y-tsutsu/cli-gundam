#pragma once

#include "IMovable.h"

namespace RX78_2
{
	namespace DirectX
	{
		using namespace System;
		using namespace System::Drawing;
		using namespace System::Windows::Forms;
		using namespace Microsoft::DirectX;
		using namespace Microsoft::DirectX::Direct3D;

		/**
		 * �J����
		 */
		ref class Camera : IMovable
		{
		/**
		 * �t�B�[���h
		 */
		private:
			float radius;
			float locationTheta;
			float locationPhi;
			float targetY;
			Point oldMouseLocation;

		/**
		 * �R���X�g���N�^
		 */
		public:
			Camera(Device^ device, float radius);

		/**
		 * ���\�b�h
		 */
		public:
			/// �}�E�X�ړ�����
			void InputMouseMove(Point mouseLocation, MouseButtons button);
			/// �}�E�X�z�C������
			void InputMouseWheel(int delta);
			/// �ړ�
			virtual void Move(Device^ device);

		/**
		 * �v���p�e�B
		 */
		public:
			/// ��
			property float Theta
			{
				float get() { return this->locationTheta; }
			}
			/// ��
			property float Phi
			{
				float get() { return this->locationPhi; }
			}
			/// R
			property float Radius
			{
				float get() { return this->radius; }
			}
		};
		// ----------------------------------------------------------------------------------------------------
	}
}

#pragma once

namespace RX78_2
{
	namespace DirectX
	{
		using namespace Microsoft::DirectX;
		using namespace Microsoft::DirectX::Direct3D;

		/**
		 * �ړ��\
		 */
		interface class IMovable
		{
		/**
		 * ���\�b�h
		 */
		public:
			/// �ړ�
			void Move(Device^ device) abstract;
		};
		// ----------------------------------------------------------------------------------------------------
	}
}

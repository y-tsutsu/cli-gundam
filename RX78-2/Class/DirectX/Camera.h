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
		 * カメラ
		 */
		ref class Camera : IMovable
		{
		/**
		 * フィールド
		 */
		private:
			float radius;
			float locationTheta;
			float locationPhi;
			Point oldMouseLocation;
			literal float TARGET_Y = 2.0f;

		/**
		 * コンストラクタ
		 */
		public:
			Camera(Device^ device, float radius, float theta, float phi);

		/**
		 * メソッド
		 */
		public:
			/// マウス移動入力
			void InputMouseMove(Point mouseLocation, MouseButtons button);
			/// マウスホイル入力
			void InputMouseWheel(int delta);
			/// 移動
			virtual void Move(Device^ device);

		/**
		 * プロパティ
		 */
		public:
			/// θ
			property float Theta
			{
				float get() { return this->locationTheta; }
			}
			/// φ
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

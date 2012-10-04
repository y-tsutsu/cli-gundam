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
		 * 証明設定
		 */
		ref  class LightingConfig
		{
		/**
		 * フィールド
		 */
		private:
			initonly int index;
			Vector3 location;
			Vector3 standardDirection;

		/**
		 * コンストラクタ
		 */
		public:
			LightingConfig(Device^ device, int index);

		/**
		 * メソッド
		 */
		public:
			/// 位置設定
			void SetLocation(Device^ device, Vector3 location);
			/// 位置オフセット
			void OffsetLocation(Device^ device, Vector3 offset);
			/// オフセット解除
			void ReleaseOffset(Device^ device);

		/**
		 * プロパティ
		 */
		public:
			/// 位置
			property Vector3 Location
			{
				Vector3 get() { return this->location; }
			}
		};
		// ----------------------------------------------------------------------------------------------------
	}
}

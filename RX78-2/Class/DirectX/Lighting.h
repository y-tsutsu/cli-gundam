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
		 * 照明
		 */
		ref class Lighting : public IMovable, IDrawable
		{
		/**
		 * フィールド
		 */
		private:
			initonly float distance;
			Mesh^ mesh;
			Material material;
			LightingConfig^ config;

		/**
		 * コンストラクタ
		 */
		public:
			Lighting(Device^ device, float distance, int index, Color color);

		/**
		 * メソッド
		 */
		public:
			/// 移動
			virtual void Move(Device^ device);
			/// 描画
			virtual void Draw(Device^ device, LightingConfig^ lightConfig);
			/// 影描画
			virtual void DrawShadow(Device^ device, LightingConfig^ lightingConfig, Plane plane);

		/**
		 * プロパティ
		 */
		public:
			/// 設定
			property LightingConfig^ Config
			{
				LightingConfig^ get() { return this->config; }
			}
		};
		// ----------------------------------------------------------------------------------------------------
	}
}

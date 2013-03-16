#pragma once

namespace Anaheim
{
	namespace Tetris
	{
		namespace Model
		{
			using namespace System;

			/**
			 * シリアライズ インターフェイス
			 */
			interface class ISerializable
			{
			/**
			 * メソッド
			 */
			public:
				/// シリアライズ
				array<Byte>^ Serialize() abstract;
				/// デシリアライズ
				void Deserialize(array<Byte>^ bytes) abstract;
			};
			// ----------------------------------------------------------------------------------------------------
		}
	}
}

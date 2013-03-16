#pragma once

namespace RX78_2
{
	namespace DirectX
	{
		using namespace Microsoft::DirectX;
		using namespace Microsoft::DirectX::Direct3D;

		ref class LightingConfig;

		/**
		 * ï`âÊâ¬î\
		 */
		interface class IDrawable
		{
		/**
		 * ÉÅÉ\ÉbÉh
		 */
		public:
			/// ï`âÊ
			void Draw(Device^ device, LightingConfig^ lightingConfig) abstract;
			/// âeï`âÊ
			void DrawShadow(Device^ device, LightingConfig^ lightingConfig, Plane plane) abstract;
		};
		// ----------------------------------------------------------------------------------------------------
	}
}

#include "stdafx.h"
#include "LightingConfig.h"

using namespace RX78_2::DirectX;

/**
 * Æ–¾Ý’è
 */
LightingConfig::LightingConfig(Microsoft::DirectX::Direct3D::Device ^device, int index)
{
	this->index = index;
	this->location = Vector3::Empty;
	this->standardDirection = Vector3::Empty;

	device->Lights[index]->Type = LightType::Directional;
	device->Lights[index]->Diffuse = Color::White;
	device->Lights[index]->Ambient = Color::FromArgb(255, 128, 128, 128);
	device->Lights[index]->Enabled = true;
	device->Lights[index]->Update();
}
// ----------------------------------------------------------------------------------------------------

void LightingConfig::SetLocation(Microsoft::DirectX::Direct3D::Device ^device, Microsoft::DirectX::Vector3 location)
{
	this->location = location;
	device->Lights[this->index]->Direction = Vector3::Normalize(Vector3(-this->location.X, -this->location.Y, -this->location.Z));
	device->Lights[this->index]->Update();
	auto vs = device->Lights[0]->Direction;
}
// ----------------------------------------------------------------------------------------------------

void LightingConfig::OffsetLocation(Microsoft::DirectX::Direct3D::Device ^device, Microsoft::DirectX::Vector3 offset)
{
	this->standardDirection = device->Lights[this->index]->Direction;
	Vector3 offsetLocation = Vector3(this->location.X - offset.X, this->location.Y - offset.Y, this->location.Z - offset.Z);
	device->Lights[this->index]->Direction = Vector3::Normalize(
		Vector3(-offsetLocation.X, -offsetLocation.Y, -offsetLocation.Z));
	device->Lights[this->index]->Update();
}
// ----------------------------------------------------------------------------------------------------

void LightingConfig::ReleaseOffset(Microsoft::DirectX::Direct3D::Device ^device)
{
	device->Lights[this->index]->Direction = this->standardDirection;
	device->Lights[this->index]->Update();
}
// ----------------------------------------------------------------------------------------------------

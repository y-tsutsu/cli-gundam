#include "StdAfx.h"
#include "Lighting.h"
#include "LightingConfig.h"

using namespace RX78_2::DirectX;

/**
 * Æ–¾
 */
Lighting::Lighting(Microsoft::DirectX::Direct3D::Device ^device, float distance, int index, System::Drawing::Color color)
{
	this->distance = distance;
	this->mesh = Mesh::Sphere(device, 0.2f, 16, 16);
	this->material.Diffuse = color;
	this->material.Ambient = color;
	this->config = gcnew LightingConfig(device, index);

	device->RenderState->Lighting = true;
}
// ----------------------------------------------------------------------------------------------------

void Lighting::Move(Microsoft::DirectX::Direct3D::Device ^device)
{
	Matrix matrix = Matrix::RotationY(Environment::TickCount / 1000.0f);
	Vector3 normalize = Vector3::TransformCoordinate(Vector3::Normalize(Vector3(1.0f, 1.5f, 0.0f)), matrix);
	Vector3 location = Vector3(normalize.X * this->distance, normalize.Y * this->distance, normalize.Z * this->distance);

	this->config->SetLocation(device, location);
}
// ----------------------------------------------------------------------------------------------------

void Lighting::Draw(Microsoft::DirectX::Direct3D::Device ^device, RX78_2::DirectX::LightingConfig ^lightingConfig)
{
	device->Material = this->material;
	device->SetTransform(TransformType::World, Matrix::Translation(this->config->Location));
	this->mesh->DrawSubset(0);
}
// ----------------------------------------------------------------------------------------------------

void Lighting::DrawShadow(Microsoft::DirectX::Direct3D::Device ^device, RX78_2::DirectX::LightingConfig ^lightingConfig, Microsoft::DirectX::Plane plane)
{
	// ‰e‚È‚µ
}
// ----------------------------------------------------------------------------------------------------

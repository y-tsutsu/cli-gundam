#include "StdAfx.h"
#include "Camera.h"

using namespace RX78_2::DirectX;

/**
 * �J����
 */
Camera::Camera(Microsoft::DirectX::Direct3D::Device ^device, float radius, float theta, float phi)
{
	this->radius = radius;
	this->locationTheta = theta;
	this->locationPhi = phi;
	this->oldMouseLocation = Point::Empty;

	// �ˉe�ϊ���ݒ�
	device->Transform->Projection = Matrix::PerspectiveFovLH(Geometry::DegreeToRadian(60.0f),
		static_cast<float>(device->Viewport.Width) / static_cast<float>(device->Viewport.Height), 1.0f, 100.0f);
}
// ----------------------------------------------------------------------------------------------------

void Camera::InputMouseMove(System::Drawing::Point mouseLocation, System::Windows::Forms::MouseButtons button)
{
	if (button == MouseButtons::Left)
	{
		this->locationTheta -= mouseLocation.X - this->oldMouseLocation.X;
		this->locationPhi += mouseLocation.Y - this->oldMouseLocation.Y;
		
		if (90.0f <= this->locationPhi)
		{
			this->locationPhi = 89.9999f;
		}
		else if (this->locationPhi <= -90.0f)
		{
			this->locationPhi = -89.9999f;
		}
	}
	this->oldMouseLocation = mouseLocation;
}
// ----------------------------------------------------------------------------------------------------

void Camera::InputMouseWheel(int delta)
{
	this->radius -= delta / 480.0f;
	if (this->radius < 4.0f)
	{
		this->radius = 4.0f;
	}
}
// ----------------------------------------------------------------------------------------------------

void Camera::Move(Microsoft::DirectX::Direct3D::Device ^device)
{
	// �����Y�̈ʒu���O�����ɍ��W�ŕϊ�
	float theta = Geometry::DegreeToRadian(this->locationTheta);
	float phi = Geometry::DegreeToRadian(this->locationPhi);
	Vector3 lensLocation = Vector3(static_cast<float>(this->radius * Math::Cos(theta) * Math::Cos(phi)),
		static_cast<float>(this->radius * Math::Sin(phi)), static_cast<float>(this->radius * Math::Sin(theta) * Math::Cos(phi)));

	// �r���[�ϊ��s���������W�n�r���[�s��Őݒ肷��
	device->Transform->View = Matrix::LookAtLH(lensLocation, Vector3(0.0f, this->TARGET_Y, 0.0f), Vector3(0.0f, 1.0f, 0.0f));
}
// ----------------------------------------------------------------------------------------------------

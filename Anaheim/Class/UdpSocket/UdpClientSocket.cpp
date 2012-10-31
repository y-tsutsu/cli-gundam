#include "StdAfx.h"
#include "UdpClientSocket.h"

using namespace Anaheim;
using namespace Anaheim::UdpSocket;

/**
 * UDPクライアント
 */
UdpClientSocket::UdpClientSocket()
{
	this->client = nullptr;
	this->receiveWorker = gcnew BackgroundWorker();
	this->receiveWorker->WorkerReportsProgress = true;
	this->receiveWorker->DoWork += gcnew DoWorkEventHandler(this, &UdpClientSocket::ReceiveWorkerDoWork);
	this->receiveWorker->ProgressChanged += gcnew ProgressChangedEventHandler(this, &UdpClientSocket::ReceiveWorkerProgressChanged);
	this->encoding = System::Text::Encoding::Default;
	this->connected = false;
}
// ----------------------------------------------------------------------------------------------------

void UdpClientSocket::ReceiveWorkerDoWork(System::Object ^sender, System::ComponentModel::DoWorkEventArgs ^e)
{
	try
	{
		while (true)
		{
			IPEndPoint^ endPoint = gcnew IPEndPoint(IPAddress::Any, 0);
			array<Byte>^ buff = this->client->Receive(endPoint);
			UdpEventArgs^ args = gcnew UdpEventArgs(endPoint, buff, this->encoding);
			this->receiveWorker->ReportProgress(0, args);
		}
	}
	catch (Exception^)
	{
		return;
	}
}
// ----------------------------------------------------------------------------------------------------

void UdpClientSocket::ReceiveWorkerProgressChanged(System::Object ^sender, System::ComponentModel::ProgressChangedEventArgs ^e)
{
	UdpEventArgs^ args = dynamic_cast<UdpEventArgs^>(e->UserState);
	this->OnReceived(args);
}
// ----------------------------------------------------------------------------------------------------

bool UdpClientSocket::IsEnabledIPAddress(System::Net::IPAddress ^ipAddress)
{
	array<IPAddress^>^ addresses = System::Net::Dns::GetHostAddresses(System::Net::Dns::GetHostName());
	for each (IPAddress^ address in addresses)
	{
		if (address->Equals(ipAddress))
		{
			return true;
		}
	}

	if (ipAddress->ToString()->Equals("127.0.0.1"))
	{
		return true;
	}

	return false;
}
// ----------------------------------------------------------------------------------------------------

bool UdpClientSocket::Start(System::Net::IPEndPoint ^endPoint)
{
	if (this->connected) return false;
	if (!this->IsEnabledIPAddress(endPoint->Address)) return false;

	try
	{
		this->client = gcnew UdpClient(endPoint);
		this->receiveWorker->RunWorkerAsync();
		this->connected = true;
	}
	catch (Exception^)
	{
		return false;
	}

	return true;
}
// ----------------------------------------------------------------------------------------------------

bool UdpClientSocket::Stop()
{
	if (!this->connected) return false;

	try
	{
		this->client->Close();
		this->connected = false;
	}
	catch (Exception^)
	{
		return false;
	}

	return true;
}
// ----------------------------------------------------------------------------------------------------

bool UdpClientSocket::SendData(cli::array<unsigned char,1> ^bytes, System::Net::IPEndPoint ^endPoint)
{
	if (!this->connected) return false;

	try
	{
		this->client->Send(bytes, bytes->Length, endPoint);
	}
	catch (Exception^)
	{
		return false;
	}

	return true;
}
// ----------------------------------------------------------------------------------------------------

bool UdpClientSocket::SendMessage(System::String ^message, System::Net::IPEndPoint ^endPoint)
{
	array<Byte>^ buffer = this->encoding->GetBytes(message);
	return this->SendData(buffer, endPoint);
}
// ----------------------------------------------------------------------------------------------------

void UdpClientSocket::OnReceived(Anaheim::UdpSocket::UdpEventArgs ^e)
{
	this->Received(this, e);
}
// ----------------------------------------------------------------------------------------------------

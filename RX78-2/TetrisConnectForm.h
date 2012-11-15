#pragma once

#include "ConfigFile.h"

namespace RX78_2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// TetrisConnectForm の概要
	/// </summary>
	public ref class TetrisConnectForm : public System::Windows::Forms::Form
	{
	private: ConfigFile^ config;	///< コンフィグファイル

	private: System::Windows::Forms::Label^  labelTitle;
	private: System::Windows::Forms::Label^  labelIpAddress;
	private: System::Windows::Forms::Label^  labelPortNo;
	private: System::Windows::Forms::TextBox^  textPortNo;
	private: System::Windows::Forms::TextBox^  textIpAddress;
	private: System::Windows::Forms::Button^  buttonOk;
	private: System::Windows::Forms::Button^  buttonCancel;

	public:
		TetrisConnectForm(RX78_2::ConfigFile^ config)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			this->config = config;
			this->Initialize();
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~TetrisConnectForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->labelIpAddress = (gcnew System::Windows::Forms::Label());
			this->labelPortNo = (gcnew System::Windows::Forms::Label());
			this->textPortNo = (gcnew System::Windows::Forms::TextBox());
			this->textIpAddress = (gcnew System::Windows::Forms::TextBox());
			this->buttonOk = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// labelTitle
			// 
			this->labelTitle->AutoSize = true;
			this->labelTitle->Location = System::Drawing::Point(12, 9);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(75, 12);
			this->labelTitle->TabIndex = 4;
			this->labelTitle->Text = L"リモート先設定";
			// 
			// labelIpAddress
			// 
			this->labelIpAddress->AutoSize = true;
			this->labelIpAddress->Location = System::Drawing::Point(36, 39);
			this->labelIpAddress->Name = L"labelIpAddress";
			this->labelIpAddress->Size = System::Drawing::Size(51, 12);
			this->labelIpAddress->TabIndex = 5;
			this->labelIpAddress->Text = L"IPアドレス";
			// 
			// labelPortNo
			// 
			this->labelPortNo->AutoSize = true;
			this->labelPortNo->Location = System::Drawing::Point(38, 64);
			this->labelPortNo->Name = L"labelPortNo";
			this->labelPortNo->Size = System::Drawing::Size(49, 12);
			this->labelPortNo->TabIndex = 6;
			this->labelPortNo->Text = L"ポートNo.";
			// 
			// textPortNo
			// 
			this->textPortNo->Location = System::Drawing::Point(93, 61);
			this->textPortNo->Name = L"textPortNo";
			this->textPortNo->Size = System::Drawing::Size(149, 19);
			this->textPortNo->TabIndex = 1;
			// 
			// textIpAddress
			// 
			this->textIpAddress->Location = System::Drawing::Point(93, 36);
			this->textIpAddress->Name = L"textIpAddress";
			this->textIpAddress->Size = System::Drawing::Size(149, 19);
			this->textIpAddress->TabIndex = 0;
			// 
			// buttonOk
			// 
			this->buttonOk->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->buttonOk->Location = System::Drawing::Point(35, 97);
			this->buttonOk->Name = L"buttonOk";
			this->buttonOk->Size = System::Drawing::Size(75, 23);
			this->buttonOk->TabIndex = 2;
			this->buttonOk->Text = L"OK";
			this->buttonOk->UseVisualStyleBackColor = true;
			this->buttonOk->Click += gcnew System::EventHandler(this, &TetrisConnectForm::buttonOk_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point(145, 97);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 3;
			this->buttonCancel->Text = L"キャンセル";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// TetrisConnectForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::GhostWhite;
			this->ClientSize = System::Drawing::Size(254, 132);
			this->ControlBox = false;
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOk);
			this->Controls->Add(this->textIpAddress);
			this->Controls->Add(this->textPortNo);
			this->Controls->Add(this->labelPortNo);
			this->Controls->Add(this->labelIpAddress);
			this->Controls->Add(this->labelTitle);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"TetrisConnectForm";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"RX78-2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	/// 初期化
	private: void Initialize()
			 {
				 IPEndPoint^ endPoint = this->config->GetTetrisIPEndPoint();
				 this->textIpAddress->Text = endPoint->Address->ToString();
				 this->textPortNo->Text = endPoint->Port.ToString();
			 }
			 // ----------------------------------------------------------------------------------------------------
	
	/// OKボタン
	private: System::Void buttonOk_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 try
				 {
					 IPEndPoint^ endPoint = gcnew IPEndPoint(IPAddress::Parse(this->textIpAddress->Text), int::Parse(this->textPortNo->Text));
					 this->config->SetTetrisIPEndPoint(endPoint);
				 }
				 catch (Exception^)
				 {
					 return;
				 }
			 }
			 // ----------------------------------------------------------------------------------------------------
	};
}

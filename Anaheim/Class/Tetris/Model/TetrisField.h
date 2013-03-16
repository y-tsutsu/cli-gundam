#pragma once

#include "ISerializable.h"
#include "TetrisMino.h"

namespace Anaheim
{
	namespace Tetris
	{
		namespace Model
		{
			using namespace System;
			using namespace System::Drawing;
			using namespace System::Collections::Generic;

			ref class TetrisMino;

			/**
			 * �e�g���X �t�B�[���h�s
			 */
			public ref class TetrisFieldRow : ISerializable
			{
			/**
			 * �t�B�[���h
			 */
			private:
				array<Color>^ colors;

			/**
			 * �R���X�g���N�^
			 */
			public:
				TetrisFieldRow(int count);

			/**
			 * ���\�b�h
			 */
			public:
				/// �N���A
				void Clear();
				/// �����`�F�b�N
				bool IsComplete();
				/// ��`�F�b�N
				bool IsEmpty();
				/// ��`�F�b�N�i��w��j
				bool IsEmpty(int col);
				/// �V���A���C�Y
				virtual array<Byte>^ Serialize();
				/// �f�V���A���C�Y
				virtual void Deserialize(array<Byte>^ bytes);

			/**
			 * �v���p�e�B
			 */
			public:
				/// �F
				property array<Color>^ Colors
				{
					array<Color>^ get() { return this->colors; }
				}
			};
			// ----------------------------------------------------------------------------------------------------

			/**
			 * �e�g���X �t�B�[���h
			 */
			public ref class TetrisField : ISerializable
			{
			/**
			 * �t�B�[���h
			 */
			private:
				List<TetrisFieldRow^>^ rows;

			public:
				/// �������T�C�Y
				literal int COL_COUNT = 10;
				/// �c�����T�C�Y
				literal int ROW_COUNT = 20;
				/// �o�C�g�T�C�Y
				literal int BYTE_SIZE = COL_COUNT * ROW_COUNT * 3;

			/**
			 * �R���X�g���N�^
			 */
			public:
				TetrisField();

			/**
			 * ���\�b�h
			 */
			private:
				bool IsEmptyRows();
				bool RemoveCompleteRowsMatch(TetrisFieldRow^ row);

			public:
				/// �N���A
				void Clear();
				/// �~�m��colors�ɃZ�b�g
				void SetMino(TetrisMino^ mino);
				/// �����s�����݂��邩����
				bool ExistsCompleteRow();
				/// �����s���폜
				int RemoveCompleteRows();
				/// �V���A���C�Y
				virtual array<Byte>^ Serialize();
				/// �f�V���A���C�Y
				virtual void Deserialize(array<Byte>^ bytes);

			/**
			 * �v���p�e�B
			 */
			public:
				/// �s�R���N�V����
				property List<TetrisFieldRow^>^ Rows
				{
					List<TetrisFieldRow^>^ get() { return this->rows; }
				}
				/// ��`�F�b�N
				property bool IsEmpty
				{
					bool get() { return this->IsEmptyRows(); }
				}
			};
			// ----------------------------------------------------------------------------------------------------
		}
	}
}

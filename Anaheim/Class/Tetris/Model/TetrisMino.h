#pragma once

#include "ISerializable.h"

namespace Anaheim
{
	namespace Tetris
	{
		namespace Model
		{
			using namespace System;
			using namespace System::Drawing;

			ref class TetrisField;
			ref class GhostTetrisMino;

			/**
			 * �e�g���X�~�m
			 */
			public ref class TetrisMino abstract : ISerializable
			{
			/**
			 * enum class
			 */
			protected:
				enum class Rotation : Byte
				{
					R1st,
					R2nd,
					R3rd,
					R4th
				};

			/**
			 * �t�B�[���h
			 */
			protected:
				Point location;
				Rotation rotation;
				array<Point>^ points;

				TetrisField^ field;

			public:
				/// �u���b�N��
				literal int BLOCK_COUNT = 4;
				/// �������T�C�Y
				literal int HORI_COUNT = 4;
				/// �c�����T�C�Y
				literal int VERT_COUNT = 2;
				/// �o�C�g�T�C�Y
				literal int BYTE_SIZE = 12;

			/**
			 * �R���X�g���N�^
			 */
			public:
				TetrisMino(Point location, TetrisField^ field);

			/**
			 * ���\�b�h
			 */
			protected:
				virtual void RefreshPoints() abstract;
				virtual array<Point>^ GetPoints();
				bool RotateCore(Rotation oldRotation);
				bool MoveCore(Point oldPoint);

			public:
				/// �s���ʒu�`�F�b�N
				bool IsIllegalLocation();
				/// �E��]
				virtual bool RotateRight();
				/// ����]
				virtual bool RotateLeft();
				/// �E�ړ�
				virtual bool MoveRight();
				/// ���ړ�
				virtual bool MoveLeft();
				/// ���ړ�
				virtual bool MoveDown();
				/// ���~�m�̈ʒu�ֈړ�
				bool MoveTo(TetrisMino^ mino);
				/// �S�[�X�g�쐬
				GhostTetrisMino^ CreateGhost();
				/// Next�\���p�u���b�N�ʒu����
				virtual PointF AdjustPointForNext(PointF location, SizeF size) abstract;
				/// �V���A���C�Y
				virtual array<Byte>^ Serialize();
				/// �f�V���A���C�Y
				virtual void Deserialize(array<Byte>^ bytes);

			/**
			 * �v���p�e�B
			 */
			public:
				/// �~�m�ʒu�擾
				property array<Point>^ Points
				{
					array<Point>^ get() { return this->GetPoints(); }
				}
				/// ���΃~�m�ʒu�擾
				property array<Point>^ RelativePoints
				{
					array<Point>^ get() { return this->points; }
				}
				/// �e���|�[�g�ʒu
				property Point TeleportPoint
				{
					Point get() { return this->location; }
				}
				/// �F
				property System::Drawing::Color Color
				{
					virtual System::Drawing::Color get() abstract;
				}
			};
			// ----------------------------------------------------------------------------------------------------

			/**
			 * I�e�g���X�~�m
			 */
			ref class ITetrisMino : public TetrisMino
			{
			/**
			 * �t�B�[���h
			 */
			public:
				static initonly System::Drawing::Color COLOR = System::Drawing::Color::Aqua;

			/**
			 * �R���X�g���N�^
			 */
			public:
				ITetrisMino(Point location, TetrisField^ field);

			/**
			 * ���\�b�h
			 */
			protected:
				virtual void RefreshPoints() override;

			public:
				/// Next�\���p�u���b�N�ʒu����
				virtual PointF AdjustPointForNext(PointF location, SizeF size) override;

			/**
			 * �v���p�e�B
			 */
			public:
				/// �F
				property System::Drawing::Color Color
				{
					virtual System::Drawing::Color get() override { return this->COLOR; }
				}
			};
			// ----------------------------------------------------------------------------------------------------

			/**
			 * J�e�g���X�~�m
			 */
			ref class JTetrisMino : public TetrisMino
			{
			/**
			 * �t�B�[���h
			 */
			public:
				static initonly System::Drawing::Color COLOR = System::Drawing::Color::Blue;

			/**
			 * �R���X�g���N�^
			 */
			public:
				JTetrisMino(Point location, TetrisField^ field);

			/**
			 * ���\�b�h
			 */
			protected:
				virtual void RefreshPoints() override;

			public:
				/// Next�\���p�u���b�N�ʒu����
				virtual PointF AdjustPointForNext(PointF location, SizeF size) override;

			/**
			 * �v���p�e�B
			 */
			public:
				/// �F
				property System::Drawing::Color Color
				{
					virtual System::Drawing::Color get() override { return this->COLOR; }
				}
			};
			// ----------------------------------------------------------------------------------------------------

			/**
			 * L�e�g���X�~�m
			 */
			ref class LTetrisMino : public TetrisMino
			{
			/**
			 * �t�B�[���h
			 */
			public:
				static initonly System::Drawing::Color COLOR = System::Drawing::Color::Orange;

			/**
			 * �R���X�g���N�^
			 */
			public:
				LTetrisMino(Point location, TetrisField^ field);

			/**
			 * ���\�b�h
			 */
			protected:
				virtual void RefreshPoints() override;

			public:
				/// Next�\���p�u���b�N�ʒu����
				virtual PointF AdjustPointForNext(PointF location, SizeF size) override;

			/**
			 * �v���p�e�B
			 */
			public:
				/// �F
				property System::Drawing::Color Color
				{
					virtual System::Drawing::Color get() override { return this->COLOR; }
				}
			};
			// ----------------------------------------------------------------------------------------------------

			/**
			 * S�e�g���X�~�m
			 */
			ref class STetrisMino : public TetrisMino
			{
			/**
			 * �t�B�[���h
			 */
			public:
				static initonly System::Drawing::Color COLOR = System::Drawing::Color::Lime;

			/**
			 * �R���X�g���N�^
			 */
			public:
				STetrisMino(Point location, TetrisField^ field);

			/**
			 * ���\�b�h
			 */
			protected:
				virtual void RefreshPoints() override;

			public:
				/// Next�\���p�u���b�N�ʒu����
				virtual PointF AdjustPointForNext(PointF location, SizeF size) override;

			/**
			 * �v���p�e�B
			 */
			public:
				/// �F
				property System::Drawing::Color Color
				{
					virtual System::Drawing::Color get() override { return this->COLOR; }
				}
			};
			// ----------------------------------------------------------------------------------------------------

			/**
			 * Z�e�g���X�~�m
			 */
			ref class ZTetrisMino : public TetrisMino
			{
			/**
			 * �t�B�[���h
			 */
			public:
				static initonly System::Drawing::Color COLOR = System::Drawing::Color::Red;

			/**
			 * �R���X�g���N�^
			 */
			public:
				ZTetrisMino(Point location, TetrisField^ field);

			/**
			 * ���\�b�h
			 */
			protected:
				virtual void RefreshPoints() override;

			public:
				/// Next�\���p�u���b�N�ʒu����
				virtual PointF AdjustPointForNext(PointF location, SizeF size) override;

			/**
			 * �v���p�e�B
			 */
			public:
				/// �F
				property System::Drawing::Color Color
				{
					virtual System::Drawing::Color get() override { return this->COLOR; }
				}
			};
			// ----------------------------------------------------------------------------------------------------

			/**
			 * T�e�g���X�~�m
			 */
			ref class TTetrisMino : public TetrisMino
			{
			/**
			 * �t�B�[���h
			 */
			public:
				static initonly System::Drawing::Color COLOR = System::Drawing::Color::Fuchsia;

			/**
			 * �R���X�g���N�^
			 */
			public:
				TTetrisMino(Point location, TetrisField^ field);

			/**
			 * ���\�b�h
			 */
			protected:
				virtual void RefreshPoints() override;

			public:
				/// Next�\���p�u���b�N�ʒu����
				virtual PointF AdjustPointForNext(PointF location, SizeF size) override;

			/**
			 * �v���p�e�B
			 */
			public:
				/// �F
				property System::Drawing::Color Color
				{
					virtual System::Drawing::Color get() override { return this->COLOR; }
				}
			};
			// ----------------------------------------------------------------------------------------------------

			/**
			 * O�e�g���X�~�m
			 */
			ref class OTetrisMino : public TetrisMino
			{
			/**
			 * �t�B�[���h
			 */
			public:
				static initonly System::Drawing::Color COLOR = System::Drawing::Color::Yellow;

			/**
			 * �R���X�g���N�^
			 */
			public:
				OTetrisMino(Point location, TetrisField^ field);

			/**
			 * ���\�b�h
			 */
			protected:
				virtual void RefreshPoints() override;

			public:
				/// Next�\���p�u���b�N�ʒu����
				virtual PointF AdjustPointForNext(PointF location, SizeF size) override;

			/**
			 * �v���p�e�B
			 */
			public:
				/// �F
				property System::Drawing::Color Color
				{
					virtual System::Drawing::Color get() override { return this->COLOR; }
				}
			};
			// ----------------------------------------------------------------------------------------------------

			/**
			 * �S�[�X�g�e�g���X�~�m
			 */
			ref class GhostTetrisMino : public TetrisMino
			{
			/**
			 * �t�B�[���h
			 */
			private:
				TetrisMino^ master;

			/**
			 * �R���X�g���N�^
			 */
			public:
				GhostTetrisMino(Point location, TetrisField^ field, TetrisMino^ master);

			/**
			 * ���\�b�h
			 */
			protected:
				virtual void RefreshPoints() override;
				System::Drawing::Color GetColor();
				System::Drawing::Color GetBrightBorderColor();
				System::Drawing::Color GetDarkBorderColor();

			public:
				/// �E��]
				virtual bool RotateRight() override;
				/// ����]
				virtual bool RotateLeft() override;
				/// �E�ړ�
				virtual bool MoveRight() override;
				/// ���ړ�
				virtual bool MoveLeft() override;
				/// Next�\���p�u���b�N�ʒu����
				virtual PointF AdjustPointForNext(PointF location, SizeF size) override;

			/**
			 * �v���p�e�B
			 */
			public:
				/// �F
				property System::Drawing::Color Color
				{
					virtual System::Drawing::Color get() override { return this->GetColor(); }
				}
				/// ���邢�g���̐F
				property System::Drawing::Color BrightBorderColor
				{
					System::Drawing::Color get() { return this->GetBrightBorderColor(); }
				}
				/// �Â��g���̐F
				property System::Drawing::Color DarkBorderColor
				{
					System::Drawing::Color get() { return this->GetDarkBorderColor(); }
				}
			};
			// ----------------------------------------------------------------------------------------------------
		}
	}
}

#include "Windows.h"
#include "paircode.h"
#include <msclr\marshal_cppstd.h>

#include <unordered_map>
#include "main_algorithm.h"
#include <mapi.h>
#using <System.dll>
#using <System.Windows.Forms.dll>
#using <Microsoft.VisualBasic.dll>
#include <shellapi.h>
#include <locale>
#include <codecvt>
#pragma comment(lib, "shell32.lib")


namespace pairup {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace System::IO;
	using namespace System::Collections::Generic;



	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ HELP;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ START;
	private: System::Windows::Forms::TextBox^ ENTER;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ PATH_LABEL;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Button^ COPY;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ VIEW;
	private: System::Windows::Forms::DataGridView^ dataGridView1;


	private: System::Windows::Forms::Panel^ panel3;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::ComponentModel::IContainer^ components;
	private: bool isDragging = false;
	private: Point lastCursorPosition;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->HELP = (gcnew System::Windows::Forms::Button());
			this->START = (gcnew System::Windows::Forms::Button());
			this->ENTER = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->PATH_LABEL = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->COPY = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->VIEW = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->AcceptsReturn = true;
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(85)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(148)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->textBox1->Location = System::Drawing::Point(12, 39);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(380, 173);
			this->textBox1->TabIndex = 5;
			this->textBox1->Text = L"The pairing result will show here.";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(148)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->button1->Location = System::Drawing::Point(12, 19);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(123, 31);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Select File";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(46)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->progressBar1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(148)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->progressBar1->Location = System::Drawing::Point(12, 19);
			this->progressBar1->Margin = System::Windows::Forms::Padding(4);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(380, 12);
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar1->TabIndex = 10;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(223)), static_cast<System::Int32>(static_cast<System::Byte>(223)),
				static_cast<System::Int32>(static_cast<System::Byte>(231)));
			this->label1->Location = System::Drawing::Point(9, 172);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 19);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Output";
			// 
			// HELP
			// 
			this->HELP->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->HELP->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->HELP->FlatAppearance->BorderSize = 0;
			this->HELP->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->HELP->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9));
			this->HELP->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(148)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->HELP->Location = System::Drawing::Point(1018, 489);
			this->HELP->Margin = System::Windows::Forms::Padding(4);
			this->HELP->Name = L"HELP";
			this->HELP->Size = System::Drawing::Size(123, 31);
			this->HELP->TabIndex = 8;
			this->HELP->Text = L"Help";
			this->HELP->UseVisualStyleBackColor = false;
			this->HELP->Click += gcnew System::EventHandler(this, &MyForm::HELP_Click);
			// 
			// START
			// 
			this->START->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->START->FlatAppearance->BorderSize = 0;
			this->START->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->START->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9));
			this->START->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(148)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->START->Location = System::Drawing::Point(12, 58);
			this->START->Margin = System::Windows::Forms::Padding(4);
			this->START->Name = L"START";
			this->START->Size = System::Drawing::Size(380, 31);
			this->START->TabIndex = 6;
			this->START->Text = L"Pair";
			this->START->UseVisualStyleBackColor = false;
			this->START->Click += gcnew System::EventHandler(this, &MyForm::START_Click);
			// 
			// ENTER
			// 
			this->ENTER->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(85)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->ENTER->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ENTER->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9));
			this->ENTER->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(148)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->ENTER->Location = System::Drawing::Point(143, 19);
			this->ENTER->Margin = System::Windows::Forms::Padding(4);
			this->ENTER->Multiline = true;
			this->ENTER->Name = L"ENTER";
			this->ENTER->Size = System::Drawing::Size(249, 31);
			this->ENTER->TabIndex = 5;
			this->ENTER->Text = L"D:\\\\main_table.csv";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(46)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->ENTER);
			this->panel1->Controls->Add(this->START);
			this->panel1->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->panel1->Location = System::Drawing::Point(14, 40);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(407, 112);
			this->panel1->TabIndex = 9;
			// 
			// PATH_LABEL
			// 
			this->PATH_LABEL->AutoSize = true;
			this->PATH_LABEL->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PATH_LABEL->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(223)), static_cast<System::Int32>(static_cast<System::Byte>(223)),
				static_cast<System::Int32>(static_cast<System::Byte>(231)));
			this->PATH_LABEL->Location = System::Drawing::Point(9, 14);
			this->PATH_LABEL->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->PATH_LABEL->Name = L"PATH_LABEL";
			this->PATH_LABEL->Size = System::Drawing::Size(93, 19);
			this->PATH_LABEL->TabIndex = 2;
			this->PATH_LABEL->Text = L"Enter the path";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(46)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->COPY);
			this->panel2->Controls->Add(this->progressBar1);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Location = System::Drawing::Point(14, 199);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(407, 270);
			this->panel2->TabIndex = 10;
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button3->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9));
			this->button3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(148)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->button3->Location = System::Drawing::Point(202, 220);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(190, 31);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Clear";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// COPY
			// 
			this->COPY->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->COPY->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->COPY->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->COPY->FlatAppearance->BorderSize = 0;
			this->COPY->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->COPY->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9));
			this->COPY->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(148)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->COPY->Location = System::Drawing::Point(12, 220);
			this->COPY->Margin = System::Windows::Forms::Padding(4);
			this->COPY->Name = L"COPY";
			this->COPY->Size = System::Drawing::Size(182, 31);
			this->COPY->TabIndex = 13;
			this->COPY->Text = L"Copy Text";
			this->COPY->UseVisualStyleBackColor = false;
			this->COPY->Click += gcnew System::EventHandler(this, &MyForm::COPY_Click);
			// 
			// textBox2
			// 
			this->textBox2->AcceptsReturn = true;
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(85)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9));
			this->textBox2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(148)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->textBox2->Location = System::Drawing::Point(18, 19);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(436, 299);
			this->textBox2->TabIndex = 11;
			this->textBox2->Text = L"(Currently Under Development)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(223)), static_cast<System::Int32>(static_cast<System::Byte>(223)),
				static_cast<System::Int32>(static_cast<System::Byte>(231)));
			this->label2->Location = System::Drawing::Point(438, 11);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 19);
			this->label2->TabIndex = 12;
			this->label2->Text = L"CSV File Preview";
			// 
			// panel3
			// 
			this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(46)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->dataGridView1);
			this->panel3->Controls->Add(this->VIEW);
			this->panel3->Controls->Add(this->textBox2);
			this->panel3->Location = System::Drawing::Point(442, 40);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(699, 428);
			this->panel3->TabIndex = 8;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCellsExceptHeader;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCellsExceptHeaders;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersHeight = 10;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(148)));
			dataGridViewCellStyle1->NullValue = nullptr;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(200)));
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->Location = System::Drawing::Point(18, 19);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->RowHeadersWidth = 15;
			this->dataGridView1->ShowCellToolTips = false;
			this->dataGridView1->ShowEditingIcon = false;
			this->dataGridView1->Size = System::Drawing::Size(660, 352);
			this->dataGridView1->TabIndex = 0;
			// 
			// VIEW
			// 
			this->VIEW->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->VIEW->FlatAppearance->BorderSize = 0;
			this->VIEW->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->VIEW->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9));
			this->VIEW->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(148)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->VIEW->Location = System::Drawing::Point(18, 379);
			this->VIEW->Margin = System::Windows::Forms::Padding(4);
			this->VIEW->Name = L"VIEW";
			this->VIEW->Size = System::Drawing::Size(660, 31);
			this->VIEW->TabIndex = 8;
			this->VIEW->Text = L"View Actual File Content";
			this->VIEW->UseVisualStyleBackColor = false;
			this->VIEW->Click += gcnew System::EventHandler(this, &MyForm::VIEW_Click);
			// 
			// textBox3
			// 
			this->textBox3->AcceptsReturn = true;
			this->textBox3->AcceptsTab = true;
			this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(37)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(148)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->textBox3->Location = System::Drawing::Point(13, 489);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(984, 70);
			this->textBox3->TabIndex = 8;
			this->textBox3->Text = L"Feature:\r\n(1) File Preview.\r\n(2) Relatively Satisfactory Pairing Result.\r\n(3) Sim"
				L"plicity Of Copying Output Text.";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button2->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9));
			this->button2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(148)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->button2->Location = System::Drawing::Point(1018, 528);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(123, 31);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Report";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::REPORT_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(37)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->ClientSize = System::Drawing::Size(1156, 583);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->HELP);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->PATH_LABEL);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel3);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"PairUP (Beta)";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void HELP_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ link = "https://docs.google.com/document/d/1HHG1y2zlczwjhcL4rsIAbo3DYaYzrJHStA5yo6rn2FM/edit?usp=sharing";
	System::Diagnostics::Process::Start(link);
}

private: System::Void START_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Enabled = true;
	String^ R = marshal_as<String^>(startPair::main_algorithm(ENTER->Text));
	if (R != "") {
		progressBar1->Value = 100;
		MessageBox::Show(this,"Best paring result has been generated! It is worth mentioning that you can also click the 'Pair' button again if you're not satisfied with this output.", "Pair Successfully!", MessageBoxButtons::OK, MessageBoxIcon::Asterisk, MessageBoxDefaultButton::Button1);
		textBox1->Text = R;
		COPY->Text = "Copy Text";
	}
}

private: List<array<String^>^>^ LoadCsv(String^ path)
{
	List<array<String^>^>^ result = gcnew List<array<String^>^>();
	StreamReader^ reader = gcnew StreamReader(path);

	while (!reader->EndOfStream)
	{
		String^ line = reader->ReadLine();
		array<String^>^ fields = line->Split(',');

		result->Add(fields);
	}

		reader->Close();
		return result;
}


private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
	
	openFileDialog1->Filter = "CSV Files (*.csv)|*.csv";
	openFileDialog1->FilterIndex = 1;
	openFileDialog1->RestoreDirectory = true;
	
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		// Get the selected file name
		ENTER->Text = openFileDialog1->FileName;
		// Use the selected file name as needed
		
	}
		
		dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();
		
		List<array<String^>^>^ data = LoadCsv(ENTER->Text);

		dataGridView1->ColumnCount = 18;
		//dataGridView1->Columns[0]->Name = "Column 1";
		//dataGridView1->Columns[1]->Name = "Column 2";
		//dataGridView1->Columns[2]->Name = "Column 3";

		for (int i = 0; i < data->Count; i++)
		{
			dataGridView1->Rows->Add(data[i]);
		}
		
		
		//textBox2->Text = marshal_as<String^>(startPair::vice_algorithm(ENTER->Text));
		/*std::vector<std::string> preview = startPair::vice_algorithm(ENTER->Text);
		textBox2->Text = "";
		for (int i = 0; i < preview.size(); i++) {
			textBox2->Text += marshal_as<String^>(preview[i]);
			textBox2->Text += "\n";
		}*/

}



private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	static int progress = 0;
	progress += 33;
	if (progress > 100) {
		timer1->Enabled = false;
		progress = 0;
	}
	progressBar1->Value = progress;
}


private: System::Void COPY_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::Clipboard::SetText(textBox1->Text);
	COPY->Text = "Text has been copied to clipboard!";
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Text = L"The pairing result will show here.";
}

	   //這個地方好重要...
private: System::Void REPORT_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ email = Microsoft::VisualBasic::Interaction::InputBox("Enter your email address:", "SendEmail", "", 100, 100);
		String^ password = Microsoft::VisualBasic::Interaction::InputBox("Enter your email password:", "SendEmail", "", 100, 100);
		String^ report = Microsoft::VisualBasic::Interaction::InputBox("Describe the problem you encounter:", "SendEmail", "", 100, 100);

		System::Net::Mail::MailMessage^ mail = gcnew System::Net::Mail::MailMessage();
		mail->From = gcnew System::Net::Mail::MailAddress(email);
		mail->To->Add("jackiesogi@outlook.com");
		mail->Subject = "PairUP error report";
		mail->Body = report;
		System::Net::Mail::SmtpClient^ smtp = gcnew System::Net::Mail::SmtpClient("smtp.outlook.com");
		smtp->EnableSsl = true;
		smtp->Credentials = gcnew System::Net::NetworkCredential(email, password);
		smtp->Send(mail);
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
	}
}

private: System::Void VIEW_Click(System::Object^ sender, System::EventArgs^ e) {
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::wstring filePath = marshal_as<std::wstring>(ENTER->Text);
	ShellExecute(NULL, L"open", L"notepad.exe", filePath.c_str(), NULL, SW_SHOW);
}

};

};
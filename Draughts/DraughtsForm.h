/*
* An interactive draughts game for windows, with an accompanying AI
* (To be added). Source code for extended project.
*/
#pragma once
#include <string>
#include <fstream>
#include "DraughtsAI.h"



namespace Draughts {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//The height and width of a cell (changing this only changes height)
	const int CELL_SIZE = 51;

	//Player one's colour
	const cellState P1_COLOUR = M_BLACK;

	//The colour of the player whose turn it is (black starts)
	cellState currentplayer = P1_COLOUR;

	//True if the player has chosen a piece to move
	bool firstCellPicked = false;

	//True if the player is in the middle of a series of captures
	bool captureinprogress = false;

	//The current move that the player is making
	DraughtsMove playermove;

	//The last cell that was moved when performing multiple captures
	Cell lastCell;

	//const std::string IMAGES[5] = {"empty.png","m_white.png","k_white.png","m_black.png","k_black.png"};
	//The current game board
	Board currentboard;

	//The AI
	AI opponent(otherplayer(P1_COLOUR));

	/// <summary>
	/// Summary for DraughtsForm
	/// </summary>
	public ref class DraughtsForm : public System::Windows::Forms::Form
	{
	public:
		DraughtsForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DraughtsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dgvBoard;
	private: System::Windows::Forms::DataGridViewImageColumn^  Column2;
	private: System::Windows::Forms::DataGridViewImageColumn^  Column1;
	private: System::Windows::Forms::DataGridViewImageColumn^  Column3;
	private: System::Windows::Forms::DataGridViewImageColumn^  Column4;
	private: System::Windows::Forms::DataGridViewImageColumn^  Column5;
	private: System::Windows::Forms::DataGridViewImageColumn^  Column6;
	private: System::Windows::Forms::DataGridViewImageColumn^  Column7;
	private: System::Windows::Forms::DataGridViewImageColumn^  Column8;
	private: System::Windows::Forms::Button^  btnReset;
	private: System::Windows::Forms::Label^  lbCurrentPlayer;
	private: System::Windows::Forms::ListBox^  lsMoveLog;

	private: System::Windows::Forms::Label^  lbMoveLog;
	private: System::Windows::Forms::Button^  btnStart;
	private: System::Windows::Forms::NumericUpDown^  nudAIDepth;
	private: System::Windows::Forms::Label^  lblAIDepth;



	protected: 

	protected: 

	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dgvBoard = (gcnew System::Windows::Forms::DataGridView());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->lbCurrentPlayer = (gcnew System::Windows::Forms::Label());
			this->lsMoveLog = (gcnew System::Windows::Forms::ListBox());
			this->lbMoveLog = (gcnew System::Windows::Forms::Label());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->nudAIDepth = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblAIDepth = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvBoard))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudAIDepth))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvBoard
			// 
			this->dgvBoard->AllowUserToAddRows = false;
			this->dgvBoard->AllowUserToDeleteRows = false;
			this->dgvBoard->AllowUserToResizeColumns = false;
			this->dgvBoard->AllowUserToResizeRows = false;
			this->dgvBoard->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvBoard->ColumnHeadersVisible = false;
			this->dgvBoard->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {this->Column2, this->Column1, 
				this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8});
			this->dgvBoard->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->dgvBoard->Location = System::Drawing::Point(12, 12);
			this->dgvBoard->MultiSelect = false;
			this->dgvBoard->Name = L"dgvBoard";
			this->dgvBoard->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dgvBoard->RowHeadersVisible = false;
			this->dgvBoard->Size = System::Drawing::Size(411, 411);
			this->dgvBoard->TabIndex = 0;
			this->dgvBoard->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &DraughtsForm::dgvBoard_CellFormatting);
			this->dgvBoard->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &DraughtsForm::dgvBoard_CellMouseClick);
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Column2";
			this->Column2->Name = L"Column2";
			this->Column2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column2->Width = 51;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Column1";
			this->Column1->Name = L"Column1";
			this->Column1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->Column1->Width = 51;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Column3";
			this->Column3->Name = L"Column3";
			this->Column3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column3->Width = 51;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Column4";
			this->Column4->Name = L"Column4";
			this->Column4->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column4->Width = 51;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Column5";
			this->Column5->Name = L"Column5";
			this->Column5->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column5->Width = 51;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Column6";
			this->Column6->Name = L"Column6";
			this->Column6->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column6->Width = 51;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Column7";
			this->Column7->Name = L"Column7";
			this->Column7->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column7->Width = 51;
			// 
			// Column8
			// 
			this->Column8->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Column8->HeaderText = L"Column8";
			this->Column8->MinimumWidth = 32;
			this->Column8->Name = L"Column8";
			this->Column8->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column8->Width = 51;
			// 
			// btnReset
			// 
			this->btnReset->Location = System::Drawing::Point(555, 39);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(75, 23);
			this->btnReset->TabIndex = 1;
			this->btnReset->Text = L"Reset";
			this->btnReset->UseVisualStyleBackColor = true;
			this->btnReset->Click += gcnew System::EventHandler(this, &DraughtsForm::btnReset_Click);
			// 
			// lbCurrentPlayer
			// 
			this->lbCurrentPlayer->AutoSize = true;
			this->lbCurrentPlayer->Location = System::Drawing::Point(474, 124);
			this->lbCurrentPlayer->Name = L"lbCurrentPlayer";
			this->lbCurrentPlayer->Size = System::Drawing::Size(80, 13);
			this->lbCurrentPlayer->TabIndex = 2;
			this->lbCurrentPlayer->Text = L"It\'s black\'s turn.";
			// 
			// lsMoveLog
			// 
			this->lsMoveLog->FormattingEnabled = true;
			this->lsMoveLog->Location = System::Drawing::Point(474, 172);
			this->lsMoveLog->Name = L"lsMoveLog";
			this->lsMoveLog->Size = System::Drawing::Size(120, 251);
			this->lsMoveLog->TabIndex = 3;
			// 
			// lbMoveLog
			// 
			this->lbMoveLog->AutoSize = true;
			this->lbMoveLog->Location = System::Drawing::Point(474, 153);
			this->lbMoveLog->Name = L"lbMoveLog";
			this->lbMoveLog->Size = System::Drawing::Size(71, 13);
			this->lbMoveLog->TabIndex = 4;
			this->lbMoveLog->Text = L"Moves so far:";
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(474, 39);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(75, 23);
			this->btnStart->TabIndex = 5;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &DraughtsForm::btnStart_Click);
			// 
			// nudAIDepth
			// 
			this->nudAIDepth->Location = System::Drawing::Point(559, 10);
			this->nudAIDepth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->nudAIDepth->Name = L"nudAIDepth";
			this->nudAIDepth->Size = System::Drawing::Size(75, 20);
			this->nudAIDepth->TabIndex = 6;
			this->nudAIDepth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			// 
			// lblAIDepth
			// 
			this->lblAIDepth->AutoSize = true;
			this->lblAIDepth->Location = System::Drawing::Point(471, 12);
			this->lblAIDepth->Name = L"lblAIDepth";
			this->lblAIDepth->Size = System::Drawing::Size(85, 13);
			this->lblAIDepth->TabIndex = 7;
			this->lblAIDepth->Text = L"AI search depth:";
			// 
			// DraughtsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(646, 433);
			this->Controls->Add(this->lblAIDepth);
			this->Controls->Add(this->nudAIDepth);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->lbMoveLog);
			this->Controls->Add(this->lsMoveLog);
			this->Controls->Add(this->lbCurrentPlayer);
			this->Controls->Add(this->btnReset);
			this->Controls->Add(this->dgvBoard);
			this->Name = L"DraughtsForm";
			this->Text = L"Draughts";
			this->Load += gcnew System::EventHandler(this, &DraughtsForm::DraughtsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvBoard))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudAIDepth))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DraughtsForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 //Initialise Board
				 for(int i=0; i<BOARD_HEIGHT; i++) {
					this->dgvBoard->Rows->Add();
					DataGridViewRow^ row = dgvBoard->Rows[i];
					row->Height = CELL_SIZE;
				 }
				 
				 ResetBoard(currentboard);
				 UpdateGrid(currentboard);

				 //this->lsMoveLog->Items->Add(gcnew String(std::to_string(static_cast<long double>(heuristic(currentboard))).c_str()));

				 /*
				 AI test(P1_COLOUR);
				 std::vector<DraughtsMove> available = test.getAvailableMoves(currentboard);
				 for(unsigned int i=0; i<available.size(); i++) {
					 this->lsMoveLog->Items->Add(gcnew String(MoveToString(available[i]).c_str()));
				 }
				 */
				 setGameStart(false);
			 }
	private: System::Void dgvBoard_CellFormatting(System::Object^  sender, System::Windows::Forms::DataGridViewCellFormattingEventArgs^  e) {
				 DataGridViewCell^ cell = this->dgvBoard->Rows[e->RowIndex]->Cells[e->ColumnIndex];
				 if(e->RowIndex % 2 != e->ColumnIndex % 2) {
					 cell->Style->BackColor = Color::FromArgb(182,73,14);
				 }
				 else {
					 cell->Style->BackColor = Color::FromArgb(240,202,126);
				 }
			 }

	void ResetBoard(Board& board) {
		//Opens the initial position file
		std::ifstream startposfile("startpos.txt");
		std::string currentline;
		int currentval;

		//Set the board's values to those of the file
		for(int y=0; y<BOARD_HEIGHT; y++) {
			if(std::getline(startposfile,currentline)) {
				for(int x=0; x<BOARD_WIDTH; x++) {
					currentval = currentline[x]-48;
					board.cells[y][x] = cellState(currentval);
				}
			}
		}	
		startposfile.close();
	}

	void UpdateGrid(Board board) {
		//Load the images
		Image^ img_empty	= Image::FromFile("empty.png");
		Image^ img_m_black	= Image::FromFile("m_black.png");
		Image^ img_k_black	= Image::FromFile("k_black.png");		
		Image^ img_m_white	= Image::FromFile("m_white.png");
		Image^ img_k_white	= Image::FromFile("k_white.png");

		//Adds an image to each cell depending on its current state
		for(int y=0; y<BOARD_HEIGHT; y++) {
			for(int x=0; x<BOARD_WIDTH; x++) {
				//System::String^ img_path = gcnew System::String(IMAGES[(int)board.cells[y][x]].c_str());
				//Image^ cellimage = Image::FromFile(img_path);
				switch (board.cells[y][x]) {
				case EMPTY:
					this->dgvBoard->Rows[y]->Cells[x]->Value = img_empty;
					break;
				case M_BLACK:
					this->dgvBoard->Rows[y]->Cells[x]->Value = img_m_black;
					break;
				case K_BLACK:
					this->dgvBoard->Rows[y]->Cells[x]->Value = img_k_black;
					break;
				case M_WHITE:
					this->dgvBoard->Rows[y]->Cells[x]->Value = img_m_white;
					break;
				case K_WHITE:
					this->dgvBoard->Rows[y]->Cells[x]->Value = img_k_white;
					break;	
				}
			}
		}
	}

	//Overloaded version of UpdateGrid that updates only the cells listed in cellsToUpdate.
	void UpdateGrid(Board board, std::vector<Cell> cellsToUpdate) {
		//Load the images
		Image^ img_empty	= Image::FromFile("empty.png");
		Image^ img_m_black	= Image::FromFile("m_black.png");
		Image^ img_k_black	= Image::FromFile("k_black.png");		
		Image^ img_m_white	= Image::FromFile("m_white.png");
		Image^ img_k_white	= Image::FromFile("k_white.png");

		//Adds an image to each cell depending on its current state
		for(unsigned int i=0; i<cellsToUpdate.size(); i++) {
				//System::String^ img_path = gcnew System::String(IMAGES[(int)board.cells[y][x]].c_str());
				//Image^ cellimage = Image::FromFile(img_path);
				switch (board.cells[cellsToUpdate[i].y][cellsToUpdate[i].x]) {
				case EMPTY:
					this->dgvBoard->Rows[cellsToUpdate[i].y]->Cells[cellsToUpdate[i].x]->Value = img_empty;
					break;
				case M_BLACK:
					this->dgvBoard->Rows[cellsToUpdate[i].y]->Cells[cellsToUpdate[i].x]->Value = img_m_black;
					break;
				case K_BLACK:
					this->dgvBoard->Rows[cellsToUpdate[i].y]->Cells[cellsToUpdate[i].x]->Value = img_k_black;
					break;
				case M_WHITE:
					this->dgvBoard->Rows[cellsToUpdate[i].y]->Cells[cellsToUpdate[i].x]->Value = img_m_white;
					break;
				case K_WHITE:
					this->dgvBoard->Rows[cellsToUpdate[i].y]->Cells[cellsToUpdate[i].x]->Value = img_k_white;
					break;	
				}
		}
	}

	//Updates the current board to represent it after move has been performed
	void DoMove(DraughtsMove move) {
		currentboard.cells[move.destination.y][move.destination.x] = currentboard.cells[move.start.y][move.start.x];
		currentboard.cells[move.start.y][move.start.x] = EMPTY;

		if(move.capture) {
			//Delete the piece that has been captured
			currentboard.cells[(move.start.y + move.destination.y)/2][(move.start.x + move.destination.x)/2] = EMPTY;
		}

		//Add the move to the game's move log
		this->lsMoveLog->Items->Add(gcnew String(MoveToString(move).c_str()));
		
	}

	void AITurn(AI ai) {
		MoveSequence AImove = ai.getMove(currentboard, ai.getSearchDepth());
		for(unsigned int i=0; i<AImove.moves.size(); i++) {
			DoMove(AImove.moves[i]);

			bool crowned = false;
			if(ai.getColour() == M_BLACK && AImove.moves[i].destination.y == 0) {
				currentboard.cells[AImove.moves[i].destination.y][AImove.moves[i].destination.x] = K_BLACK;
				crowned = true;
			}
			if(ai.getColour() == M_WHITE && AImove.moves[i].destination.y == BOARD_HEIGHT-1) {
				currentboard.cells[AImove.moves[i].destination.y][AImove.moves[i].destination.x] = K_WHITE;
				crowned = true;
			}
			UpdateGrid(currentboard,AImove.moves[i].getAffectedCells());
		}
	}

	private: System::Void dgvBoard_CellMouseClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) {
			 Cell clickedcell(e->ColumnIndex,e->RowIndex);

			 /*
			 If the clicked cell contains one of the player's men or kings and they are not
			 in the middle of a series of captures, set this as the piece to move.
			 */
			 if(((currentboard.cells[clickedcell.y][clickedcell.x] == currentplayer)||(currentboard.cells[clickedcell.y][clickedcell.x] == currentplayer+1)) && !captureinprogress) {
				playermove.start = clickedcell;
				firstCellPicked = true;
			 }
			 /*
			 If the user has picked an empty cell to move their piece to, move it there if it
			 is a valid draughts move.
			 */
			 else if((currentboard.cells[clickedcell.y][clickedcell.x] == EMPTY) && firstCellPicked) {
				playermove.destination = clickedcell;
				if(playermove.isValid(currentboard,currentplayer)) {
					DoMove(playermove);
					bool crowned = false;

					if(currentplayer == M_BLACK && playermove.destination.y == 0) {
						currentboard.cells[playermove.destination.y][playermove.destination.x] = K_BLACK;
						crowned = true;
					}
					if(currentplayer == M_WHITE && playermove.destination.y == BOARD_HEIGHT-1) {
						currentboard.cells[playermove.destination.y][playermove.destination.x] = K_WHITE;
						crowned = true;
					}

					UpdateGrid(currentboard,playermove.getAffectedCells());
					
					if(HasWon(currentplayer,currentboard)) {
						if(currentplayer == M_WHITE) {MessageBox::Show("White is the winner!","Victory!");}
						else {MessageBox::Show("Black is the winner!","Victory!");}
						ResetBoard(currentboard);
						UpdateGrid(currentboard);
					} //If an additional capture is not possible after a capture or a man was crowned, end the turn.
					else if(CanCapture(currentboard,playermove.destination.x,playermove.destination.y) && playermove.capture && !crowned) {
						captureinprogress = true;
						playermove.start = playermove.destination;
					} else {
						//Reset the value of playermove.capture
						playermove.capture = false;

						firstCellPicked = false;
						captureinprogress = false;
						//this->lsMoveLog->Items->Add(gcnew String(std::to_string(static_cast<long double>(opponent.heuristic(currentboard))).c_str()));
						AITurn(opponent);
						//this->lsMoveLog->Items->Add(gcnew String(std::to_string(static_cast<long double>(opponent.heuristic(currentboard))).c_str()));
					}

					
				}
				else {
					//Show the 'invalid move' dialog box
					MessageBox::Show("That move is not valid.","Invalid Move");
				}
			 }
		 }
	
	private: System::Void btnReset_Click(System::Object^  sender, System::EventArgs^  e) {
			 //Reset the game to its starting setup
			 ResetBoard(currentboard);
			 UpdateGrid(currentboard);
			 currentplayer = M_BLACK;
			 this->lbCurrentPlayer->Text = "It's black's turn.";
			 this->lsMoveLog->Items->Clear();
			 setGameStart(false);
		 }

	void NextPlayer() {
		if(currentplayer == M_BLACK) {
			currentplayer = M_WHITE;
			this->lbCurrentPlayer->Text = "It's white's turn.";
		}
		else {
			currentplayer = M_BLACK;
			this->lbCurrentPlayer->Text = "It's black's turn.";
		}
	}
	
	//Returns the cell's number in draughts game documentation
	int CellValue(Cell cell) {
		return ((cell.y * 4) + ((cell.x + 1 + (cell.y%2)) / 2));
	}

	//Converts a move object into a string to display
	std::string MoveToString(DraughtsMove move) {
		using namespace std;
		char symbol;
		if(move.capture) {symbol = 'x';}
		else {symbol = '-';}
		string result = to_string(static_cast<long double>(CellValue(move.start))) + symbol + to_string(static_cast<long double>(CellValue(move.destination)));
		return result;
	}

	void setGameStart(bool start) {
		this->dgvBoard->Enabled = start;
		this->btnReset->Enabled = start;
		
		this->btnStart->Enabled = !start;
		this->nudAIDepth->Enabled = !start;
	}
private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {
			 setGameStart(true);
			 opponent.setSearchDepth((int)this->nudAIDepth->Value);
		 }
};
}


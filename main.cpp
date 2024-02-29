#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::vector;

char player{'X'};
bool game_over{false};

int row{};
int col{};

void move(char token, vector<vector<char>> &board, int row, int col) {
  board[row][col] = token;
}

void render(vector<vector<char>> &board) {

  cout << "     █     █     \n";
  cout << "  " << board[0][0] << "  █  " << board[0][1] << "  █  "
       << board[0][2] << '\n';
  cout << "     █     █     \n";
  cout << "█████████████████\n";
  cout << "     █     █     \n";
  cout << "  " << board[1][0] << "  █  " << board[1][1] << "  █  "
       << board[1][2] << '\n';
  cout << "     █     █     \n";
  cout << "█████████████████\n";
  cout << "     █     █     \n";
  cout << "  " << board[2][0] << "  █  " << board[2][1] << "  █  "
       << board[2][2] << '\n';
  cout << "     █     █     \n";
}

void toggle_player() {
  if (player == 'X') {
    player = 'O';
  } else {
    player = 'X';
  }
}

void input() {
  cout << player << " moves\n";
  cout << "Row: ";
  cin >> row;

  cout << "Column: ";
  cin >> col;
}

int main() {
  vector<vector<char>> board{{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

  while (!game_over) {
    input();

    if (board[row - 1][col - 1] == ' ') {
      move(player, board, row - 1, col - 1);
      render(board);

      // check wins for row
      for (int row_num{0}; row_num < board.size(); row_num++) {
        if (board[row_num][0] == player && board[row_num][1] == player &&
            board[row_num][2] == player) {
          game_over = true;
        }
      }

      // check wins for column
      for (int col_num{0}; col_num < board[0].size(); col_num++) {
        if (board[0][col_num] == player && board[1][col_num] == player &&
            board[2][col_num] == player) {
          game_over = true;
        }
      }

      // check wins for diagonal
      if (board[0][0] == player && board[1][1] == player &&
          board[2][2] == player) {
        game_over = true;
      }

      // check wins for anti-diagonal
      if (board[0][2] == player && board[2][2] == player &&
          board[2][0] == player) {
        game_over = true;
      }

      toggle_player();
    } else {
      cout << "Square occupied. Move again.\n";
    }
  }
  toggle_player();
  cout << player << " wins!\n";
  return 0;
}

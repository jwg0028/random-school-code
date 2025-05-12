/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package checkersgame;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class CheckersGame extends JFrame {
    
        static final int //needed static that will populate the board
        BOARD_SIZE = 8,
        EMPTY = ' ',
        RED = 'R',
        BLACK = 'B',
        PLAYER1_KING = 'K', 
        PLAYER2_KING = 'Q';
        
         private char[][] board; //the board 

    CheckersGame(int fromRow, int fromCol, int toRow, int toCol) {
   
        }

    public CheckersGame() {
        initializeBoard();
        SetupGUI();
    }

//Initialized the board and its pieces to the right places
    private void initializeBoard() {
        board = new char[BOARD_SIZE][BOARD_SIZE];
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                if ((row + col) % 2 == 0 && row < 3) {
                    board[row][col] = BLACK;
                } else if ((row + col) % 2 == 0 && row > 4) {
                    board[row][col] = RED;
                } else {
                    board[row][col] = EMPTY;
                }
            }
        }
    }

    //SetupGUI is what sets up the GUI. it creates the intractable board and populates it with the pieces. It also creates the buttons.
    private void SetupGUI() {
        //the title and basic operationf for the GUI
        setTitle("Checkers Game");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(BOARD_SIZE+1, BOARD_SIZE));

        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                JButton button = new JButton(String.valueOf(board[row][col]));
                button.setFont(new Font("Arial", Font.BOLD, 20));
                button.addActionListener(new ButtonListener(row, col));
                add(button);
            }
        }
        
        //Start of Save button initialization
        JButton saveButton = new JButton("Save");
        saveButton.setFont(new Font("Arial", Font.BOLD, 20));
        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Call the saveData method when the "Save" button is clicked
                String name = "saved_game.txt";
                saveData(name);
            }
        });

        add(saveButton);
        //End of Save button initialization
        //Start of Load button initialization
        JButton loadButton = new JButton("Load");
        loadButton.setFont(new Font("Arial", Font.BOLD, 20));
        loadButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Call the saveData method when the "Save" button is clicked
                String name = "saved_game.txt";
                fromSave(name);
            }
        });

        add(loadButton);
        //End of load initialization
        
        
        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    } //end of SetupGUI

    // This section is supposed to deal with reading inputs for movement later and triggering button presses
    private class ButtonListener implements ActionListener {
        private int fromRow, fromCol;
        private boolean isSelected = false;

        public ButtonListener(int row, int col) {
            fromRow = row;
            fromCol = col;
        }
       
        @Override
        public void actionPerformed(ActionEvent e) {
            JButton clickedButton = (JButton) e.getSource();

            if (!isSelected) {
                isSelected = true;
                clickedButton.setBackground(Color.YELLOW);
            } else {
                int toRow = fromRow;
                int toCol = fromCol;

                // Get the destination row and column from the clicked button
                Component[] buttons = getContentPane().getComponents();
                for (int i = 0; i < buttons.length; i++) {
                    if (buttons[i] == clickedButton) {
                        toRow = i / BOARD_SIZE;
                        toCol = i % BOARD_SIZE;
                        break;
                    }
                }

                if (IsValidMove(fromRow, fromCol, toRow, toCol)) {
                    MakeMove(fromRow, fromCol, toRow, toCol);
                    updateBoard();
                } else {
                    JOptionPane.showMessageDialog(null, "Invalid move! Try again.");
                }

                isSelected = false;
            }
        } //end of actionPerformed

        
    } //end of ButtonListener

    private boolean IsValidMove(int fromRow, int fromCol, int toRow, int toCol) { //FIX OR DELETE PLEASE
        
        
        
        

        return true; // Temporary - Replace with actual validation logic
    }

    class LegalMove {
    private int player; 

    public LegalMove(int player) {
        
        
        this.player = player; // Assign the parameter to the instance variable
        if (this.player != 1 || this.player != 2) {
            // Handle the case where player is not equal to 1
        }

        int PlayerKing;
        int PLAYER1_KING = CheckersGame.PLAYER1_KING;
        int PLAYER2_KING = CheckersGame.PLAYER2_KING;
        
        
        if ( this.player  == 1) //the if state ment is to properly define the kings to the correct player.
                PlayerKing = PLAYER1_KING ; 
        else
                PlayerKing = PLAYER2_KING; 
    }

      
    
        
        CheckersGame[]  LegalJump( int row, int col ) { 
        
        
            
              ArrayList<CheckersGame> moves = new ArrayList<CheckersGame>();
              
                    if (board[row][col] == player || board[row][col] == PLAYER1_KING || board[row][col] == PLAYER2_KING) {
                        if (CanJump(player, row, col, row+1, col+1, row+2, col+2))
                            moves.add(new CheckersGame(row, col, row+2, col+2));
                        if (CanJump(player, row, col, row-1, col+1, row-2, col+2))
                            moves.add(new CheckersGame(row, col, row-2, col+2));
                        if (CanJump(player, row, col, row+1, col-1, row+2, col-2))
                            moves.add(new CheckersGame(row, col, row+2, col-2));
                        if (CanJump(player, row, col, row-1, col-1, row-2, col-2))
                            moves.add(new CheckersGame(row, col, row-2, col-2));
                    }
              /*  If any jump moves were found, then the user must jump, so we don't 
             add any regular moves.  However, if no jumps were found, check for
             any legal regular moves.  Look at each square on the board.
             If that square contains one of the player's pieces, look at a possible
             move in each of the four directions from that square.  If there is 
             a legal move in that direction, put it in the moves ArrayList.
             */

            if (moves.size() == 0) { 
                for ( row = 0; row < 8; row++) { 
                    for ( col = 0; col < 8; col++) {
                        if (board[row][col] == player || board[row][col] == PLAYER1_KING || board[row][col] == PLAYER2_KING) {
                            if (CanMove(player,row,col,row+1,col+1))
                                moves.add(new CheckersGame(row,col,row+1,col+1));
                            if (CanMove(player,row,col,row-1,col+1))
                                moves.add(new CheckersGame(row,col,row-1,col+1));
                            if (CanMove(player,row,col,row+1,col-1))
                                moves.add(new CheckersGame(row,col,row+1,col-1));
                            if (CanMove(player,row,col,row-1,col-1))
                                moves.add(new CheckersGame(row,col,row-1,col-1));
                        }
                    }
                }
            }

            /* If no legal moves have been found, return null.  Otherwise, create
             an array just big enough to hold all the legal moves, copy the
             legal moves from the ArrayList into the array, and return the array. */

            if (moves.size() == 0)
                return null;
            else {
                CheckersGame[] moveArray = new CheckersGame[moves.size()]; 
                for (int i = 0; i < moves.size(); i++)
                    moveArray[i] = moves.get(i);
                return moveArray;
            }
        } //end of GetLegalJumpsFrom
    } //end of LegalMove
    
    
    // the CanJump boolean test if a jump is possible and if there is one voice the player to jump
    private boolean CanJump(int player, int r1, int c1, int r2, int c2, int r3, int c3) {


        int PLAYER1_KING =CheckersGame.PLAYER1_KING;
        int PLAYER2_KING =CheckersGame.PLAYER2_KING;
        int EMPTY = CheckersGame.EMPTY;
       
            if (r3 < 0 || r3 >= 8 || c3 < 0 || c3 >= 8)
                return false;  // (r3,c3) is off the board.

            if (board[r3][c3] != EMPTY)
                return false;  // (r3,c3) already contains a piece.

            if (player == RED) {
                if (board[r1][c1] == RED && r3 > r1)
                    return false;  // Regular red piece can only move up.
                if (board[r2][c2] != BLACK && board[r2][c2] != PLAYER2_KING)
                    return false;  // There is no black piece to jump.
                return true;  // The jump is legal.
            }
            else {
                if (board[r1][c1] == BLACK && r3 < r1)
                    return false;  // Regular black piece can only move downn.
                if (board[r2][c2] != RED && board[r2][c2] != PLAYER1_KING)
                    return false;  // There is no red piece to jump.
               
                return true;  // The jump is legal.
            }

    }  // end canJump() 
    
    
    // the CanMove boolean specifically test if a move is possible when a piece is choosen.
    private boolean CanMove( int player, int fromRow, int fromCol, int toRow, int toCol) {
        

            if (toRow < 0 || toRow >= 8 || toCol < 0 || toCol >= 8)
                return false;  // (r2,c2) is off the board.

            if (board[toRow][toCol] != 0) //empty error
                return false;  // (r2,c2) already contains a piece.

            if (player == RED) {
                if (board[fromRow][fromCol] == 1 && toRow > fromRow)
                    return false;  // Regular piece of the first player  can only move down.
                return true;  // The move is legal.
            }
            else {
                if (board[fromRow][fromCol] == 2 && toRow < fromRow)
                    return false;  // Regular  piece of the second player can only move up.
                return true;  // The move is legal.
            }
    } //end of CanMove
    
    
    //MakeMove is what allows the pieces to move. it does not check for any of the rules however.
    private void MakeMove(int fromRow, int fromCol, int toRow, int toCol) { 
        
        
         int PLAYER1 =CheckersGame.RED;
        int PLAYER1_KING =CheckersGame.PLAYER1_KING;
        int PLAYER2 =CheckersGame.BLACK;
        int PLAYER2_KING =CheckersGame.PLAYER2_KING;
        int EMPTY = CheckersGame.EMPTY;
        
            board[toRow][toCol] = board[fromRow][fromCol];
            board[fromRow][fromCol] = (char) EMPTY;
            if (fromRow - toRow == 2 || fromRow - toRow == -2) {
                // The move is a jump.  Remove the jumped piece from the board.
                int jumpRow = (fromRow + toRow) / 2;  // Row of the jumped piece.
                int jumpCol = (fromCol + toCol) / 2;  // Column of the jumped piece.
                board[jumpRow][jumpCol] = (char) EMPTY;
            }
            if (toRow == 0 && board[toRow][toCol] == PLAYER1)
                board[toRow][toCol] = (char) PLAYER1_KING;
            if (toRow == 7 && board[toRow][toCol] == PLAYER2)
                board[toRow][toCol] = (char) PLAYER2_KING;
  
        char temp = board[toRow][toCol];
        board[toRow][toCol] = board[fromRow][fromCol];
        board[fromRow][fromCol] = temp;
    } //end of MakeMove
    
    //updateBoard is supposed to update the board and buttons (visually)
    private void updateBoard() {
        Component[] buttons = getContentPane().getComponents();
        int index = 0;
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                JButton button = (JButton) buttons[index++];
                button.setText(String.valueOf(board[row][col]));
                button.setBackground(null);
            }
        }
    } //end of updateBoard

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new CheckersGame();
        });
    }

/* The saveData function takes a string and saves a file containing board data 
the game and names the text file after the string. As it is now, it will always
save the text document with the name "saved_game.txt"*/
void saveData(String saveName) {
    String fileName = saveName;
    try {
        File file = new File(fileName);
        file.createNewFile();
        FileWriter writeFile = new FileWriter(fileName);
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                writeFile.write(board[row][col]);
            }
            writeFile.write('\n'); // Add a new line after each row
        }
        writeFile.close();
    } catch (IOException e) {
        System.out.println("An error occurred");
    }
} //end of saveDate

/*This function is supposed to take the data from the save file made by the 
previous function and load its data into the board. As it is now, it does
nothing due to other problems in the code and we can't check if it works*/
void fromSave(String saveName) {
    String fileName = saveName;
    int row = 0; // Initialize the 'row' variable

    try {
        Scanner read = new Scanner(new File(fileName));
        read.useDelimiter(",");

        while (read.hasNextLine()) {
            String line = read.nextLine();
            for (int col = 0; col < line.length(); col++) {
                board[row][col] = line.charAt(col);
            }
            row++;
        }
        read.close();
    } catch (IOException e) {
        System.out.println("An error occurred");
    }
}//end of fromSave

} //end of CheckersGame
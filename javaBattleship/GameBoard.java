/* Blake Impecoven - CSCD211 - HW3

*/

public class GameBoard
{
   private char[][]gameboard;
   
   public GameBoard()
   {
      this.gameboard = new char[10][10];
      for(int rows = 0; rows < gameboard.length; rows++)
      {
         for(int cols = 0; cols < gameboard.length; cols++)
         {
            gameboard[rows][cols] = '~';
         }//end for(cols
      }//end for(rows
   }//end EVC
   
   public String toString()
   {
      String str = "";
      
      for(int rows = 0; rows < gameboard.length; rows++)
      {
         str += " ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ";
         str += "\n| ";
         for(int col = 0; col < gameboard[rows].length; col ++)
         {
            str += gameboard[rows][col] + " | ";
            if(col == 10)
               str += "\n";
         }//end for(col
         str += "\n";
      }//end for(rows
      return str;
   }//end toString
   
   public char[][] getGameBoard(){return this.gameboard;}
   
}//end class
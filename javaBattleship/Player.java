/* Blake Impecoven - CSCD211 - HW3

*/

import java.util.Scanner;
import java.util.Random;

public class Player
{
   protected String name;
   protected Ship[]ships;
   protected GameBoard gameboardBottom;
   protected GameBoard gameboardTop;
   
   public Player(final String name)
   {
      if(name == null)
         throw new RuntimeException("Preconditions not yet met!");
      this.name = name;
   }
   public Player(final String name, final Ship[]ships, final char[][]gameboardBottom, final char[][]gameboardTop)
   {
      this.name = name;
      this.ships = new Ship[5];  
      this.gameboardBottom = new GameBoard();
      this.gameboardTop = new GameBoard();
   }//end EVC
   
   //get methods//
   public String getName(){return this.name;}
   public Ship[] getShips(){return this.ships;}
   public GameBoard getGameboardBottom(){return this.gameboardBottom;}
   public GameBoard getGameboardTop(){return this.gameboardTop;}
   //end get methods//
   
   //Set methods//
   public void setShips(final Ship[]ships)
   {
      ships[0] = new AircraftCarrier(5, 0, false);
      ships[1] = new Battleship(4, 0, false);
      ships[2] = new Submarine(3, 0, false);
      ships[3] = new Destroyer(3, 0, false);
      ships[4] = new PatrolBoat(2, 0 , false);
   }
   public void setGameboardTop(final GameBoard gameboardBottom)
   {
      this.gameboardBottom = gameboardBottom;
   }
   public void setGameboardBottom(final GameBoard gameboardBottom)
   {
      this.gameboardTop = gameboardTop;
   }
   //End set methods//
   
   
   
   public String toString()
   {
      return " ";
   }//end toString

   public void placeShips(final Scanner kb)
   {
      Ship[]ships = new Ship[5];
      setShips(ships);
     
      gameboardTop = new GameBoard();
      setGameboardTop(gameboardTop);
      char[][]boardTop = gameboardTop.getGameBoard();
      gameboardBottom = new GameBoard();
      setGameboardBottom(gameboardBottom);
      char[][]board = gameboardBottom.getGameBoard();
      Player human = new Player(name, ships, board, boardTop);
      for(Ship s: ships)
      {
         Random rand = new Random();
         boolean placed = false;
         boolean okay = false;
         int row = 0;
         int col = 0;
   
         while(placed != true)
         {
            do{
               do{
                  try
                  {
                     System.out.print("Where would you like to place your " + s + "?");
                     String coordinates = kb.nextLine();
                     if(coordinates.length() < 2 || coordinates.length() > 3)
                        throw new BattleshipException("Cannot use coordinates.");
                     okay = true;
                     if(coordinates.charAt(0) == 'a' || coordinates.charAt(0) == 'A')
                        row = 0;
                     if(coordinates.charAt(0) == 'b' || coordinates.charAt(0) == 'B')
                        row = 1;
                     if(coordinates.charAt(0) == 'c' || coordinates.charAt(0) == 'C')
                        row = 2;
                     if(coordinates.charAt(0) == 'd' || coordinates.charAt(0) == 'D')
                        row = 3;
                     if(coordinates.charAt(0) == 'e' || coordinates.charAt(0) == 'E')
                        row = 4;
                     if(coordinates.charAt(0) == 'f' || coordinates.charAt(0) == 'F')
                        row = 5;
                     if(coordinates.charAt(0) == 'g' || coordinates.charAt(0) == 'G')
                        row = 6;
                     if(coordinates.charAt(0) == 'h' || coordinates.charAt(0) == 'H')
                        row = 7;
                     if(coordinates.charAt(0) == 'i' || coordinates.charAt(0) == 'I')
                        row = 8;
                     if(coordinates.charAt(0) == 'j' || coordinates.charAt(0) == 'J')
                        row = 9;
               
                     if(coordinates.charAt(1) == '1')
                        col = 0;
                     if(coordinates.charAt(1) == '2')
                        col = 1;
                     if(coordinates.charAt(1) == '3')
                        col = 2;
                     if(coordinates.charAt(1) == '4')
                        col = 3;
                     if(coordinates.charAt(1) == '5')
                        col = 4;
                     if(coordinates.charAt(1) == '6')
                        col = 5;
                     if(coordinates.charAt(1) == '7')
                        col = 6;
                     if(coordinates.charAt(1) == '8')
                        col = 7;
                     if(coordinates.charAt(1) == '9')
                        col = 8;
                     if(coordinates.length() == 3)
                        if(coordinates.charAt(1) == '1' && coordinates.charAt(2) == '0')
                           col = 9;
                  }//end try
                  catch(BattleshipException e)
                  {
                     System.out.println("Coordinates not on gameboard.");
                     okay = false;
                  }//end catch
               }while(!(okay));
            }while(board[row][col] != '~'); //pick random coordiantes
           
            int direction = rand.nextInt(4); //pick random direction
            boolean canPlace = true;
           
            if(direction == 0) //North
            {
               if(row - s.getSize() >= 0)
               {
                  for(int y = row; y < row - s.getSize(); y--)
                  {
                     if(board[y][col] != '~')
                        canPlace = false;
                  }      
                  if(canPlace == true)
                  {
                     String d = "north";
                     setShip(board, row, col, s, d);  
                     placed = true;
                  }      
               }
            }
           
            if(direction == 1) //South
            {
               if(row + s.getSize() <= 9)
               {
                  for(int y = row; y > row + s.getSize(); y++)
                  {
                     if(board[y][col] != '~')
                        canPlace = false;
                  }      
                  if(canPlace == true)
                  {
                     String d = "south";
                     setShip(board, row, col, s, d);  
                     placed = true;
                  }        
               }
            }
           
            if(direction == 2) //East
            {
               if(col + s.getSize() <= 9)
               {
                  for(int y = col; y < col + s.getSize(); y++)
                  {
                     if(board[row][y] != '~')
                        canPlace = false;
                  }      
                  if(canPlace == true)
                  {
                     String d = "east";
                     setShip(board, row, col, s, d);  
                     placed = true;
                  }        
               }
            }
           
            if(direction == 3) //West
            {
               if(col - s.getSize() >= 0)
               {
                  for(int y = col; y > col - s.getSize(); y--)
                  {
                     if(board[row][y] != '~')
                        canPlace = false;
                  }      
                  if(canPlace == true)
                  {
                     String d = "west";
                     setShip(board, row, col, s, d);  
                     placed = true;
                  }        
               }
            }  
         }//end while
      }//end for
   }//end placeShips(player
 
   public void placeShips()
   {
      Ship[]ships = new Ship[5];
      setShips(ships);
      gameboardBottom = new GameBoard();
      char[][]board = gameboardBottom.getGameBoard();
      char[][]boardTop = gameboardBottom.getGameBoard();
      Player Computer = new Player(getName(), getShips(), board, boardTop);
      for(Ship s: ships)
      {
         boolean placed = false;
         Random rand = new Random();
         int row = 0;
         int col = 0;
         while(placed != true)
         {
            do{
               row = rand.nextInt(10);
               col = rand.nextInt(10);
            }while(board[row][col] != '~'); //pick random coordiantes
           
            int direction = rand.nextInt(4); //pick random direction
            boolean canPlace = true;
           
            if(direction == 0) //North
            {
               if(row - s.getSize() >= 0)
               {
                  for(int y = row; y < row - s.getSize(); y--)
                  {
                     if(board[y][col] != '~')
                        canPlace = false;
                  }      
                  if(canPlace == true)
                  {
                     String d = "north";
                     setShip(board, row, col, s, d);  
                     placed = true;
                  }      
               }
            }
           
            if(direction == 1) //South
            {
               if(row + s.getSize() <= 9)
               {
                  for(int y = row; y > row + s.getSize(); y++)
                  {
                     if(board[y][col] != '~')
                        canPlace = false;
                  }      
                  if(canPlace == true)
                  {
                     String d = "south";
                     setShip(board, row, col, s, d);  
                     placed = true;
                  }        
               }
            }
           
            if(direction == 2) //East
            {
               if(col + s.getSize() <= 9)
               {
                  for(int y = col; y < col + s.getSize(); y++)
                  {
                     if(board[row][y] != '~')
                        canPlace = false;
                  }      
                  if(canPlace == true)
                  {
                     String d = "east";
                     setShip(board, row, col, s, d);  
                     placed = true;
                  }        
               }
            }
           
            if(direction == 3) //West
            {
               if(col - s.getSize() >= 0)
               {
                  for(int y = col; y > col - s.getSize(); y--)
                  {
                     if(board[row][y] != '~')
                        canPlace = false;
                  }      
                  if(canPlace == true)
                  {
                     String d = "west";
                     setShip(board, row, col, s, d);  
                     placed = true;
                  }        
               }
            }
         }//end while      
 
      } //end for
   }//end placeShips(computer
   
   public void setShip(final char[][]gameboard, final int row, final int col, final Ship s, final String direction)
   {
      //String name = s.getName();
      char marker = s.getName().charAt(0);
      gameboard[row][col] = marker;
      if(direction.equalsIgnoreCase("north"))
      {
         if(s.getName().equalsIgnoreCase("aircraft carrier"))
         {
            gameboard[row-1][col] = marker;
            gameboard[row-2][col] = marker;
            gameboard[row-3][col] = marker;
            gameboard[row-4][col] = marker;
         }//end aircraft carrier
         
         if(s.getName().equalsIgnoreCase("battleship"))
         {
            gameboard[row-1][col] = marker;
            gameboard[row-2][col] = marker;
            gameboard[row-3][col] = marker;
         }//end battleship
         
         if(s.getName().equalsIgnoreCase("destroyer"))
         {
            gameboard[row-1][col] = marker;
            gameboard[row-2][col] = marker;
         }//end destroyer
         
         if(s.getName().equalsIgnoreCase("submarine"))
         {
            gameboard[row-1][col] = marker;
            gameboard[row-2][col] = marker;
         }//end submarine
                 
         if(s.getName().equalsIgnoreCase("patrol boat"))
         {
            gameboard[row-1][col] = marker;
         }//end patrol boat        
      }//end if north  
     
     
     
     
     
      if(direction.equalsIgnoreCase("south"))
      {
         if(s.getName().equalsIgnoreCase("aircraft carrier"))
         {
            gameboard[row+1][col] = marker;
            gameboard[row+2][col] = marker;
            gameboard[row+3][col] = marker;
            gameboard[row+4][col] = marker;
         }//end aircraft carrier
         
         if(s.getName().equalsIgnoreCase("battleship"))
         {
            gameboard[row+1][col] = marker;
            gameboard[row+2][col] = marker;
            gameboard[row+3][col] = marker;
         }//end battleship
         
         if(s.getName().equalsIgnoreCase("destroyer"))
         {
            gameboard[row+1][col] = marker;
            gameboard[row+2][col] = marker;
         }//end destroyer
         
         if(s.getName().equalsIgnoreCase("submarine"))
         {
            gameboard[row+1][col] = marker;
            gameboard[row+2][col] = marker;
         }//end submarine
                 
         if(s.getName().equalsIgnoreCase("patrol boat"))
         {
            gameboard[row+1][col] = marker;
         }//end patrol boat
      }//end if south
     
     
     
     
     
      if(direction.equalsIgnoreCase("east"))
      {
         if(s.getName().equalsIgnoreCase("aircraft carrier"))
         {
            gameboard[row][col+1] = marker;
            gameboard[row][col+2] = marker;
            gameboard[row][col+3] = marker;
            gameboard[row][col+4] = marker;
         }//end aircraft carrier
         
         if(s.getName().equalsIgnoreCase("battleship"))
         {
            gameboard[row][col+1] = marker;
            gameboard[row][col+2] = marker;
            gameboard[row][col+3] = marker;
         }//end battleship
         
         if(s.getName().equalsIgnoreCase("destroyer"))
         {
            gameboard[row][col+1] = marker;
            gameboard[row][col+2] = marker;
         }//end destroyer
         
         if(s.getName().equalsIgnoreCase("submarine"))
         {
            gameboard[row][col+1] = marker;
            gameboard[row][col+2] = marker;
         }//end submarine
                 
         if(s.getName().equalsIgnoreCase("patrol boat"))
         {
            gameboard[row][col+1] = marker;
         }//end patrol boat
      }//end if east
     
     
     
     
     
      if(direction.equalsIgnoreCase("west"))
      {
         if(s.getName().equalsIgnoreCase("aircraft carrier"))
         {
            gameboard[row][col-1] = marker;
            gameboard[row][col-2] = marker;
            gameboard[row][col-3] = marker;
            gameboard[row][col-4] = marker;
         }//end aircraft carrier
         
         if(s.getName().equalsIgnoreCase("battleship"))
         {
            gameboard[row][col-1] = marker;
            gameboard[row][col-2] = marker;
            gameboard[row][col-3] = marker;
         }//end battleship
         
         if(s.getName().equalsIgnoreCase("destroyer"))
         {
            gameboard[row][col-1] = marker;
            gameboard[row][col-2] = marker;
         }//end destroyer
         
         if(s.getName().equalsIgnoreCase("submarine"))
         {
            gameboard[row][col-1] = marker;
            gameboard[row][col-2] = marker;
         }//end submarine
                 
         if(s.getName().equalsIgnoreCase("patrol boat"))
         {
            gameboard[row][col-1] = marker;
         }//end patrol boat
      }//end if west
   }//end setShip
}//end class
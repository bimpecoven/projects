/* Blake Impecoven - CSCD211 - HW3
comment lines 80 and 81 to hide computers board
*/

import java.util.*;

public class HW3Methods
{
   public static void rulesAndIntro()
   {
      System.out.println("Welcome to BattleShip!");
      System.out.println("Each Player will have 5 ships, you will need to place them wisely.");
      System.out.println("Every turn each player is allowed an attack, hits and misses will be marked");
      System.out.println("Certain ships can take more hits than others, when the maximum amount of");
      System.out.println("damage is reached your ship will be sunk. The player to sink the opposing");
      System.out.println("players ships first will be the winner.");
      System.out.println("Hits will be marked with a 'X' and misses will be marked by an '*'");
      System.out.println("Good luck!");
      System.out.println(" ");
   }//end menu
   
   public static String readPlayersName(final Scanner kb)
   {
      if(kb == null)
         throw new RuntimeException("Preconditions not yet met!");
      System.out.print("Please enter your name: ");
      String name = kb.nextLine();
      while(name == "" || name.isEmpty())
      {
         System.out.println("That name is empty!");
         System.out.print("Please enter your name: ");
         name = kb.nextLine();   
      }//end while 
      return name;
   }//end readPlayersName
   
   public static boolean goAgain(final Scanner kb)
   {
      if(kb == null)
         throw new RuntimeException("Preconditions not yet met!");
      System.out.print("Would you like to play again?(yes/no): ");
      String choice = kb.nextLine();
      while(!(choice.equalsIgnoreCase("yes") || choice.equalsIgnoreCase("no")))
      {
         System.out.println("Invalid choice!");
         System.out.print("Would you like to play again?(yes/no): ");
         choice = kb.nextLine();
      }
      
      if(choice.equalsIgnoreCase("yes"))
         return true;
      
      if(choice.equalsIgnoreCase("no"))
         return false;
         
      return false;    
      
   }//end goAgain
   
   public static void play(final Player computer, final Player human)
   {
      if(computer == null || human == null)
         throw new RuntimeException("Preconditions not yet met!");
      int[] attackCoordinates = new int[2];
      Ship[]hShips = new Ship[5];
      human.setShips(hShips);
      Ship[]cShips = new Ship[5];
      computer.setShips(cShips);

      Scanner kb = new Scanner(System.in);
      boolean continuePlaying = true;
      int hCtr = 0;
      int cCtr = 0;
      do{
         //display user game board//
         System.out.print(human.getGameboardTop());
         System.out.println(" ");
         System.out.print(human.getGameboardBottom());
         
         System.out.println("CHEAT - Computer Ships");                     //comment to hide cheat to see Computer ships
         System.out.print(computer.getGameboardBottom());                  //comment to hide cheat to see Computer ships
         
         attackCoordinates = HW3Methods.readAttackCoordinates(kb);
         HW3Methods.userAttack(computer, human, attackCoordinates, cShips);
         
         System.out.println(" ");
         attackCoordinates = HW3Methods.randAttackCoordinates();
         HW3Methods.computerAttack(human, attackCoordinates);
         
         continuePlaying = HW3Methods.checkStatus(computer, human);

      }while(continuePlaying == true);     
   }//end play
   
   public static boolean checkStatus(final Player computer, final Player human)
   {
      if(computer == null || human == null)
         throw new RuntimeException("Preconditions not yet met!");
         
      GameBoard uBoard = human.getGameboardBottom();
      GameBoard cBoard = computer.getGameboardBottom();
      int hCtr = 0;
      int cCtr = 0;
      
      for(int row = 0; row < uBoard.getGameBoard().length; row++)
      {
         for(int col = 0; col < uBoard.getGameBoard()[row].length; col++)
         {  
            if(uBoard.getGameBoard()[row][col] == 'X')
               hCtr++;
            if(cBoard.getGameBoard()[row][col] == 'X')
               cCtr++;  
         }//end for(col
      }//end for(row 
      if(hCtr == 17)
      {
         System.out.println("You Lose!");
         return false;
      } 
      if(cCtr == 17)
      {
         System.out.println("You Win!");
         return false;
      }   
      return true;
   }//end checkStatus
   
   public static int[] readAttackCoordinates(final Scanner kb)
   {
      if(kb == null)
         throw new RuntimeException("Preconditions not yet met!");
      String coordinate;
      int row = 0;
      int col = 0;
      int[]attackArray = new int[2];
      System.out.print("Enter coordinates for your attack: ");
      coordinate = kb.nextLine();
      
      if(coordinate.charAt(0) == 'a' || coordinate.charAt(0) == 'A')
         row = 0;
      if(coordinate.charAt(0) == 'b' || coordinate.charAt(0) == 'B')
         row = 1;
      if(coordinate.charAt(0) == 'c' || coordinate.charAt(0) == 'C')
         row = 2;
      if(coordinate.charAt(0) == 'd' || coordinate.charAt(0) == 'D')
         row = 3;
      if(coordinate.charAt(0) == 'e' || coordinate.charAt(0) == 'E')
         row = 4;
      if(coordinate.charAt(0) == 'f' || coordinate.charAt(0) == 'F')
         row = 5; 
      if(coordinate.charAt(0) == 'g' || coordinate.charAt(0) == 'G')
         row = 6;
      if(coordinate.charAt(0) == 'h' || coordinate.charAt(0) == 'H')
         row = 7;
      if(coordinate.charAt(0) == 'i' || coordinate.charAt(0) == 'I')
         row = 8;
      if(coordinate.charAt(0) == 'j' || coordinate.charAt(0) == 'J')
         row = 9;
        

      if(coordinate.charAt(1) == '1')
         col = 0;
      if(coordinate.charAt(1) == '2')
         col = 1;
      if(coordinate.charAt(1) == '3')
         col = 2;
      if(coordinate.charAt(1) == '4')
         col = 3;
      if(coordinate.charAt(1) == '5')
         col = 4;
      if(coordinate.charAt(1) == '6')
         col = 5; 
      if(coordinate.charAt(1) == '7')
         col = 6;
      if(coordinate.charAt(1) == '8')
         col = 7;
      if(coordinate.charAt(1) == '9')
         col = 8;
      if(coordinate.length() == 3)   
         if(coordinate.charAt(1) == '1')
            if(coordinate.charAt(2) == '0')
               col = 9;
     
         
      attackArray[0] = row;
      attackArray[1] = col;
      return attackArray;   
   }//end readAttackCoordinates
   
   public static int[] randAttackCoordinates()
   {
      int row = 0;
      int col = 0;
      int[]attackArray = new int[2];
      Random rand = new Random();
      row = rand.nextInt(10);
      col = rand.nextInt(10);
      attackArray[0] = row;
      attackArray[1] = col;
      return attackArray;
   }//end randAttackCoordinates
   
   public static void userAttack(final Player computer, final Player human, final int[] attack, final Ship[]cShips)
   {
      if(computer == null || human == null)
         throw new RuntimeException("Preconditions not yet met!");
      if(attack.length < 1 || cShips.length < 1)
         throw new RuntimeException("Preconditions not yet met!");
      GameBoard uBoard = human.getGameboardTop();
      GameBoard cBoard = computer.getGameboardBottom();
      
      if(cBoard.getGameBoard()[attack[0]][attack[1]] == '~')
      {
         uBoard.getGameBoard()[attack[0]][attack[1]] = '*';     
         cBoard.getGameBoard()[attack[0]][attack[1]] = '*';
      }//end if(miss
      
      else
      {
         if(cBoard.getGameBoard()[attack[0]][attack[1]] == 'A')
            cShips[0] = new AircraftCarrier(5, cShips[0].getHits() + 1, cShips[0].getStatus());
         if(cBoard.getGameBoard()[attack[0]][attack[1]] == 'B')
            cShips[1] = new AircraftCarrier(5, cShips[1].getHits() + 1, cShips[0].getStatus());
         if(cBoard.getGameBoard()[attack[0]][attack[1]] == 'S')
            cShips[2] = new AircraftCarrier(5, cShips[2].getHits() + 1, cShips[0].getStatus());
         if(cBoard.getGameBoard()[attack[0]][attack[1]] == 'D')
            cShips[3] = new AircraftCarrier(5, cShips[3].getHits() + 1, cShips[0].getStatus());
         if(cBoard.getGameBoard()[attack[0]][attack[1]] == 'P')
            cShips[4] = new AircraftCarrier(5, cShips[4].getHits() + 1, cShips[0].getStatus());
                        
         uBoard.getGameBoard()[attack[0]][attack[1]] = 'X';     
         cBoard.getGameBoard()[attack[0]][attack[1]] = 'X';
      }//end hit      
   }//end userAttack
   
   public static void computerAttack(final Player human, final int[]attack)
   {
      if(human == null)
         throw new RuntimeException("Preconditions not yet met!");
      if(attack.length < 1)
         throw new RuntimeException("Preconditions not yet met!");   
      GameBoard uBoard = human.getGameboardBottom();
      

      if(uBoard.getGameBoard()[attack[0]][attack[1]] == '~')
         uBoard.getGameBoard()[attack[0]][attack[1]] = '*';
         
      if(uBoard.getGameBoard()[attack[0]][attack[1]] == '*')
         uBoard.getGameBoard()[attack[0]][attack[1]] = '*';   
         
      else
         uBoard.getGameBoard()[attack[0]][attack[1]] = 'X';
  
   }//end computerAttack
 
}//end class
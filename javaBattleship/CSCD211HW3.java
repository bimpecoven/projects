import java.util.Scanner;

public class CSCD211HW3
{
    public static void main(String[] args)
    {
      Scanner kb = new Scanner(System.in);
	   Player computer = null, human = null;
      
      HW3Methods.rulesAndIntro();
	
   	do
   	{
   	    computer = new Player("Computer");
   	    human = new Player(HW3Methods.readPlayersName(kb));
   	    
   	    computer.placeShips();
   	    human.placeShips(kb);
   	    
   	    HW3Methods.play(computer, human);
          
   	}while(HW3Methods.goAgain(kb));

    }// end main
  
}// end class
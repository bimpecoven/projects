/* Blake Impecoven - CSCD211 - HW3

*/

public class Destroyer extends Ship
{
   private String name = "Destroyer";
   
   public Destroyer(final int size, final int hits, final boolean status)
   {
      super(3, hits, status);
   }//end EVC
   
   public void attack()
   {
      this.hits += 1;   
   }//end attack
   
   public void setStatus(final boolean status)
   {
      if(hits >= size)
         this.status = false;
         
      else
         this.status = true;      
   }//end setStatus
   
   public boolean getStatus(){return this.status;}
   public String getName(){return this.name;}
   
   public String toString()
   {
      return "Destroyer";
   }
}//end class
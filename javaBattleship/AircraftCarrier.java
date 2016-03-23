/* Blake Impecoven - CSCD211 - HW3

*/

public class AircraftCarrier extends Ship
{
   private String name = "Aircraft Carrier";
   public AircraftCarrier(final int size, final int hits, final boolean status)
   {
      super(size, hits, status); 
   }//end EVC
   
   public String getName(){return this.name;}
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
   
   public String toString()
   {
      return "Aircraft Carrier";
   }
}//end class
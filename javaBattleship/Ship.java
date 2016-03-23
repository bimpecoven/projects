/* Blake Impecoven - CSCD211 - HW3

*/

public abstract class Ship
{
   protected int size;
   protected int hits;
   protected boolean status;
   
   public Ship(final int size, final int hits, final boolean status)
   {
      if(size < 2 || size > 5)
         throw new RuntimeException("Preconditions not yet met!");
      this.size = size;
      this.hits = hits;
      this.status = status;
   }//end EVC
   
   public abstract void attack();
   
   public int getSize(){return this.size;}
   public abstract String getName();
   public abstract boolean getStatus();
   public int getHits(){return this.hits;}
   
   //Set methods//
   public void setSize(final int size)
   {
      if(size < 2 || size > 5)
         throw new RuntimeException("Preconditions not yet met!");
      this.size = size;
   }
   public void setHits(final int hits)
   {
      this.hits = hits;
   }
   public void setStatus(final boolean status)
   {
      this.status = status;
   }
   //End set methods//
   
   
   
   public String toString()
   {
      String str = "";
      return str;
   }//end toString
}//end class
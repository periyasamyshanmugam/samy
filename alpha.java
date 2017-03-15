import java.util.*;
 
class alpha
{
    public static void main(String[] args)
    {
        char ch;
        Scanner s=new Scanner(System.in);
        ch=s.next().charAt(0);
        if( (ch>='A' && ch<='Z') || ch>='a' && ch<='z')
        {
            System.out.println("Entered charecter is an Alphabet");
        }       
        else
        {
            System.out.println("Entered Charecter is not an Alphabet");
        }
         
    }
}
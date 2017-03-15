import java.util.*;
 
class greater
{
    public static void main(String[] args)  throws java.lang.Exception
    {
        int a,b,c;
        Scanner s=new Scanner(System.in);
        a = s.nextInt();
        b = s.nextInt();
        c = s.nextInt();
        if(a>b&&a>c)
        {
            System.out.print("a is greater");
        }       
        else if(b>a&&b>c)
        {
            System.out.println("b is greater");
        }
        else
        {
            System.out.println("c is greater");
        }
    }
}
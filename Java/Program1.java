import java.util.Scanner;

public class CS490Project1
{
    public static void main(String[] args)
    {
        var consoleReader = new Scanner(System.in);
        
        System.out.print("How many message threads should be started?  (Enter a number): ");
        var nThreads = consoleReader.nextInt();

        System.out.println("Will run " + nThreads + " threads.");

        var msgWriter = new MessageWriter("" + 1);
        var thread = new Thread(msgWriter);
        thread.start();
/*
        try
        {
            thread.join();
        }
        catch (Exception exc)
        {
            System.out.println(exc);
        }
*/
        System.out.println("Main Program Ended");
        // System.exit(0);
    }
}

// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.*;


class Main {
    public static void main(String[] args) {
    Scanner sc= new Scanner(System.in);
    String play = "y";
    while(play == "y")
        {
        System.out.println("Rock Paper Scissors. Enter your choice: ");
        //String test = sc.nextInt();
        String choice = sc.nextLine();
        int choiceNum = 0;
        String CPU = "";
        double randomNumber = Math.random()*2;
        int rNum = (int) Math.round(randomNumber);
        //Convert choice into int
        if(choice.equals("rock") || choice.equals("Rock"))
            {
                choiceNum = 0;
            }
        
        if(choice.equals("paper") || choice.equals("Paper"))
            {
                choiceNum = 1;
            }
        
        if(choice.equals("scissors") || choice.equals("Scissors"))
            {
                choiceNum = 2;
            }
        
        //Convert rNum into string
        if(rNum == 0)
            {
                CPU = "Rock";
            }
            
        if(rNum == 1)
            {
                CPU = "Paper";
            }
        
        if(rNum == 2)
            {
                CPU = "Scissors";
            }
        
        System.out.println("\n" +choice+ " vs " +CPU+ "\n");
        if(rNum == choiceNum)
            {
                System.out.println("It's a Tie\n");
            }
        if((choiceNum == 0 && rNum == 2) || (choiceNum == 1 && rNum == 0) || (choiceNum == 2 && rNum == 1))
            {
                System.out.println("You Win\n");
            }
        if((choiceNum == 0 && rNum == 1) || (choiceNum == 1 && rNum == 2) || (choiceNum == 2 && rNum == 0))
            {
                System.out.println("You Lose\n");
            }
        System.out.println("Do you want to play again? (y or n)\n");
        play = sc.nextLine();
        if(play == "y")
            {
            System.out.println("Let's play again\n");
            }
        }
        System.out.println(play);
        System.out.println("Goodbye\n");
        new java.util.Scanner(System.in).nextLine();
    }
}
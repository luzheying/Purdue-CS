import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * This is your Main program. This File will be run all operations, based on the input different function will be called.
 *
 * Complete the given and add necessary functions as per your requirement.
 */

public class Main {
    // Part 1 : Find the connected components and the bridge
    public static void Part1(Scanner in, PrintWriter out){
        //use in and out for file input output

    }

    // Part 2 :  Find a ticket using Dijkstra
    public static void Part2(Scanner in, PrintWriter out){
        //use in and out for file input output

    }

    // Part 3 :Try to do a tour of all cities
    public static void Part3(Scanner in, PrintWriter out){
        //use in and out for file input output

    }

    public static void main(String[] args) {
        if(args.length!=2){
            System.out.println("ERROR: Not enough Parameters");
            System.exit(0);
        }
        Scanner in=null;
        PrintWriter out=null;
        try {
            in = new Scanner(new File(args[0]));
            out= new PrintWriter(new File(args[1]));
        }
        catch (Exception e){
            e.printStackTrace();
            System.exit(0);
        }

        int PartNo=in.nextInt();

        if(PartNo==1){


        }else if(PartNo==2){


        }else if(PartNo==3){


        }else{
            System.out.println("Invalid Input");
            System.exit(0);
        }

        in.close();
        out.close();
    }
}
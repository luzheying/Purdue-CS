import java.util.Scanner;

/**
 *Comments
 */

public class MathTools {
   
    public static void main(String[] args) {
        /*Here are prompts and outputs for this lab. Build your program around them. */
        Scanner s= new Scanner(System.in);
        boolean ret = false;
        do {
            System.out.println("#######################################");
            System.out.println("1 - Absolute Value");
            System.out.println("2 - Power");
            System.out.println("3 - Scientific Notation");
            System.out.println("4 - isPrime");
            System.out.print("Select a number from the menu choices: ");
            int choice = s.nextInt();
            System.out.println("#######################################");
            if (choice == 1) {
                System.out.println("***Absolute Value***");
                System.out.print("Enter the number: ");
                float number = s.nextFloat();
               // System.out.println("");
                if (number < 0) {
                    number = -number;
                }
                System.out.println("Result:" + " " + number);
            } else if (choice == 2) {
                System.out.println("***Power***");
                System.out.print("Enter the base: ");
                float base = s.nextFloat();
                //System.out.println("");
                System.out.print("Enter the exponent: ");
                int ex = s.nextInt();
                //System.out.println("");
                float answer = 1;
                if ( ex == 0) {
                    answer = 1;
                }
                else if (ex > 0){
                    for (int i = 0; i < ex; i++) {
                        answer = answer * base;
                    }
                }
                else {
                    ex = -ex;
                    for (int i = 0; i < ex; i++) {
                        answer = answer * base;
                    }
                    answer = ((float)1)/answer;
                }
                System.out.println("Result:" + " " + answer);
            } else if (choice == 3) {
                System.out.print("Enter the number: ");
                double num = s.nextDouble();
                int count = 0;
                //System.out.println("");
                if ( num > 0) {
                    if ( num < 1) {
                        while(num<1) {
                            num = num * 10;
                            count++;
                        }
                    }
                    while (num >= 10) {
                        num = num / 10;
                        count++;}
                    num = ((int) (num*1000000))/1000000.0;
                    System.out.println("Result: " + num + " x 10 ^ " + count);
                }
                else {
                    num = -num;
                    if ( num < 1) {
                        while(num<1) {
                            num = num * 10;
                            count++;
                        }
                    }
                    while (num >= 10) {
                        num = num / 10;
                        count++;}
                    num = ((int) (num*1000000))/1000000.0;
                    System.out.println("Result: " + num + " x 10 ^ " + count);
                }
            } else if (choice == 4) {
                System.out.print("Enter the integer: ");
                int n = s.nextInt();
               // System.out.println("");
                int check = 0;
                if (n == 2) {
                    check = 1;
                    System.out.println(n +" is Prime");
                }else if (n == 3) {
                    check = 1;
                    System.out.println(n +" is Prime");
                }else if (n == 5) {
                    check = 1;
                    System.out.println(n +" is Prime");
                }else if (n == 7) {
                    check = 1;
                    System.out.println(n +" is Prime");
                }
                 else if (n%2 == 0) {
                    System.out.println(n+" is not Prime");
                    check = 1;
                }else {
                    for ( int i = 3; i < Math.sqrt(n); i=i+2) {
                        if(n%i == 0) {
                            System.out.println(n +" is not Prime");
                            check = 1;
                            break;
                        }
                    }
                }
                if ( check == 0) {
                    System.out.println(n +" is Prime");
                }
            } else {
                System.out.println("Invalid option.");
            }
            System.out.print("Return to the menu? (yes/no): ");
            String ans = s.next();
            if (ans.equalsIgnoreCase("yes")) {
                System.out.println("");
                ret = true;
            }
            else{
                System.out.println("");
                System.out.println("Exiting MathToolsClient...");
                ret = false;
            }
        }while (ret);
    }
}

import java.util.Scanner;

public class CollegeFeeCalculator {
    public static void main(String[] args) {
        int housingExpense = 0;
        int tuitionFee = 0;
        Scanner s = new Scanner(System.in);
        System.out.println("Welcome to CollegeFeeCalculator!");
        System.out.println("Please enter your name");
        String userName = s.nextLine();
        System.out.println("Please enter the no. of credit hours");
        int creditHours = s.nextInt();
        if (creditHours <1 || creditHours>21) {
            return;
        }
        System.out.println("Please select the appropriate residency\n1. In-state\n2. Out-of-state\n3. International");
        int residencyInput  = s.nextInt();
        if (residencyInput <1 || residencyInput>3) {
            return;
        }
        String residencyString = "";
        if ( 9 <= creditHours && creditHours <= 21) {
            switch (residencyInput) {
                case 1:
                    residencyString = "In-state";
                    tuitionFee = 4996;
                    break;
                case 2:
                    residencyString = "Out-of-state";
                    tuitionFee = 14397;
                    break;
                case 3:
                    residencyString = "International";
                    tuitionFee = 15397;
                    break;

                default:
                    return;
            }
        } else {
            switch (residencyInput) {
                case 1:
                    residencyString = "In-state";
                    tuitionFee = 350*creditHours;
                    break;
                case 2:
                    residencyString = "Out-of-state";
                    tuitionFee = 950*creditHours;

                    break;
                case 3:
                    residencyString = "International";
                    tuitionFee = 1020*creditHours;

                    break;

                default:
                    return;
            }
        }
        System.out.println("Please select your housing\n1. ON-Campus\n2. OFF-Campus");
        int housingInput  = s.nextInt();
        if ( housingInput < 1 || housingInput > 2) {
            return;
        }
        String housingString = "";
        String mealString = "";
        if ( housingInput == 1) {
            housingString = "ON-Campus";
            System.out.println("Please select the residence hall\n1. Earhart\n2. Hillenbrand\n3. Owen\n4. Windsor");
            int dorm = s.nextInt();
            if ( dorm <1||dorm>4) {
                return;
            }
            if ( dorm == 1) {
                housingExpense = 4745;
            }else if (dorm == 2) {
                housingExpense = 4150;
            }else if(dorm == 3) {
                housingExpense = 5307;
            } else {
                housingExpense = 4130;
            }
        } else {
            housingString = "OFF-Campus";
            System.out.println("Please input your monthly rent:");
            int rent = s.nextInt();
            if ( rent <= 0) {
                return;
            }
            housingExpense = rent*5;
        }
        System.out.println("Are you purchasing a meal plan?:\n1. Yes\n2. No");
        int mealInput = s.nextInt();
        if ( mealInput <1 || mealInput>2) {
            return;
        }
        if ( mealInput == 1) {
            mealString = "Yes";
            housingExpense+=1500;
        }else {
            mealString = "No";
        }

        int totalFee = tuitionFee + housingExpense;
        System.out.println("\nName: " + userName + "\nCredit Hours: " + creditHours +
                "\nResidency: " + residencyString + "\nHousing: " + housingString +
                "\nMeal Plan: " + mealString + "\nHousing Expenses: " + housingExpense +
                "\nTuition Fee: " + tuitionFee + "\nTotal Sem. Fee: " + totalFee);

    }
}

import java.io.*;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

/**
 *
 */
public class DataInput {
    public static Star[] stars;
    public void read(String filename){
        try {
            BufferedReader bfr = new BufferedReader(new FileReader(new File(filename)));
            ArrayList<Star> stars = new ArrayList<Star>();

            bfr.readLine();
            while(true) {
                String s = bfr.readLine();
                if (s==null){
                    break;
                }
                stars.add(parse(s));
            }
            this.stars = stars.toArray(new Star[1]);
            bfr.close();
        }catch (FileNotFoundException e) {
            System.out.println("File not found!");
        }
        catch (IOException e) {
            System.out.println("IO Exception");
        }
    }

    public Star parse(String input){
        String [] initial = input.split(",");
        boolean planets = false;
        if (initial[3].equals("Yes")){
            planets = true;
        }
        return new Star(initial[0],Double.parseDouble(initial[1]),Double.parseDouble(initial[2]),planets);
    }

    public void printInfo(StellarGrouping sg, Month month){
        //TODO: Print the requested information
        System.out.printf("Grouping name: %s\n",sg.getName());
        System.out.printf("The brightest star in this grouping is %s.\n",sg.brightestStar().getName());
        System.out.printf("%s is %f trillion miles from earth.\n",sg.brightestStar().getName(),sg.distanceFromEarth(sg.brightestStar()));
        System.out.printf("The furthest star from earth in this group is %f trillion miles from earth.\n", sg.furthestStar());
        String output;
        if (sg.isVisible(month)) {
            output = "Yes";
        }
        else {
            output = "No";
        }
        System.out.printf("Currenty visible to the naked eye: %s\n",output);
        System.out.printf("Planets orbiting one or more stars in this group: %s\n",sg.planetsOrbiting());
        //Tip: The numbers printed will only be tested for up to the first three decimal places

    }

    public static void main(String[] args) {
        //TODO: Parse command line arguments (the first should be the CSV name, the second should be the month)
        //Tip: You can use <Enum_Name>.valueOf(<String>) to get an enum constant of the same name as the String (case sensitive)
        String file = args[0];
        Month month = Month.valueOf(args[1]);
        File f = new File(file);

        try {
            Star[] stars = new Star[10];
            int count = 0;
            BufferedReader bfr = new BufferedReader(new InputStreamReader(new FileInputStream(f)));
            bfr.readLine();
            String input;
            while((input = bfr.readLine())!= null) {
               // input = bfr.readLine();
                String[] values = input.split(",");
               // System.out.println(values[0]);
                boolean check;
                if (values[3].equals("Unknown")) {
                    check = false;
                }
                else {
                    check = true;
                }
                Star s = new Star(values[0],Double.parseDouble(values[1]),Double.parseDouble(values[2]),check) {};
                stars[count] = s;
                count++;
            }
            bfr.close();
            StellarGrouping stella = new SouthernSummerConstellation("Canis Major",stars);
            DataInput d = new DataInput();
            d.printInfo(stella,month);
        }
        catch (FileNotFoundException e) {
            System.out.println("file not found");
        }
        catch (IOException e) {
        }

        //TODO: Create an instance of DataInput and pass the filename to .read

        //TODO: Create a StellarGrouping instance and print the info for that grouping and the month given above

    }

}

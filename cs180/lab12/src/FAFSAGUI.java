import javax.swing.*;

public class FAFSAGUI {
    public static void main(String[] args) {
        boolean con = false;
        do {
            JOptionPane.showMessageDialog(null, "Welcome to the FAFSA!", "Welcome", JOptionPane.INFORMATION_MESSAGE);
            int res1 = JOptionPane.showConfirmDialog(null, "Have you been accepted into a degree or certificate program?",
                    "Program Acceptance", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);
            int res2 = JOptionPane.showConfirmDialog(null, "Are you registered for the selective service?",
                    "Selective Service", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);
            int res3 = JOptionPane.showConfirmDialog(null, "Do you have a social security number?",
                    "Social Security Number", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);
            int res6 = JOptionPane.showConfirmDialog(null, "Do you have valid residency status?",
                    "Residency Status", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);
            boolean keepGoing;
            String ageIn;
            do {
                keepGoing = false;
                ageIn = JOptionPane.showInputDialog(null, "How old are you?", "Age", JOptionPane.QUESTION_MESSAGE);
                if (Integer.parseInt(ageIn) < 0) {
                    JOptionPane.showMessageDialog(null, "Age cannot be a negative number.", "Error: Age",
                            JOptionPane.ERROR_MESSAGE);
                    keepGoing = true;
                }
            } while (keepGoing);

            String hoursIn;
            do {
                keepGoing = false;
                hoursIn = JOptionPane.showInputDialog(null, "How many credit hours do you plan on taking?", "Credit Hours", JOptionPane.QUESTION_MESSAGE);
                if (Integer.parseInt(hoursIn) < 1 || Integer.parseInt(hoursIn) > 24) {
                    JOptionPane.showMessageDialog(null, "Credit hours must be between 1 and 24.", "Error: Credit Hours",
                            JOptionPane.ERROR_MESSAGE);
                    keepGoing = true;
                }
            } while (keepGoing);

            String incomeS;
            do {
                keepGoing = false;
                incomeS = JOptionPane.showInputDialog(null, "What is your yearly income?", "Student Income", JOptionPane.QUESTION_MESSAGE);
                if (Integer.parseInt(incomeS) < 0) {
                    JOptionPane.showMessageDialog(null, "Income cannot be a negative number.", "Error: Student Income",
                            JOptionPane.ERROR_MESSAGE);
                    keepGoing = true;
                }
            } while (keepGoing);

            String incomeP;
            do {
                keepGoing = false;
                incomeP = JOptionPane.showInputDialog(null, "What is your parent's total yearly income?", "Parent Income", JOptionPane.QUESTION_MESSAGE);
                if (Integer.parseInt(incomeP) < 0) {
                    JOptionPane.showMessageDialog(null, "Income cannot be a negative number.", "Error: Parent Income",
                            JOptionPane.ERROR_MESSAGE);
                    keepGoing = true;
                }
            } while (keepGoing);

            int res4 = JOptionPane.showConfirmDialog(null, "Are you a dependent?",
                    "Residency Status", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);
            String[] selevtionValues = {"Freshman", "Sophomore", "Junior", "Senior", "Graduate"};
            String res5 = (String) JOptionPane.showInputDialog(null, "What is your current class standing?",
                    "Class Standing", JOptionPane.PLAIN_MESSAGE, null, selevtionValues, JOptionPane.PLAIN_MESSAGE);
            String classStanding;
            if (res5.equals(selevtionValues[4])) {
                classStanding = "Graduate";
            } else {
                classStanding = "Undergraduate";
            }
            boolean isAcceptedStudent, isSSregistered, hasSSN, hasValidResidency, isDependent;
            int age, creditHours;
            double studentIncome, parentIncome;
            age = Integer.parseInt(ageIn);
            creditHours = Integer.parseInt(hoursIn);
            studentIncome = Double.parseDouble(incomeS);
            parentIncome = Double.parseDouble(incomeP);

            if (res1 == JOptionPane.YES_OPTION) {
                isAcceptedStudent = true;
            } else {
                isAcceptedStudent = false;
            }

            if (res2 == JOptionPane.YES_OPTION) {
                isSSregistered = true;
            } else {
                isSSregistered = false;
            }

            if (res6 == JOptionPane.YES_OPTION) {
                hasValidResidency = true;
            } else {
                hasValidResidency = false;
            }
            if (res3 == JOptionPane.YES_OPTION) {
                hasSSN = true;
            } else {
                hasSSN = false;
            }

            if (res4 == JOptionPane.YES_OPTION) {
                isDependent = true;
            } else {
                isDependent = false;
            }

            FAFSA fafsa = new FAFSA(isAcceptedStudent, isSSregistered, hasSSN, hasValidResidency, isDependent, age, creditHours,
                    studentIncome, parentIncome, classStanding);
            double loan = fafsa.calcStaffordLoan();
            double workStudy = fafsa.calcWorkStudy();
            double grant = fafsa.calcFederalGrant();
            double awards = fafsa.calcFederalAidAmount();

            if (awards == 0) {
                JOptionPane.showMessageDialog(null, "Sorry, you do not qualify for Financial Aid", "Ineligible",
                        JOptionPane.INFORMATION_MESSAGE);
            }
            else {
                JOptionPane.showMessageDialog(null, "loan: " + loan + "\n" + "workStudy: " + workStudy + "\n"+
                        "grant: " + grant + "\n"+"total: " + awards + "\n", "FAFSA Result", JOptionPane.INFORMATION_MESSAGE);
            }
            int conti = JOptionPane.showConfirmDialog(null,"Would you like to complete another Application?",
                    "Continue",JOptionPane.YES_NO_OPTION);
            if (conti == JOptionPane.YES_OPTION) {
                con = true;
            }else {
                con = false;
            }
        }while (con);
    }
}


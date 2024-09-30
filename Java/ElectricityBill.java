/* Program to calculate the Electricity bill bi-month period for different types of consumers
 */

import java.util.Scanner;
class Bill {
    //Declaring the instances of the class
    String customerName;
    float totalAmount;
    int units;
    String customerType;
    int services;
    int demandCharge;
    String supplyType;
    String instituteType;

    //Creating a method to get info about the user
    void getInfo() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the Customer name");
        customerName = scan.nextLine();
        System.out.println("Enter the number of units used :");
        units = scan.nextInt();
        System.out.println("Enter Customer's type : domestic, public, industry or institution?");
        customerType = scan.next();
        customerType = customerType.toLowerCase();  // converting the input to lowercase to avoid errors
        switch (customerType) {
            case "domestic":
                System.out.println("Enter the number of services used : ");
                services = scan.nextInt();
                totalAmount = performDomesticCalculation(services,units);
                break;
            case "industry":
                System.out.println("Enter the demand charge in kva:");
                demandCharge = scan.nextInt();
                totalAmount = performIndustryCalculation(demandCharge,units);
                break;
            case "institution":
                System.out.println("Enter the demand charge in kW:");
                demandCharge = scan.nextInt();
                System.out.println("Enter the type of tension of supply : high or low ?");
                supplyType = scan.next();
                supplyType = supplyType.toLowerCase();
                if (supplyType.equals("high") || supplyType.equals("low"))
                {
                    System.out.println("Enter the type of Institution : private or government ?");
                    instituteType = scan.next();
                    instituteType = instituteType.toLowerCase(); // converting the input to lowercase to avoid errors
                    totalAmount = performInstitutionCalculation(supplyType,instituteType,demandCharge,units);
                    break;
                }
                else{
                    System.out.println("Please enter either high or low");
                    System.exit(0);  // converting the input to lowercase to avoid errors
                }

            default:
                System.out.println("Please enter a valid option");
                System.exit(0); // converting the input to lowercase to avoid errors

        }
        scan.close();
    }
    //Creating method to display the bill details
    void displayBill() {
        System.out.println("Customer name : " + customerName);
        System.out.println("Customer type : " + customerType);
        switch (customerType){
            case "domestic":
                System.out.println("Number of Services :" + services);
                break;
            case "industry":
                System.out.println("Demand Charge :" + demandCharge + " kva");
                break;
            case "institution":
                System.out.println("Demand Charge :" + demandCharge + " kW");
                System.out.println("Supply type :" + supplyType);
                System.out.println("Institute type :" + instituteType);
                break;
        }
        System.out.println("Units spent :" + units);
        System.out.println("Bill amount = Rs." + totalAmount);
    }
    //Creating a method to perform bill calculation for domestic customers
    float performDomesticCalculation(int services, int units) {
        float amount = 0;
        System.out.println("Hi");
        if (units <= 100) {
            return 0;
        } else if (units > 100 && units <= 200) {
            amount += (units-100) * 1.5 ;
            amount += services * 20; // Adding fixed charges according to the number of services used
            return amount;
        } else if (units > 200 && units <= 500) {
            amount += 100 * 2.0 ;
            amount += (units-200) * 3.0;
            amount += services * 30 ; // Adding fixed charges according to the number of services used
        } else if (units > 500) {
            amount += 100 * 3.5 ;
            amount += 300 * 4.6;
            amount += (units-500) * 6.6;
            amount += services * 50; // Adding fixed charges according to the number of services used
        }
        return amount;

    }
    //Creating a method to perform bill calculation for industry customers
    float performIndustryCalculation(int demandCharge, int units) {
        float amount = 0;
        amount += demandCharge * 350 * 2; //Adding cost of demand charge. Multiplying by 2 as the rate is given per month
        amount += units * 6.35;
        return amount;
    }
    //Creating a method to perform bill calculation for institution customers
    float performInstitutionCalculation(String supplyType, String instituteType, int demandCharge, int units) {
        float amount = 0;
        amount += demandCharge * 120; //Adding cost of demand charge
        switch (supplyType) {
            case "high" :
                // Institute type is not checked as the tariff rate is not different for the 2 types.
                amount += units * 6.35;
                break;
            case "low" :
                // Checking the institute type as tariff rate varies with both
                if (instituteType.equals("private")) {
                    amount += units * 7.5;
                }
                else if(instituteType.equals("government")){
                    amount +=units * 5.75 ;
                }
                break;
            default:
                System.out.println("Invalid institution type");
                System.exit(0); // converting the input to lowercase to avoid errors
        }
        return amount ;

    }

}

public class ElectricityBill {
    public static void main(String[] args) {
        Bill user1 = new Bill(); // Creating an object for user1
        user1.getInfo();
        user1.displayBill();
    }
}


import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int inputSelection = -1;
        Scanner scanner = new Scanner(System.in);
        DataController dataController = new DataController();
        boolean exceptionCaught;

        do {
            exceptionCaught = false;
            System.out.print("\033[H\033[2J");
            System.out.flush();

            System.out.println("Welcome to DPR Information System!");
            System.out.println("What will you do? Select 1:\n 1. Create a new data\n 2. Modify an existing data\n 3. Delete a data\n 4. Show table of all existing data\n 0. End program\n");

            
            try {
                inputSelection = scanner.nextInt();
            } catch(Exception e){
                System.err.println("The input is not an integer!");
                exceptionCaught = true;
            }


            if(!exceptionCaught) {
                
                switch(inputSelection) {
                    case 0:
                        System.out.println("See you next time!");
                        break;
                    case 1:
                        dataController.createData();
                        break;
                    case 2:
                        dataController.modifyData();
                        break;
                    case 3:
                        dataController.deleteData();
                        break;
                    case 4:
                        dataController.showAll();
                        break;
                    default:
                        System.err.println("Invalid option!");
                        break;
                }
            }

            if(inputSelection != 0) {
                System.out.println("\nPress Enter to continue...");
                scanner.nextLine();
                scanner.nextLine();
            }


        } while (inputSelection != 0);

        scanner.close();
    }
}
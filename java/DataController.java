import java.util.Scanner;
import java.util.ArrayList;


public class DataController {

    private ArrayList<AnggotaDPR> container = new ArrayList<>();
    private Scanner sc = new Scanner(System.in);


    public DataController() {

    }

    public DataController(ArrayList<AnggotaDPR> src) {
        this.container = src;
    }

    public ArrayList<AnggotaDPR> getContainer() {
        return this.container;
    }

    public void setContainer(ArrayList<AnggotaDPR> container) {
        this.container = container;
    }

    public AnggotaDPR searchById(String id) {
        for(AnggotaDPR obj : this.container) {
            if(obj.getId().equals(id)) {
                return obj;
            }
        }
        return null;
    }

    public void createData() {
        String id, name, field, electoralDistrict, position, party;

        System.out.println("\nPlease give attributes for new data:");
        System.out.print("ID                 : ");
        id = sc.next();
        sc.nextLine();
        System.out.print("Name               : ");
        name = sc.nextLine();
        System.out.print("Field              : ");
        field = sc.nextLine();
        System.out.print("Electoral District : ");
        electoralDistrict = sc.nextLine();
        System.out.print("Position           : ");
        position = sc.nextLine();
        System.out.print("Party              : ");
        party = sc.nextLine();

        AnggotaDPR temp = new AnggotaDPR(id, name, field, electoralDistrict, position, party);
        this.container.add(temp);

        System.out.println("Data has been successfully created!");
        

    }

    public void modifyData() {
        String targetID;
        System.out.print("\nPlease select data to modify by ID : ");
        targetID = sc.next();

        AnggotaDPR target = this.searchById(targetID);
        if(target == null) {
            System.err.println("Data was not found!");
            return; 
        }

        System.out.println("\nData found. Please enter new data attributes");
        sc.nextLine();

        String name, field, electoralDistrict, position, party;

        System.out.print("Name               : ");
        name = sc.nextLine();
        System.out.print("Field              : ");
        field = sc.nextLine();
        System.out.print("Electoral District : ");
        electoralDistrict = sc.nextLine();
        System.out.print("Position           : ");
        position = sc.nextLine();
        System.out.print("Party              : ");
        party = sc.nextLine();

        target.setName(name);
        target.setField(field);
        target.setElectoralDistrict(electoralDistrict);
        target.setPosition(position);
        target.setParty(party);

        System.out.println("Data successfully modified!");

    }

    public void deleteData() {
        String targetID;
        System.out.print("\nPlease select data to delete by ID : ");
        targetID = sc.next();

        AnggotaDPR target = this.searchById(targetID);
        if(target == null) {
            System.err.println("Data was not found!");
        }

        

        System.out.println("Data has been found.");
        System.out.println(target.getId() + ". " + target.getName());
        System.out.println("Confirm to delete? (y/n)");

        char del_confirm = sc.next().charAt(0);

        if(del_confirm == 'y') {
            this.container.remove(target);
        } else {
            System.out.println("Cancelled data deletion\n");
        }
        
        
    }
    
    public void showAll() {
        Table table = new Table();
        int numRows = this.container.size();
        
        String[][] data = new String[numRows + 1][6];
        
        data[0][0] = "ID";
        data[0][1] = "Name";
        data[0][2] = "Field";
        data[0][3] = "Electoral District";
        data[0][4] = "Position";
        data[0][5] = "Party";



        for (int i = 0; i < numRows; i++) {
            AnggotaDPR anggotaDPR = container.get(i);
            data[i + 1][0] = anggotaDPR.getId();
            data[i + 1][1] = anggotaDPR.getName();
            data[i + 1][2] = anggotaDPR.getField();
            data[i + 1][3] = anggotaDPR.getElectoralDistrict();
            data[i + 1][4] = anggotaDPR.getPosition();
            data[i + 1][5] = anggotaDPR.getParty();
        }

        table.createRows(numRows + 1, 6, data);
        
    }

}

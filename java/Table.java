import java.util.Arrays;


public class Table {

    private int rows;
    private int cols;

    

    Table() {

    }

    public int getRows() {
        return this.rows;
    }

    public void setRows(int rows) {
        this.rows = rows;
    }

    public int getCols() {
        return this.cols;
    }

    public void setCols(int cols) {
        this.cols = cols;
    }

    public void createRows(int rows, int cols, String data[][]) {
        int[] maxLen = new int[cols];

        Arrays.fill(maxLen, 0);

        for(int i = 0; i < cols; i++) {
            for(int j = 0; j < rows; j++) {
                maxLen[i] = Math.max(maxLen[i], data[j][i].length());
            }
        }

        int separatorLength = 19;

        for(int num : maxLen) {
            separatorLength += num;
        }

        String separator = String.format("%-" + separatorLength + "s", "").replace(' ', '-');

        for(int i = 0; i < rows; i++) {

            System.out.println(separator);

            for(int j = 0; j < cols; j++) {
                System.out.printf("| %-" + maxLen[j] + "s ", data[i][j]);
            }
            
            System.out.println("|");
        }

        System.out.println(separator);


    }
    

}

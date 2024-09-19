package tatoloops.learningpacks.view;

public class MatrixCell {
    private static int widthInCells;
    private static int heightInCells;
    private static int heightInLabels;
    private static int maxLabelsPerCell;
    
    private String [] line; 
    private int lineNumber;
    
    public MatrixCell(){
        this.line = new String[1];
        this.line[0] = "";
        this.lineNumber=0;
    }
    public MatrixCell(int amountOfLines){
        this.line = new String[amountOfLines];
        this.lineNumber=0;
        for (int i=0;i<amountOfLines;i++){
            this.line[i]="";
        }
    }

    public static int getWidthInCells() {
        return widthInCells;
    }

    public static void setWidthInCells(int widthInCells) {
        MatrixCell.widthInCells = widthInCells;
    }

    public static int getHeightInCells() {
        return heightInCells;
    }

    public static void setHeightInCells(int heightInCells) {
        MatrixCell.heightInCells = heightInCells;
    }

    public static int getHeightInLabels() {
        return heightInLabels;
    }

    public static void setHeightInLabels(int heightInLabels) {
        MatrixCell.heightInLabels = heightInLabels;
    }

    public static int getMaxLabelsPerCell() {
        return maxLabelsPerCell;
    }

    public static void setMaxLabelsPerCell(int maxLabelsPerCell) {
        MatrixCell.maxLabelsPerCell = maxLabelsPerCell;
    }
    
    
    public String[] getLine() {
        return line;
    }
    
    public String getLine(int index) {
        return line[index];
    }

    public void addLine(String line) {
        this.line[this.lineNumber] = line;
        this.lineNumber++;
    }
    public void addLine(String line,int index) {
        this.line[this.lineNumber] = line;
        this.lineNumber++;
    }
    public void removeLine(String line){
        this.lineNumber--;
        this.line[this.lineNumber] = line; 
    }
    
    public void removeLine(String line,int index){
        this.lineNumber--;
        this.line[this.lineNumber] = line; 
    }
    
}

package tatoloops.learningpacks.content.datosBancarios;

import javax.swing.JLayeredPane;
import tatoloops.learningpacks.view.MatrixCell;
import tatoloops.learningpacks.view.ToFrame;

public class DatosBancarios {
    
    public static void main (){
        Cuenta[] cuentaList = new Cuenta[4];
        Cliente[] clienteList = new Cliente[2];
        
        cuentaList[0] = new Cuenta(100,5000000);
        cuentaList[1] = new Cuenta(102,400000);
        cuentaList[2] = new Cuenta(301,120);
        cuentaList[3] = new Cuenta(400,650345);
        
        clienteList[0] = new Cliente("Juan",3);
        clienteList[1] = new Cliente("Marcela",1);
        
        for (int i =0; i<2;i++){
            for(int j=0;j< clienteList[i].getNumCuentas();j++){
                System.out.println("i="+i);
                clienteList[i].myCuenta.add(cuentaList[j]);
                clienteList[i].myCuenta.get(j).setOwner(clienteList[i].getName());
            }
        }
        ToView(clienteList,cuentaList);
    }
    
    public static void mainLegacy (JLayeredPane pane){
        Cuenta[] cuentaList = new Cuenta[4];
        Cliente[] clienteList = new Cliente[2];
        
        cuentaList[0] = new Cuenta(100,5000000);
        cuentaList[1] = new Cuenta(102,400000);
        cuentaList[2] = new Cuenta(301,120);
        cuentaList[3] = new Cuenta(400,650345);
        
        clienteList[0] = new Cliente("Juan",3);
        clienteList[1] = new Cliente("Marcela",1);
        
        for (int i =0; i<2;i++){
            for(int j=0;j< clienteList[i].getNumCuentas();j++){
                System.out.println("i="+i);
                clienteList[i].myCuenta.add(cuentaList[j]);
                clienteList[i].myCuenta.get(j).setOwner(clienteList[i].getName());
            }
        }
        ToView(clienteList,cuentaList);
    }
    
    private static void ToView(Cliente[] clienteList,Cuenta[] cuentaList){
        JLayeredPane pane = new JLayeredPane();
        
        //get dimensions
        int widthInCells=2;
        int heightInCells=0;
        for (int i=0; i<2;i++){
            for(int j=0;j< clienteList[i].getMyCuenta().size();j++){
                heightInCells++;
            }
        }
        
        System.out.println("height= "+heightInCells);
        //create arrays with dimensions
        
        MatrixCell[][] matrix = new MatrixCell [heightInCells][widthInCells];
        
        MatrixCell.setHeightInCells(heightInCells);
        MatrixCell.setWidthInCells(widthInCells);
        
        int maxLinesPerCell=2;
        
        MatrixCell.setMaxLabelsPerCell(maxLinesPerCell);
        MatrixCell.setHeightInLabels(MatrixCell.getHeightInCells()*maxLinesPerCell);
        
        //write data
        
        int row=0;
        for (int i=0; i<2;i++){
            for(int j=0;j< clienteList[i].getMyCuenta().size();j++){
                
                //System.out.println("i"+i +"j: "+j);
                
                matrix[row][1] = new MatrixCell(maxLinesPerCell);
                matrix[row][0] = new MatrixCell(maxLinesPerCell);
                
                if (j==0){
                    //matrix[row][0] = new MatrixCell(1);
                    matrix[row][0].addLine("Cliente: "+ clienteList[i].getName());
                    matrix[row][0].addLine("");
                }
                else{
                    //matrix[row][0] = new MatrixCell();
                    matrix[row][0].addLine("");
                    matrix[row][0].addLine("");
                }
                
                matrix[row][1].addLine("cuenta: "+ cuentaList[j].getId());
                matrix[row][1].addLine("Monto: "+ cuentaList[j].getMoney());
                
                row++;
            }
        }
        System.out.println("ToFrame");
        ToFrame.ToFrame(pane,matrix);
        
        
    }
}

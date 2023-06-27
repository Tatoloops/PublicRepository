package tatoloops.learningpacks.content.datosBancarios;

import java.util.ArrayList;
import java.util.Scanner;
import javax.swing.JLayeredPane;
import tatoloops.learningpacks.view.MatrixCell;
import tatoloops.learningpacks.view.ToFrame;

public class DatosBancarios {
    

    public static void main (){
        Scanner myScanner = new Scanner(System.in);
        System.out.print("Numero de clientes a ingresar: ");
        int numClientes= Integer.parseInt(myScanner.nextLine());
        
        Cliente[] clienteList = new Cliente[numClientes];
        Cuenta[][] cuentaListPersonal = new Cuenta[numClientes][100];
        int totalCuentas = 0;
        
        
        for (int i=0;i<numClientes;i++){
            System.out.println("");
            System.out.println("-- Datos de nuevo cliente --");
            System.out.print("Nombre cliente: ");
            String nombre=myScanner.nextLine();
            System.out.print("Rut cliente " + nombre+": ");
            String rut=myScanner.nextLine();
            System.out.print("numero de cuentas para cliente "+nombre+ ": ");
            int numCuentas=Integer.parseInt(myScanner.nextLine());
            totalCuentas+=numCuentas;
            
            clienteList[i] = new Cliente(nombre,rut,numCuentas);
            
            for(int j=0;j<numCuentas;j++){
                System.out.println("");
                System.out.println("-- Datos de nueva cuenta --");
                System.out.print("numero de la cuenta: ");
                int cuentaId=Integer.parseInt(myScanner.nextLine());
                System.out.print("saldo cuenta " + cuentaId+": ");
                int cuentaSaldo=Integer.parseInt(myScanner.nextLine());
                cuentaListPersonal[i][j] = new Cuenta(cuentaId,cuentaSaldo,nombre);
                clienteList[i].addCuenta(Integer.toString(cuentaId));
            }
            
        }
        
        System.out.println("total cuentas: "+ totalCuentas);
        // Preparando los datos para impresion
        Cuenta[] cuentaList = new Cuenta[totalCuentas];
        int totalCount=0;
        
        for (int i=0;i<numClientes;i++){

            String nombre=clienteList[i].getName();
            String rut=clienteList[i].getRut();
            int numCuentas=clienteList[i].getNumCuentas();
            
            for(int j=0;j<numCuentas;j++){
                int cuentaId=cuentaListPersonal[i][j].getId();
                int cuentaSaldo=cuentaListPersonal[i][j].getMoney();
                cuentaList[totalCount]= new Cuenta(cuentaId,cuentaSaldo,nombre);
                totalCount++;
            }

        }
     
        ToView(clienteList,cuentaList);
    }
    /*
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
    */
    private static void ToView(Cliente[] clienteList,Cuenta[] cuentaList){
        JLayeredPane pane = new JLayeredPane();
        
        //get dimensions
        int widthInCells=2;
        int heightInCells=0;
        for(int j=0;j< cuentaList.length;j++){
            heightInCells++;
        }

        
        System.out.println("height= "+heightInCells);
        //create arrays with dimensions
        
        MatrixCell[][] matrix = new MatrixCell [heightInCells][widthInCells];
        
        MatrixCell.setHeightInCells(heightInCells);
        MatrixCell.setWidthInCells(widthInCells);
        
        int maxLinesPerCell=3;
        
        MatrixCell.setMaxLabelsPerCell(maxLinesPerCell);
        MatrixCell.setHeightInLabels(MatrixCell.getHeightInCells()*maxLinesPerCell);
        
        //write data
        
        int row=0;
        for (int i=0; i<clienteList.length;i++){
            for(int j=0;j< clienteList[i].getNumCuentas();j++){
                
                //System.out.println("i"+i +"j: "+j);
                
                matrix[row][1] = new MatrixCell(maxLinesPerCell);
                matrix[row][0] = new MatrixCell(maxLinesPerCell);
                
                if (j==0){
                    //matrix[row][0] = new MatrixCell(1);
                    matrix[row][0].addLine("Cliente: "+ clienteList[i].getName());
                    matrix[row][0].addLine("Rut: "+ clienteList[i].getRut());
                    matrix[row][0].addLine("Cuentas: "+ clienteList[i].getCuentas());
                }
                else{
                    //matrix[row][0] = new MatrixCell();
                    matrix[row][0].addLine("");
                    matrix[row][0].addLine("");
                    matrix[row][0].addLine("");
                }
                
                matrix[row][1].addLine("cuenta: "+ cuentaList[j].getId());
                matrix[row][1].addLine("Monto: "+ cuentaList[j].getMoney());
                matrix[row][1].addLine("duenio: "+ cuentaList[j].getOwner());
                
                row++;
            }
        }
        System.out.println("ToFrame");
        ToFrame.ToFrame(pane,matrix);
        
        
    }
}

package tatoloops.learningpacks.content.datosBancarios;

import java.util.Scanner;
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
        
        //System.out.println("total cuentas: "+ totalCuentas);
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
     
        PackToFrame(clienteList,cuentaList);
    }
    
    /**
     *
     * @param clienteList Array of clients
     * @param cuentaList Array of bank accounts
     */
    //@Override
    public static void PackToFrame(Cliente[] clienteList,Cuenta[] cuentaList){
        //get dimensions
        int widthInCells=2;
        int heightInCells=0;
        for(int j=0;j< cuentaList.length;j++){
            heightInCells++;
        }

        MatrixCell[][] matrix = new MatrixCell [heightInCells][widthInCells];
        
        MatrixCell.setHeightInCells(heightInCells);
        MatrixCell.setWidthInCells(widthInCells);
        
        int maxLinesPerCell=3;
        
        MatrixCell.setMaxLabelsPerCell(maxLinesPerCell);
        MatrixCell.setHeightInLabels(MatrixCell.getHeightInCells()*maxLinesPerCell);
        
        //write data
        
        int row=0;
        for(int i=0; i<clienteList.length;i++){
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
                
                matrix[row][1].addLine("cuenta: "+ cuentaList[row].getId());
                matrix[row][1].addLine("Monto: "+ cuentaList[row].getMoney());
                matrix[row][1].addLine("duenio: "+ cuentaList[row].getOwner());
                
                row++;
            }
        }
        //System.out.println("ToFrame");
        ToFrame.ToFrame("Datos Bancarios",matrix);
    }
}

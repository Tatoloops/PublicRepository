package tatoloops.learningpacks.content.fichero;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

class JavaApplication1 {
    public static void EscribirArchivo(String filename,int[] reg){
       
        File archivo = null;
        FileWriter writer = null;
        PrintWriter pw = null;
       
        try {
            archivo = new File(filename);
            writer = new FileWriter(archivo, false);
            pw = new PrintWriter(writer);
         
            int largo = reg.length;
            for (int i=0; i<largo; i++){
                if (reg[i] != 0)
                    pw.println(reg[i]);
                else
                    break;
            }
        }
        catch(Exception e){
            e.printStackTrace();
        }
        finally {
            try{
                if (null != writer ){
                    writer.close();
                }
            }catch (Exception e2){
                e2.printStackTrace();
            }
        }        
    }
    public static int getFileSize(String filename){
        //funcion que solo determina el tamano del fichero. era necesario para no dejarlo en "100" o usar varaibles globales.
        File archivo = null;
        FileReader reader = null;
        BufferedReader buffer = null;
        
        int [] listado=null;
        
        try {
            archivo = new File(filename);
            reader = new FileReader(archivo);
            buffer = new BufferedReader(reader);
         
            String linea;
            int i = 0;
            while( (linea=buffer.readLine())!=null){
                i++;
            }
            return i;
        }
        catch(IOException e){
            return 0;
        }
        finally {
            try{
                if (null != reader ){
                    reader.close();
                }
            }
            catch (IOException e2){
            }
        }
    }
    public static void leerArchivo(String filename,int[] listado){
       
        File archivo = null;
        FileReader reader = null;
        BufferedReader buffer = null;
        /*
            creo que para optimizar se podria eliminar el "reg" y reemplazar directamente con "listado"
        */
        int[] reg = new int[listado.length];
        
        try {
            archivo = new File(filename);
            reader = new FileReader(archivo);
            buffer = new BufferedReader(reader);
         
            String linea;
            int i = 0;
            while( (linea=buffer.readLine())!=null){
                reg[i++]= Integer.parseInt(linea);
            }
         
            for (int j = 0; j < i; j++)
                listado[j] = reg[j];
        }
        catch(Exception e){
            e.printStackTrace();
        }finally {
            try{
                if (null != reader ){
                    reader.close();
                }
            }catch (Exception e2){
                e2.printStackTrace();
            }
        }
    }    
    public static void eliminaDuplicado(int[] sourArray,int[] destArray){
        int largo = sourArray.length;
        int j = 0;
        //ordernar array
        Arrays.sort(sourArray);

        //transferir nuevos datos a destArray
        for (int i=0; i<largo-1; i++){  
            if (sourArray[i] != sourArray[i+1]){  
                destArray[j++] = sourArray[i];  
            }
            //Agregar ultimo termino
            if (i==largo-2){
                destArray[j++] = sourArray[i+1];  
            }
        }
    }
    public static double determinarPromedioFichero (int [] numeros,int cantidadNumeros){
        /*
            fue necesario usar "cantidadNumeros" como argumento ya que el array.length 
            es mucho mayor de la cantidad de numeros que se ulitizan, arrojando un promedio menor.
        */
        double suma=0;
        for (int j=0;j<cantidadNumeros;j++){
            suma+=numeros[j];
        }
        suma =(double)suma;
        return (suma/(double)cantidadNumeros);
    }
    public static void imprimirNumero(String numeroTipo,double numero){
        /*
        numero tipo es simplemente un string que estara impreso, el motivo por el que fue agregado es 
        que tener una funcion para determinar el promedio y otra para imprimir un resultado en mi opinion deberian ir separadas.
        
        en caso de que queramos determinar otro tipo de valor en los numeros de array e imprimirlos, esta funcion resulta versatil.
        
        */
        System.out.println("El "+ numeroTipo + " es: "+ numero);
    }
}

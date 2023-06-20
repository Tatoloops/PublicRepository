package tatoloops.learningpacks.content.fichero;

class fichero {

    static void main(String[] args) {
        
        //Crear una instancia de la clase JavaApplication1;
        //JavaApplication1  Apli = new JavaApplication1();
        
        //Determinar el tamaño del fichero (en líneas)
        int fileSizeInLines = JavaApplication1.getFileSize(Paths.getFile01());
        
        //Crear los vectores (arrays) respectivos con el tamaño determinado por la función anterior.
        int[] sourceArray = new int [fileSizeInLines];
        int[] destinationArray = new int [fileSizeInLines];

        
        
        JavaApplication1.leerArchivo(Paths.getFile01(),sourceArray);
        JavaApplication1.eliminaDuplicado(sourceArray,destinationArray);
        JavaApplication1.EscribirArchivo( Paths.getFile02(),destinationArray);
        

        //determinar promedio
        /*
            Fue necesario volver a determinar el tamano en filas del archivo02, ya que el "destinationArray" posee las mismas
        cantidades de valores que el array "sourceArray". Con este determinamos el nuevo tamano.
        
            Obviamente se puede hacer de otras formas pero el metodo ya estaba hecho
        */
        fileSizeInLines = JavaApplication1.getFileSize(Paths.getFile02());
        double promedio = JavaApplication1.determinarPromedioFichero(destinationArray,fileSizeInLines);
        JavaApplication1.imprimirNumero("promedio", promedio);
        /*
            Aqui nose si el promedio hay que conseguirlo al leer un fichero.
            nose si el promedio se escribe al fichero o a otro fichero
            asi que solamente lo imprimo, nose donde estan las instrucciones, 
            es lo que recuerdo de la clase.
        
        */
    }
}


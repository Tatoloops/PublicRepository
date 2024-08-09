package com.tatoloops.projectokol;

/**
 *
 * @author Tatoloops
 */
public class Inicio {

    public static void main(String[] args) {
        System.out.println("Hello World!");
        
        
        
        Gato gatito= new Gato("Garfield",4);
        Gato gato2 = new Gato ("Silvestre",5);
        Gato gato3 = new Gato("Tom",7);
        Gato gato4 = new Gato("Maxito",21);

        int myedad = gato2.getEdad();
        System.out.println("myedad = " + myedad);
        System.out.println(gatito);
    }
}

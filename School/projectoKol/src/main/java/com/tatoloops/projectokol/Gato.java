/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.tatoloops.projectokol;

/**
 *
 * @author Tatoloops
 */
public class Gato {
    private String name;
    private int edad;
    
    //constructor
    public Gato(){
        this.name = "unnamed";
        this.edad = 0;
    }
    
    public Gato(String _name, int _edad){
        this.name = _name;
        this.edad = _edad;
    }
    
    //functions custom
    public void maullar(){
        
    }
    public void dormir(){
        
    }
    
    //setters getters
    public String getName()         {return name;}
    public void setName(String name){this.name = name;}
    public int getEdad()            {return edad;}
    public void setEdad(int edad)   {this.edad = edad;}
    
    //toString

    //@Override
    public String toString() {
        return "| --- Ø Gato Ø --- |\n" + "× name: " + name + "\n× edad: " + edad+"\n| --- ---  --- --- |\n";
    }
    
    
    
}

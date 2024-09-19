/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package myprojectu;

import java.util.Date;

/**
 *
 * @author tatoloops
 */
public class Perro {
    // --- Atributos ---
    private String name;
    private Date fechaNacimiento;
    private double height;
    private double weight;
    private int age;
    private byte cantidadVacunas;
    private char sexo;
    
    // --- Metodos ---
    // - Constructores -
    public Perro(){
    this.name="";
    this.fechaNacimiento=new Date("2020/03/13");

    this.height=0.5;
    this.weight=20;
    this.age=6;
    this.cantidadVacunas=(byte)1;
    this.sexo = 'm';
    }
    
    public Perro(String name,int height,int weight, int age){
        this.name = name;
        this.age = age;
        this.weight = weight;
        this.height = height;
    }
    // - Get & set - 
    
    // - Customers - 
    
    // - Destructor -
    
}

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
    private int height;
    private int weight;
    private int age;
    private byte cantidadVacunas;
    private char sexo = '\0';
    
    // --- Metodos ---
    // - Constructores -
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


package com.tatoloops.projectokol;

/**
 *
 * @author Tatoloops
 */
public class TiranosaurioRex {
    private String name;
    private int edad;
    private int height;
    private int weight;
    
    //datos de pelea
//    int hp;
//    int atk;
//    int def;
//    int speed;
           
    
    // constructores
     public TiranosaurioRex(){
        this.name="sin nombre";
        this.edad=0;
        this.height=0;
        this.weight=0;
     }
    
    public TiranosaurioRex(String _name,int _edad){
        this.name=_name;
        this.edad=_edad;
        this.height=0;
        this.weight=0;
    }

    public TiranosaurioRex(String _name,int _edad,int _height,int _weight){
        this.name=_name;
        this.edad=_edad;
        this.height=_height;
        this.weight=_weight;
    }
    
    //getters && setters
    public String getName(){
        return this.name;
    }
    public void setName(String _name){
        this.name=_name;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

//    public int getHp() {
//        return hp;
//    }
//
//    public void setHp(int hp) {
//        this.hp = hp;
//    }
//
//    public int getAtk() {
//        return atk;
//    }
//
//    public void setAtk(int atk) {
//        this.atk = atk;
//    }
//
//    public int getDef() {
//        return def;
//    }
//
//    public void setDef(int def) {
//        this.def = def;
//    }
//
//    public int getSpeed() {
//        return speed;
//    }
//
//    public void setSpeed(int speed) {
//        this.speed = speed;
//    }
    
    public String toString(){
        return "| --- Ø Tiranosaurio-Rex Ø --- |\n" + "× name: " + name + "\n× edad: " + edad+"\n| --- ---  --- --- |\n";
    }
}

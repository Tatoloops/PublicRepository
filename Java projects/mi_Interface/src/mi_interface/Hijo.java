package mi_interface;

/**
 *
 * @author tatoloops
 */

public class Hijo extends Persona implements iPapa, iMama{
//    super (name);
    private int edad;
    
    
    public Hijo(){
        
    }

    public Hijo(int edad, String name) {
        super(name);
        this.edad = edad;
    }

    public void setEdad(int edad){
        this.edad=edad;
    }
    
    
    
    
    @Override
    public String toString() {
        return "Hijo{" + super.toString() + "edad=" + edad + '}';
    }

        
    
    //implements iPapa
    @Override
    public void lavarAuto() {
        System.out.println("Lavando el auto...\n");
    }

    @Override
    public void cortarPasto() {
        System.out.println("Cortando el pasto...\n");
    }

    @Override
    public void lavarLoza() {
        System.out.println("Lavando la loza...\n");
    }

    
    
}

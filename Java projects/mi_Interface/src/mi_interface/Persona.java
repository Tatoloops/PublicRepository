package mi_interface;

/**
 *
 * @author tatoloops
 */
public class Persona {
    protected String name;
    
    
    public Persona(){
        
    }
    
    public Persona(String name){
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Persona{" + "name=" + name + '}';
    }
    
    
}
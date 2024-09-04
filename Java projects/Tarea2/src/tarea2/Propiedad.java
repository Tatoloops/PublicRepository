
package tarea2;

/**
 *
 * @author Tatoloops
 */
public abstract class Propiedad {
    protected String direction;
    protected float metrosCuadrados;
    
    // --- constructor ---
//    Propiedad(){
//        this.direction="";
//        this.metrosCuadrados=0.0f;
//    }
    Propiedad(String direction, float metrosCuadrados){
        this.setDirection(direction);
        this.setMetrosCuadrados(metrosCuadrados);
    }
    
    // --- getter & setter ---

    public String getDirection() {
        return direction;
    }

    public void setDirection(String direction) {
        if (!direction.isBlank() && !direction.isEmpty()){
            this.direction = direction;
        }
       
    }

    public float getMetrosCuadrados() {
        return metrosCuadrados;
    }

    public void setMetrosCuadrados(float metrosCuadrados) {
        if (this.metrosCuadrados>=5000){
            this.metrosCuadrados = metrosCuadrados;
        }
        
    }
    
    // --- customers ---
    
    abstract int calcularContribuciones();
}

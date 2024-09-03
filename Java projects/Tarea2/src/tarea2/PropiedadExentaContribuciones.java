package tarea2;

/**
 *
 * @author Tatoloops
 */
public class PropiedadExentaContribuciones extends Propiedad {
    
    // --- constructor ---
//    PropiedadExentaContribuciones(){
//        super();
//        
//    }
    PropiedadExentaContribuciones(String direction,float metrosCuadrados){
        super(direction,metrosCuadrados);
        
    }
    
    
    // --- getter & setter ---
    
    
    
    // --- customers ---
    
    @Override
    int calcularContribuciones() {

        return 0;
    }
    
}

package tarea2;

/**
 *
 * @author Tatoloops
 */
public class PropiedadAfectaContribucionesSitioEriazo extends PropiedadAfectaContribuciones {

    // --- constructor ---
//    PropiedadAfectaContribucionesSitioEriazo(){
//        super();
//        
//    }
    PropiedadAfectaContribucionesSitioEriazo(String direction,float metrosCuadrados){
        super(direction,metrosCuadrados);
        
    }
    
    // --- getter & setter ---
    
    
    
    // --- customers ---

    @Override
    int calcularContribuciones() {
        int impuesto = 0;
        
        // propiedad afecta debe pagar un 15% si tiene mas de 5000 mt2
        if (super.metrosCuadrados>=5000){
            impuesto+=15;
        }
        
        return impuesto;
    }
    
}

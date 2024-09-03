package tarea2;

/**
 *
 * @author Tatoloops
 */
public class PropiedadAfectaContribucionesConInmueble extends PropiedadAfectaContribuciones {
    
    private int mt2Imueble;
    
    
     // --- constructor ---
//    PropiedadAfectaContribucionesConInmueble(){
//        super();
//        
//    }
    PropiedadAfectaContribucionesConInmueble(String direction,float metrosCuadrados){
        super(direction,metrosCuadrados);
        
    }
    
    
    // --- getter & setter ---

    public int getMt2Imueble() {
        return mt2Imueble;
    }

    public void setMt2Imueble(int mt2Imueble) {
        this.mt2Imueble = mt2Imueble;
    }
    
    
    
    // --- customers ---


    @Override
    int calcularContribuciones() {
        int impuesto = 0;
        
        // propiedad afecta debe pagar un 15% si tiene mas de 5000 mt2
        if (super.metrosCuadrados>=5000){
            impuesto+=15;
        }
        
        // propiedad debe pagar un impuesto mayor si inmueble mayor a 120 mt2
        if (this.mt2Imueble>=120){
            impuesto+=25;
        }
        
        return impuesto;
    }

}

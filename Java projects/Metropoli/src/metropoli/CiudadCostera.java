package metropoli;

/**
 *
 * @author tatoloops
 */
public class CiudadCostera extends Ciudad {
    private boolean hasPuerto;
    
    
    
    // --- constructor ---

    public CiudadCostera() {
    }

    public CiudadCostera(boolean hasPuerto, int id, String nombre, float nivelCo2, int numeroAutos) {
        super(id, nombre, nivelCo2, numeroAutos);
        this.hasPuerto = hasPuerto;
    }
    
    
    
    
    // --- getter & setter ---

    public boolean isHasPuerto() {
        return hasPuerto;
    }

    public void setHasPuerto(boolean hasPuerto) {
        this.hasPuerto = hasPuerto;
    }

    
    
    
    // --- customers ---
    
    public String toString(){
        return "hola";
    }
    
    
    // override from Ciudad parent class
    @Override
    public void eventosAleatoriosIncendioVaguada() {
        
    }
    
}

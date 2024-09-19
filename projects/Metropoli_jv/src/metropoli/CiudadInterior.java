package metropoli;

/**
 *
 * @author tatoloops
 */
public class CiudadInterior extends Ciudad {
    boolean entreCerros;

    // --- cosntructors ---

    public CiudadInterior() {
    }

    public CiudadInterior(boolean entreCerros, int id, String nombre, float nivelCo2, int numeroAutos) {
        super(id, nombre, nivelCo2, numeroAutos);
        this.entreCerros = entreCerros;
    }
    
    
    // --- getter & setter ---

    public boolean isEntreCerros() {
        return entreCerros;
    }

    public void setEntreCerros(boolean entreCerros) {
        this.entreCerros = entreCerros;
    }

//    public int getId() {
//        return id;
//    }
//
//    public void setId(int id) {
//        this.id = id;
//    }
//
//    public String getNombre() {
//        return nombre;
//    }
//
//    public void setNombre(String nombre) {
//        this.nombre = nombre;
//    }
//
//    public float getNivelCo2() {
//        return nivelCo2;
//    }
//
//    public void setNivelCo2(float nivelCo2) {
//        this.nivelCo2 = nivelCo2;
//    }
//
//    public int getNumeroAutos() {
//        return numeroAutos;
//    }
//
//    public void setNumeroAutos(int numeroAutos) {
//        this.numeroAutos = numeroAutos;
//    }
    
    
    // --- customers ---
    
    // override from ciudad parent class

//    @Override
//    public void calcularC02AutosDiario() {
//        
//    }

    @Override
    public void actualizarNivelC02CiudadHora() {
        float co2=iContaminable.FACTOR_GENERACION_C02_CIUDAD_INTERIOR_X_HORA;
    }

    @Override
    public void realizarSimulacionCiudad() {
        
    }

    @Override
    public String toString() {
        return "hola";
    }

    @Override
    void calcularCo2CiudadTotal() {
        
    }

    @Override
    public void eventosAleatoriosIncendioVaguada() {
        
    }
    
    
}

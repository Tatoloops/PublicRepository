package metropoli;

/**
 *
 * @author tatoloops
 */

public abstract class Ciudad implements iContaminable {

    private static int cantidad;

    protected int id;
    protected String nombre;
    protected float nivelCo2;
    protected int numeroAutos;
    
    // --- constructors ---

    public Ciudad() {
    }

    public Ciudad(int id, String nombre, float nivelCo2, int numeroAutos) {
        this.id = id;
        this.nombre = nombre;
        this.nivelCo2 = nivelCo2;
        this.numeroAutos = numeroAutos;
    }
    
    // --- getter & setter ---

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public float getNivelCo2() {
        return nivelCo2;
    }

    public void setNivelCo2(float nivelCo2) {
        this.nivelCo2 = nivelCo2;
    }

    public int getNumeroAutos() {
        return numeroAutos;
    }

    public void setNumeroAutos(int numeroAutos) {
        this.numeroAutos = numeroAutos;
    }
    
    
  
    // --- customers ---
    public abstract void eventosAleatoriosIncendioVaguada();
    
    void calcularCo2CiudadTotal(){
        float total=iContaminable.FACTOR_GENERACION_C02_AUTOS_X_VEHICULO_DIARIO*this.numeroAutos;
        System.out.println("C02 total generado: "+total);
    }

    public String toString(){
        return this.nombre;
    }
    
    //implemented from iContaminable:
    
    @Override
    public void actualizarNivelC02CiudadHora() {
       
    }

    
    @Override
    public void realizarSimulacionCiudad() {
        for (int i=0;i<24;i++){
            System.out.println("hora "+i+": ");
            actualizarNivelC02CiudadHora();
        }
        
    }

    
    @Override
    public void calcularC02AutosDiario() {
        float calculo= iContaminable.FACTOR_GENERACION_C02_AUTOS_X_VEHICULO_DIARIO * this.numeroAutos;
        System.out.println("C02 producido por autos al dia: " + calculo); 
    }
    
    
    
    //  statics 
    public static int getCantidad(){
        return Ciudad.cantidad;
        
    }
    public static void agregar(Ciudad p){
        
    }
    public static void realizarSimulacionCiudades(){
        
    }
    public static void imprimirCiudades(){
        
    }
    
}

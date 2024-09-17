package metropoli;

/**
 *
 * @author tatoloops
 */
public interface iContaminable {
    float FACTOR_GENERACION_C02_CIUDAD_COSTERA_X_HORA=(float) 0.15;
    float FACTOR_GENERACION_C02_CIUDAD_INTERIOR_X_HORA=(float) 0.35;
    float FACTOR_GENERACION_C02_AUTOS_X_VEHICULO_DIARIO=(float) 0.01234;
    
    
    void realizarSimulacionCiudad();
    void actualizarNivelC02CiudadHora();
    void calcularC02AutosDiario();
}

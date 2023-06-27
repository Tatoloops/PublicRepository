package tatoloops.learningpacks.content.datosBancarios;

import java.util.ArrayList;

class Cliente {
    
    
    private String name;
    private String rut;
    private int numCuentas;
    public ArrayList<Cuenta> myCuenta;
    private String cuentas;
    
    Cliente(String name,String rut, int numCuentas){
        this.name=name;
        this.rut=rut;
        this.numCuentas=numCuentas;
        this.myCuenta=new ArrayList<>();
        this.cuentas="";
    }
    
    public String getName() {
        return name;
    }

    public String getRut() {
        return rut;
    }
    
    
    public int getNumCuentas() {
        return numCuentas;
    }
    
    public ArrayList<Cuenta> getMyCuenta() {
        return myCuenta;
    }

    public String getCuentas() {
        return cuentas;
    }

    public void addCuenta(String newCuenta) {
        if ("".equals(this.cuentas)){
            this.cuentas = newCuenta;
        }
        else{
            this.cuentas += ", "+ newCuenta;
        }
        
    }
    
    
    public void setMyCuenta(ArrayList<Cuenta> myCuenta) {
        this.myCuenta = myCuenta;
    }
}

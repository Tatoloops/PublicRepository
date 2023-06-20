package tatoloops.learningpacks.content.datosBancarios;

import java.util.ArrayList;

class Cliente {
    
    
    private String name;
    private int numCuentas;
    public ArrayList<Cuenta> myCuenta;
    
    Cliente(String name,int numCuentas){
        this.name=name;
        this.numCuentas=numCuentas;
        this.myCuenta=new ArrayList<>();
    }
    
    public String getName() {
        return name;
    }
    
    public int getNumCuentas() {
        return numCuentas;
    }
    
    public ArrayList<Cuenta> getMyCuenta() {
        return myCuenta;
    }

    public void setMyCuenta(ArrayList<Cuenta> myCuenta) {
        this.myCuenta = myCuenta;
    }
}

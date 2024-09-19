package tatoloops.learningpacks.content.datosBancarios;

class Cuenta {
    private int id ;
    private int money;
    
    private String owner;
    //private String ClientId;
    Cuenta(){
        
    }
    
    Cuenta(int id,int money,String owner){
        this.id = id;
        this.money=money;
        this.owner=owner;
    }
    
    public String getOwner() {
        return owner;
    }

    public int getId() {
        return id;
    }

    public int getMoney() {
        return money;
    }
    
}

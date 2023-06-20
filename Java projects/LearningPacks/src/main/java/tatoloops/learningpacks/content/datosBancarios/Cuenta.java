package tatoloops.learningpacks.content.datosBancarios;

class Cuenta {
    private int id ;
    private int money;
    
    private String owner;
    //private String ClientId;

    public String getOwner() {
        return owner;
    }

    public int getId() {
        return id;
    }

    public int getMoney() {
        return money;
    }

    public void setOwner(String owner) {
        this.owner = owner;
    }
    

    Cuenta(int id,int money){
        this.id = id;
        this.money=money;
    }
}

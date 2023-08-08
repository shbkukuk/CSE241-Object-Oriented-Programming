class Image extends Content implements visual, nonplayable{
    private String dimensionInfo;

    public Image(String name, String dimensionInfo, String otherInfo) {
        super(name, otherInfo);
        this.dimensionInfo = dimensionInfo;
    }

    public String getDimensionInfo() {
        return dimensionInfo;
    }

    @Override
    String getCategory() {
        return "image";
    }

    @Override 
    public void info()
    {
        System.out.println("Name: " + getName());
        System.out.println("Other Info: " + getDimensionInfo());
        System.out.println("Other Info: " + getOtherInfo());
        
    }
}
/**
 * The Text class represents a text content that is non-visual and non-playable.
 */
class Text extends Content implements nonvisual,nonplayable{
    
     /**
     * Constructs a Text object with the specified name and other information.
     *
     * @param name      The name of the text content.
     * @param otherInfo Other information about the text content.
     */
    public Text(String name, String otherInfo) {
        super(name, otherInfo);
    }

    @Override
    String getCategory() {
        return "text";
    }

    @Override 
    public void info()
    {
        System.out.println("Name: " + getName());
        System.out.println("Other Info: " + getOtherInfo());
        
    }
}

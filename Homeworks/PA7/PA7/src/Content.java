/**
 * The Playable interface represents content that can be played.
 */
interface playable
{
    void info();
    

}

/**
 * The NonPlayable interface represents content that cannot be played.
 */
interface nonplayable
{
    void info();
}

/**
 * The Visual interface represents content that is visual.
 */
interface visual
{
    void info();
}

/**
 * The NonVisual interface represents content that is non-visual.
 */
interface nonvisual
{
    void info();
}
/**
 * The Content class is an abstract class representing general content.
 */
abstract class Content {
    private String name;
    private String otherInfo;

    /**
     * Constructs a Content object with the specified name and other information.
     *
     * @param name      The name of the content.
     * @param otherInfo Other information about the content.
     */
    public Content(String name, String otherInfo) {
        this.name = name;
        this.otherInfo = otherInfo;
    }

    /**
     * Retrieves the name of the content.
     *
     * @return The name of the content.
     */
    public String getName() {
        return name;
    }
    
     /**
     * Retrieves the other information about the content.
     *
     * @return The other information about the content.
     */
    public String getOtherInfo() {
        return otherInfo;
    }

    /**
     * Retrieves the category of the content.
     *
     * @return The category of the content.
     */
    abstract String getCategory();
}


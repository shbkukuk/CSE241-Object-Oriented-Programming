/**
 * The Audio class represents an audio content that is non-visual and playable.
 */
class Audio extends Content implements nonvisual, playable{
    private String duration;

    /**
     * Constructs an Audio object with the specified name, duration, and other information.
     *
     * @param name      The name of the audio content.
     * @param duration  The duration of the audio content.
     * @param otherInfo Other information about the audio content.
     */
    public Audio(String name, String duration, String otherInfo) {
        super(name, otherInfo);
        this.duration = duration;
    }

     /**
     * Retrieves the duration of the audio content.
     *
     * @return The duration of the audio content.
     */
    public String getDuration() {
        return duration;
    }

    @Override
    String getCategory() {
        return "audio";
    }

    @Override 
    public void info()
    {
        System.out.println("Name: " + getName());
        System.out.println("Other Info: " + getDuration());
        System.out.println("Other Info: " + getOtherInfo());
        
    }
}

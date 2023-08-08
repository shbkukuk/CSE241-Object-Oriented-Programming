/**
 * The Video class represents a video content that is visual and playable.
 */
class Video extends Content implements visual,playable{
    private String duration;


     /**
     * Constructs a Video object with the specified name, duration, and other information.
     *
     * @param name      The name of the video content.
     * @param duration  The duration of the video content.
     * @param otherInfo Other information about the video content.
     */
    public Video(String name, String duration, String otherInfo) {
        super(name, otherInfo);
        this.duration = duration;
    }

    /**
     * Retrieves the duration of the video content.
     *
     * @return The duration of the video content.
     */
    public String getDuration() {
        return duration;
    }

    @Override
    String getCategory() {
        return "video";
    }

    @Override 
    public void info()
    {
        System.out.println("Name: " + getName());
        System.out.println("Other Info: " + getDuration());
        System.out.println("Other Info: " + getOtherInfo());
        
    }
}

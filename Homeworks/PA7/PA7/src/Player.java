import java.util.List;
import java.util.ArrayList;

/**
 * The Player class represents an observer who can play and navigate content objects.
 */
class Player implements Observer {
    private String name;
    private List<Content> playlist;
    private int currentIndex;

    /**
     * Constructs a Player object with the specified name.
     *
     * @param name The name of the player.
     */
    public Player(String name) {
        this.name = name;
        this.playlist = new ArrayList<>();
        this.currentIndex = -1;
    }

    @Override
    public void update(Content content) {
        playlist.add(content);
    }

    @Override
    public String getObserverTyype()
    {
        return  "player";
    }

    @Override
    public void remove(Content content)
    {
        playlist.remove(content);
    }

    /**
     * Displays the list of content objects in the player's playlist.
     */
    public void show_list() {
        System.out.println("Playlist for Player " + name + ":");
        for (Content Content : playlist) {
            System.out.println(Content.getName() + " - " + Content.getCategory());
        }
    }

     /**
     * Retrieves the content object currently being played by the player.
     *
     * @return The currently played content object, or null if none.
     */
    public playable currently_playing() {
        if (currentIndex >= 0 && currentIndex < playlist.size()) {
            return (playable) playlist.get(currentIndex);
        }
        return null;
    }

     /**
     * Moves to the next content object of the specified type in the playlist.
     *
     * @param type The type of content ("audio" or "video") to navigate to.
     */
    public void next(String type) {
        //it is not going to change. If the list is empty
        if(playlist.isEmpty())
        {
            System.out.println("The list is empty. You can not move to next object");
            return;
        }
        if (type.equals("audio")) {
            playNextAudio();
        } else if (type.equals("video")) {
            playNextVideo();
        }
    }

    private void playNextAudio() {
        for (int i = currentIndex + 1; i < playlist.size(); i++) {
            Content Content = playlist.get(i);
            if (Content instanceof Audio) {
                currentIndex = i;
                return;
            }
        }
        currentIndex = -1; // No more audio objects in the playlist
    }

    private void playNextVideo() {
        for (int i = currentIndex + 1; i < playlist.size(); i++) {
            Content Content = playlist.get(i);
            if (Content instanceof Video) {
                currentIndex = i;
                return;
            }
        }
        currentIndex = -1; // No more video objects in the playlist
    }
}


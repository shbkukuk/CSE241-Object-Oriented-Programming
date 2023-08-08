
import java.util.List;
import java.util.ArrayList;

/**
 * The Viewer class represents an observer who can view and navigate content objects.
 */
class Viewer implements Observer {
    private String name;
    private List<Content> viewlist;
    private int currentIndex;

     /**
     * Constructs a Viewer object with the specified name.
     *
     * @param name The name of the viewer.
     */
    public Viewer(String name) {
        this.name = name;
        this.viewlist = new ArrayList<>();
        this.currentIndex = -1;
    }

    @Override
    public void update(Content content) {
        
        viewlist.add(content);
    }

    @Override
    public String getObserverTyype()
    {
        return  "viewer";
    }

    @Override
    public void remove(Content content)
    {

        viewlist.remove(content);
    }

    /**
     * Displays the list of content objects in the viewer's viewlist.
     */
    public void show_list() {
        System.out.println("Viewlist for Viewer " + name + ":");
        for (Content Content : viewlist) {
            System.out.println(Content.getName() + " - " + Content.getCategory());
        }
    }

    /**
     * Retrieves the content object currently being viewed by the viewer.
     *
     * @return The currently viewed content object, or null if none.
     */
    public nonplayable currently_viewing() {
        if (currentIndex >= 0 && currentIndex < viewlist.size()) {
            return (nonplayable) viewlist.get(currentIndex);
        }
        return null;
    }

     /**
     * Moves to the next content object of the specified type in the viewlist.
     *
     * @param type The type of content ("text" or "image") to navigate to.
     */
    public void next(String type) {
        if (type.equals("text")) {
            jumpToNextText();
        } else if (type.equals("image")) {
            jumpToNextImage();
        }
    }

    /**
     * Moves to the previous content object of the specified type in the viewlist.
     *
     * @param type The type of content ("text" or "image") to navigate to.
     */
    public void previous(String type) {
        if (type.equals("text")) {
            jumpToPreviousText();
        } else if (type.equals("image")) {
            jumpToPreviousImage();
        }
    }

    private void jumpToNextText() {
        for (int i = currentIndex + 1; i < viewlist.size(); i++) {
            Content Content = viewlist.get(i);
            if (Content instanceof Text) {
                currentIndex = i;
                return;
            }
        }
        currentIndex = -1; // No more text objects in the viewlist
    }

    private void jumpToNextImage() {
        for (int i = currentIndex + 1; i < viewlist.size(); i++) {
            Content Content = viewlist.get(i);
            if (Content instanceof Image) {
                currentIndex = i;
                return;
            }
        }
        currentIndex = -1; // No more image objects in the viewlist
    }

    private void jumpToPreviousText() {
        for (int i = currentIndex - 1; i >= 0; i--) {
            Content Content = viewlist.get(i);
            if (Content instanceof Text) {
                currentIndex = i;
                return;
            }
        }
        currentIndex = -1; // No previous text objects in the viewlist
    }

    private void jumpToPreviousImage() {
        for (int i = currentIndex - 1; i >= 0; i--) {
            Content Content = viewlist.get(i);
            if (Content instanceof Image) {
                currentIndex = i;
                return;
            }
        }
        currentIndex = -1; // No previous image objects in the viewlist
    }
}

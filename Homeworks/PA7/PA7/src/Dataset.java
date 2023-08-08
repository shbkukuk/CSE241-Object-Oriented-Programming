import java.util.List;
import java.util.ArrayList;


/**
 * The Dataset class represents a collection of content objects and provides
 * methods to add and remove content objects. It also allows observers to
 * register and receive notifications when content objects are added or removed.
 */
public class Dataset {
    private List<Content> contents = new ArrayList<>();
    private List<Observer> playerobserver = new ArrayList<>();
    private List<Observer> viewerobserver = new ArrayList<>();
    
     /**
     * Adds a content object to the dataset and notifies registered observers.
     *
     * @param content The content object to be added.
     */
    public void add(Content content) {
        contents.add(content);
        notify(content.getCategory(),content);
        
    }

    /**
     * Removes an observer from the registered player and viewer observers list.
     *
     * @param observer The observer to be removed.
     */
    public void removeRegister(Observer observer)
    {
        
        playerobserver.remove(observer);
        viewerobserver.remove(observer);
    }

    /**
     * Registers an observer to receive notifications for specific content types.
     *
     * @param observer The observer to be registered.
     */
    public void register(Observer observer) {
        if (observer.getObserverTyype() == "viewer")
        {
            viewerobserver.add(observer);
        }
        else
        {
            playerobserver.add(observer);
        }
    }

     /**
     * Notifies the registered observers about the addition of a content object.
     *
     * @param category The category of the content object.
     * @param content  The content object added to the dataset.
     */
    private void notify(String category, Content content) {
        
        if(category=="video" || category=="audio")
        {
            for(Observer obs: playerobserver)
            {
                obs.update(content);
            }
        }
        else
        {
            for(Observer obs: viewerobserver)
            {
                obs.update(content);
            }
        }
            
        
    }

    /**
     * Notifies the registered observers about the removal of a content object.
     *
     * @param category The category of the content object.
     * @param content  The content object removed from the dataset.
     */
    private void notifyRemove(String category, Content content) {
        
        if(category=="video" || category=="audio")
        {
            for(Observer obs: playerobserver)
            {
                obs.remove(content);
            }
        }
        else
        {
            for(Observer obs: viewerobserver)
            {
                obs.remove(content);
            }
        }
            
        
    }

    /**
     * Retrieves the list of content objects in the dataset.
     *
     * @return The list of content objects.
     */
    public List<Content> getObjects()
    {
        return contents;
    }

    /**
     * Removes a content object from the dataset and notifies registered observers.
     *
     * @param deleteContent The content object to be removed.
     */
    public void remove(Content deleteContent)
    {
        if(contents.contains(deleteContent))
        {
            contents.remove(deleteContent);
            notifyRemove(deleteContent.getCategory(), deleteContent);
        }
        else
        {
            System.out.println("In the dataset does not have Content Object");
        }
    }
}

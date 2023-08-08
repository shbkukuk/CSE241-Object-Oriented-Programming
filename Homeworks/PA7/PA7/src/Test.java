public class Test {
    public static void main(String[] args) throws Exception {
        Dataset dataset = new Dataset();

        Player player1 = new Player("Player 1");
        Player player2 = new Player("Player 2");
        Viewer viewer1 = new Viewer("Viewer 1");
        Viewer viewer2 = new Viewer("Viewer 2");

        dataset.register(player1);
        dataset.register(player2);
        dataset.register(viewer1);
        dataset.register(viewer2);
        // Add content into dataset
        dataset.add(new Image("imagename1", "dimension info1", "other info1"));
        dataset.add(new Image("imagename2", "dimension info2", "other info2"));
        dataset.add(new Image("imagename3", "dimension info3", "other info3"));
        dataset.add(new Image("imagename4", "dimension info4", "other info4"));
        dataset.add(new Image("imagename5", "dimension info5", "other info5"));
        dataset.add(new Audio("audioname1", "duration1", "other info1"));
        dataset.add(new Audio("audioname2", "duration2", "other info2"));
        dataset.add(new Audio("audioname3", "duration3", "other info3"));
        dataset.add(new Video("videoname1", "duration1", "other info1"));
        dataset.add(new Video("videoname2", "duration2", "other info2"));
        dataset.add(new Video("videoname3", "duration3", "other info3"));
        dataset.add(new Text("textname1", "other info1"));
        dataset.add(new Text("textname2", "other info2"));
        dataset.add(new Text("textname3", "other info3"));
        
        int size =dataset.getObjects().size();
        System.out.println("size:" +size);
        // Show current playlist and viewlist
        player1.show_list();
        player2.show_list();
        viewer1.show_list();
        viewer2.show_list();

        // Play the currently playing object
        playable currentPlayable = player1.currently_playing();
        if (currentPlayable != null) {
            currentPlayable.info();
        }

        // View the currently viewing object
        nonplayable currentNonPlayable = viewer1.currently_viewing();
        if (currentNonPlayable != null) {
            currentNonPlayable.info();
        }

        // Delete an object from the dataset
        Content objectToDelete = dataset.getObjects().get(0);
        dataset.remove(objectToDelete);

        // Show updated playlist and viewlist
        player1.show_list();
        viewer1.show_list();
        viewer2.show_list();


        // Play next audio
        player1.next("audio");
        currentPlayable = player1.currently_playing();
        if (currentPlayable != null) {
            currentPlayable.info();
        }

        // Play next video
        player1.next("video");
        currentPlayable = player1.currently_playing();
        if (currentPlayable != null) {
            currentPlayable.info();
        }

        // View next image
        viewer1.next("image");
        currentNonPlayable = viewer1.currently_viewing();
        if (currentNonPlayable != null) {
            currentNonPlayable.info();
        }

        // View previous text
        viewer1.previous("text");
        currentNonPlayable = viewer1.currently_viewing();
        if (currentNonPlayable != null) {
            currentNonPlayable.info();
        }
    }
}

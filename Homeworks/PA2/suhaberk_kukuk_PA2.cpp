#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class menu{
    private:
        //RGB Data keep in 2D array
        vector<vector <int>> red;
        vector<vector <int>> blue;
        vector<vector <int>> green;
        //number of pixels for width and height 
        int width;
        int height;
        //Image format data
        string imageFormat;
        //Image File name  
        string imageName;
    public:
        int choose;
        //default constructor
        void mainMenu();
        //Menu Functions
        /*@brief Get input from user and call sub-menu*/
        void imageMenu();
        /*@brief Get input from user and call method*/
        void saveMenu();
        /*@brief Get input from user and call method*/
        void scriptMenu();
        /*@brief Get input from user and call method*/
        void convertGrayscale();
        //Helper Functions
        /*@brief Convert RGB to Grayscale */
        void grayScale();
        /*@brief Get input as String from user and read name of file*/
        void readFile();
        /*@brief Get input as String from user and call save file in directory*/
        void writeFile();

};

int main(){
    //Declaration menu class
    menu newmenu = menu();
    //Call MainMenu method
    newmenu.mainMenu();

}

void menu::mainMenu(){
    cout<<"MAIN MENU"<<endl;
    cout<<"0 - Exit\n"<<"1 - Open An Image(D)\n"<<"2 - Save Image Data(D)\n"
    <<"3 - Scripts"<<endl;
    //Get select menu from user.
    cin>>this->choose;
    //Call menu respect to action 
    switch (this->choose)
    {
    case 0:
        exit(1);
        break;
    case 1:
        this->imageMenu();
        break;
    case 2:
        this->saveMenu();
        break;
    case 3:
        this->scriptMenu();
    default:
        this->mainMenu();
        
    }
}
void menu::imageMenu(){
    int action;
    cout<<"0 - UP\n"<<"1 - Enter The Name Of The Image File"<<endl;
    //Get select menu from user.
    cin>>action;
    //Condition of actions
    if (action == 0){
        this->mainMenu();
    }
    else if (action==1)
    {
        readFile();
    }
    //Call imageMenu for showing menu again. 
    imageMenu();
    
}

void menu::saveMenu(){
    int action;
    cout<<"SAVE IMAGE DATA MENU"<<endl;
    cout<<"0 - UP\n"<<"1 - Enter A File Name"<<endl;
    //Get select menu from user.
    cin>>action;
    //Condition of actions 
    if (action == 0){
        this->mainMenu();
    }
    else if (action==1)
    {
        writeFile();
    }
    //Call saveMenu for showing menu again. 
    saveMenu();

}

void menu::scriptMenu(){
    int action;
    cout<<"SCRIPTS MENU"<<endl;
    cout<<"0 - UP\n"<<"1 - Convert To Grayscale(D) "<<endl;
    //Get select menu from user.
    cin>>action;
    //Condition of actions 
    if (action == 0){
        this->mainMenu();
    }
    else if (action==1)
    {
        convertGrayscale();
    }
    //Call scriptMenu for showing menu again. 
    scriptMenu();
}

void menu::convertGrayscale(){
    int action;
    cout<<"CONVERT TO GRAYSCALE MENU"<<endl;
    cout<<"0 - UP\n"<<"1 - Enter Coefficients For RED GREEN And BLUE Channels."<<endl;
    //Get select menu from user.
    cin>>action;
    //Condition of actions 
    if (action == 0){
        this->scriptMenu();
    }
    else if (action==1)
    {
       grayScale();
    }
    //Call convertGrayscale for showing menu again.  
    convertGrayscale();

}

void menu::readFile(){
    fstream image; // Input File
    //Get File Name
    cin>>imageName;
    //Open Image
    image.open(imageName);

    if(image.is_open()){
       
        int upperLimit; //it usually be 255
        //Set Header Data Of The ppm File
        image >> imageFormat >> width >> height >> upperLimit;

        //Set Widt of Pixels
        red.resize(width);
        blue.resize(width);
        green.resize(width);

        //Set Height of Every Column 
        for(int i = 0; i < width; i++){
            red[i].resize(height);
            blue[i].resize(height);
            green[i].resize(height);
        }

        //Write Values in Vector 
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++ ){
             image >> red[j][i] >> green[j][i] >> blue[j][i];
            }
        }
    }
    else 
        exit(0); // Execution for invalid output
    image.close();

    //Call imageMenu for showing menu again.  
    imageMenu();

}

void menu::writeFile(){
    string outputName; //Outut name for save file 
    ofstream newFile; // Output file
    cin>>outputName;
    //Open New File
    newFile.open(outputName);
    if(newFile.is_open()){
        //Write Header of ppm file
        newFile<<imageFormat<<endl
        <<width<<" "<<height<<endl
        <<255<<endl;
        //write the pixels to output file
        for(int i = 0; i < height; i++ ){
            for(int j = 0; j < width; j++){
                newFile << red[j][i] << " " << green[j][i] << " " << blue[j][i] << " ";
            }
            newFile << endl;
        }

    }
    else
        exit(0); // Execuaiton for Invalid Input
    newFile.close();
    //Call saveMenu for showing menu again.  
    saveMenu();
}

void menu::grayScale(){
    //Data : grayscale coeffients and RGB values
    double c_r =-1.0 ,c_g=-1.0 ,c_b=-1.0;
    double Red,Blue,Green;
    //Get grayscale coefficients
    while(c_r > 1 || c_r < 0 || c_g > 1 || c_g < 0 || c_b > 1 || c_b < 0 ){
        cin>>c_r>>c_g>>c_b;
    }
    //setting every pixels one by one
    for( int i = 0; i < height; i++ ){
        for( int j = 0; j < width; j++){
            //calculation of parameters
            Red = (int)(c_r*red[i][j] + c_g*green[i][j] + c_b*blue[i][j]);
            Green = (int)(c_r*red[i][j] + c_g*green[i][j] + c_b*blue[i][j]);
            Blue = (int)(c_r*red[i][j] + c_g*green[i][j] + c_b*blue[i][j]);
            
            //checking the parameters for rgb range and setting them accordingly
            //If channels(R,G,B) have bigger than 255, I set 255.
            if( Red <= 255 )
                red[i][j] = (int)Red;
            else
                red[i][j] = 255;

            if( Green <= 255 )
                green[i][j] = (int)Green;
            else
                green[i][j] = 255;
            
            if( Blue <= 255 )
                blue[i][j] = (int)Blue;
            else
                blue[i][j] = 255;
        }
    }  
    //Call convertGraysale for showing menu again.     
    convertGrayscale();
}
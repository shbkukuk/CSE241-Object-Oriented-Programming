#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct  dimension
{
    /* @brief		Returns true if points have same X, Y values
    * @param	p	Other point
    * @return		True if points are same, false otherwise
    */
	bool operator==(const dimension &p) const;
    /* @brief		Inserts point into output buffer
    * @param	out	Output buffer
    * @param	p	Point that will be inserted
    * @return		Returns given output buffer
    */
    friend ostream & operator<<(ostream &out, const dimension &p);
    
    /* @brief		Gets point from input buffer
    * @param	in	Input buffer
    * @param	p	Point that will be set
    * @return		Returns given input buffer
    */
    friend istream & operator>>(istream &in, dimension &p);
    int width;
    int height;
};

struct pixel{
	public:

		/* @brief		Initializes pixel as black (0, 0, 0)
		 */
		pixel();

		/* @brief		Initializes pixel with given R, G, and B values
		 * @param	_r	R value
		 * @param	_g	G value
		 * @param	_b	B value
		 */
		pixel(int _r, int _g, int _b);
		
		/* @brief			Sets pixel R, G, and B values to given pixel's, respectively
		 * @param	other	Point whose R, G, and B values will be inherited
		 */
		void operator=(const pixel &other);

		/* @brief		Inserts pixel into output buffer
		 * @param	out	Output buffer
		 * @param	p	Pixel that will be inserted
		 * @return		Returns given output buffer
		 */
		friend ostream & operator<<(ostream &out, const pixel &p);
		
		/* @brief		Gets pixel from input buffer
		 * @param	in	Input buffer
		 * @param	p	Pixel that will be set
		 * @return		Returns given input buffer
		 */
		friend istream & operator>>(istream &in, pixel &p);

		/* @brief			Returns writable reference to R, G, or B value for 0, 1, or 2 values of index, respectively
		 * @param	index	Index corresponding to R, G, or B value of pixel
		 * @return			Writable reference to R, G, or B value of pixel
		 */
		int & operator[](int index);
		
		/* @brief			Returns const reference to R, G, or B value for 0, 1, or 2 values of index, respectively
		 * @param	index	Index corresponding to R, G, or B value of pixel
		 * @return			Const reference to R, G, or B value of pixel
		 */
		const int & operator[](int index) const; 

		/* @brief			Adds pixels, returns sum
		 * @param	other	Other pixel
		 * @return			Sum of pixels
		 */
		pixel operator+(const pixel &other) const;

		/* @brief			Subtracts pixels, returns difference
		 * @param	other	Other pixel
		 * @return			Difference of pixels
		 */
		pixel operator-(const pixel &other) const;

		/* @brief			Sets pixel's values to given value if they are lesser
		 * @param	lower	Lower limit for pixel's values
		 * @return			Pixel after processed
		 */
		pixel & CapValuesLower(int lower);

		/* @brief			Sets pixel's values to given value if they are greater
		 * @param	lower	Upper limit for pixel's values
		 * @return			Pixel after processed
		 */
		pixel & CapValuesUpper(int upper);

		/* @brief			Sets pixel's values to given values if they are lesser or greater respectfully
		 * @param	lower	Lower limit for pixel's values
		 * @param	upper	Upper limit for pixel's values
		 * @return			Pixel after processed
		 */
		pixel & CapValues(int lower, int upper);
	
		int r;	// Red value of pixel
		int g;	// Green value of pixel
		int b;	// Blue value of pixel

};
class ppmImage
{
    public:
        /* @brief	Initializes as in the file with given file name
		 * @param	fileName	Name of ppm file
		 */
        ppmImage(const string &filename);

        /* @brief	Initializes with given dimensions and 255 as the upper limit for pixel values
		 * @param	size	    Size consisting of image's column and row dimensions respectively
		 */
        ppmImage (const dimension &size);

        /*  @brief  Initializes with given dimensions and 255 as upper limit.
        *   @param  size Size consisting of image's and row dimensions.
        */
        ppmImage(dimension &size);

        /* @brief Initializes with given dimensions and 255 as upper limit.
        *  @param size  Size consisting of image's and row dimensions.
        *  @param limit Limit of upper pixel value
        */
        ppmImage(dimension size,int limit);

        /* @brief	Initializes with 0 dimensions
		 */
        ppmImage();

        /*@brief  Set dimension of size
        */
        void setSize(dimension newSize);

        /*@brief  Set int value of max pixel value.
        */
        void setPixelValueLimit(int limit);

        /*  @brief read from directory
         *   @return if it works correctly return 1, otherwise 0 
         */
        int read(string filename);

        /*  @brief save to directory
         *   @return if it works correctly return 1, otherwise 0 
         */
        int save(string outputName) const;

        /*  @brief swap to chaennel respect chose channel
         *   @return if it works correctly return 1, otherwise 0 
         */
        int swapChannels(int swapChoise);

        /*  @brief change  to specific chosen pixels.
         */
        void changePixel(dimension dimension, pixel newPixel);

        /*  @brief swap to chaennel respect chose channel
         *   @return if it works correctly return 1, otherwise 0 
         */
        int GetPixelValueLimit();

        /*  @brief swap to chaennel respect chose channel
         *   @return Max pixl value.
         */
        int GetPixelValueLimit() const;

        /*  @brief swap to chaennel respect chose channel
         *   @return if it works correctly return 1, otherwise 0 
         */
        void Resize(dimension dimension);

        /*  @brief swap to chaennel respect chose channel
         *   @return if it works correctly return 1, otherwise 0 
         */
        pixel getPixel(dimension dimension);

        /*  @brief swap to chaennel respect chose channel
         *   @return if it works correctly return 1, otherwise 0 
         */
        dimension getSize() const;

        /*  @brief swap to chaennel respect chose channel
         *   @return if it works correctly return 1, otherwise 0 
         */
        vector<vector <pixel>> getVector();

        /*  @brief swap to chaennel respect chose channel
         *   @return if it works correctly return 1, otherwise 0 
         */
        vector<pixel> & operator[](int index);
		
		/* @brief			Returns const row of pixels at given index
		 * @param	index	Index of wanted row of pixels
		 * @return			Const vector of pixels that are treated as row of pixels of image at index
		 */
		const vector<pixel> & operator[](int index) const;

		/* @brief			Inherits values of given image
		 * @param	image	Image whose values will be inherited
		 */

        /* @brief			Returns sum of images
		 * @param	image	Other image
		 * @return			Sum of images
		 */
		ppmImage operator+(const ppmImage &image);

		/* @brief			Returns difference of images
		 * @param	image	Other image
		 * @return			Difference of images
		 */
		ppmImage operator-(const ppmImage &image);

		/* @brief			Prints image
		 * @param	out		Out stream
		 * @param	image	Printed image
		 * @return			Out stream
		 */
		friend ostream & operator<<(ostream &out, const ppmImage &image);

		/* @brief			Returns pixel value at given index
		 * @param	row		Row value of pixel
		 * @param	column	Column value of pixel
		 * @param	pIndex	Index of value of pixel 1 for R, 2 for G, and 3 for B
		 * @return			R, G, or B value of pixel
		 */
		int & operator()(int row, int column, int pIndex);
        /* @brief			Returns pixel value at given index
		 * @param	row		Row value of pixel
		 * @param	column	Column value of pixel
		 * @param	pIndex	Index of value of pixel 1 for R, 2 for G, and 3 for B
		 * @return			R, G, or B value of pixel
		 */
		const int & operator()(int row, int column, int pIndex) const;

    private:
        int pixelValueLimit;
        vector <vector<pixel>> pixels;
        dimension size;

};

//Standalone Functions

int read_ppm(const string source_ppm_file_name, ppmImage &destination_object);
int write_ppm(const string destination_ppm_file_name, const ppmImage &source_object);
int swap_channels(ppmImage &image_object_to_be_modified, int swap_choice);
ppmImage single_color(const ppmImage &source, int color_choice);
int test_addition(const string filename_image1, const string filename_image2, const string filename_image3);
int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3);
int test_print(const string filename_image1);


int main(int argc, char ** argv){

	if(argc > 3 ){	// Execute if and only if there are at least four arguments (executable name, choice number, name of first and second file)

	int choiceNumber;									// Argument number to execute corresponding process
		string ppmFileName1(argv[2]), ppmFileName2(argv[3]);	// File names

		choiceNumber =stoi(argv[1]);	// Convert argument to integer 

		ppmImage readPPMImage;		// Image of read file
		ppmImage processedPPMImage;	// Image that is the result of process

		// Execute corresponding process
		switch(choiceNumber){
			case 1:
				if(argc != 5) return 0;
				test_addition(ppmFileName1, ppmFileName2, argv[4]);
				break;
			case 2:
				if(argc != 5) return 0;
				test_subtraction(ppmFileName1, ppmFileName2, argv[4]);
				break;
			case 3:
				read_ppm(ppmFileName1, readPPMImage);
				swap_channels(readPPMImage, 2);
				write_ppm(ppmFileName2, readPPMImage);
				break;
			case 4:
				read_ppm(ppmFileName1, readPPMImage);
				swap_channels(readPPMImage, 3);
				write_ppm(ppmFileName2, readPPMImage);
				break;
			case 5:
				read_ppm(ppmFileName1, readPPMImage);
				processedPPMImage = single_color(readPPMImage, 1);
				write_ppm(ppmFileName2, processedPPMImage);
				break;
			case 6:
				read_ppm(ppmFileName1, readPPMImage);
				processedPPMImage = single_color(readPPMImage, 2);
				write_ppm(ppmFileName2, processedPPMImage);
				break;
			case 7:
				read_ppm(ppmFileName1, readPPMImage);
				processedPPMImage = single_color(readPPMImage, 3);
				write_ppm(ppmFileName2, processedPPMImage);
				break;
			default:
				std::cout << "Invalid choice number!\n";	// Inform if invalid choice number is entered
		}
	}

	return 0;
}

/* Standalone Functions Implementaion*/
int read_ppm(const string source_ppm_file_name, ppmImage &destination_object){
	return destination_object.read(source_ppm_file_name);	// Execute Read function of the image with given file name
}

int write_ppm(const string destination_ppm_file_name, const ppmImage &source_object){
	return source_object.save(destination_ppm_file_name);	// Execute Write function of the image with given file name
}

int swap_channels(ppmImage &image_object_to_be_modified, int swap_choice){
	// Execute SwapPixelChannels function of image with given swap choice
	return image_object_to_be_modified.swapChannels(swap_choice);
}

ppmImage single_color(const ppmImage &source, int color_choice){
	dimension dimensions = source.getSize();
    int limit = source.GetPixelValueLimit();						// Dimensions of the source image
	ppmImage copy(dimensions,limit);	// Initialized as blank image with dimensions and pixel value limit of source image

    dimension tempDimension;
	for(int i = 0; i < dimensions.width; ++i){						// For every row
		for(int j = 0; j < dimensions.height; ++j){
            copy(i,j,color_choice) = source(i,j,color_choice);
            				// For every column

        }	// Set corresponding pixel value to source image's														

	}

	return copy;	// Return new image
}

int test_addition(const string filename_image1, const string filename_image2, const string filename_image3){
	ppmImage image1(filename_image1), image2(filename_image2);	
	int  sumImage = image1.getSize().height + image2.getSize().height;					
	return sumImage;				
}

int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3){
	ppmImage image1(filename_image1), image2(filename_image2);	
	ppmImage sumImage = image1 - image2;						
	return write_ppm(filename_image3, sumImage);				
}

int test_print(const string filename_image1){
	ppmImage image(filename_image1);	
	cout << image;
	return 1;				
}

/**Dimension */
bool dimension::operator==(const dimension &p) const{
	return  width== p.width && height == p.height;
}
ostream & operator<<(ostream &out, const dimension &p){
	out << p.width << " " << p.height;	
	return out;					
}

istream & operator>>(istream &in, dimension &p){
	in >> p.width >> p.height;	
	return in;
}
/*Pixels Implementation*/

pixel::pixel() 
{
	pixel(0,0,0);
}


pixel::pixel(int _r, int _g, int _b) 
{
	this->r = _r;
	this->g = _g;
	this->b = _b;
}

ostream & operator<<(ostream &out, const pixel &p){
	out << p.r << " " << p.g << " " << p.b;	// Insert as "R G B"
	return out;
			
}
istream & operator>>(istream &in, pixel &p){
	in >> p.r >> p.g >> p.b;	// Get first R then G then B values
	return in;
}
void pixel::operator=(const pixel &other){
	r = other.r;
	g = other.g;
	b = other.b;
}

pixel pixel::operator+(const pixel &other) const{
	return pixel(r + other.r, g + other.g, b + other.b);
}

pixel pixel::operator-(const pixel &other) const{
	return pixel(r - other.r, g - other.g, b - other.b);
}


pixel & pixel::CapValuesLower(int lower){
	r = r < lower ? lower : r;	// If lower than lower limit than set to limit
	g = g < lower ? lower : g;	// If lower than lower limit than set to limit
	b = b < lower ? lower : b;	// If lower than lower limit than set to limit
	return *this;
}

pixel & pixel::CapValuesUpper(int upper){
	r = r > upper ? upper : r;	// If greater than upper limit than set to limit
	g = g > upper ? upper : g;	// If greater than upper limit than set to limit
	b = b > upper ? upper : b;	// If greater than upper limit than set to limit
	return *this;
}

pixel & pixel::CapValues(int lower, int upper){
	CapValuesLower(lower);
	CapValuesUpper(upper);
	return *this;
}

int & pixel::operator[](int index){
	switch(index){
		case 0:
			return r;
		case 1:
			return g;
		case 2:
			return b;
		default:
			// Raise error if index is other than 0, 1, and 2
			throw "Pixel index is out of bounds!";
	}
}

const int & pixel::operator[](int index) const{
	switch(index){
		case 0:
			return r;
		case 1:
			return g;
		case 2:
			return b;
		default:
			// Raise error if index is other than 0, 1, and 2
			throw "Pixel index is out of bounds!";
	}
}

/*ppmImage Implementation*/
ppmImage::ppmImage()
{
    //create ppmImage which has 0 number of pixels
    dimension size = {0,0};
    this->setPixelValueLimit(255);
    this->setSize(size);

}

ppmImage::ppmImage(const string &filename)
{
    read(filename);
}

ppmImage::ppmImage (const dimension &size)
{
    pixel zeros = {0 , 0, 0};
    int row = size.width;
    int column = size.height;

    for(int i = 0; i < row; i++)
    {
        pixels[i].resize(column);
        for (int j = 0; j < column; j++)
        {
            pixels[i][j] = zeros;
        }
    }
}

ppmImage::ppmImage (dimension &size)
{
    pixel zeros = {0 , 0, 0};
    int row = size.width;
    int column = size.height;

    for(int i = 0; i < row; i++)
    {
        pixels[i].resize(column);
        for (int j = 0; j < column; j++)
        {
            pixels[i][j] = zeros;
        }
    }
}
ppmImage::ppmImage(dimension size,int limit)
{
    this->setPixelValueLimit(255);
    this->setSize(size);
}



void ppmImage::setPixelValueLimit(int limit)
{
    this->pixelValueLimit = limit;
}

void ppmImage::setSize(dimension newSize)
{
    this->size = newSize;
}



void ppmImage::changePixel(dimension dimension, pixel newPixel)
{
    int w = dimension.width;
    int h = dimension.height;
    this->pixels[w][h] = newPixel;
}

int ppmImage::GetPixelValueLimit()
{
    return this->pixelValueLimit;
}
int ppmImage::GetPixelValueLimit() const
{
    return pixelValueLimit;
}
pixel ppmImage::getPixel(dimension dimensions)
{
    int w = dimensions.width;
    int h = dimensions.height;
    return pixels[w][h];
}
dimension ppmImage::getSize() const
{
    return size;
}
vector<vector <pixel>> ppmImage::getVector()
{
    return pixels;
}

void ppmImage::Resize(dimension dimensions)
{
    pixels.resize(dimensions.width);	// Resize vector of vectors of pixels to new row dimension

	for(int i = 0; i < dimensions.height; ++i)	// For evert vector of pixels
		pixels[i].resize(dimensions.width);
}

int ppmImage::read(string fileName){
	
	int readSuccesful = 0;		// Is read successfull

	ifstream ppmImage(fileName);	// Open file

	char charBuffer;	// Character buffer
	int intBuffer;		// Integer Buffer

	ppmImage >> charBuffer;	// Read first character

	if(charBuffer == 'P'){		// Continue only if it's 'P'
		ppmImage >> intBuffer;	// Read first integer

		if(intBuffer == 3){		// Continue only if it's 3
			ppmImage >> size.width>>size.height;	// Get dimensions specified in the file
			
			pixels.resize(size.width);	// Resize main vector (row vector)

			ppmImage >> pixelValueLimit;	// Get limit for pixel values specified in the file

			pixel white(pixelValueLimit, pixelValueLimit, pixelValueLimit);	// White pixel
			pixel black(0, 0, 0);											// Black pixel
			pixel tempPixel;												// Read pixel

			readSuccesful = 1;	// Set to successful for now

			for(int i = 0; i < size.width; ++i){	// For every row

				pixels[i].resize(size.height);	// Resize pixel vector (column vector)

				for(int j = 0; j < size.width; ++j){	// For every column
					ppmImage >> tempPixel;	// Read pixel
					
					// If any of pixel's value is greater than upper limit or lesser than 0 or file is ended before 
					// image is completed
					if(tempPixel.b>255 || tempPixel.g>255 ||tempPixel.b){
						readSuccesful = 0;	// Read failed
						break;				// Stop
					}
					
					// else read pixel is valid so assign
					pixels[i][j] = tempPixel;
				}

				// If process failed, stop 
				if(!readSuccesful) break;
			}
		}
	}

	ppmImage.close();	// Close the file

	return readSuccesful;
}

int ppmImage::save(string outputName) const
{
    int writeSuccessful = 1;	// Is write successful

	ofstream ppmFile(outputName);	// Open file

	ppmFile << *this;	

	ppmFile.close();	// Close file

	return writeSuccessful;
}

int ppmImage::swapChannels(int swapChoise)
{
    int swapSuccesfull = 0;

   for(int i = 0; i<size.width;i++){
        for (int j = 0; j <size.height ; j++)
        {
            pixel tempPixel = pixels[i][j];
            int temp = 0;
            switch (swapChoise)
            {
            case 1:
                swapSuccesfull = 1;
                temp = tempPixel.r;
                tempPixel.r = tempPixel.g;
                tempPixel.g = temp;
                break;
            case 2:
                swapSuccesfull = 1;
                temp = tempPixel.r;
                tempPixel.r = tempPixel.b;
                tempPixel.b = temp;
                break;
            case 3:
                swapSuccesfull = 1;
                temp = tempPixel.g;
                tempPixel.g = tempPixel.b;
                tempPixel.b = temp;
                break;
            default:
                return swapSuccesfull;
            }
        }

    }

    return swapSuccesfull;
}
vector<pixel> & ppmImage::operator[](int index){
	return pixels[index];	// Return row of pixels at index
}

const vector<pixel> & ppmImage::operator[](int index) const{
	return pixels[index];	// Return row of pixels at index
}

ppmImage ppmImage::operator+(const ppmImage &image){
	ppmImage sumImage;	// Sum of images

	// Add only if dimensions are same
	if(size==image.size){
		dimension newDimension = image.getSize();
        sumImage.Resize(newDimension);	// Resize sum image to files' dimensions

		// It is said pixel upper limits will be same but if not set sum image's to greater one
		int pixelMaxValue = 255;
		sumImage.setPixelValueLimit(pixelMaxValue);

		pixel sumPixel;	// Sum of each pixel

		// For every pixel
		for(int i = 0; i <newDimension.width ; ++i){
			for(int j = 0; j < newDimension.height; ++j){
				sumPixel = pixels[i][j] + image[i][j];						// Add two corresponding pixels together
				sumImage[i][j] = sumPixel.CapValuesUpper(pixelMaxValue);	// Cap it under the max value, then set sum image's to it
			}
		}
	}

	return sumImage;
}


ppmImage ppmImage::operator-(const ppmImage &image){
	ppmImage differenceImage;	// Resulting image

	// Continue only if sizes are same
	if(size == image.size){
		differenceImage.Resize(size);	// Resize to the correct size

		// It is said pixel upper limits will be same but if not set sum image's to greater one
		int pixelMaxValue = 255;
		differenceImage.setPixelValueLimit(pixelMaxValue);

		pixel differencePixel;	// Difference of each pixel

		// For every pixel
		for(int i = 0; i < size.width; ++i){
			for(int j = 0; j < size.height; ++j){
				differencePixel = pixels[i][j] - image[i][j];				// Subtract pixels
				differenceImage[i][j] = differencePixel.CapValuesLower(0);	// Make sure rgb values are greater than or equal to 0
			}
		}
	}

	return differenceImage;
}

ostream & operator<<(ostream &out, const ppmImage &image)
{

    // Write header
	out << "P3\n"
		<< image.size << endl
		<< image.pixelValueLimit << endl;
	
	// Write pixel values
	for(int i = 0; i < image.size.width; ++i){
		for(int j = 0; j < image.size.height; ++j)
			out << image[i][j] << "  ";
		out << endl;
	}

	return out;

}


int & ppmImage::operator()(int row, int column, int pIndex){
	return pixels[row][column][pIndex - 1];
}

const int & ppmImage::operator()(int row, int column, int pIndex) const{
	return pixels[row][column][pIndex - 1];
}
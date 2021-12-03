//Jacob Isber
//Lab10
//Revision 1.o
//I attempted this lab and had little idea on how exactly to do the read function. Very sorry, this is the first lab that I didn't really know how to do. I would like to see the code running one day.
//I was at the programming clinic Monday and Tuesday, the TA's tried to help but were unfortantly very busy.
//I honestly do not know if my other functions even work.



#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


struct Pixel {
	
	unsigned int R, G, B;

};
//This is my pixel struct.

class Picture {
	
	private:
		vector<Pixel>pixels_struct = {};
		unsigned int width, height, maxIntensity;


	public: 
		Picture();
	//	static string error;
		Pixel get_pixel(unsigned int row, unsigned int column) const;
		Pixel &get_pixel(unsigned int row, unsigned int column);
		void set_pixel(unsigned int row, unsigned int column, const Pixel &pixleset);
		void invert();
		void flip_x();
		void flip_y();
		bool read_input(istream &in);
		void write_output(ostream &out);

};
//This is the Picture class.

int main(int argc, char *argv[]) {
/*	ifstream fin(argv[1]);
	ofstream fout;
	bool temp_TF;
	string change;

	if((argc != 3) && (argc != 4)) {
		cout << "Not enough arguments!" << endl;
		return 3;
	}

	if(argc == 4) {
		change = argv[3];
		change = change[0];
	}
	else {
		change = "0";
	}
	fin.open(argv[1]);
	Picture picture;
//	temp_TF = picture.read_input(fin);

*/
return 0;
}
//This is my int main. I attempted to try it, but it was impossible to do without my read function.

Picture::Picture() {
	width = 0;
	height = 0;
	maxIntensity = 0;
}
//This sets the values = to 0.

Pixel Picture::get_pixel(unsigned int row, unsigned int column) const {
	
	Pixel pixeloutput =  pixels_struct.at( width * row + column);
	return pixeloutput;

}
//This is the scope for the get_pixle


Pixel& Picture::get_pixel(unsigned int row, unsigned int column) {
	
	Pixel &pixeloutput =  pixels_struct.at( width * row + column);
	return pixeloutput;
}
//This is the scope for the get_pixle when passed by reference

void Picture::set_pixel(unsigned int row, unsigned int column, const Pixel &pixleset) {
	get_pixel(row, column) = pixleset;
}
//This is scope for set_pixle.

void Picture::invert() {
	Pixel Temp;
	for(unsigned int i = 0; i < height; i++) {
		for(unsigned int j = 0; j < width; j++) {
			Temp = get_pixel(i,j);
			Temp.R -= maxIntensity;
			Temp.G -= maxIntensity;
			Temp.B -= maxIntensity;
			set_pixel(i,j,Temp);
			
		}
	}
}
//This is the invert definiton.

void Picture::flip_x() {	
	Pixel Temp_Top, Temp_Bottom;
	for(unsigned int i = 0; i < width; i++) {
		for(unsigned int j = 0; j < height/2; j++) {
			Temp_Top = get_pixel(i, j);
			Temp_Bottom = get_pixel(height - i - 1, j);
			set_pixel(i, j, Temp_Bottom);
			set_pixel (height - i - 1, j, Temp_Top);

		}
	}
}
//This is the flip function. I honestly have no idea if this works, and had no way to test it. I did receive help with the flip y and x from a TA.

void Picture::flip_y() {
	Pixel Temp_Left, Temp_Right;
	for(unsigned int i = 0; i < width/2; i++) {
		for(unsigned int j = 0; j < height; j++) {
			Temp_Left = get_pixel(i,j);
			Temp_Right = get_pixel(i,width - j - 1);
			set_pixel(i, j, Temp_Right);
			set_pixel(i, width - j - 1, Temp_Left);

		}
	}
}

//This is the flip function. I honestly have no idea if this works, and had no way to test it.
	

/*bool Picture::read_input(istream &in) {
	string pixleLine, fileType;
	stringstream getstring;
	if(in.good()) {
		while(getline(in, pixleLine)) {
			if(pixleLine[0] =="#") {
				continue;
			}

				if(pixleLine[0] != "P3") {
					return false;
				}
				else {
					break;
				}
			}
			while(getline(in, pixleLine) {
				
				if(pixleLine[0] =="#") {
					continue;
			}
			getstring.str(pixleLine);

			//	if(pixleLine == "P3") {
				pixleLine >> width >> height;
				break;
			//	}
				
			}
			while(getline(in, pixleLine) {

				if(pixleLine[0] == "#") {
					continue;
				}
				getstring.str(pixleLine);

				pixleLine >> maxIntensity;
				break;
			}
			while(getline(in, pixleLine) {
				if(pixleLine[0] == "#") {
					continue;
				}
				getstring.str(pixleLine);





			}

		}
	}
}
*/
//This is my attempted read function. I think I was on the right track but I could not figure it out for the rest of my life.
void Picture::write_output(ostream &out) { 
	Pixel NewPixel;
	if(out.good()) {
		out << "P3" << endl;
		out << width << height << endl;
		out << maxIntensity << endl;
		for(unsigned int i = 0; i < height; i++) {
			for(unsigned int j = 0; i < width; j++) {
				NewPixel = get_pixel(i, j);
				out << NewPixel.R << NewPixel.G << NewPixel.B << endl;
			}
		}
	cout << "Image has been successfully modified" << endl;
	 }
	else {
		cout << "Image could not be modified" << endl;
	}
}
//This is my write function. Again no way to test it, I just literally followed the instructions on canvas. 



#include <iostream>
#include <vector>
#include "lodepng.h"

std::vector< unsigned char > outputData;

void writeAtLocation( int x, int y, int z, unsigned char r, unsigned char g, unsigned char b ) {
	int index = ( x + ( 512 * y ) + ( 512 * 512 * z ) ) * 4;
	outputData[ index + 0 ] = r;
	outputData[ index + 1 ] = g;
	outputData[ index + 2 ] = b;
	outputData[ index + 3 ] = 255;
}

void loadImageAndPopulateBuffer( int image ) {
	// load the image
	unsigned imageWidth, imageHeight, error;
	std::vector< unsigned char > inputImageData;
	std::string filename = std::string("./") + std::to_string( image ) + std::string(".png");
	error = lodepng::decode( inputImageData, imageWidth, imageHeight, filename.c_str() );
	if ( error ) {
		std::cout << "decode error during load(\" " + filename + " \") " << error << ": " << lodepng_error_text( error ) << std::endl;
		return;
	}

	// put it in the buffer
	for ( unsigned x = 0; x < imageWidth; x++ ) {
		for ( unsigned y = 0; y < imageHeight; y++ ) {
			int index = ( x + imageWidth * y ) * 4;
			writeAtLocation( x, y, image, inputImageData[ index ], inputImageData[ index + 1 ], inputImageData[ index + 2 ] );
		}
	}
}

void outputFinishedData() {
	// save the block data
	std::cout << "writing image... ";
	unsigned error = lodepng::encode( std::string( "froggeSection.png" ).c_str(), outputData, 512, 512 * 512 );
	if ( error ) {
		std::cout << "encode error during save of output " << error << ": " << lodepng_error_text( error ) << std::endl;
	} else {
		std::cout << "done." << std::endl;
	}
}

int main( int argc, char const *argv[] ) {
	outputData.resize( 512 * 512 * 512 * 4 ); // size of 512 block

	for ( int i = 0; i <= 136; i++ ) {
		loadImageAndPopulateBuffer( i );
	} // get the current slice and put it in the buffer

	outputFinishedData(); // write result

	return 0;
}

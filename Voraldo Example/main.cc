#include <iostream>
#include <vector>
#include "lodepng.h"

enum layer {
	COLOR			= 0,
	BLOOD			= 1,
	BRAIN			= 2,
	DUODENUM	= 3,
	EYERETINA	= 4,
	EYES			= 5,
	EYEWHITE	= 6,
	HEART			= 7,
	ILEUM			= 8,
	INTESTINE	= 9,
	KIDNEY		= 10,
	LIVER			= 11,
	LUNG			= 12,
	MUSCLE		= 13,
	NERVES		= 14,
	SKELETON	= 15,
	SPLEEN		= 16,
	STOMACH		= 17
};

#define NUM_LAYERS 18

std::vector< unsigned char > outputData;
std::vector< unsigned char > outputDataFalseColor;

void writeAtLocation( int x, int y, int z, unsigned char r, unsigned char g, unsigned char b, unsigned char a ) {
	int index = ( x + ( 512 * y ) + ( 512 * 512 * z ) ) * 4;

	if ( x < 0 || x >= 512 || y < 0 || y >= 512 || z < 0 || z >= 512 ) {
		return; // out of bounds
	}

	outputData[ index + 0 ] = r;
	outputData[ index + 1 ] = g;
	outputData[ index + 2 ] = b;
	outputData[ index + 3 ] = a;
}

void loadImageAndPopulateBuffer( int image ) {
	// load the image
	unsigned imageWidth[ NUM_LAYERS ], imageHeight[ NUM_LAYERS ], error;
	std::vector< unsigned char > inputImageData [ NUM_LAYERS ];

	for ( int i = 0; i < NUM_LAYERS; i++ ) {
		std::string filename;
		switch ( i ) {
			case COLOR: 		filename = std::string( "Color Data (PNG)/" ) + std::to_string( image + 1 ) + std::string( ".png" ); break;
			case BLOOD: 		filename = std::string( "Organ System Masks (PNG)/Blood/" ) + std::to_string( image ) + std::string( ".png" ); break;
			case BRAIN: 		filename = std::string( "Organ System Masks (PNG)/Brain/" ) + std::to_string( image ) + std::string( ".png" ); break;
			case DUODENUM: 	filename = std::string( "Organ System Masks (PNG)/Duodenum/" ) + std::to_string( image ) + std::string( ".png" ); break;
			case EYERETINA: filename = std::string( "Organ System Masks (PNG)/EyeRetina/" ) + std::to_string( image ) + std::string( ".png" ); break;
			case EYES: 			filename = std::string( "Organ System Masks (PNG)/Eyes/" ) + std::to_string( image ) + std::string( ".png" ); break;
			case EYEWHITE: 	filename = std::string( "Organ System Masks (PNG)/EyeWhite/" ) + std::to_string( image ) + std::string( ".png" ); break;
			case HEART: 		filename = std::string( "Organ System Masks (PNG)/Heart/" ) + std::to_string( image ) + std::string( ".png" ); break;
			case ILEUM: 		filename = std::string( "Organ System Masks (PNG)/Ileum/" ) + std::to_string( image ) + std::string( ".png" ); break;
			case INTESTINE:	filename = std::string( "Organ System Masks (PNG)/Intestine/" ) + std::to_string( image ) + std::string( ".png" ); break;
			case KIDNEY: 		filename = std::string( "Organ System Masks (PNG)/Kidney/" ) + std::to_string( image ) + std::string( ".png" ); break;
			case LIVER: 		filename = std::string( "Organ System Masks (PNG)/Liver/" ) + std::to_string( image ) + std::string( ".png" ); break;
			case LUNG: 			filename = std::string( "Organ System Masks (PNG)/Lung/" ) + std::to_string( image ) + std::string( ".png" ); break;
			case MUSCLE: 		filename = std::string( "Organ System Masks (PNG)/Muscle/" ) + std::to_string( image ) + std::string( ".png" ); break;
			case NERVES: 		filename = std::string( "Organ System Masks (PNG)/Nerves/" ) + std::to_string( image ) + std::string( ".png" ); break;
			case SKELETON: 	filename = std::string( "Organ System Masks (PNG)/Skeleton/" ) + std::to_string( image ) + std::string( ".png" ); break;
			case SPLEEN: 		filename = std::string( "Organ System Masks (PNG)/Spleen/" ) + std::to_string( image ) + std::string( ".png" ); break;
			case STOMACH: 	filename = std::string( "Organ System Masks (PNG)/Stomach/" ) + std::to_string( image ) + std::string( ".png" ); break;
			default: break;
		}

		error = lodepng::decode( inputImageData[ i ], imageWidth[ i ], imageHeight[ i ], filename.c_str() );
		if ( error ) {
			std::cout << "decode error during load(\" " + filename + " \") " << error << ": " << lodepng_error_text( error ) << std::endl;
			return;
		}
	}



	// put it in the buffer
	for ( unsigned x = 0; x < imageWidth[ COLOR ] && x < 512; x++ ) {
		for ( unsigned y = 0; y < imageHeight[ COLOR ] && y < 512; y++ ) {
			int index = ( x + imageWidth[ COLOR ] * y ) * 4;

			// logic for applying the masks
			// if ( inputImageData[ MUSCLE ][ ( x + imageWidth[ MUSCLE ] * y ) * 4 ] == 255 ) {
			// 	// writeAtLocation( x, y, image, inputImageData[ COLOR ][ index ], inputImageData[ COLOR ][ index + 1 ], inputImageData[ COLOR ][ index + 2 ], 100 );
			// 	writeAtLocation( x, y, image, 128, 64, 64, 100 );
			// }

			if ( inputImageData[ SKELETON ][ ( x + imageWidth[ SKELETON ] * y ) * 4 ] == 255 ) {
				// writeAtLocation( x, y, image, inputImageData[ COLOR ][ index ], inputImageData[ COLOR ][ index + 1 ], inputImageData[ COLOR ][ index + 2 ], 200 );
				writeAtLocation( x, y, image, 164, 164, 164, 200 );
			}

			// if ( inputImageData[ EYES ][ ( x + imageWidth[ EYES ] * y ) * 4 ] == 255 ) {
			// 	// writeAtLocation( x, y, image, inputImageData[ COLOR ][ index ], inputImageData[ COLOR ][ index + 1 ], inputImageData[ COLOR ][ index + 2 ], 200 );
			// 	writeAtLocation( x, y, image, 64, 100, 164, 128 );
			// }

			if ( inputImageData[ NERVES ][ ( x + imageWidth[ NERVES ] * y ) * 4 ] == 255 ) {
				// writeAtLocation( x, y, image, inputImageData[ COLOR ][ index ], inputImageData[ COLOR ][ index + 1 ], inputImageData[ COLOR ][ index + 2 ], 200 );
				writeAtLocation( x, y, image, 164, 164, 32, 200 );
			}

			if ( inputImageData[ BLOOD ][ ( x + imageWidth[ BLOOD ] * y ) * 4 ] == 255 ) {
				// writeAtLocation( x, y, image, inputImageData[ COLOR ][ index ], inputImageData[ COLOR ][ index + 1 ], inputImageData[ COLOR ][ index + 2 ], 200 );
				writeAtLocation( x, y, image, 230, 64, 32, 200 );
			}

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
	outputDataFalseColor.resize( 512 * 512 * 512 * 4 );

	for ( int i = 0; i < 136; i++ ) {
		loadImageAndPopulateBuffer( i );
	} // get the current slice and put it in the buffer

	outputFinishedData(); // write result

	return 0;
}

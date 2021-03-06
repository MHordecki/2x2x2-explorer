#ifndef _222CUBE_H
#define _222CUBE_H

#include <stdint.h>
#include <stdio.h>

/*********************
 *
 * 2x2x2 cube representation
 *
 * for Explorer
 *
 * by Michal Hordecki
 *
 *********************/

/************
 * Cube representation structure:
 *
 * There are 5 bits, at different positions, dedicated to each position on the 2x2x2.
 * For each position, there are 2 pieces of information stored:
 *
 * - Which cubie is in this position? (1 of 8 = 3 bits)
 * - What's the orientation of this cubie? (1 of 3 = 2 bits)
 *
 * Which totals in 5 bit each and 40 for the whole cube.
 * In each such group orientation info comes first.
 *
 * First criterion is probably self explanatory (see #defs below), but for
 * second I think there should be some kind of clarifying:
 * 
 * Corner orientation can be one of these three types:
 *
 * 0 - facing U/D face
 * 1 - facing F/B face
 * 2 - facing R/L face
 *
 * 
 *
 */

//Corner offsets
#define UFR 0
#define URB 5
#define UBL 10
#define ULF 15

#define DRF 20
#define DFL 25
#define DLB 30
#define DBR 35

// Cubies
#define CUFR 0
#define CURB 1
#define CUBL 3
#define CULF 2

#define CDRF 4
#define CDFL 6
#define CDLB 7
#define CDBR 5

//Orientations
#define orientUD 0LL
#define orientFB 1LL
#define orientRL 2LL

namespace Explorer
{
	/**
	 * Representation of a single cube state. Refer to
	 * the Manual for more.
	 */
	class Cube
	{
		public:
			uint64_t corners;

			/**
			 * Sets a single position. Use it unless
			 * you want to mess with bit operations.
			 * 
			 * @param slot Position to be set.
			 * @param cubie Cubie on this position.
			 * @param orient Orientation of the cube.
			 *
			 * @see Explorer::Mask
			 */

			void set(int slot, uint64_t cubie, uint64_t orient);


			/**
			 * Prints single bits of a state to the standard output.
			 * Bits are printed in little endian format (i.e. the least
			 * important bit comes first).
			 */
			void strip();

	};

	typedef Cube (*MovePtr)(const Cube&);

	/**
	 * A structure that wraps move functions, providing
	 * useful informations.
	 */
	struct Move
	{
		/// Function pointer.
		MovePtr fun;

		// Name of the move.
		const char *name;

		// Internal use
		int index;
	};

	Cube cube_ideal();

	bool operator==(const Cube &a, const Cube &b);

	bool operator<(const Cube &a, const Cube &b);

	Cube moveR(const Cube &state);
	Cube moveRp(const Cube &state);

	Cube moveU(const Cube &state);
	Cube moveUp(const Cube &state);

	Cube moveF(const Cube &state);
	Cube moveFp(const Cube &state);

	Cube moveL(const Cube &state);
	Cube moveLp(const Cube &state);

	Cube moveD(const Cube &state);
	Cube moveDp(const Cube &state);

	Cube moveB(const Cube &state);
	Cube moveBp(const Cube &state);

}

#endif

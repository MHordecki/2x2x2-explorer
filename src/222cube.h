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

typedef struct
{
	uint64_t corners;
} Cube;

typedef Cube (*MovePtr)(const Cube&);
struct Move
{
	MovePtr fun;
	const char *name;
	int index;
};

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
#define CUBL 2
#define CULF 3

#define CDRF 4
#define CDFL 5
#define CDLB 6
#define CDBR 7

//Orientations
#define orientUD 0
#define orientFB 1
#define orientRL 2

// Helper functions

//Trigger bit
#define trig(x, y) (x) ^= (((uint64_t)1)<<(uint64_t)(y))

//Read bit
#define bitread(x, y) ((x) & (((uint64_t)1)<<((uint64_t)(y))))

//Read corner orientation (check for 0/ check for 1/ check for 2)
#define rOC2(x, y) ((x) & (1<<(y+1)))
#define rOC1(x, y) ((x) & (1<<(y)))
#define rOC0(x, y) (!(rOC1((x), (y)) | rOC2((x), (y))))
#define rOC(x, y) (((x) & (3<<(y)))>>(y))

// Some stuff

#define corner_compose(cubie, orient) ((uint64_t) (((uint64_t)(cubie) << 2) | (orient)))

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

#endif

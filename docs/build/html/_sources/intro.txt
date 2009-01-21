**************
Fundamentals
**************

:Author: Michal Hordecki
:Release: |release|
:Date: |today|

2x2x2 Explorer is a programming library written in C++ language.
Following assumptions are made:

  * You can program in C++.
  * You understand bit operations and bit arithmetic.
  * You know basics of cube theory (cubies, orientations, and so on).

This document will bring you the fundamentals of the Explorer.

.. contents::


---------------------
Cube representation
---------------------

============
Cube state
============

First thing to learn is how is a cube state represented in a memory.

2x2x2 Explorer favors performance over beauty. Instead of using more human-friendly representation,
such as array of cubies and their positions, which is fairly slow, Explorer represents a cube using
single 64-bit integer value.

Cube state consists of eight corners, each in it's own, distinct position, and each having one of the
three possible orientations. 

Instead of storing information about *where* certain cubie is positioned, Explorer stores information
about *which* cubie is placed in certain positions. Each such chunk of information is composed of:

  * Cubie index that is placed in given position (8 possibilities)
  * Orientation of this piece (3 possibilities)

Such chunk can be then stored in **5 bits** (3 bits for cubie, 2 bits for orientation). There are
8 positions on the Pocket Cube. The whole cube can be stored, then, in 40 bits (which is really a
64-bit long long due to alignment). First position is stored at position 0, second at 5, and so on
(remember, we're talking about bit positions there).

Order in which positions are represented (excerpt from ``222cube.h``)::

  //Corner offsets
  #define UFR 0
  #define URB 5
  #define UBL 10
  #define ULF 15
  
  #define DRF 20
  #define DFL 25
  #define DLB 30
  #define DBR 35

First two bits of each chunk is used for orientation, remaining three - for cubie index::

  // Cubies
  #define CUFR 0
  #define CURB 1
  #define CUBL 2
  #define CULF 3
  
  #define CDRF 4
  #define CDFL 5
  #define CDLB 6
  #define CDBR 7

Orientation is represented in the following fashion:

  0 - top/bottom sticker is facing up/down.
  1 - top/bottom sticker is facing front/back.
  2 - top/bottom sticker is facing left/right.

In 2x2x2 Explorer, declare cube state as :ctype:`Cube` object. For historic reasons it's implemented
as ``int64_t`` packed in a C structure.

.. seealso::

  Function :func:`Explorer.strip`
    Prints cube state in human-readable format.

  Function :func:`Explorer.cube_ideal`
    In order to get a representation for the solved state.
  
  :ref:`idioms-bits`
    Tips and tricks when operating with bit values.

=======
Moves
=======

In order to change the cube state, some moves must be applied. 2x2x2 Explorer defines them as follows::

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

As you can see, move methods don't modify given cube state, but generate a new one instead.

In practice, only {R, Rp, U, Up, F, Fp} are used. Why?

Pocket Cube has no fixed centers. There are no 'fixed' points that other pieces can be compared with.
3x3x3 Cube, for example, has six fixed pieces - the centers (center stickers on each side). Such move
sequence as *R L'* yields therefore a different cube state.

In 2x2x2, hovewer, *R L'* does not change the state. It's still the same. 

Given these circumstances, 2x2x2 Explorer 'artificially' creates such a 'fixed' point - the DBL cubie.
Note that you can't move this cubie with moves only from {R, Rp, U, Up, F, Fp}. 

Though not obvious at the first glance, every 2x2x2 case can be solved using only these moves, provided
the DBL cubie is in it's place, correctly oriented.



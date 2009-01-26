#ifndef _MASK_H
#define _MASK_H

#include "222cube.h"

#define MASK_ANY 0
#define MASK_R 1
#define MASK_U 2
#define MASK_F 4
#define MASK_L 8
#define MASK_D 16
#define MASK_B 32

namespace Explorer
{
	/**
	 * When searching for algorithms, sometimes some pieces are
	 * irrelevenant. Consider classic OLL - you need pieces to be
	 * oriented correctly, but their permutation(on the last layer,
	 * of course) can be completely random.
	 *
	 * It would seem that to achieve such an effect with 2x2x2
	 * Explorer, one would have to prepare special number, called
	 * mask, and then combine it with every state using ''AND''
	 * binary operation. Usually, it's a bit cumbersome.
	 *
	 * Of course, 2x2x2 Explorer has builtin means to achieve
	 * such an effect.
	 *
	 * :class:`Mask` instances store information about what's
	 * expected on every position of the cube. It can be percieved
	 * as 'abstract' goal state, abstract in the sense that it
	 * leaves some expectations unspecified.
	 *
	 * Usage of :class:`Mask` class consists usually of two steps:
	 * 
	 *   1. Construct your mask by multiple calls :func:`.mask`
	 *   2. Compare your mask to the visited states in your
	 *      :class:`Examiner` object. 
	 */
	class Mask
	{
		protected:
			uint64_t bitmask;
			uint64_t goal;
		public:
			/**
			 * On default, mask object is set to the solved
			 * state.
			 */
			Mask(): bitmask(~0LL), goal(cube_ideal().corners) {}

			/**
			 * This method sets *masking* data of the current
			 * position (which is denoted by the first argument)
			 * 
			 * There are two 'modes' of this method:
			 *
			 *   + masked = false -> means that no 'masking' is
			 *     done - in ``piece`` argument, you should put
			 *     a valid cubie indentifier (i.e CUFR etc., 
			 *     check :ref:`fundamentals`)
			 *
			 *   + masked = true -> masking mode is 'on' this
			 *     time, ``piece`` argument now expects so-called
			 *     *mask flags*. There are a few of them::
			 *       
			 *       #define MASK_ANY 0
			 *       #define MASK_R 1
			 *       #define MASK_U 2
			 *       #define MASK_F 4
			 *       #define MASK_L 8
			 *       #define MASK_D 16
			 *       #define MASK_B 32
			 *
			 * Combine them with OR (``|``) operator, of course.
			 * The given mask flag puts some requirement on the
			 * piece placed in the given position. So, for
			 * example, MASK_R | MASK_U means that the piece can
			 * be either UFR or URB (R and U are fixed, but it's
			 * undetermined whether B or F is expected).
			 */
			void maskCubie(int slot, bool masked, uint64_t cubie);

			/**
			 * It's the :func:`maskCubie` counterpart for the cubie
			 * orientation.
			 *
			 *   + masked = false -> no 'masking' - put the
			 *     orientation identifier in the third argument.
			 *
			 *   + masked = true -> as of |release|, there is only
			 *     one mask defined for an orientation::
			 *
			 *       #define MASK_ANY 0  
			 */
			void maskOrientation(int slot, bool masked, uint64_t orientation);

			/**
			 * Resets the mask to it's initial state (i.e. right
			 * after the construction).
			 */
			void reset();

			/// Checks whether the given state comply to the mask 
			bool operator==(const Cube &state);

			/**
			 * Get bit mask (for more sophiscated manual operations).
			 */
			uint64_t getBitmask();

			/**
			 * Get state number (for more manual operations).
			 */
			uint64_t getState();
	};

}
#endif

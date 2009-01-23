:mod:`Explorer` -- reference manual
===============================================

.. module:: Explorer

------------------------
Global-level functions
------------------------

.. function:: void Explorer::init()

  Inits 2x2x2 Explorer. It must be the first 2x2x2 Explorer function called
  in your program. If it isn't, behavior is undefined.


-------
Masks
-------

When searching for algorithms, sometimes some pieces are irrelevenant. Consider
classic OLL - you need pieces to be oriented correctly, but their permutation(
on the last layer, of course) can be completely random.

To achieve such an effect when using 2x2x2 Explorer, one must prepare special
number, called mask, and then combine it with every state using ''AND'' binary
operation. Usually, it's a bit cumbersome. 2x2x2 Explorer has builtin means
to achieve similar effect.

.. class:: Mask

  :class:`Mask` instances store information about what's expected on every
  position of the cube. It can be percieved as 'abstract' goal state, abstract
  in the sense that it leaves some information unspecified.

  Usage of :class:`Mask` class consists usually of two steps:

    1. Construct your mask by multiple calls :func:`.mask`
    2. Compare your mask to the visited states in your :class:`Examiner` object.

  .. method:: void reset()
  
  .. method:: bool operator==(const Cube &state)

    Checks whether the given state comply to the mask 

  .. method:: mask


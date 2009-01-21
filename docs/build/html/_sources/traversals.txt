**************
Traversal
**************

:Author: Michal Hordecki
:Release: |release|
:Date: |today|

.. contents::

-------------------
Traversal objects
-------------------

As for now, you know how states are represented and how to perform simple operations on them.

The most interesting part, however, has yet to come.

There are approximately 3,5 million of possible 2x2x2 situations. This space can be then processed
in a reasonable time. 2x2x2 Explorer provides so-called traversal objects to visit them in certain
order.

.. class:: Traversal

  Traversal class is an abstract base class from which every other traversal class inherits.
  It specifies standard operations that can be made with every traversal class. Specifics
  of the traversal method are left to the inheriting classes.

  .. method:: virtual void traverse(Cube state, Examiner &examiner) = 0
  
    This is the main method of traversal objects. It starts the traversal, beginning
    with the state provided by argument *state*. Some traversal implementations may ignore
    it, some may not.

    Second parameter is an user-provided :class:`Examiner` object. :class:`Examiner` is an
    another abstract base class, acting as a functor object.

  .. method:: virtual void setVerbosity(bool verbosity);

    It sets object's verbosity, i.e. whether it should process some debug output to the standard
    output.




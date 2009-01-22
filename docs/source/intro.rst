*****************
Getting Started
*****************

:Author: Michal Hordecki
:Release: |release|
:Date: |today|

Hello! Thanks you for downloading 2x2x2 Explorer.

2x2x2 Explorer is a programming library aiming to aid with
developing new Pocket Cube methods and with 2x2x2-oriented development
overall.

Explorer is written in C++ and is covered by MIT License. Use it freely.

------------------
Learning process
------------------

2x2x2 Explorer is a really small library, easy to learn and develop with.

Recommended learning curve:

  1. Learn about 2x2x2 Explorer :ref:`fundamentals`.
  2. Get in touch with :ref:`traversal` classes.
  3. Read some examples placed in :file:`examples/` directory.
  4. When in doubt, refer to :mod:`Explorer`.

---------------------------
Installing 2x2x2 Explorer
---------------------------

To install 2x2x2 Explorer, be sure that you have working programming
environment on your computer. 2x2x2 Explorer is written with GCC in mind,
but it will probably run flawlessly on other platforms, too.

-----------------------------------
Using 2x2x2 Explorer - guidelines
-----------------------------------

There are a few things that need to be considered during development with
2x2x2 Explorer.

  + To include 2x2x2 Explorer's header file, type:::
    
       #include <222Explorer/222Explorer.h>

  + You need to link your application against 222explorer library (in G++,
    pass -l222explorer flag to linker)

  + All 2x2x2 Explorer files are placed in :mod:`Explorer` namespace

  + Be sure to call :func:`Explorer::init()` at the beginning of your program.



